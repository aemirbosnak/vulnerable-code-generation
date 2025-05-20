//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IP_SIZE 32

int main() {
    char ip[15];
    int prefix;
    int subnet_mask[4];

    printf("Enter the IP address with a CIDR notation (e.g., 192.168.0.0/24):\n");
    scanf("%s", ip);
    scanf("%d", &prefix);

    char* token = strtok(ip, ".");
    int i = 0;

    while (token != NULL) {
        int octet = atoi(token);
        if (octet < 0 || octet > 255) {
            printf("Invalid IP address\n");
            return 1;
        }
        subnet_mask[i++] = octet;
        token = strtok(NULL, ".");
    }

    if (prefix < 0 || prefix > IP_SIZE) {
        printf("Invalid CIDR notation\n");
        return 1;
    }

    int mask_bits = 0;
    for (i = 0; i < 4; i++) {
        int tmp = subnet_mask[i];
        int j = 0;

        while (tmp != 0) {
            mask_bits += tmp % 2;
            tmp /= 2;
            j++;
        }

        if (j != 8) {
            printf("Invalid IP address\n");
            return 1;
        }
    }

    int net_mask[4];

    for (i = 0; i < 4; i++) {
        net_mask[i] = 0;
    }

    for (i = 0; i < prefix; i++) {
        int offset = i % 8;
        int octet = i / 8;

        net_mask[octet] |= 1 << (7 - offset);
    }

    printf("Subnet mask: %d.%d.%d.%d\n", net_mask[0], net_mask[1], net_mask[2], net_mask[3]);

    return 0;
}