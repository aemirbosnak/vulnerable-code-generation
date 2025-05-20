#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void ipToBinary(char *ip) {
    int i;
    unsigned char octets[4];
    sscanf(ip, "%hhu.%hhu.%hhu.%hhu", &octets[0], &octets[1], &octets[2], &octets[3]);
    printf("Binary: ");
    for (i = 0; i < 4; i++) {
        printf("%d%d%d%d %d%d%d%d ", 
               (octets[i] >> 7) & 1, (octets[i] >> 6) & 1, (octets[i] >> 5) & 1, (octets[i] >> 4) & 1,
               (octets[i] >> 3) & 1, (octets[i] >> 2) & 1, (octets[i] >> 1) & 1, octets[i] & 1);
    }
    printf("\n");
}

int main() {
    char ip[16], subnetMask[16];
    printf("Enter IP Address: ");
    scanf("%s", ip);
    printf("Enter Subnet Mask: ");
    scanf("%s", subnetMask);

    ipToBinary(ip);

    return 0;
}
