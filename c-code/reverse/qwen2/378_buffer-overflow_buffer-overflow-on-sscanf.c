#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void calculate_subnet_info(const char *ip_str, const char *mask_str) {
    unsigned int ip[4], mask[4];
    sscanf(ip_str, "%u.%u.%u.%u", &ip[0], &ip[1], &ip[2], &ip[3]);
    sscanf(mask_str, "%u.%u.%u.%u", &mask[0], &mask[1], &mask[2], &mask[3]);

    unsigned int network[4] = {ip[0] & mask[0], ip[1] & mask[1], ip[2] & mask[2], ip[3] & mask[3]};
    unsigned int broadcast[4] = {network[0] | ~mask[0], network[1] | ~mask[1], network[2] | ~mask[2], network[3] | ~mask[3]};

    printf("Network: %u.%u.%u.%u\n", network[0], network[1], network[2], network[3]);
    printf("Broadcast: %u.%u.%u.%u\n", broadcast[0], broadcast[1], broadcast[2], broadcast[3]);
}

int main() {
    char ip[16], mask[16];
    printf("Enter IP address (e.g., 192.168.1.1): ");
    scanf("%s", ip);
    printf("Enter subnet mask (e.g., 255.255.255.0): ");
    scanf("%s", mask);

    calculate_subnet_info(ip, mask);

    return 0;
}
