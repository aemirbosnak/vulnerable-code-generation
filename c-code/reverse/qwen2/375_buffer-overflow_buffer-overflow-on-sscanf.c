#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void calculateSubnetInfo(char *ip, char *mask) {
    unsigned int ipInt = 0, maskInt = 0;
    for (int i = 0; i < 4; i++) {
        sscanf(ip + i*3, "%d", &ipInt);
        sscanf(mask + i*3, "%d", &maskInt);
        printf("IP%d: %u\n", i+1, ipInt);
        printf("Mask%d: %u\n", i+1, maskInt);
    }
}

int main() {
    char ip[20], mask[20];
    printf("Enter IP address: ");
    fgets(ip, sizeof(ip), stdin);
    printf("Enter subnet mask: ");
    fgets(mask, sizeof(mask), stdin);
    calculateSubnetInfo(ip, mask);
    return 0;
}
