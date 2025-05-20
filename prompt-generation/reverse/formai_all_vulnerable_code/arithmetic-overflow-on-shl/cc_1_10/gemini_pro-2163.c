//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned int address;
    unsigned int mask;
    unsigned int network;
    unsigned int broadcast;
    unsigned int first;
    unsigned int last;
    unsigned int hosts;
} Subnet;

void calculate(Subnet *subnet, unsigned int address, unsigned int mask) {
    subnet->address = address;
    subnet->mask = mask;
    
    // Calculate the network address
    subnet->network = subnet->address & subnet->mask;
    
    // Calculate the broadcast address
    unsigned int broadcast_mask = ~subnet->mask;
    subnet->broadcast = (subnet->network | broadcast_mask) | 0xFFFFFFFF;
    
    // Calculate the first and last host addresses
    subnet->first = subnet->network + 1;
    subnet->last = subnet->broadcast - 1;
    
    // Calculate the number of hosts
    subnet->hosts = (1 << (32 - bitcount(subnet->mask))) - 2;
}

int bitcount(unsigned int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

void print(Subnet *subnet) {
    printf("Sherlock Holmes Subnet Calculator\n");
    printf("---------------------------------\n");
    printf("IP Address: %u.%u.%u.%u\n",
        (subnet->address >> 24) & 0xFF,
        (subnet->address >> 16) & 0xFF,
        (subnet->address >> 8) & 0xFF,
        subnet->address & 0xFF);
    printf("Subnet Mask: %u.%u.%u.%u\n",
        (subnet->mask >> 24) & 0xFF,
        (subnet->mask >> 16) & 0xFF,
        (subnet->mask >> 8) & 0xFF,
        subnet->mask & 0xFF);
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
    printf("First Host Address: %u.%u.%u.%u\n",
        (subnet->first >> 24) & 0xFF,
        (subnet->first >> 16) & 0xFF,
        (subnet->first >> 8) & 0xFF,
        subnet->first & 0xFF);
    printf("Last Host Address: %u.%u.%u.%u\n",
        (subnet->last >> 24) & 0xFF,
        (subnet->last >> 16) & 0xFF,
        (subnet->last >> 8) & 0xFF,
        subnet->last & 0xFF);
    printf("Number of Hosts: %u\n", subnet->hosts);
}

int main() {
    Subnet subnet;
    
    // Get the IP address from the user
    unsigned int address;
    printf("Enter the IP address: ");
    scanf("%u", &address);
    
    // Get the subnet mask from the user
    unsigned int mask;
    printf("Enter the subnet mask: ");
    scanf("%u", &mask);
    
    // Calculate the subnet information
    calculate(&subnet, address, mask);
    
    // Print the subnet information
    print(&subnet);
    
    return 0;
}