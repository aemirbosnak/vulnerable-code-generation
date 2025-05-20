//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the maximum number of subnets
#define MAX_SUBNETS 100

// Define the maximum number of hosts per subnet
#define MAX_HOSTS 255

// Declare the main function
int main(void) {
    // Declare the variables
    char ip_address[16];
    char subnet_mask[16];
    int num_subnets;
    int num_hosts;
    int subnet_id;
    int host_id;
    int i;
    int j;

    // Prompt the user for the IP address
    printf("Enter the IP address: ");
    scanf("%s", ip_address);

    // Prompt the user for the subnet mask
    printf("Enter the subnet mask: ");
    scanf("%s", subnet_mask);

    // Prompt the user for the number of subnets
    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    // Prompt the user for the number of hosts per subnet
    printf("Enter the number of hosts per subnet: ");
    scanf("%d", &num_hosts);

    // Calculate the subnet ID for each subnet
    for (i = 0; i < num_subnets; i++) {
        subnet_id = i * num_hosts;

        // Calculate the host ID for each host in the subnet
        for (j = 0; j < num_hosts; j++) {
            host_id = subnet_id + j;

            // Print the subnet ID and host ID for each host in the subnet
            printf("Subnet ID: %d, Host ID: %d\n", subnet_id, host_id);
        }
    }

    return 0;
}