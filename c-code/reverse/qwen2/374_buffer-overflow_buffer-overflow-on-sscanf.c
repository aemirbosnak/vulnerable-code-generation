#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void calculateSubnet(char *ip, char *mask) {
    int ip_parts[4], mask_parts[4];
    sscanf(ip, "%d.%d.%d.%d", &ip_parts[0], &ip_parts[1], &ip_parts[2], &ip_parts[3]);
    sscanf(mask, "%d.%d.%d.%d", &mask_parts[0], &mask_parts[1], &mask_parts[2], &mask_parts[3]);

    printf("Network Address: %d.%d.%d.%d\n",
           (ip_parts[0] & mask_parts[0]),
           (ip_parts[1] & mask_parts[1]),
           (ip_parts[2] & mask_parts[2]),
           (ip_parts[3] & mask_parts[3]));
}

int main() {
    char ip[16], mask[16];
    printf("Enter IP address: ");
    scanf("%s", ip);
    printf("Enter Subnet Mask: ");
    scanf("%s", mask);

    calculateSubnet(ip, mask);

    return 0;
}
