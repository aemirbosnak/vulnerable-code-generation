#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calculate_network_broadcast(char *ip, char *subnet_mask) {
    unsigned int ip_parts[4], subnet_parts[4];
    unsigned int network_parts[4], broadcast_parts[4];
    unsigned long host_count = 0;

    sscanf(ip, "%u.%u.%u.%u", &ip_parts[0], &ip_parts[1], &ip_parts[2], &ip_parts[3]);
    sscanf(subnet_mask, "%u.%u.%u.%u", &subnet_parts[0], &subnet_parts[1], &subnet_parts[2], &subnet_parts[3]);

    for (int i = 0; i < 4; i++) {
        network_parts[i] = ip_parts[i] & subnet_parts[i];
        broadcast_parts[i] = network_parts[i] | (~subnet_parts[i]);
    }

    printf("Network Address: %d.%d.%d.%d\n", network_parts[0], network_parts[1], network_parts[2], network_parts[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n", broadcast_parts[0], broadcast_parts[1], broadcast_parts[2], broadcast_parts[3]);

    for (int i = 0; i < 4; i++) {
        if (subnet_parts[i] != 0xFF) {
            host_count += (1 << (8 - (subnet_parts[i] & 0xFF)));
        }
    }

    printf("Number of Hosts: %lu\n", host_count);
}

int main() {
    char ip[16], subnet_mask[16];

    printf("Enter IP address: ");
    fgets(ip, sizeof(ip), stdin);
    ip[strcspn(ip, "\n")] = '\0';

    printf("Enter Subnet Mask: ");
    fgets(subnet_mask, sizeof(subnet_mask), stdin);
    subnet_mask[strcspn(subnet_mask, "\n")] = '\0';

    calculate_network_broadcast(ip, subnet_mask);

    return 0;
}
