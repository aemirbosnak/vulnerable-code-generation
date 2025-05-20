//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct _Subnet {
    unsigned int ip;
    unsigned int mask;
    unsigned int cidr;
    unsigned int network;
    unsigned int broadcast;
    unsigned int usable;
    unsigned int host_range;
    unsigned int hosts_per_subnet;
    char *address;
} Subnet;

void calculate_subnet(Subnet *subnet) {
    // Calculate the network address
    subnet->network = subnet->ip & subnet->mask;

    // Calculate the broadcast address
    subnet->broadcast = subnet->network | ~subnet->mask;

    // Calculate the usable host range
    subnet->usable = subnet->broadcast - subnet->network - 1;

    // Calculate the number of hosts per subnet
    subnet->hosts_per_subnet = pow(2, 32 - subnet->cidr) - 2;

    // Calculate the host range
    subnet->host_range = subnet->usable + 1;

    // Convert the IP address to a string
    subnet->address = malloc(16);
    sprintf(subnet->address, "%u.%u.%u.%u",
            (subnet->ip >> 24) & 0xFF,
            (subnet->ip >> 16) & 0xFF,
            (subnet->ip >> 8) & 0xFF,
            subnet->ip & 0xFF);
}

void print_subnet(Subnet *subnet) {
    printf("Subnet Calculator\n");
    printf("-----------------\n");
    printf("IP Address: %s\n", subnet->address);
    printf("Subnet Mask: %u.%u.%u.%u\n",
            (subnet->mask >> 24) & 0xFF,
            (subnet->mask >> 16) & 0xFF,
            (subnet->mask >> 8) & 0xFF,
            subnet->mask & 0xFF);
    printf("CIDR: %u\n", subnet->cidr);
    printf("Network Address: %u.%u.%u.%u\n",
            (subnet->network >> 24) & 0xFF,
            (subnet->network >> 16) & 0xFF,
            (subnet->network >> 8) & 0xFF,
            subnet->network & 0xFF);
    printf("Broadcast Address: %u.%u.%u.%u\n",
            (subnet->broadcast >> 24) & 0xFF,
            (subnet->broadcast >> 16) & 0xFF,
            (subnet->broadcast >> 8) & 0xFF,
            subnet->broadcast & 0xFF);
    printf("Usable Host Range: %u.%u.%u.%u - %u.%u.%u.%u\n",
            (subnet->network >> 24) & 0xFF,
            (subnet->network >> 16) & 0xFF,
            (subnet->network >> 8) & 0xFF,
            subnet->network & 0xFF,
            (subnet->broadcast >> 24) & 0xFF,
            (subnet->broadcast >> 16) & 0xFF,
            (subnet->broadcast >> 8) & 0xFF,
            subnet->broadcast & 0xFF);
    printf("Host Range: %u\n", subnet->host_range);
    printf("Hosts per Subnet: %u\n", subnet->hosts_per_subnet);
}

int main() {
    // Create a new subnet
    Subnet subnet;

    // Get the IP address from the user
    printf("Enter the IP address: ");
    scanf("%u", &subnet.ip);

    // Get the subnet mask from the user
    printf("Enter the subnet mask: ");
    scanf("%u", &subnet.mask);

    // Calculate the CIDR notation
    subnet.cidr = 0;
    for (int i = 0; i < 32; i++) {
        if ((subnet.mask >> i) & 1) {
            subnet.cidr++;
        }
    }

    // Calculate the subnet information
    calculate_subnet(&subnet);

    // Print the subnet information
    print_subnet(&subnet);

    // Free the allocated memory
    free(subnet.address);

    return 0;
}