#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void calculateSubnet(char *ip, char *mask) {
    unsigned int ipInt = 0, maskInt = 0;
    sscanf(ip, "%u.%u.%u.%u", &ipInt, &ipInt, &ipInt, &ipInt);
    sscanf(mask, "%u.%u.%u.%u", &maskInt, &maskInt, &maskInt, &maskInt);

    unsigned int network = (ipInt & maskInt);
    unsigned int broadcast = (network | (~maskInt));

    printf("Network: %d.%d.%d.%d\n", (network >> 24) & 0xFF, (network >> 16) & 0xFF, (network >> 8) & 0xFF, network & 0xFF);
    printf("Broadcast: %d.%d.%d.%d\n", (broadcast >> 24) & 0xFF, (broadcast >> 16) & 0xFF, (broadcast >> 8) & 0xFF, broadcast & 0xFF);
}

int main() {
    char ip[20], mask[20];
    printf("Enter IP address: ");
    scanf("%s", ip);
    printf("Enter Subnet Mask: ");
    scanf("%s", mask);
    calculateSubnet(ip, mask);
    return 0;
}
