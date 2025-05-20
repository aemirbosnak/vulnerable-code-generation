//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK_SIZE 4

typedef struct {
    char name[MAX_SUBNET_SIZE];
    char subnet_mask[MAX_SUBNET_MASK_SIZE];
    int num_subnets;
    int subnet_size;
} Subnet;

void print_subnet_info(Subnet *subnet) {
    printf("Subnet name: %s\n", subnet->name);
    printf("Subnet mask: %s\n", subnet->subnet_mask);
    printf("Number of subnets: %d\n", subnet->num_subnets);
    printf("Subnet size: %d\n", subnet->subnet_size);
}

int main() {
    int num_subnets;
    char input[MAX_SUBNET_SIZE];
    Subnet subnets[MAX_SUBNETS];
    int i;

    // Prompt user for number of subnets
    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    // Loop through each subnet
    for (i = 0; i < num_subnets; i++) {
        // Prompt user for subnet name
        printf("Enter the name of subnet %d: ", i + 1);
        scanf("%s", input);
        strncpy(subnets[i].name, input, MAX_SUBNET_SIZE);

        // Prompt user for subnet mask
        printf("Enter the subnet mask for %s: ", input);
        scanf("%s", subnets[i].subnet_mask);

        // Determine number of subnets and subnet size
        int num_bits = strlen(subnets[i].subnet_mask);
        int subnet_size = (int)pow(2, num_bits);
        int num_subnet_bits = num_bits - 1;
        int num_subnets_total = (int)pow(2, num_subnet_bits);

        // Check if number of subnets is valid
        if (num_subnets_total < num_subnets) {
            printf("Error: Number of subnets must be smaller than or equal to %d\n", num_subnets_total);
            return 1;
        }

        // Calculate subnet size
        subnets[i].subnet_size = subnet_size / num_subnets;

        // Set number of subnets
        subnets[i].num_subnets = num_subnets;
    }

    // Print subnet information
    printf("\nSubnet information:\n");
    for (i = 0; i < num_subnets; i++) {
        print_subnet_info(&subnets[i]);
    }

    return 0;
}