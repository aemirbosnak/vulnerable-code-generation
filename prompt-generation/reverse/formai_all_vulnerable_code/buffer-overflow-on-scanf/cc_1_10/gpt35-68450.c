//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_STR_LEN 16

/* Function to check the validity of the IP address */
int is_valid_ip_address(char *ip_address_str) {
    int ip_digits[4];
    int valid_count = sscanf(ip_address_str, "%d.%d.%d.%d",
                              &ip_digits[0], &ip_digits[1], 
                              &ip_digits[2], &ip_digits[3]);
    if (valid_count != 4) {
        return 0; /* Invalid IP address */
    }

    for (int i = 0; i < 4; i++) {
        if (ip_digits[i] < 0 || ip_digits[i] > 255) {
            return 0; /* Invalid IP address */
        }
    }

    return 1; /* Valid IP address */
}

/* Function to calculate the subnet mask from CIDR notation */
void calculate_subnet_mask(int cidr_notation, char *subnet_mask_str) {
    int remaining_bits = 32 - cidr_notation;
    int subnet_octets[4] = {0, 0, 0, 0};

    for (int i = 0; i < 4; i++) {
        int current_byte_bits = remaining_bits > 8 ? 8 : remaining_bits;
        remaining_bits -= current_byte_bits;
        subnet_octets[i] = 0xff << (8 - current_byte_bits);
    }

    sprintf(subnet_mask_str, "%d.%d.%d.%d", subnet_octets[0], subnet_octets[1],
            subnet_octets[2], subnet_octets[3]);
}

/* Function to get the network address from IP address and subnet mask */
void get_network_address(char *ip_address_str, char *subnet_mask_str, char *network_address_str) {
    int ip_octets[4];
    int subnet_mask_octets[4];
    int network_address_octets[4];

    sscanf(ip_address_str, "%d.%d.%d.%d", &ip_octets[0], &ip_octets[1],
           &ip_octets[2], &ip_octets[3]);
    sscanf(subnet_mask_str, "%d.%d.%d.%d", &subnet_mask_octets[0],
           &subnet_mask_octets[1], &subnet_mask_octets[2], &subnet_mask_octets[3]);

    for (int i = 0; i < 4; i++) {
        network_address_octets[i] = ip_octets[i] & subnet_mask_octets[i];
    }

    sprintf(network_address_str, "%d.%d.%d.%d", network_address_octets[0],
            network_address_octets[1], network_address_octets[2], network_address_octets[3]);
}

int main() {
    char ip_address_str[MAX_IP_STR_LEN];
    char subnet_mask_str[MAX_IP_STR_LEN];
    char network_address_str[MAX_IP_STR_LEN];

    /* Get the IP address */
    printf("Enter the IP address: ");
    scanf("%s", ip_address_str);

    if (!is_valid_ip_address(ip_address_str)) {
        printf("Error: Invalid IP address\n");
        return 1;
    }

    /* Get the CIDR notation */
    int cidr_notation;
    printf("Enter the CIDR notation: ");
    scanf("%d", &cidr_notation);

    /* Calculate the subnet mask */
    calculate_subnet_mask(cidr_notation, subnet_mask_str);
    printf("Subnet mask: %s\n", subnet_mask_str);

    /* Get the network address */
    get_network_address(ip_address_str, subnet_mask_str, network_address_str);
    printf("Network address: %s\n", network_address_str);

    return 0;
}