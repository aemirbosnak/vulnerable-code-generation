//Falcon2-11B DATASET v1.0 Category: Subnet Calculator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int subnet_mask_bits;
    int subnet_mask;
    int first_usable_ip_address;
    int last_ip_address;
    int network_address;
    int broadcast_address;
    int subnet_size;
    int i;

    // Get the subnet mask bits
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s subnet_mask_bits\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    subnet_mask_bits = atoi(argv[1]);

    // Calculate the subnet mask
    subnet_mask = (1 << subnet_mask_bits) - 1;

    // Calculate the first usable IP address
    first_usable_ip_address = subnet_mask + 1;

    // Calculate the last IP address
    last_ip_address = ((1 << 32) - 1) - first_usable_ip_address;

    // Calculate the network address
    network_address = ((1 << 32) - 1) - ((1 << (32 - subnet_mask_bits)) - 1);

    // Calculate the broadcast address
    broadcast_address = ((1 << 32) - 1) - ((1 << (32 - subnet_mask_bits)) - 1);

    // Calculate the subnet size
    subnet_size = last_ip_address - first_usable_ip_address + 1;

    // Print the results
    printf("Subnet mask bits: %d\n", subnet_mask_bits);
    printf("Subnet mask: %d\n", subnet_mask);
    printf("First usable IP address: %d\n", first_usable_ip_address);
    printf("Last IP address: %d\n", last_ip_address);
    printf("Network address: %d\n", network_address);
    printf("Broadcast address: %d\n", broadcast_address);
    printf("Subnet size: %d\n", subnet_size);

    return 0;
}