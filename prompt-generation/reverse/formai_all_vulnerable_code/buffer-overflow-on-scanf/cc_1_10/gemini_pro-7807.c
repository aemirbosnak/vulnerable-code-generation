//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the subnet information
typedef struct Subnet {
    unsigned int address;    // Subnet address
    unsigned int mask;      // Subnet mask
    unsigned int broadcast; // Broadcast address
    unsigned int range;     // Range of IP addresses in the subnet
} Subnet;

// Function to calculate the subnet information recursively
Subnet calculate_subnet(unsigned int address, unsigned int mask, int level) {
    Subnet subnet;

    // Base case: Reached the maximum recursion level
    if (level == 32) {
        subnet.address = address;
        subnet.mask = mask;
        subnet.broadcast = subnet.address | ~subnet.mask;
        subnet.range = subnet.broadcast - subnet.address + 1;
        return subnet;
    }

    // Recursive case: Split the subnet into two halves
    subnet = calculate_subnet(address, mask << 1, level + 1);

    // Calculate the second half of the subnet
    Subnet subnet2;
    subnet2.address = subnet.address + subnet.range / 2;
    subnet2.mask = subnet.mask;
    subnet2.broadcast = subnet2.address | ~subnet2.mask;
    subnet2.range = subnet2.broadcast - subnet2.address + 1;

    // Return the first half of the subnet
    return subnet;
}

// Function to print the subnet information
void print_subnet(Subnet subnet) {
    printf("Subnet address:\t%u.%u.%u.%u\n",
        (subnet.address >> 24) & 0xFF,
        (subnet.address >> 16) & 0xFF,
        (subnet.address >> 8) & 0xFF,
        subnet.address & 0xFF);

    printf("Subnet mask:\t\t%u.%u.%u.%u\n",
        (subnet.mask >> 24) & 0xFF,
        (subnet.mask >> 16) & 0xFF,
        (subnet.mask >> 8) & 0xFF,
        subnet.mask & 0xFF);

    printf("Broadcast address:\t%u.%u.%u.%u\n",
        (subnet.broadcast >> 24) & 0xFF,
        (subnet.broadcast >> 16) & 0xFF,
        (subnet.broadcast >> 8) & 0xFF,
        subnet.broadcast & 0xFF);

    printf("Range of IP addresses:\t%u\n", subnet.range);
}

int main() {
    // Get the IP address and subnet mask from the user
    unsigned int address, mask;
    printf("Enter the IP address (in dotted decimal notation): ");
    scanf("%u.%u.%u.%u", &address, &address, &address, &address);

    printf("Enter the subnet mask (in dotted decimal notation): ");
    scanf("%u.%u.%u.%u", &mask, &mask, &mask, &mask);

    // Calculate the subnet information
    Subnet subnet = calculate_subnet(address, mask, 0);

    // Print the subnet information
    print_subnet(subnet);

    return 0;
}