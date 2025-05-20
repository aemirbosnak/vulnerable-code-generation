//Falcon2-11B DATASET v1.0 Category: Subnet Calculator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_SUBNET_LENGTH 30
#define DEFAULT_PREFIX 24

typedef struct {
    int network_id;
    int network_mask;
} subnet_t;

int main(int argc, char **argv) {
    // Check command line arguments
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <network_id>\n", argv[0]);
        exit(1);
    }

    char *network_id = argv[1];

    // Convert network_id to an integer
    char *endptr;
    int network_id_int = strtol(network_id, &endptr, 10);
    if (*endptr!= '\0') {
        fprintf(stderr, "Invalid network_id: %s\n", network_id);
        exit(1);
    }

    // Create a subnet object
    subnet_t subnet;
    subnet.network_id = network_id_int;
    subnet.network_mask = DEFAULT_PREFIX;

    // Calculate the subnet mask
    int subnet_mask_int = subnet.network_mask;
    while (subnet_mask_int > 0) {
        subnet_mask_int -= 1;
        subnet.network_mask -= 1;
    }

    // Print the subnet mask
    printf("Subnet mask: %d.%d.%d.%d\n",
           subnet.network_mask / 256,
           subnet.network_mask / 64 % 256,
           subnet.network_mask / 32 % 256,
           subnet.network_mask % 256);

    return 0;
}