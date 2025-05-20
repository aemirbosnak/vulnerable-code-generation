//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_SUBNETS 10

typedef struct {
    int ip;
    int mask;
    int subnet;
    char name[20];
} subnet_t;

int main() {
    int num_subnets;
    subnet_t subnets[MAX_SUBNETS];
    int i, j;

    // Ask user for number of subnets
    printf("How many subnets do you want to calculate? (max %d): ", MAX_SUBNETS);
    scanf("%d", &num_subnets);

    // Initialize subnets
    for (i = 0; i < num_subnets; i++) {
        subnets[i].ip = 0;
        subnets[i].mask = 0;
        subnets[i].subnet = 0;
        strcpy(subnets[i].name, "");
    }

    // Ask user for subnet information
    for (i = 0; i < num_subnets; i++) {
        printf("Enter subnet %d information:\n", i+1);
        printf("IP address: ");
        scanf("%d", &subnets[i].ip);
        printf("Subnet mask: ");
        scanf("%d", &subnets[i].mask);
        printf("Subnet name: ");
        scanf("%s", subnets[i].name);

        // Calculate subnet
        subnets[i].subnet = subnets[i].ip & subnets[i].mask;

        // Print subnet information
        printf("\nSubnet %d:\n", i+1);
        printf("IP address: %d\n", subnets[i].ip);
        printf("Subnet mask: %d\n", subnets[i].mask);
        printf("Subnet: %d\n", subnets[i].subnet);
        printf("Name: %s\n\n", subnets[i].name);
    }

    return 0;
}