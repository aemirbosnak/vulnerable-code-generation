//Code Llama-13B DATASET v1.0 Category: Subnet Calculator ; Style: portable
#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    struct subnet_info {
        char* address;
        char* mask;
        char* network;
        char* broadcast;
        char* first_host;
        char* last_host;
        char* total_hosts;
    };

    void calculate_subnet(struct subnet_info* info) {
        // Calculate the network address
        info->network = calloc(16, sizeof(char));
        strcpy(info->network, info->address);
        info->network[strlen(info->network) - 1] = '0';

        // Calculate the broadcast address
        info->broadcast = calloc(16, sizeof(char));
        strcpy(info->broadcast, info->address);
        info->broadcast[strlen(info->broadcast) - 1] = '1';

        // Calculate the first host address
        info->first_host = calloc(16, sizeof(char));
        strcpy(info->first_host, info->network);
        info->first_host[strlen(info->first_host) - 1] = '1';

        // Calculate the last host address
        info->last_host = calloc(16, sizeof(char));
        strcpy(info->last_host, info->broadcast);
        info->last_host[strlen(info->last_host) - 1] = '0';

        // Calculate the total number of hosts
        info->total_hosts = calloc(16, sizeof(char));
        strcpy(info->total_hosts, "255");
    }

    int main() {
        struct subnet_info info;
        char address[16];
        char mask[16];

        printf("Enter the IP address: ");
        scanf("%s", address);
        printf("Enter the subnet mask: ");
        scanf("%s", mask);

        info.address = address;
        info.mask = mask;

        calculate_subnet(&info);

        printf("Network address: %s\n", info.network);
        printf("Broadcast address: %s\n", info.broadcast);
        printf("First host address: %s\n", info.first_host);
        printf("Last host address: %s\n", info.last_host);
        printf("Total number of hosts: %s\n", info.total_hosts);

        return 0;
    }