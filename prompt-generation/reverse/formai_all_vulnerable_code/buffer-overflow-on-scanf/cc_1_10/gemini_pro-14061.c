//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_LENGTH 16
#define MAX_SUBNET_MASK_LENGTH 16

struct ip_address {
    unsigned char octets[4];
};

struct subnet_mask {
    unsigned char octets[4];
};

int main() {
    char ip_address_string[MAX_IP_LENGTH];
    char subnet_mask_string[MAX_SUBNET_MASK_LENGTH];
    struct ip_address ip_address;
    struct subnet_mask subnet_mask;
    unsigned int subnet_prefix_length;
    unsigned int number_of_hosts;
    unsigned int first_usable_ip_address;
    unsigned int last_usable_ip_address;
    unsigned int broadcast_ip_address;
    unsigned int network_ip_address;

    printf("Enter an IP address: ");
    scanf("%s", ip_address_string);

    printf("Enter a subnet mask: ");
    scanf("%s", subnet_mask_string);

    // Parse the IP address.
    if (sscanf(ip_address_string, "%hhu.%hhu.%hhu.%hhu", &ip_address.octets[0], &ip_address.octets[1], &ip_address.octets[2], &ip_address.octets[3]) != 4) {
        printf("Invalid IP address.\n");
        return EXIT_FAILURE;
    }

    // Parse the subnet mask.
    if (sscanf(subnet_mask_string, "%hhu.%hhu.%hhu.%hhu", &subnet_mask.octets[0], &subnet_mask.octets[1], &subnet_mask.octets[2], &subnet_mask.octets[3]) != 4) {
        printf("Invalid subnet mask.\n");
        return EXIT_FAILURE;
    }

    // Calculate the subnet prefix length.
    subnet_prefix_length = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            if ((subnet_mask.octets[i] >> j) & 1) {
                subnet_prefix_length++;
            } else {
                break;
            }
        }
    }

    // Calculate the number of hosts.
    number_of_hosts = (1 << (32 - subnet_prefix_length)) - 2;

    // Calculate the first usable IP address.
    first_usable_ip_address = ip_address.octets[0] | (ip_address.octets[1] & subnet_mask.octets[1]) | (ip_address.octets[2] & subnet_mask.octets[2]) | (ip_address.octets[3] & subnet_mask.octets[3]);

    // Calculate the last usable IP address.
    last_usable_ip_address = ip_address.octets[0] | (ip_address.octets[1] & subnet_mask.octets[1]) | (ip_address.octets[2] & subnet_mask.octets[2]) | ((ip_address.octets[3] & subnet_mask.octets[3]) | (1 << (32 - subnet_prefix_length)) - 1);

    // Calculate the broadcast IP address.
    broadcast_ip_address = ip_address.octets[0] | (ip_address.octets[1] & subnet_mask.octets[1]) | (ip_address.octets[2] & subnet_mask.octets[2]) | ((ip_address.octets[3] & subnet_mask.octets[3]) | (1 << (32 - subnet_prefix_length)) - 1);

    // Calculate the network IP address.
    network_ip_address = ip_address.octets[0] & subnet_mask.octets[0] & subnet_mask.octets[1] & subnet_mask.octets[2] & subnet_mask.octets[3];

    // Print the results.
    printf("Subnet prefix length: %u\n", subnet_prefix_length);
    printf("Number of hosts: %u\n", number_of_hosts);
    printf("First usable IP address: %u.%u.%u.%u\n", first_usable_ip_address >> 24 & 0xFF, first_usable_ip_address >> 16 & 0xFF, first_usable_ip_address >> 8 & 0xFF, first_usable_ip_address & 0xFF);
    printf("Last usable IP address: %u.%u.%u.%u\n", last_usable_ip_address >> 24 & 0xFF, last_usable_ip_address >> 16 & 0xFF, last_usable_ip_address >> 8 & 0xFF, last_usable_ip_address & 0xFF);
    printf("Broadcast IP address: %u.%u.%u.%u\n", broadcast_ip_address >> 24 & 0xFF, broadcast_ip_address >> 16 & 0xFF, broadcast_ip_address >> 8 & 0xFF, broadcast_ip_address & 0xFF);
    printf("Network IP address: %u.%u.%u.%u\n", network_ip_address >> 24 & 0xFF, network_ip_address >> 16 & 0xFF, network_ip_address >> 8 & 0xFF, network_ip_address & 0xFF);

    return EXIT_SUCCESS;
}