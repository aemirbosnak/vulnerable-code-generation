//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 20
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK 32

struct subnet {
    char name[MAX_SUBNET_SIZE];
    char mask[MAX_SUBNET_MASK];
    int num_hosts;
};

int main() {
    int num_subnets;
    int i, j, k;
    struct subnet subnets[MAX_SUBNETS];

    // Get number of subnets from user
    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    // Initialize subnets with default values
    for (i = 0; i < num_subnets; i++) {
        strcpy(subnets[i].name, "Subnet");
        strcpy(subnets[i].mask, "255.255.255.0");
        subnets[i].num_hosts = 254;
    }

    // Get subnet details from user
    for (i = 0; i < num_subnets; i++) {
        printf("Enter the name of subnet %d: ", i + 1);
        scanf("%s", subnets[i].name);

        printf("Enter the mask of subnet %d: ", i + 1);
        scanf("%s", subnets[i].mask);

        printf("Enter the number of hosts in subnet %d: ", i + 1);
        scanf("%d", &subnets[i].num_hosts);
    }

    // Calculate and display subnet details
    printf("\nSubnet Details:\n");
    for (i = 0; i < num_subnets; i++) {
        printf("Subnet %d:\n", i + 1);
        printf("Name: %s\n", subnets[i].name);
        printf("Mask: %s\n", subnets[i].mask);
        printf("Number of hosts: %d\n", subnets[i].num_hosts);

        printf("IP addresses in this subnet:\n");
        for (j = 1; j <= subnets[i].num_hosts; j++) {
            for (k = 0; k < strlen(subnets[i].mask); k++) {
                if (subnets[i].mask[k] == '1') {
                    printf("%d.%d.%d.%d\n", i + 1, j, (int) rand() % 256, (int) rand() % 256);
                }
            }
        }
        printf("\n");
    }

    return 0;
}