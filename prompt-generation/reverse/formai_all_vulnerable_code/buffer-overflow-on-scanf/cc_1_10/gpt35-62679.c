//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void subnet_mask(int cidr, int i, int bit, int *subnet) {
    if (i < 4) {
        int mask = 0;
        for (int b = 0; b < 8; b++) {
            if (bit > 0) {
                mask |= 1 << (7 - b);
                bit--;
            }
        }
        subnet[i] = mask;
        subnet_mask(cidr, i + 1, bit, subnet);
    }
}

int main() {
    int ip[4];
    int cidr;
    int subnet[4];
    int broadcast[4];
    int network[4];
    int address[4];
    int hosts;
    int valid = 1;

    printf("Enter IP address in the format xxx.xxx.xxx.xxx: ");
    scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);

    printf("Enter CIDR notation (e.g. 24): ");
    scanf("%d", &cidr);

    if (cidr < 1 || cidr > 32) {
        printf("Invalid CIDR notation!");
        valid = 0;
    }

    if (valid) {
        subnet_mask(cidr, 0, 8, subnet);

        for (int i = 0; i < 4; i++) {
            broadcast[i] = ip[i] | ~subnet[i];
            network[i] = ip[i] & subnet[i];
        }

        hosts = 1 << (32 - cidr) - 2;

        printf("\nSubnet mask: %d.%d.%d.%d\n", subnet[0], subnet[1], subnet[2], subnet[3]);

        printf("Network address: %d.%d.%d.%d\n", network[0], network[1], network[2], network[3]);

        printf("Broadcast address: %d.%d.%d.%d\n", broadcast[0], broadcast[1], broadcast[2], broadcast[3]);

        printf("Number of hosts: %d\n", hosts);

        printf("Possible IP addresses:\n");

        for (int i = 1; i < hosts + 1; i++) {
            int index = i - 1;
            int bit1 = (index >> 7) & 1;
            int bit2 = (index >> 6) & 1;
            int bit3 = (index >> 5) & 1;
            int bit4 = (index >> 4) & 1;
            int bit5 = (index >> 3) & 1;
            int bit6 = (index >> 2) & 1;
            int bit7 = (index >> 1) & 1;
            int bit8 = index & 1;
            address[0] = network[0] + bit1;
            address[1] = network[1] + bit2;
            address[2] = network[2] + bit3;
            address[3] = network[3] + bit4;
            if (address[3] > broadcast[3] || (address[3] == broadcast[3] && address[2] > broadcast[2]) ||
                (address[3] == broadcast[3] && address[2] == broadcast[2] && address[1] > broadcast[1]) ||
                (address[3] == broadcast[3] && address[2] == broadcast[2] && address[1] == broadcast[1] &&
                 address[0] > broadcast[0])) {
                break;
            }
            printf("%d.%d.%d.%d\n", address[0], address[1], address[2], address[3]);
        }
    }

    return 0;
}