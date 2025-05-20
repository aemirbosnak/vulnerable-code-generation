//Code Llama-13B DATASET v1.0 Category: Subnet Calculator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1024

typedef struct {
    char* address;
    char* netmask;
    char* network;
    char* broadcast;
    char* wildcard;
} subnet_t;

void print_subnet_info(subnet_t* subnet) {
    printf("Address: %s\n", subnet->address);
    printf("Netmask: %s\n", subnet->netmask);
    printf("Network: %s\n", subnet->network);
    printf("Broadcast: %s\n", subnet->broadcast);
    printf("Wildcard: %s\n", subnet->wildcard);
}

int main() {
    char* address;
    char* netmask;
    char* network;
    char* broadcast;
    char* wildcard;

    // Get user input
    printf("Enter IP address: ");
    scanf("%s", address);
    printf("Enter netmask: ");
    scanf("%s", netmask);

    // Convert address and netmask to binary
    int address_bin[32];
    int netmask_bin[32];
    for (int i = 0; i < 32; i++) {
        if (address[i] == '.') {
            address_bin[i] = 0;
        } else {
            address_bin[i] = 1;
        }
        if (netmask[i] == '.') {
            netmask_bin[i] = 0;
        } else {
            netmask_bin[i] = 1;
        }
    }

    // Calculate network and broadcast addresses
    int network_bin[32];
    int broadcast_bin[32];
    for (int i = 0; i < 32; i++) {
        network_bin[i] = address_bin[i] & netmask_bin[i];
        broadcast_bin[i] = address_bin[i] | ~netmask_bin[i];
    }

    // Convert binary to dotted decimal
    char network_str[16];
    char broadcast_str[16];
    for (int i = 0; i < 32; i++) {
        if (network_bin[i]) {
            strcat(network_str, "1");
        } else {
            strcat(network_str, "0");
        }
        if (broadcast_bin[i]) {
            strcat(broadcast_str, "1");
        } else {
            strcat(broadcast_str, "0");
        }
    }
    network = strtok(network_str, ".");
    broadcast = strtok(broadcast_str, ".");

    // Calculate wildcard
    int wildcard_bin[32];
    for (int i = 0; i < 32; i++) {
        wildcard_bin[i] = ~netmask_bin[i];
    }
    char wildcard_str[16];
    for (int i = 0; i < 32; i++) {
        if (wildcard_bin[i]) {
            strcat(wildcard_str, "1");
        } else {
            strcat(wildcard_str, "0");
        }
    }
    wildcard = strtok(wildcard_str, ".");

    // Print subnet information
    subnet_t subnet;
    subnet.address = address;
    subnet.netmask = netmask;
    subnet.network = network;
    subnet.broadcast = broadcast;
    subnet.wildcard = wildcard;
    print_subnet_info(&subnet);

    return 0;
}