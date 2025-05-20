//Code Llama-13B DATASET v1.0 Category: Subnet Calculator ; Style: surrealist
/*
 * C Subnet Calculator
 * A surrealist take on a classic networking program
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 100
#define MAX_OUTPUT 100

// Function to calculate the subnet mask for a given IP address
unsigned int calculate_subnet_mask(unsigned int ip_addr) {
    unsigned int subnet_mask = 0;
    unsigned int ones_count = 0;

    // Convert the IP address to binary
    char binary_ip_addr[MAX_INPUT];
    sprintf(binary_ip_addr, "%u", ip_addr);

    // Count the number of consecutive ones in the binary representation
    for (int i = 0; i < strlen(binary_ip_addr); i++) {
        if (binary_ip_addr[i] == '1') {
            ones_count++;
        } else {
            break;
        }
    }

    // Calculate the subnet mask based on the number of consecutive ones
    subnet_mask = (ones_count << 1) + 1;

    return subnet_mask;
}

// Function to calculate the number of hosts for a given subnet mask
unsigned int calculate_hosts(unsigned int subnet_mask) {
    unsigned int hosts = 0;

    // Calculate the number of hosts based on the subnet mask
    hosts = (unsigned int) pow(2, (32 - subnet_mask));

    return hosts;
}

int main() {
    // Declare variables
    unsigned int ip_addr = 0;
    unsigned int subnet_mask = 0;
    unsigned int hosts = 0;
    char output[MAX_OUTPUT];

    // Get the IP address from the user
    printf("Enter an IP address: ");
    scanf("%u", &ip_addr);

    // Calculate the subnet mask
    subnet_mask = calculate_subnet_mask(ip_addr);

    // Calculate the number of hosts
    hosts = calculate_hosts(subnet_mask);

    // Print the results
    sprintf(output, "Subnet Mask: %u\nNumber of Hosts: %u\n", subnet_mask, hosts);
    printf("%s\n", output);

    return 0;
}