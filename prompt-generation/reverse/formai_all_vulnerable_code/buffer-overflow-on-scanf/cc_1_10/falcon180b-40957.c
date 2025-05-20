//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the subnet mask based on the given IP address and subnet bits
void calculate_subnet_mask(char *ip_address, int subnet_bits) {
    int i, j;
    char *subnet_mask = malloc(15 * sizeof(char)); // Allocate memory for the subnet mask string
    strcpy(subnet_mask, "255.255.255.0"); // Set the default subnet mask to /24
    for (i = 0; i < subnet_bits; i++) {
        for (j = 0; j < 8; j++) {
            if (subnet_mask[j] == '0' && i % 8 == j) {
                subnet_mask[j] = '1';
            }
        }
    }
    printf("Subnet mask for %s is: %s\n", ip_address, subnet_mask);
}

// Function to validate the given IP address
int validate_ip_address(char *ip_address) {
    int i, j, count = 0;
    for (i = 0; i < strlen(ip_address); i++) {
        if (ip_address[i] == '.') {
            count++;
        }
    }
    if (count!= 3) {
        printf("Invalid IP address.\n");
        return 0;
    }
    for (i = 0; i < strlen(ip_address); i++) {
        if (ip_address[i] < '0' || ip_address[i] > '9') {
            printf("Invalid IP address.\n");
            return 0;
        }
    }
    for (i = 0; i < strlen(ip_address); i++) {
        if (ip_address[i] == '.') {
            for (j = i + 1; j < strlen(ip_address); j++) {
                if (ip_address[j] < '0' || ip_address[j] > '9') {
                    printf("Invalid IP address.\n");
                    return 0;
                }
            }
        }
    }
    return 1;
}

int main() {
    char ip_address[15];
    int subnet_bits;

    printf("Enter the IP address: ");
    scanf("%s", ip_address);

    if (!validate_ip_address(ip_address)) {
        return 0;
    }

    printf("Enter the subnet bits: ");
    scanf("%d", &subnet_bits);

    calculate_subnet_mask(ip_address, subnet_bits);

    return 0;
}