//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char ip[16];
    int cidr;

    printf("Enter IP address: ");
    scanf("%s", ip);

    printf("Enter CIDR notation: ");
    scanf("%d", &cidr);

    const int MAX_BITS = 32;
    int octet[4];

    memset(octet, 0, sizeof(octet));

    int i, j = 0;
    for (i = 0; i < strlen(ip); i++) {
        if (ip[i] == '.') {
            octet[j++] = atoi(ip + i - strlen(ip));
        }
    }
    octet[j++] = atoi(ip + i - strlen(ip));

    int p = cidr / 8;
    int rem = cidr % 8;
    int mask[4];

    memset(mask, 0, sizeof(mask));

    for (i = 0; i < p; i++) {
        mask[i] = 255;
    }

    if (rem) {
        mask[p] |= (1 << (8 - rem)) - 1;
    }

    printf("Network address: ");

    for (i = 0; i < 4; i++) {
        printf("%d%s", octet[i] & mask[i], (i == 3) ? "" : ".");
    }

    printf("\n");

    printf("Broadcast address: ");

    for (i = 0; i < 4; i++) {
        printf("%d%s", octet[i] | ~mask[i], (i == 3) ? "" : ".");
    }

    printf("\n");

    int hostBits = MAX_BITS - cidr;
    int hosts = (hostBits == MAX_BITS) ? 0 : (1 << hostBits) - 2;

    printf("Number of hosts: %d\n", hosts);

    return 0;
}