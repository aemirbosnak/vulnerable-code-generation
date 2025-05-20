//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 16
#define MAX_SUBNET_MASK 32
#define MAX_IP_SIZE 16

typedef struct {
    char ip[MAX_IP_SIZE];
    char mask[MAX_SUBNET_MASK];
    char size[MAX_SUBNET_SIZE];
} Subnet;

int main() {
    int numSubnets;
    Subnet subnets[MAX_SUBNETS];
    char ip[MAX_IP_SIZE];
    char mask[MAX_SUBNET_MASK];
    char size[MAX_SUBNET_SIZE];

    printf("Enter the IP address in the format xxx.xxx.xxx.xxx: ");
    scanf("%s", ip);

    printf("Enter the subnet mask in the format xxx.xxx.xxx.xxx: ");
    scanf("%s", mask);

    printf("Enter the number of subnets: ");
    scanf("%d", &numSubnets);

    subnets[0].ip[0] = '\0';
    strcpy(subnets[0].ip, ip);
    strcpy(subnets[0].mask, mask);
    sprintf(subnets[0].size, "%d", 32);

    for (int i = 1; i < numSubnets; i++) {
        int maskBits = 32 - atoi(subnets[i - 1].size);
        int subnetBits = maskBits - 2;
        int subnet = (int)pow(2, subnetBits);
        sprintf(size, "%d", subnet);

        strcpy(subnets[i].ip, ip);
        strcpy(subnets[i].mask, mask);
        strcpy(subnets[i].size, size);
    }

    printf("\nSubnet\tIP Address\tSubnet Mask\tSubnet Size\n");
    for (int i = 0; i < numSubnets; i++) {
        printf("%d\t%s\t%s\t%s\n", i + 1, subnets[i].ip, subnets[i].mask, subnets[i].size);
    }

    return 0;
}