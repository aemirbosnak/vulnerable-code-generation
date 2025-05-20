//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK 32
#define MAX_HOSTS_PER_SUBNET 254

typedef struct {
    char subnet[MAX_SUBNET_SIZE];
    int mask;
    int hosts_per_subnet;
} Subnet;

int main() {
    int num_subnets;
    int i;
    Subnet subnets[MAX_SUBNETS];

    // Get number of subnets from user
    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    // Initialize subnets
    for (i = 0; i < num_subnets; i++) {
        subnets[i].subnet[0] = '\0';
        subnets[i].mask = 0;
        subnets[i].hosts_per_subnet = 0;
    }

    // Get subnet information from user
    printf("Enter subnet information:\n");
    for (i = 0; i < num_subnets; i++) {
        printf("Subnet %d:\n", i+1);
        printf("Subnet: ");
        scanf("%s", subnets[i].subnet);
        printf("Mask: ");
        scanf("%d", &subnets[i].mask);
        printf("Hosts per subnet: ");
        scanf("%d", &subnets[i].hosts_per_subnet);
    }

    // Calculate subnet information
    for (i = 0; i < num_subnets; i++) {
        int j;
        for (j = 0; j < strlen(subnets[i].subnet); j++) {
            if (subnets[i].subnet[j] == '.') {
                subnets[i].subnet[j] = '\0';
            }
        }
        int subnet_size = strlen(subnets[i].subnet);
        int host_bits = MAX_SUBNET_SIZE - subnet_size - subnets[i].mask;
        int num_hosts = (int)pow(2, host_bits);
        if (num_hosts > MAX_HOSTS_PER_SUBNET) {
            printf("Error: Subnet %d has more than %d hosts.\n", i+1, MAX_HOSTS_PER_SUBNET);
            exit(1);
        }
        subnets[i].hosts_per_subnet = num_hosts;
    }

    // Print subnet information
    printf("\nSubnet information:\n");
    for (i = 0; i < num_subnets; i++) {
        printf("Subnet %d:\n", i+1);
        printf("Subnet: %s\n", subnets[i].subnet);
        printf("Mask: %d\n", subnets[i].mask);
        printf("Hosts per subnet: %d\n", subnets[i].hosts_per_subnet);
    }

    return 0;
}