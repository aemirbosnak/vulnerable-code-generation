//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_NETWORK_SIZE 32
#define MAX_SUBNET_SIZE 32
#define MAX_BROADCAST_SIZE 32
#define MAX_MASK_SIZE 32

typedef struct {
    char network[MAX_NETWORK_SIZE];
    char subnet[MAX_SUBNET_SIZE];
    char broadcast[MAX_BROADCAST_SIZE];
    char mask[MAX_MASK_SIZE];
} subnet_t;

void print_subnet(subnet_t *subnet) {
    printf("Network: %s\n", subnet->network);
    printf("Subnet: %s\n", subnet->subnet);
    printf("Broadcast: %s\n", subnet->broadcast);
    printf("Mask: %s\n", subnet->mask);
}

void calculate_subnet(subnet_t *subnet, char *network, char *mask) {
    int i;
    for (i = 0; i < strlen(mask); i++) {
        if (mask[i] == '1') {
            subnet->subnet[i] = network[i];
        } else {
            subnet->subnet[i] = '0';
        }
    }
    subnet->broadcast[strlen(mask) - 1] = '1';
    for (i = strlen(mask) - 1; i >= 0; i--) {
        if (mask[i] == '1') {
            subnet->broadcast[i] = '1';
        } else {
            subnet->broadcast[i] = '0';
        }
    }
    for (i = 0; i < strlen(mask); i++) {
        if (mask[i] == '1') {
            subnet->mask[i] = '1';
        } else {
            subnet->mask[i] = '0';
        }
    }
}

int main() {
    subnet_t subnet;
    char network[MAX_NETWORK_SIZE];
    char mask[MAX_MASK_SIZE];
    char *token;
    int i;

    printf("Enter the network address: ");
    scanf("%s", network);

    printf("Enter the subnet mask: ");
    scanf("%s", mask);

    calculate_subnet(&subnet, network, mask);

    printf("Network: %s\n", subnet.network);
    printf("Subnet: %s\n", subnet.subnet);
    printf("Broadcast: %s\n", subnet.broadcast);
    printf("Mask: %s\n", subnet.mask);

    return 0;
}