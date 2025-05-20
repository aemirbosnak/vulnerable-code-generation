//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 32

typedef struct {
    char name[MAX_SUBNET_SIZE];
    int size;
} Subnet;

int main(int argc, char *argv[]) {
    int num_subnets = 0;
    Subnet subnets[MAX_SUBNETS];

    if (argc < 2) {
        printf("Usage: %s <IP address> <subnet mask>\n", argv[0]);
        return 1;
    }

    char *ip_str = argv[1];
    char *mask_str = argv[2];

    int ip[4] = {0};
    int mask[4] = {0};

    sscanf(ip_str, "%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);
    sscanf(mask_str, "%d.%d.%d.%d", &mask[0], &mask[1], &mask[2], &mask[3]);

    int network_bits = 0;
    for (int i = 0; i < 4; i++) {
        if (mask[i] == 255) {
            continue;
        }
        if (mask[i] == 0) {
            network_bits += 8;
        } else {
            network_bits += (int)log2(255 - mask[i]);
        }
    }

    int num_hosts = (int)pow(2, 8 * (4 - network_bits));
    int num_subnet_hosts = num_hosts / num_subnets;

    for (int i = 0; i < num_subnets; i++) {
        sprintf(subnets[i].name, "%d.%d.%d.%d", ip[0], ip[1], ip[2], (ip[3] + i * num_subnet_hosts) % 256);
        subnets[i].size = num_subnet_hosts;
        num_subnets++;
    }

    printf("Subnet Name\t\tSubnet Size\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("%s\t\t%d\n", subnets[i].name, subnets[i].size);
    }

    return 0;
}