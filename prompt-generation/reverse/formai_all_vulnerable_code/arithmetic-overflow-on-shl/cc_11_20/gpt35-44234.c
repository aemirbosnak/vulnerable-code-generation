//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Error: Please enter a valid IP address and subnet mask!\n");
        return 0;
    }

    char *ip_addr = argv[1];
    char *subnet_mask = argv[2];

    struct in_addr addr;
    if (inet_pton(AF_INET, ip_addr, &addr) == 0) {
        printf("Error: Invalid IP address entered!\n");
        return 0;
    }

    int subnet_bits = 0;
    char *subnet_bit_ptr = subnet_mask;
    int octet_value = atoi(subnet_bit_ptr);
    
    if (octet_value < 0 || octet_value > 255) {
        printf("Error: Invalid subnet mask entered!\n");
        return 0;
    }

    // Convert subnet mask from dotted decimal to bits
    while (*subnet_bit_ptr != '\0') {
        if (*subnet_bit_ptr == '.') {
            if (octet_value < 0 || octet_value > 255) {
                printf("Error: Invalid subnet mask entered!\n");
                return 0;
            }
            subnet_bits += __builtin_popcount(octet_value);
            octet_value = 0;
        }
        else {
            if (*subnet_bit_ptr < '0' || *subnet_bit_ptr > '9') {
                printf("Error: Invalid subnet mask entered!\n");
                return 0;
            }
            octet_value = (octet_value * 10) + (*subnet_bit_ptr - '0');
        }
        subnet_bit_ptr++;
    }

    if (octet_value < 0 || octet_value > 255) {
        printf("Error: Invalid subnet mask entered!\n");
        return 0;
    }

    subnet_bits += __builtin_popcount(octet_value);

    long int num_hosts = (1 << (32 - subnet_bits)) - 2;
    unsigned int subnet_mask_int = ~(((1 << (32 - subnet_bits)) - 1));
    unsigned int network_address_int = ntohl(addr.s_addr) & subnet_mask_int;
    struct in_addr network_address;
    network_address.s_addr = htonl(network_address_int);

    printf("IP Address: %s\n", ip_addr);
    printf("Subnet Mask: %s\n", subnet_mask);
    printf("Network Address: %s\n", inet_ntoa(network_address));
    printf("Number of Hosts: %ld\n", num_hosts);

    return 0;
}