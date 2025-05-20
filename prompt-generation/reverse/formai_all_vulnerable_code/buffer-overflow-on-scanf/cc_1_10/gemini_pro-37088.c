//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

// Define the maximum number of subnets
#define MAX_SUBNETS 10

// Define the maximum number of hosts per subnet
#define MAX_HOSTS 254

// Define the structure of a subnet
typedef struct {
    unsigned int subnet_address;
    unsigned int subnet_mask;
    unsigned int num_hosts;
} subnet_t;

// Define the function to calculate the subnets
void calculate_subnets(unsigned int ip_address, unsigned int subnet_mask, subnet_t *subnets, int *num_subnets) {
    // Check if the IP address is valid
    if (!inet_aton(ip_address, &ip_address)) {
        fprintf(stderr, "Invalid IP address: %s\n", ip_address);
        exit(EXIT_FAILURE);
    }

    // Check if the subnet mask is valid
    if (!inet_aton(subnet_mask, &subnet_mask)) {
        fprintf(stderr, "Invalid subnet mask: %s\n", subnet_mask);
        exit(EXIT_FAILURE);
    }

    // Calculate the number of subnets
    *num_subnets = 0;
    for (unsigned int i = 0; i < 32; i++) {
        if ((subnet_mask >> i) & 1) {
            (*num_subnets)++;
        }
    }

    // Check if the number of subnets is greater than the maximum
    if (*num_subnets > MAX_SUBNETS) {
        fprintf(stderr, "Too many subnets: %d\n", *num_subnets);
        exit(EXIT_FAILURE);
    }

    // Calculate the subnets
    for (int i = 0; i < *num_subnets; i++) {
        subnets[i].subnet_address = ip_address & subnet_mask;
        subnets[i].subnet_mask = subnet_mask;
        subnets[i].num_hosts = MAX_HOSTS;
        ip_address += (1 << (32 - *num_subnets));
    }
}

// Define the function to print the subnets
void print_subnets(subnet_t *subnets, int num_subnets) {
    printf("Subnets:\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("Subnet %d:\n", i + 1);
        printf("  Subnet address: %s\n", inet_ntoa(*(struct in_addr *)&subnets[i].subnet_address));
        printf("  Subnet mask: %s\n", inet_ntoa(*(struct in_addr *)&subnets[i].subnet_mask));
        printf("  Number of hosts: %d\n", subnets[i].num_hosts);
    }
}

// Define the function to get the input from the user
void get_input(unsigned int *ip_address, unsigned int *subnet_mask) {
    char ip_address_str[16];
    char subnet_mask_str[16];

    printf("Enter the IP address: ");
    scanf("%s", ip_address_str);

    printf("Enter the subnet mask: ");
    scanf("%s", subnet_mask_str);

    *ip_address = inet_addr(ip_address_str);
    *subnet_mask = inet_addr(subnet_mask_str);
}

// Define the main function
int main() {
    // Define the variables
    unsigned int ip_address;
    unsigned int subnet_mask;
    subnet_t subnets[MAX_SUBNETS];
    int num_subnets;

    // Get the input from the user
    get_input(&ip_address, &subnet_mask);

    // Calculate the subnets
    calculate_subnets(ip_address, subnet_mask, subnets, &num_subnets);

    // Print the subnets
    print_subnets(subnets, num_subnets);

    return 0;
}