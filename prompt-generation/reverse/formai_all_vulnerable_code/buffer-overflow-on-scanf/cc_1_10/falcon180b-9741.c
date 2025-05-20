//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASKS 32

struct subnet {
    char name[MAX_SUBNET_SIZE];
    char mask[MAX_SUBNET_MASKS];
    int num_hosts;
};

int main() {
    int num_subnets, i;
    struct subnet subnets[MAX_SUBNETS];
    char input[MAX_SUBNET_SIZE];
    char *token;

    // Get number of subnets from user
    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    // Loop through each subnet
    for (i = 0; i < num_subnets; i++) {
        printf("Enter the name of subnet %d: ", i+1);
        scanf("%s", subnets[i].name);

        // Get subnet mask and number of hosts from user
        printf("Enter the subnet mask for %s: ", subnets[i].name);
        scanf("%s", input);
        strcpy(subnets[i].mask, input);

        printf("Enter the number of hosts for %s: ", subnets[i].name);
        scanf("%d", &subnets[i].num_hosts);

        // Calculate the number of subnet bits
        int num_subnet_bits = 0;
        token = strtok(subnets[i].mask, ".");
        while (token!= NULL) {
            if (atoi(token) == 255) {
                num_subnet_bits += 8;
            } else {
                num_subnet_bits += atoi(token);
            }
            token = strtok(NULL, ".");
        }

        // Calculate the number of host bits
        int num_host_bits = 32 - num_subnet_bits;

        // Calculate the number of hosts in the subnet
        int num_hosts_in_subnet = pow(2, num_host_bits) - 2;

        // Check if the number of hosts is valid
        if (subnets[i].num_hosts > num_hosts_in_subnet) {
            printf("Error: Number of hosts exceeds the maximum for subnet %s.\n", subnets[i].name);
            exit(1);
        }
    }

    return 0;
}