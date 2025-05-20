//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 32

struct subnet {
    char name[MAX_SUBNET_SIZE];
    char ip[MAX_SUBNET_SIZE];
    char mask[MAX_SUBNET_SIZE];
    int num_hosts;
};

int main() {
    int num_subnets, i, j;
    struct subnet subnets[MAX_SUBNETS];

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    for (i = 0; i < num_subnets; i++) {
        printf("Enter the name of subnet %d: ", i+1);
        scanf("%s", subnets[i].name);

        printf("Enter the IP address of subnet %s: ", subnets[i].name);
        scanf("%s", subnets[i].ip);

        printf("Enter the subnet mask of subnet %s: ", subnets[i].name);
        scanf("%s", subnets[i].mask);

        subnets[i].num_hosts = 0;
    }

    for (i = 0; i < num_subnets; i++) {
        for (j = 0; j < MAX_SUBNET_SIZE; j++) {
            if (subnets[i].ip[j] == '.' || subnets[i].mask[j] == '.') {
                subnets[i].ip[j] = '\0';
                subnets[i].mask[j] = '\0';
            }
        }

        int num_octets = strlen(subnets[i].ip) - 1;
        int mask_size = strlen(subnets[i].mask) - 1;

        if (num_octets!= mask_size) {
            printf("Invalid subnet mask for subnet %s\n", subnets[i].name);
            exit(1);
        }

        int host_bits = 0;
        for (j = 0; j < mask_size; j++) {
            if (subnets[i].mask[j] == '0') {
                host_bits++;
            }
        }

        subnets[i].num_hosts = (int)pow(2, host_bits) - 2;
    }

    printf("Subnet\tIP Address\tSubnet Mask\tNumber of Hosts\n");
    for (i = 0; i < num_subnets; i++) {
        printf("%s\t%s\t%s\t%d\n", subnets[i].name, subnets[i].ip, subnets[i].mask, subnets[i].num_hosts);
    }

    return 0;
}