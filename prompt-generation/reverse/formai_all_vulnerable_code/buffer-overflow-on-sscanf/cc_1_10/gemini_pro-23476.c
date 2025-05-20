//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_IP_ADDRESS_LENGTH 16
#define MAX_SUBNET_MASK_LENGTH 16

struct ip_address {
    unsigned char octets[4];
};

struct subnet_mask {
    unsigned char octets[4];
};

struct subnet_calculator {
    struct ip_address ip_address;
    struct subnet_mask subnet_mask;
    unsigned int num_hosts;
    unsigned int num_subnets;
    unsigned int subnet_prefix_length;
};

int main() {
    struct subnet_calculator subnet_calculator;

    // Get the IP address from the user.
    printf("Enter the IP address: ");
    char ip_address_string[MAX_IP_ADDRESS_LENGTH];
    fgets(ip_address_string, MAX_IP_ADDRESS_LENGTH, stdin);
    sscanf(ip_address_string, "%hhu.%hhu.%hhu.%hhu", &subnet_calculator.ip_address.octets[0], &subnet_calculator.ip_address.octets[1], &subnet_calculator.ip_address.octets[2], &subnet_calculator.ip_address.octets[3]);

    // Get the subnet mask from the user.
    printf("Enter the subnet mask: ");
    char subnet_mask_string[MAX_SUBNET_MASK_LENGTH];
    fgets(subnet_mask_string, MAX_SUBNET_MASK_LENGTH, stdin);
    sscanf(subnet_mask_string, "%hhu.%hhu.%hhu.%hhu", &subnet_calculator.subnet_mask.octets[0], &subnet_calculator.subnet_mask.octets[1], &subnet_calculator.subnet_mask.octets[2], &subnet_calculator.subnet_mask.octets[3]);

    // Calculate the subnet prefix length.
    unsigned int subnet_prefix_length = 0;
    for (unsigned int i = 0; i < 4; i++) {
        for (unsigned int j = 0; j < 8; j++) {
            if ((subnet_calculator.subnet_mask.octets[i] & (1 << j)) != 0) {
                subnet_prefix_length++;
            }
        }
    }

    // Calculate the number of subnets.
    subnet_calculator.num_subnets = pow(2, 32 - subnet_prefix_length);

    // Calculate the number of hosts per subnet.
    subnet_calculator.num_hosts = pow(2, 32 - subnet_prefix_length) - 2;

    // Print the subnet calculator results.
    printf("IP address: %hhu.%hhu.%hhu.%hhu\n", subnet_calculator.ip_address.octets[0], subnet_calculator.ip_address.octets[1], subnet_calculator.ip_address.octets[2], subnet_calculator.ip_address.octets[3]);
    printf("Subnet mask: %hhu.%hhu.%hhu.%hhu\n", subnet_calculator.subnet_mask.octets[0], subnet_calculator.subnet_mask.octets[1], subnet_calculator.subnet_mask.octets[2], subnet_calculator.subnet_mask.octets[3]);
    printf("Subnet prefix length: %u\n", subnet_prefix_length);
    printf("Number of subnets: %u\n", subnet_calculator.num_subnets);
    printf("Number of hosts per subnet: %u\n", subnet_calculator.num_hosts);
}