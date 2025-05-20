//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define IP_ADDRESS_LENGTH 15

struct subnet {
    char name[MAX_SUBNETS];
    int size;
};

int main() {
    struct subnet subnets[MAX_SUBNETS];
    int num_subnets = 0;
    char ip_address[IP_ADDRESS_LENGTH];

    // Get the number of subnets from the user
    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    // Get the IP address from the user
    printf("Enter the IP address: ");
    scanf("%s", ip_address);

    // Calculate the size of the IP address
    int size = 0;
    while (ip_address[size]!= '.') {
        size++;
    }

    // Prompt the user for the subnet names and sizes
    for (int i = 0; i < num_subnets; i++) {
        printf("Enter the name for subnet %d: ", i + 1);
        scanf("%s", subnets[i].name);

        printf("Enter the size for subnet %d: ", i + 1);
        scanf("%d", &subnets[i].size);
    }

    // Calculate the subnet sizes
    int remaining_size = size;
    for (int i = 0; i < num_subnets; i++) {
        if (remaining_size < subnets[i].size) {
            printf("Error: Subnet %s requires a larger IP address\n", subnets[i].name);
            exit(1);
        }

        remaining_size -= subnets[i].size;
    }

    // Print the subnet information
    for (int i = 0; i < num_subnets; i++) {
        printf("Subnet %s: ", subnets[i].name);
        for (int j = 0; j < subnets[i].size; j++) {
            printf("%d.", ip_address[j]);
        }
        printf("\n");
    }

    return 0;
}