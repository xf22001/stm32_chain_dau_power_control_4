

/*================================================================
 *   
 *   
 *   文件名称：power_manager_group_policy_config.c
 *   创 建 者：肖飞
 *   创建日期：2022年07月19日 星期二 14时59分42秒
 *   修改日期：2022年07月19日 星期二 15时02分36秒
 *   描    述：
 *
 *================================================================*/
#include "power_manager_group_policy_chain.h"

#include "power_manager.h"
#include "main.h"

#include "log.h"

extern ADC_HandleTypeDef hadc1;

static relay_node_info_t relay_node_info_0_0 = {
	.relay_id = 0,
	.bind_node_id = {0, 1},
	.gpio_port = kg1_GPIO_Port,//km1-kg1
	.gpio_pin = kg1_Pin,
	.gpio_port_fb = fb1_GPIO_Port,
	.gpio_pin_fb = fb1_Pin,
};

static relay_node_info_t relay_node_info_0_1 = {
	.relay_id = 1,
	.bind_node_id = {1, 2},
	.gpio_port = kg2_GPIO_Port,//km2-kg2
	.gpio_pin = kg2_Pin,
	.gpio_port_fb = fb2_GPIO_Port,
	.gpio_pin_fb = fb2_Pin,
};

static relay_node_info_t relay_node_info_0_2 = {
	.relay_id = 2,
	.bind_node_id = {2, 3},
	.gpio_port = kg3_GPIO_Port,//km3-kg3
	.gpio_pin = kg3_Pin,
	.gpio_port_fb = fb3_GPIO_Port,
	.gpio_pin_fb = fb3_Pin,
};

static relay_node_info_t relay_node_info_0_3 = {
	.relay_id = 3,
	.bind_node_id = {3, 4},
	.gpio_port = kg4_GPIO_Port,//km4-kg4
	.gpio_pin = kg4_Pin,
	.gpio_port_fb = fb4_GPIO_Port,
	.gpio_pin_fb = fb4_Pin,
};

static relay_node_info_t relay_node_info_0_4 = {
	.relay_id = 4,
	.bind_node_id = {4, 0},
	.gpio_port = kg5_GPIO_Port,//km5-kg5
	.gpio_pin = kg5_Pin,
	.gpio_port_fb = fb5_GPIO_Port,
	.gpio_pin_fb = fb5_Pin,
};

static relay_node_info_t *relay_node_info_0_sz[] = {
	&relay_node_info_0_0,
	&relay_node_info_0_1,
	&relay_node_info_0_2,
	&relay_node_info_0_3,
	&relay_node_info_0_4,
};

static power_manager_group_relay_info_t power_manager_group_relay_info_0 = {
	.power_manager_group_id = 0,
	.size = ARRAY_SIZE(relay_node_info_0_sz),
	.relay_node_info = relay_node_info_0_sz,
};

static power_manager_group_relay_info_t *power_manager_relay_info_sz[] = {
	&power_manager_group_relay_info_0,
};

relay_info_t relay_info = {
	.size = ARRAY_SIZE(power_manager_relay_info_sz),
	.power_manager_group_relay_info = power_manager_relay_info_sz,
};

static power_module_group_bind_node_t power_module_group_bind_node_0_0 = {
	.id = 0,
	.channel_id = 0,
	.power_module_group_id = {0},
};

static power_module_group_bind_node_t power_module_group_bind_node_0_1 = {
	.id = 1,
	.channel_id = 1,
	.power_module_group_id = {1},
};

static power_module_group_bind_node_t power_module_group_bind_node_0_2 = {
	.id = 2,
	.channel_id = 2,
	.power_module_group_id = {2},
};

static power_module_group_bind_node_t power_module_group_bind_node_0_3 = {
	.id = 3,
	.channel_id = 3,
	.power_module_group_id = {3},
};

static power_module_group_bind_node_t power_module_group_bind_node_0_4 = {
	.id = 4,
	.channel_id = 4,
	.power_module_group_id = {4},
};

static power_module_group_bind_node_t *power_module_group_bind_node_sz[] = {
	&power_module_group_bind_node_0_0,
	&power_module_group_bind_node_0_1,
	&power_module_group_bind_node_0_2,
	&power_module_group_bind_node_0_3,
	&power_module_group_bind_node_0_4,
};

static group_power_module_group_bind_info_t group_power_module_group_bind_info_0 = {
	.power_manager_group_id = 0,
	.size = ARRAY_SIZE(power_module_group_bind_node_sz),
	.power_module_group_bind_node = power_module_group_bind_node_sz,
};

static group_power_module_group_bind_info_t *group_power_module_group_bind_info_sz[] = {
	&group_power_module_group_bind_info_0,
};

groups_power_module_group_bind_info_t groups_power_module_group_bind_info = {
	.size = ARRAY_SIZE(group_power_module_group_bind_info_sz),
	.group_power_module_group_bind_info = group_power_module_group_bind_info_sz,
};

static channel_relay_fb_node_info_t channel_relay_fb_node_info_0 = {
	.channel_id = 0,
	.gpio_port_fb = fb6_GPIO_Port,
	.gpio_pin_fb = fb6_Pin,
	.hadc = &hadc1,
	.rank = 0,
};

static channel_relay_fb_node_info_t channel_relay_fb_node_info_1 = {
	.channel_id = 1,
	.gpio_port_fb = fb7_GPIO_Port,
	.gpio_pin_fb = fb7_Pin,
	.hadc = &hadc1,
	.rank = 1,
};

static channel_relay_fb_node_info_t channel_relay_fb_node_info_2 = {
	.channel_id = 2,
	.gpio_port_fb = fb8_GPIO_Port,
	.gpio_pin_fb = fb8_Pin,
	.hadc = &hadc1,
	.rank = 2,
};

static channel_relay_fb_node_info_t channel_relay_fb_node_info_3 = {
	.channel_id = 3,
	.gpio_port_fb = fb9_GPIO_Port,
	.gpio_pin_fb = fb9_Pin,
	.hadc = &hadc1,
	.rank = 3,
};

static channel_relay_fb_node_info_t channel_relay_fb_node_info_4 = {
	.channel_id = 4,
	.gpio_port_fb = fb10_GPIO_Port,
	.gpio_pin_fb = fb10_Pin,
	.hadc = &hadc1,
	.rank = 4,
};

static channel_relay_fb_node_info_t *channel_relay_fb_node_info_sz[] = {
	&channel_relay_fb_node_info_0,
	&channel_relay_fb_node_info_1,
	&channel_relay_fb_node_info_2,
	&channel_relay_fb_node_info_3,
	&channel_relay_fb_node_info_4,
};

static power_manager_group_channel_relay_fb_info_t power_manager_group_channel_relay_fb_info_0 = {
	.power_manager_group_id = 0,
	.size = ARRAY_SIZE(channel_relay_fb_node_info_sz),
	.channel_relay_fb_node_info = channel_relay_fb_node_info_sz,
};

static power_manager_group_channel_relay_fb_info_t *power_manager_group_channel_relay_fb_info_sz[] = {
	&power_manager_group_channel_relay_fb_info_0,
};

channel_relay_fb_info_t channel_relay_fb_info = {
	.size = ARRAY_SIZE(power_manager_group_channel_relay_fb_info_sz),
	.power_manager_group_channel_relay_fb_info = power_manager_group_channel_relay_fb_info_sz,
};

void power_manager_restore_config(channels_info_t *channels_info)
{
	int i;
	int j;

	channels_settings_t *channels_settings = &channels_info->channels_settings;
	power_manager_settings_t *power_manager_settings = &channels_settings->power_manager_settings;

	power_manager_settings->power_manager_group_number = 1;

	debug("power_manager_group_number:%d", power_manager_settings->power_manager_group_number);

	for(i = 0; i < power_manager_settings->power_manager_group_number; i++) {
		power_manager_group_settings_t *power_manager_group_settings = &power_manager_settings->power_manager_group_settings[i];

		power_manager_group_settings->channel_number = 5;
		power_manager_group_settings->relay_board_number_per_channel = 0;

		for(j = 0; j < power_manager_group_settings->relay_board_number_per_channel; j++) {
			power_manager_group_settings->slot_per_relay_board[j] = 5;
		}

		power_manager_group_settings->power_module_group_number = 5;

		channels_info->channel_number += power_manager_group_settings->channel_number;

		for(j = 0; j < power_manager_group_settings->power_module_group_number; j++) {
			power_module_group_settings_t *power_module_group_settings = &power_manager_group_settings->power_module_group_settings[j];
			power_module_group_settings->power_module_number = 3;
		}
	}
}

