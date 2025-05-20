//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 255

struct subnet {
    char name[20];
    int mask;
    int num_hosts;
};

int main() {
    int num_subnets;
    int i;
    struct subnet subnets[MAX_SUBNETS];

    // Get the number of subnets from the user
    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    // Loop through each subnet and get its name, mask, and number of hosts
    for (i = 0; i < num_subnets; i++) {
        printf("Enter subnet %d name: ", i+1);
        scanf("%s", subnets[i].name);

        printf("Enter subnet %d mask: ", i+1);
        scanf("%d", &subnets[i].mask);

        printf("Enter subnet %d number of hosts: ", i+1);
        scanf("%d", &subnets[i].num_hosts);
    }

    // Calculate the number of hosts in each subnet
    for (i = 0; i < num_subnets; i++) {
        int num_bits = subnets[i].mask;
        int num_ones = 0;

        // Count the number of 1's in the subnet mask
        while (num_bits > 0) {
            if (num_bits & 1) {
                num_ones++;
            }
            num_bits >>= 1;
        }

        // Calculate the number of hosts
        int num_hosts_in_subnet = pow(2, num_ones) - 2;
        subnets[i].num_hosts = num_hosts_in_subnet;
    }

    // Print the subnet details
    printf("\nSubnet details:\n");
    for (i = 0; i < num_subnets; i++) {
        printf("Subnet %d: %s\n", i+1, subnets[i].name);
        printf("Mask: %d\n", subnets[i].mask);
        printf("Number of hosts: %d\n\n", subnets[i].num_hosts);
    }

    return 0;
}