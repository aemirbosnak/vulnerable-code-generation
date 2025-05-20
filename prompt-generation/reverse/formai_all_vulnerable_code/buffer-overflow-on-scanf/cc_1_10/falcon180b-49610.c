//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK 32

typedef struct {
    char name[32];
    char subnet[MAX_SUBNET_SIZE];
    char mask[MAX_SUBNET_MASK];
} Subnet;

int main() {
    int numSubnets;
    Subnet subnets[MAX_SUBNETS];
    int i;

    // Prompt user for number of subnets
    printf("Enter the number of subnets: ");
    scanf("%d", &numSubnets);

    // Initialize all subnets to default values
    for (i = 0; i < numSubnets; i++) {
        strcpy(subnets[i].name, "Subnet");
        strcpy(subnets[i].subnet, "192.168.0.0");
        strcpy(subnets[i].mask, "255.255.255.0");
    }

    // Prompt user for subnet information
    printf("Enter the subnet information:\n");
    for (i = 0; i < numSubnets; i++) {
        printf("Subnet %d:\n", i+1);
        printf("Name: ");
        scanf("%s", subnets[i].name);
        printf("Subnet: ");
        scanf("%s", subnets[i].subnet);
        printf("Mask: ");
        scanf("%s", subnets[i].mask);
    }

    // Print subnet information
    printf("\nSubnet Information:\n");
    for (i = 0; i < numSubnets; i++) {
        printf("Subnet %d:\n", i+1);
        printf("Name: %s\n", subnets[i].name);
        printf("Subnet: %s\n", subnets[i].subnet);
        printf("Mask: %s\n", subnets[i].mask);
        printf("\n");
    }

    return 0;
}