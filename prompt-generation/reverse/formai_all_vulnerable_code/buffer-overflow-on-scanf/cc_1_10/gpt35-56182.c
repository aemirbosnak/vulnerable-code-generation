//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_IP_ADDR_LENGTH 15
#define MAX_SUBNET_MASK_LENGTH 3

/* This function converts an IP address from string representation to integer representation */
uint32_t str_to_ip(char *str) {
    uint32_t octet;
    uint32_t ip = 0;
    char *token, *ptr;

    /* Tokenize the input string */
    token = strtok_r(str, ".", &ptr);

    while (token != NULL) {
        /* Convert the octet from string to integer */
        sscanf(token, "%u", &octet);
        /* Shift the octet to the appropriate position and add it to the IP address */
        ip |= (octet << ((3 - strlen(token)) * 8));
        token = strtok_r(NULL, ".", &ptr);
    }

    return ip;
}

/* This function converts a subnet mask from string representation to integer representation */
uint32_t str_to_subnet_mask(char *str) {
    uint32_t subnet_mask = 0;
    int subnet_mask_length = atoi(str);

    /* Set the appropriate number of bits in the subnet mask */
    for (int i = 0; i < subnet_mask_length; i++) {
        subnet_mask |= (1 << (31 - i));
    }

    return subnet_mask;
}

/* This function prints an IP address in human-readable form */
void ip_to_str(uint32_t ip, char *str) {
    sprintf(str, "%u.%u.%u.%u", (ip >> 24), (ip >> 16) & 0xff, (ip >> 8) & 0xff, ip & 0xff);
}

int main() {
    char ip_addr_str[MAX_IP_ADDR_LENGTH + 1];
    char subnet_mask_str[MAX_SUBNET_MASK_LENGTH + 1];
    uint32_t ip_addr, subnet_mask;
    bool input_valid = false;

    /* Loop until the user inputs a valid IP address and subnet mask */
    while (!input_valid) {
        /* Get the IP address from the user */
        printf("Enter the IP address: ");
        fflush(stdout);
        scanf("%s", ip_addr_str);
        ip_addr = str_to_ip(ip_addr_str);

        /* Get the subnet mask from the user */
        printf("Enter the subnet mask: ");
        fflush(stdout);
        scanf("%s", subnet_mask_str);
        subnet_mask = str_to_subnet_mask(subnet_mask_str);

        /* Validate the input */
        if ((ip_addr != 0) && (subnet_mask != 0) && ((ip_addr & (~subnet_mask)) == 0)) {
            input_valid = true;
        }
        else {
            printf("Invalid input. Please try again.\n");
        }
    }

    /* Calculate the network address */
    uint32_t network_addr = ip_addr & subnet_mask;
    char network_addr_str[MAX_IP_ADDR_LENGTH + 1];
    ip_to_str(network_addr, network_addr_str);

    /* Calculate the broadcast address */
    uint32_t broadcast_addr = ip_addr | (~subnet_mask);
    char broadcast_addr_str[MAX_IP_ADDR_LENGTH + 1];
    ip_to_str(broadcast_addr, broadcast_addr_str);

    /* Calculate the number of hosts in the subnet */
    uint32_t num_hosts = (1 << (32 - atoi(subnet_mask_str))) - 2;

    /* Print the results */
    printf("IP address: %s\n", ip_addr_str);
    printf("Subnet mask: %s\n", subnet_mask_str);
    printf("Network address: %s\n", network_addr_str);
    printf("Broadcast address: %s\n", broadcast_addr_str);
    printf("Number of hosts: %u\n", num_hosts);

    return 0;
}