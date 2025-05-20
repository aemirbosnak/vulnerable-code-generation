//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to convert binary to decimal
int bin_to_dec(char *str, int len) {
    int i, sum = 0;
    for (i = 0; i < len; i++) {
        if (str[i] == '1') {
            sum += 1 << (len - 1 - i);
        }
    }
    return sum;
}

int main() {
    char ip[16], subnet_mask[16];
    printf("Enter the IP address (e.g. 192.168.0.1): ");
    scanf("%s", ip);
    printf("Enter the subnet mask (e.g. 255.255.255.0): ");
    scanf("%s", subnet_mask);

    // separating the IP address into 4 parts
    char *token;
    int ip_parts[4], i = 0;
    token = strtok(ip, ".");
    while (token != NULL && i < 4) {
        ip_parts[i] = atoi(token);
        i++;
        token = strtok(NULL, ".");
    }

    // separating the subnet mask into 4 parts
    int subnet_mask_parts[4], j = 0;
    token = strtok(subnet_mask, ".");
    while (token != NULL && j < 4) {
        subnet_mask_parts[j] = atoi(token);
        j++;
        token = strtok(NULL, ".");
    }

    // convert the subnet mask to binary
    int subnet_mask_binary[32] = {0};
    for (i = 0; i < 4; i++) {
        char subnet_part[9] = {'\0'};
        int subnet_part_int = subnet_mask_parts[i];
        int index = i * 8;
        int j = 0;
        while (subnet_part_int > 0) {
            subnet_part[j++] = subnet_part_int % 2 + '0';
            subnet_part_int /= 2;
        }

        int len = strlen(subnet_part);
        for (j = len - 1; j >= 0; j--, index++) {
            subnet_mask_binary[index] = subnet_part[j] - '0';
        }
    }

    // calculate the number of hosts and network id
    int num_of_hosts = 1 << (32 - bin_to_dec(subnet_mask_binary, 32));
    int network_id_binary[32] = {0};
    for (i = 0; i < 4; i++) {
        int network_part = ip_parts[i] & subnet_mask_parts[i];
        char network_part_binary[9] = {'\0'};
        int j = 0;
        while (network_part > 0) {
            network_part_binary[j++] = network_part % 2 + '0';
            network_part /= 2;
        }

        int len = strlen(network_part_binary);
        for (j = len - 1; j >= 0; j--) {
            network_id_binary[i * 8 + j] = network_part_binary[j] - '0';
        }
    }

    // convert the network id to decimal
    int network_id_parts[4];
    for (i = 0; i < 4; i++) {
        network_id_parts[i] = bin_to_dec(&network_id_binary[i * 8], 8);
    }

    printf("Number of hosts: %d\n", num_of_hosts);
    printf("Network ID: %d.%d.%d.%d\n", network_id_parts[0], network_id_parts[1], network_id_parts[2], network_id_parts[3]);

    return 0;
}