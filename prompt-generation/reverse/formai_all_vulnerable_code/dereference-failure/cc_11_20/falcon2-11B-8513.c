//Falcon2-11B DATASET v1.0 Category: Subnet Calculator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc!= 3) {
        printf("Usage: subnet <network> <prefix>\n");
        return 1;
    }

    char *network = argv[1];
    char *prefix = argv[2];

    if (strlen(network)!= 15) {
        printf("Invalid network address.\n");
        return 1;
    }

    if (strlen(prefix) > 3) {
        printf("Invalid prefix length.\n");
        return 1;
    }

    char *mask = malloc(3 * sizeof(char));
    if (mask == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < 3; i++) {
        mask[i] = '1';
    }

    int netmask = 0;
    for (int i = 0; i < strlen(prefix); i++) {
        if (prefix[i] == '1') {
            netmask += pow(2, i);
        }
    }

    char *subnet = malloc(strlen(network) + 3 * sizeof(char));
    if (subnet == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < strlen(network); i++) {
        subnet[i] = network[i];
        if (i == 3) {
            subnet[i] = '1';
        } else if (i == 7) {
            subnet[i] = '1';
            subnet[i + 1] = '0';
        } else if (i == 11) {
            subnet[i] = '1';
            subnet[i + 1] = '0';
            subnet[i + 2] = '0';
        }
    }

    char *address = malloc(strlen(subnet) + 1 * sizeof(char));
    if (address == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < strlen(subnet); i++) {
        address[i] = subnet[i];
        if (i == 12) {
            address[i] = '1';
        } else if (i == 16) {
            address[i] = '1';
            address[i + 1] = '0';
        } else if (i == 20) {
            address[i] = '1';
            address[i + 1] = '0';
            address[i + 2] = '0';
        }
    }

    printf("Network: %s\n", network);
    printf("Prefix: %s\n", prefix);
    printf("Netmask: %s\n", mask);
    printf("Subnet: %s\n", subnet);
    printf("Address: %s\n", address);
    printf("Number of hosts: %d\n", (pow(2, 32) - 2 - (netmask << 24)) / (pow(2, 8) - 1));
    return 0;
}