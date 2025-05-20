//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK_SIZE 32

typedef struct {
    char name[MAX_SUBNET_SIZE];
    char mask[MAX_SUBNET_MASK_SIZE];
    int numHosts;
} subnet;

int main() {
    int numSubnets, i;
    subnet subnets[MAX_SUBNETS];
    char input[MAX_SUBNET_SIZE];
    char maskInput[MAX_SUBNET_MASK_SIZE];
    int numHostsInput;

    // Read in number of subnets
    printf("Enter number of subnets: ");
    scanf("%d", &numSubnets);

    // Read in subnet information
    for (i = 0; i < numSubnets; i++) {
        printf("Enter subnet name: ");
        scanf("%s", subnets[i].name);

        printf("Enter subnet mask: ");
        scanf("%s", maskInput);
        strcpy(subnets[i].mask, maskInput);

        printf("Enter number of hosts: ");
        scanf("%d", &numHostsInput);
        subnets[i].numHosts = numHostsInput;
    }

    // Calculate subnet information
    for (i = 0; i < numSubnets; i++) {
        char *maskPtr = strchr(subnets[i].mask, '.');
        int maskLen = strlen(subnets[i].mask);
        int numHosts = subnets[i].numHosts;
        int hostLen = maskLen - 1;
        int hostBits = hostLen * 8;
        int subnetBits = 32 - hostLen * 8;
        int numSubnets = pow(2, subnetBits);
        int subnetMask = 0;
        int j;

        for (j = 0; j < hostLen; j++) {
            subnetMask |= (1 << (32 - (j + 1) * 8)) - 1;
        }

        printf("Subnet %s:\n", subnets[i].name);
        printf("Subnet mask: %s\n", subnets[i].mask);
        printf("Number of hosts: %d\n", numHosts);
        printf("Subnet bits: %d\n", subnetBits);
        printf("Number of subnets: %d\n", numSubnets);
        printf("Subnet mask: %d.%d.%d.%d\n", (subnetMask >> 24) & 0xFF, (subnetMask >> 16) & 0xFF, (subnetMask >> 8) & 0xFF, subnetMask & 0xFF);
        printf("\n");
    }

    return 0;
}