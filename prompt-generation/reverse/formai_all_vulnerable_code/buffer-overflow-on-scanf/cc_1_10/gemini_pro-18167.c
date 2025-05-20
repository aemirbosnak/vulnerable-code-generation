//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

// Define the maximum number of subnets
#define MAX_SUBNETS 100

// Define the structure of a subnet
typedef struct subnet {
    char name[20];
    char ip_address[20];
    char subnet_mask[20];
    char broadcast_address[20];
    char network_address[20];
    char first_usable_address[20];
    char last_usable_address[20];
    char number_of_hosts[20];
} subnet;

// Declare an array of subnets
subnet subnets[MAX_SUBNETS];

// Define the function to print the subnet information
void print_subnet_info(subnet *subnet) {
    printf("Subnet Name: %s\n", subnet->name);
    printf("IP Address: %s\n", subnet->ip_address);
    printf("Subnet Mask: %s\n", subnet->subnet_mask);
    printf("Broadcast Address: %s\n", subnet->broadcast_address);
    printf("Network Address: %s\n", subnet->network_address);
    printf("First Usable Address: %s\n", subnet->first_usable_address);
    printf("Last Usable Address: %s\n", subnet->last_usable_address);
    printf("Number of Hosts: %s\n", subnet->number_of_hosts);
}

// Define the main function
int main() {
    // Declare the variables
    int num_subnets;
    int i;

    // Get the number of subnets from the user
    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    // Get the subnet information from the user
    for (i = 0; i < num_subnets; i++) {
        printf("Enter the subnet name: ");
        scanf("%s", subnets[i].name);

        printf("Enter the IP address: ");
        scanf("%s", subnets[i].ip_address);

        printf("Enter the subnet mask: ");
        scanf("%s", subnets[i].subnet_mask);
    }

    // Calculate the subnet information
    for (i = 0; i < num_subnets; i++) {
        // Calculate the broadcast address
        unsigned long int broadcast_address = inet_addr(subnets[i].ip_address) | ~inet_addr(subnets[i].subnet_mask);
        sprintf(subnets[i].broadcast_address, "%s", inet_ntoa((struct in_addr){broadcast_address}));

        // Calculate the network address
        unsigned long int network_address = inet_addr(subnets[i].ip_address) & inet_addr(subnets[i].subnet_mask);
        sprintf(subnets[i].network_address, "%s", inet_ntoa((struct in_addr){network_address}));

        // Calculate the first usable address
        unsigned long int first_usable_address = network_address + 1;
        sprintf(subnets[i].first_usable_address, "%s", inet_ntoa((struct in_addr){first_usable_address}));

        // Calculate the last usable address
        unsigned long int last_usable_address = broadcast_address - 1;
        sprintf(subnets[i].last_usable_address, "%s", inet_ntoa((struct in_addr){last_usable_address}));

        // Calculate the number of hosts
        unsigned long int number_of_hosts = (last_usable_address - first_usable_address + 1);
        sprintf(subnets[i].number_of_hosts, "%lu", number_of_hosts);
    }

    // Print the subnet information
    for (i = 0; i < num_subnets; i++) {
        print_subnet_info(&subnets[i]);
    }

    return 0;
}