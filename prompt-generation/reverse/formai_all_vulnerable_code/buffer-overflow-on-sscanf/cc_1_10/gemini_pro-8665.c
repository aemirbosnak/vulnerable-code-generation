//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: Donald Knuth
/*
 * A Subnet Calculator in the style of Donald Knuth
 *
 * This program is a unique implementation of a subnet calculator in the style of Donald Knuth.
 * It is a text-based program that allows the user to calculate the subnet mask, broadcast address, and usable host range for a given IP address and subnet prefix length.
 *
 * The program is written in a Knuth-inspired style, with a focus on clarity and conciseness.
 * It uses a combination of imperative and functional programming techniques to achieve its goals.
 *
 * The program is also highly modular, with each function performing a specific task.
 * This makes the program easy to understand and maintain.
 *
 * Overall, this program is a unique and elegant implementation of a subnet calculator.
 * It is a valuable tool for anyone who needs to work with IP addresses and subnets.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The maximum number of bits in an IP address.
#define IP_ADDRESS_BITS 32

// The maximum number of bits in a subnet mask.
#define SUBNET_MASK_BITS 32

// The maximum number of bits in a subnet prefix length.
#define SUBNET_PREFIX_LENGTH_BITS 8

// The number of octets in an IP address.
#define IP_ADDRESS_OCTETS 4

// The number of bits in an octet.
#define OCTET_BITS 8

// The maximum value of an octet.
#define OCTET_MAX 255

// The minimum value of a subnet prefix length.
#define SUBNET_PREFIX_LENGTH_MIN 0

// The maximum value of a subnet prefix length.
#define SUBNET_PREFIX_LENGTH_MAX 32

// The default subnet prefix length.
#define SUBNET_PREFIX_LENGTH_DEFAULT 24

// The broadcast address.
#define BROADCAST_ADDRESS "255.255.255.255"

// The usable host range.
#define USABLE_HOST_RANGE "0.0.0.0"

// The error message for an invalid IP address.
#define INVALID_IP_ADDRESS_ERROR "Invalid IP address."

// The error message for an invalid subnet prefix length.
#define INVALID_SUBNET_PREFIX_LENGTH_ERROR "Invalid subnet prefix length."

// The error message for an invalid subnet mask.
#define INVALID_SUBNET_MASK_ERROR "Invalid subnet mask."

// The error message for an invalid broadcast address.
#define INVALID_BROADCAST_ADDRESS_ERROR "Invalid broadcast address."

// The error message for an invalid usable host range.
#define INVALID_USABLE_HOST_RANGE_ERROR "Invalid usable host range."

// The function to get the IP address.
char *get_ip_address() {
    char *ip_address = malloc(IP_ADDRESS_OCTETS * sizeof(char));
    if (ip_address == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for IP address.\n");
        exit(EXIT_FAILURE);
    }
    printf("Enter the IP address: ");
    scanf("%s", ip_address);
    return ip_address;
}

// The function to get the subnet prefix length.
int get_subnet_prefix_length() {
    int subnet_prefix_length;
    printf("Enter the subnet prefix length: ");
    scanf("%d", &subnet_prefix_length);
    return subnet_prefix_length;
}

// The function to validate the IP address.
int validate_ip_address(char *ip_address) {
    int octets[IP_ADDRESS_OCTETS];
    if (sscanf(ip_address, "%d.%d.%d.%d", &octets[0], &octets[1], &octets[2], &octets[3]) != IP_ADDRESS_OCTETS) {
        fprintf(stderr, "%s\n", INVALID_IP_ADDRESS_ERROR);
        return 0;
    }
    for (int i = 0; i < IP_ADDRESS_OCTETS; i++) {
        if (octets[i] < 0 || octets[i] > OCTET_MAX) {
            fprintf(stderr, "%s\n", INVALID_IP_ADDRESS_ERROR);
            return 0;
        }
    }
    return 1;
}

// The function to validate the subnet prefix length.
int validate_subnet_prefix_length(int subnet_prefix_length) {
    if (subnet_prefix_length < SUBNET_PREFIX_LENGTH_MIN || subnet_prefix_length > SUBNET_PREFIX_LENGTH_MAX) {
        fprintf(stderr, "%s\n", INVALID_SUBNET_PREFIX_LENGTH_ERROR);
        return 0;
    }
    return 1;
}

// The function to calculate the subnet mask.
char *calculate_subnet_mask(char *ip_address, int subnet_prefix_length) {
    char *subnet_mask = malloc(SUBNET_MASK_BITS * sizeof(char));
    if (subnet_mask == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for subnet mask.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < subnet_prefix_length; i++) {
        subnet_mask[i] = '1';
    }
    for (int i = subnet_prefix_length; i < SUBNET_MASK_BITS; i++) {
        subnet_mask[i] = '0';
    }
    return subnet_mask;
}

// The function to calculate the broadcast address.
char *calculate_broadcast_address(char *ip_address, char *subnet_mask) {
    char *broadcast_address = malloc(IP_ADDRESS_BITS * sizeof(char));
    if (broadcast_address == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for broadcast address.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < IP_ADDRESS_BITS; i++) {
        broadcast_address[i] = ip_address[i] | ~subnet_mask[i];
    }
    return broadcast_address;
}

// The function to calculate the usable host range.
char *calculate_usable_host_range(char *subnet_mask) {
    char *usable_host_range = malloc(IP_ADDRESS_BITS * sizeof(char));
    if (usable_host_range == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for usable host range.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < IP_ADDRESS_BITS; i++) {
        usable_host_range[i] = subnet_mask[i] & ~0x1;
    }
    return usable_host_range;
}

// The function to print the subnet calculator results.
void print_subnet_calculator_results(char *ip_address, int subnet_prefix_length, char *subnet_mask, char *broadcast_address, char *usable_host_range) {
    printf("IP Address: %s\n", ip_address);
    printf("Subnet Prefix Length: %d\n", subnet_prefix_length);
    printf("Subnet Mask: %s\n", subnet_mask);
    printf("Broadcast Address: %s\n", broadcast_address);
    printf("Usable Host Range: %s\n", usable_host_range);
}

// The main function.
int main() {
    char *ip_address = get_ip_address();
    int subnet_prefix_length = get_subnet_prefix_length();
    if (!validate_ip_address(ip_address)) {
        return EXIT_FAILURE;
    }
    if (!validate_subnet_prefix_length(subnet_prefix_length)) {
        return EXIT_FAILURE;
    }
    char *subnet_mask = calculate_subnet_mask(ip_address, subnet_prefix_length);
    char *broadcast_address = calculate_broadcast_address(ip_address, subnet_mask);
    char *usable_host_range = calculate_usable_host_range(subnet_mask);
    print_subnet_calculator_results(ip_address, subnet_prefix_length, subnet_mask, broadcast_address, usable_host_range);
    return EXIT_SUCCESS;
}