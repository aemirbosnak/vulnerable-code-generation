//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SUBNETS 32
#define IP_OCTETS 4

typedef struct {
    char ip[16];
    char mask[16];
    char subnet[16];
    char broadcast[16];
} subnet_t;

int main(int argc, char *argv[]) {
    subnet_t subnet;
    int num_subnets = 0;
    int i, j;

    if (argc < 3) {
        printf("Usage: %s <IP address> <subnet mask>\n", argv[0]);
        return 1;
    }

    strcpy(subnet.ip, argv[1]);
    strcpy(subnet.mask, argv[2]);

    // validate input
    for (i = 0; i < IP_OCTETS; i++) {
        if (subnet.ip[i] == '.' || subnet.ip[i] == '*') {
            printf("Invalid IP address.\n");
            return 1;
        }
        if (subnet.mask[i] == '.' || subnet.mask[i] == '*') {
            printf("Invalid subnet mask.\n");
            return 1;
        }
    }

    // calculate subnet information
    for (i = 0; i < IP_OCTETS; i++) {
        if (subnet.mask[i] == '*') {
            for (j = 0; j <= 255; j++) {
                sprintf(subnet.subnet + strlen(subnet.subnet), "%d.%d.%d.%d ",
                    subnet.ip[0], subnet.ip[1], subnet.ip[2], j);
                sprintf(subnet.broadcast + strlen(subnet.broadcast), "%d.%d.%d.%d ",
                    subnet.ip[0], subnet.ip[1], subnet.ip[2], j);
                num_subnets++;
            }
        } else {
            int mask_value = atoi(subnet.mask + i);
            int ip_value = atoi(subnet.ip + i);
            int subnet_value = (ip_value & mask_value) << (8 - mask_value);

            for (j = 0; j <= mask_value - 1; j++) {
                sprintf(subnet.subnet + strlen(subnet.subnet), "%d.%d.%d.%d ",
                    subnet.ip[0], subnet.ip[1], subnet.ip[2], subnet_value + j);
                sprintf(subnet.broadcast + strlen(subnet.broadcast), "%d.%d.%d.%d ",
                    subnet.ip[0], subnet.ip[1], subnet.ip[2], subnet_value + j - 1);
                num_subnets++;
            }
        }
    }

    // print subnet information
    printf("Subnet information:\n");
    printf("IP address: %s\n", subnet.ip);
    printf("Subnet mask: %s\n", subnet.mask);
    printf("Number of subnets: %d\n", num_subnets);

    for (i = 0; i < num_subnets; i++) {
        printf("Subnet %d: %s\n", i + 1, subnet.subnet);
        printf("Broadcast address: %s\n\n", subnet.broadcast);
    }

    return 0;
}