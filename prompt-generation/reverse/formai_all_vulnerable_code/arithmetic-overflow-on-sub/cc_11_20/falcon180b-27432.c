//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 256
#define IP_MAX_LENGTH 16

typedef struct {
    char *name;
    char *ip;
    char *mask;
    int num_hosts;
} subnet_t;

int main() {
    int num_subnets = 0;
    subnet_t subnets[MAX_SUBNETS];

    printf("Enter the number of subnets to calculate: ");
    scanf("%d", &num_subnets);

    for (int i = 0; i < num_subnets; i++) {
        subnet_t *subnet = &subnets[i];

        printf("Enter the name of subnet %d: ", i+1);
        scanf("%s", subnet->name);

        printf("Enter the IP address of subnet %d: ", i+1);
        scanf("%s", subnet->ip);

        printf("Enter the subnet mask of subnet %d: ", i+1);
        scanf("%s", subnet->mask);

        int ip_length = strlen(subnet->ip);
        int mask_length = strlen(subnet->mask);

        if (ip_length!= mask_length) {
            printf("Error: IP address and subnet mask must have the same length.\n");
            exit(1);
        }

        if (ip_length > IP_MAX_LENGTH) {
            printf("Error: IP address and subnet mask cannot be longer than %d characters.\n", IP_MAX_LENGTH);
            exit(1);
        }

        if (sscanf(subnet->ip, "%d.%d.%d.%d", &subnet->ip[0], &subnet->ip[1], &subnet->ip[2], &subnet->ip[3])!= 4) {
            printf("Error: Invalid IP address format.\n");
            exit(1);
        }

        if (sscanf(subnet->mask, "%d.%d.%d.%d", &subnet->mask[0], &subnet->mask[1], &subnet->mask[2], &subnet->mask[3])!= 4) {
            printf("Error: Invalid subnet mask format.\n");
            exit(1);
        }

        for (int j = 0; j < mask_length; j++) {
            if (subnet->mask[j]!= '.' && subnet->mask[j]!= '0' && subnet->mask[j]!= '1') {
                printf("Error: Invalid subnet mask format.\n");
                exit(1);
            }
        }

        int num_ones = 0;
        for (int j = 0; j < mask_length; j++) {
            if (subnet->mask[j] == '1') {
                num_ones++;
            }
        }

        if (num_ones > MAX_SUBNET_SIZE) {
            printf("Error: Subnet mask is too large.\n");
            exit(1);
        }

        subnet->num_hosts = (int)pow(2, MAX_SUBNET_SIZE - num_ones) - 2;
    }

    printf("Subnet Name\tIP Address\tSubnet Mask\tNumber of Hosts\n");

    for (int i = 0; i < num_subnets; i++) {
        subnet_t *subnet = &subnets[i];

        printf("%s\t%s\t%s\t%d\n", subnet->name, subnet->ip, subnet->mask, subnet->num_hosts);
    }

    return 0;
}