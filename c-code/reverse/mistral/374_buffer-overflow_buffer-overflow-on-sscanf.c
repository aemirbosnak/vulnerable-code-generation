#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void subnet_calculator(char *ip, char *mask) {
    char buffer[10];
    int octet[4];
    int i, pos;

    sscanf(ip, "%d.%d.%d.%d", &octet[0], &octet[1], &octet[2], &octet[3]);
    sscanf(mask, "%d.%d.%d.%d", &pos, &buffer[0], &buffer[1], &buffer[2]);

    for (i = 0; i < pos; i++) {
        buffer[i] = '1';
    }

    printf("Network Address: %d.%d.%d.%d\n", octet[0], octet[1], octet[2], octet[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n", octet[0] + 255 - (255 >> pos), octet[1] + 255 - (255 >> pos), octet[2] + 255 - (255 >> pos), octet[3] + 255 - (255 >> pos));
    printf("Subnet Mask: %s\n", buffer);
}

int main() {
    char ip[30], mask[16];

    printf("Enter IP address: ");
    fgets(ip, sizeof(ip), stdin);
    printf("Enter subnet mask (e.g. 255.255.255.0): ");
    fgets(mask, sizeof(mask), stdin);

    subnet_calculator(ip, mask);

    return 0;
}
