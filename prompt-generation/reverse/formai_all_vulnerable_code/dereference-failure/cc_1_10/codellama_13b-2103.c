//Code Llama-13B DATASET v1.0 Category: Subnet Calculator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 100

int main() {
    char input[MAX_INPUT];
    char* token;
    int subnet_mask;
    int network_address;
    int broadcast_address;
    int number_of_hosts;
    int subnet_mask_binary[32];
    int network_address_binary[32];
    int broadcast_address_binary[32];

    printf("Enter the subnet mask: ");
    fgets(input, MAX_INPUT, stdin);
    token = strtok(input, "/");
    subnet_mask = atoi(token);

    printf("Enter the network address: ");
    fgets(input, MAX_INPUT, stdin);
    token = strtok(input, ".");
    network_address = atoi(token);

    printf("Enter the broadcast address: ");
    fgets(input, MAX_INPUT, stdin);
    token = strtok(input, ".");
    broadcast_address = atoi(token);

    for (int i = 0; i < 32; i++) {
        if (subnet_mask & (1 << i)) {
            subnet_mask_binary[i] = 1;
        } else {
            subnet_mask_binary[i] = 0;
        }
    }

    for (int i = 0; i < 32; i++) {
        if (network_address & (1 << i)) {
            network_address_binary[i] = 1;
        } else {
            network_address_binary[i] = 0;
        }
    }

    for (int i = 0; i < 32; i++) {
        if (broadcast_address & (1 << i)) {
            broadcast_address_binary[i] = 1;
        } else {
            broadcast_address_binary[i] = 0;
        }
    }

    for (int i = 0; i < 32; i++) {
        if (subnet_mask_binary[i] == 1) {
            if (network_address_binary[i] == broadcast_address_binary[i]) {
                number_of_hosts++;
            } else {
                break;
            }
        }
    }

    printf("The number of hosts in the subnet is: %d\n", number_of_hosts);

    return 0;
}