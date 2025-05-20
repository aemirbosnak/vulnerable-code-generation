//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK 32

typedef struct {
    char name[MAX_SUBNETS][MAX_SUBNET_SIZE];
    char mask[MAX_SUBNETS][MAX_SUBNET_MASK];
    int num_subnets;
} SubnetConfig;

void parse_subnet_config(SubnetConfig *config, char *config_str) {
    char *token;
    int i = 0;

    config->num_subnets = 0;

    token = strtok(config_str, ",");
    while (token!= NULL && i < MAX_SUBNETS) {
        strcpy(config->name[i], token);
        strcpy(config->mask[i], "255.255.255.0");
        i++;
        token = strtok(NULL, ",");
    }

    config->num_subnets = i;
}

void print_subnet_config(SubnetConfig *config) {
    int i;

    for (i = 0; i < config->num_subnets; i++) {
        printf("Subnet %d: %s (%s)\n", i + 1, config->name[i], config->mask[i]);
    }
}

int main() {
    SubnetConfig config;
    char config_str[MAX_SUBNETS * (MAX_SUBNET_SIZE + MAX_SUBNET_MASK + 2)];
    int i, j;

    printf("Enter subnet configuration (format: subnet1,subnet2,...): ");
    scanf("%s", config_str);

    parse_subnet_config(&config, config_str);
    print_subnet_config(&config);

    return 0;
}