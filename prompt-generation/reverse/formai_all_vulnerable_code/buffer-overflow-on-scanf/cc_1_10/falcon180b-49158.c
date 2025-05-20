//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK 32
#define MAX_SUBNET_NAME 64

typedef struct {
    char name[MAX_SUBNET_NAME];
    char mask[MAX_SUBNET_MASK];
    char size[MAX_SUBNET_SIZE];
} subnet;

void calculate_subnets(char *ip, int mask, subnet *subnets) {
    int i, j, k;
    char subnet_ip[16];
    char subnet_mask[16];
    char subnet_size[16];

    for (i = 0; i < MAX_SUBNETS; i++) {
        sprintf(subnet_ip, "%s.%d", ip, i);
        sprintf(subnet_mask, "%d.%d.%d.%d", (mask >> 24) & 0xff, (mask >> 16) & 0xff, (mask >> 8) & 0xff, mask & 0xff);
        sprintf(subnet_size, "%d", 32 - mask);

        strcpy(subnets[i].name, subnet_ip);
        strcpy(subnets[i].mask, subnet_mask);
        strcpy(subnets[i].size, subnet_size);
    }
}

int main() {
    char ip[16];
    int mask;
    subnet subnets[MAX_SUBNETS];

    printf("Enter the IP address: ");
    scanf("%s", ip);

    printf("Enter the subnet mask: ");
    scanf("%d", &mask);

    calculate_subnets(ip, mask, subnets);

    printf("Subnet IP\tSubnet Mask\tSubnet Size\n");

    for (int i = 0; i < MAX_SUBNETS; i++) {
        printf("%s\t%s\t%s\n", subnets[i].name, subnets[i].mask, subnets[i].size);
    }

    return 0;
}