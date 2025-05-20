//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: scientific
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MAX_OCTET_VAL 255
#define MAX_MASK_LENGTH 32

/**
 * Function to check if a given IP address is valid.
 */
bool is_valid_ip(char *ip_address) {
    int octet_count = 0;
    char *octet;
    char *delimiter = ".";
    octet = strtok(ip_address, delimiter);

    while (octet != NULL) {
        int val = atoi(octet);

        if (val < 0 || val > MAX_OCTET_VAL) {
            return false;
        }

        octet_count++;
        octet = strtok(NULL, delimiter);
    }

    return octet_count == 4;
}

/**
 * Function to check if a given mask is valid.
 */
bool is_valid_mask(int mask) {
    return mask >= 0 && mask <= MAX_MASK_LENGTH;
}

/**
 * Function to print the binary representation of a given decimal number.
 */
void decimal_to_binary(int num, int bits) {
    int binary_num[32];
    int i = 0;

    // Convert decimal to binary
    while (num > 0) {
        binary_num[i] = num % 2;
        num /= 2;
        i++;
    }

    // Pad with leading zeroes if necessary
    while (i < bits) {
        binary_num[i] = 0;
        i++;
    }

    // Print binary representation
    for (int j = bits - 1; j >= 0; j--) {
        printf("%d", binary_num[j]);
    }

    printf("\n");
}

/**
 * Main function to calculate subnet information.
 */
int main() {
    char ip_address[15];
    int mask;

    // Get user input
    printf("Enter an IP address: ");
    scanf("%s", ip_address);

    if (!is_valid_ip(ip_address)) {
        printf("Invalid IP address.\n");
        return 1;
    }

    printf("\nEnter a subnet mask (0 - 32): ");
    scanf("%d", &mask);

    if (!is_valid_mask(mask)) {
        printf("Invalid subnet mask.\n");
        return 1;
    }

    // Calculate subnet information
    int num_hosts = pow(2, MAX_MASK_LENGTH - mask) - 2;
    int wildcard_mask = MAX_OCTET_VAL >> mask;
    int network_address = 0;
    char *octet = strtok(ip_address, ".");
    int octet_count = 0;

    while (octet != NULL) {
        int val = atoi(octet);
        network_address |= val << (24 - octet_count * 8);
        octet_count++;
        octet = strtok(NULL, ".");
    }

    int broadcast_address = network_address + num_hosts + 1;

    // Print subnet information
    printf("\nSubnet information:\n");
    printf("Number of hosts: %d\n", num_hosts);
    printf("Wildcard mask: ");

    // Convert wildcard mask to binary and print
    for (int i = 0; i < 4; i++) {
        int octet_val;

        if (mask >= 8) {
            octet_val = 0;
        } else if (mask <= 0) {
            octet_val = 255;
        } else {
            if (i * 8 + mask >= 32) {
                octet_val = 0;
            } else {
                octet_val = MAX_OCTET_VAL >> (i * 8 + mask);
            }
        }

        printf("%d", octet_val);

        if (i < 3) {
            printf(".");
        }
    }

    printf("\nNetwork address: ");
    decimal_to_binary(network_address, 32);
    printf("Broadcast address: ");
    decimal_to_binary(broadcast_address, 32);

    return 0;
}