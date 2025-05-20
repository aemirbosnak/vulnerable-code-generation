//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_ADDR_LEN 16
#define MAX_SUBNET_MASK_LEN 3
#define MAX_BINARY_STR_LEN 32

void decimal_to_binary(int decimal, char *binary_str);
void calculate_subnet(char *ip_address, char *subnet_mask, char *network_address,
                      char *broadcast_address, char *usable_host_addresses);

int main() {
    char ip_address[MAX_IP_ADDR_LEN];
    char subnet_mask[MAX_SUBNET_MASK_LEN];
    char network_address[MAX_IP_ADDR_LEN];
    char broadcast_address[MAX_IP_ADDR_LEN];
    char usable_host_addresses[MAX_BINARY_STR_LEN];

    printf("Please enter IP address (xxx.xxx.xxx.xxx): ");
    fgets(ip_address, MAX_IP_ADDR_LEN, stdin);
    strtok(ip_address, "\n");

    printf("Please enter subnet mask (/yy): ");
    fgets(subnet_mask, MAX_SUBNET_MASK_LEN, stdin);
    strtok(subnet_mask, "\n");

    calculate_subnet(ip_address, subnet_mask, network_address, broadcast_address, usable_host_addresses);

    printf("\nNetwork Address: %s\n", network_address);
    printf("Broadcast Address: %s\n", broadcast_address);
    printf("Usable host addresses: %s\n", usable_host_addresses);

    return 0;
}

void decimal_to_binary(int decimal, char *binary_str) {
    int i;
    for (i = 31; i >= 0; i--) {
        binary_str[i] = (decimal & 1) + '0';
        decimal >>= 1;
    }
    binary_str[32] = '\0';
}

void calculate_subnet(char *ip_address, char *subnet_mask, char *network_address,
                      char *broadcast_address, char *usable_host_addresses) {
    int ip[4];
    int mask;
    char binary_ip[MAX_BINARY_STR_LEN];
    char binary_subnet[MAX_BINARY_STR_LEN];
    char binary_network_address[MAX_BINARY_STR_LEN];
    char binary_broadcast_address[MAX_BINARY_STR_LEN];

    sscanf(ip_address, "%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);
    sscanf(subnet_mask, "/%d", &mask);

    decimal_to_binary(ip[0], &binary_ip[0]);
    decimal_to_binary(ip[1], &binary_ip[8]);
    decimal_to_binary(ip[2], &binary_ip[16]);
    decimal_to_binary(ip[3], &binary_ip[24]);

    memset(binary_subnet, '1', mask);
    memset(binary_subnet + mask, '0', 32 - mask);

    binary_subnet[32] = '\0';

    for (int i = 0; i < 32; i++) {
        if (binary_subnet[i] == '1' && binary_ip[i] == '1') {
            binary_network_address[i] = '1';
            binary_broadcast_address[i] = '1';
        } else if (binary_subnet[i] == '1') {
            binary_network_address[i] = '0';
            binary_broadcast_address[i] = '1';
        } else {
            binary_network_address[i] = binary_ip[i];
            binary_broadcast_address[i] = binary_ip[i];
        }
    }

    binary_network_address[32] = '\0';
    binary_broadcast_address[32] = '\0';

    sprintf(network_address, "%d.%d.%d.%d", strtol(binary_network_address, NULL, 2),
            strtol(binary_network_address + 8, NULL, 2),
            strtol(binary_network_address + 16, NULL, 2),
            strtol(binary_network_address + 24, NULL, 2));

    sprintf(broadcast_address, "%d.%d.%d.%d", strtol(binary_broadcast_address, NULL, 2),
            strtol(binary_broadcast_address + 8, NULL, 2),
            strtol(binary_broadcast_address + 16, NULL, 2),
            strtol(binary_broadcast_address + 24, NULL, 2));

    int num_hosts = (1 << (32 - mask)) - 2;
    decimal_to_binary(num_hosts, usable_host_addresses);
    int len = strlen(usable_host_addresses);
    strncpy(usable_host_addresses, usable_host_addresses + (32 - len), len);
    usable_host_addresses[32 - len] = '\0';
}