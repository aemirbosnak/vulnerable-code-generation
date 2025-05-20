//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int num_subnets, subnet_size, i, j, k, valid;
    char *ip_address, *subnet_mask, *subnet_ip;
    char subnet_ip_str[16];

    // Get IP address and subnet mask from user
    printf("Enter IP address: ");
    scanf("%s", ip_address);
    printf("Enter subnet mask: ");
    scanf("%s", subnet_mask);

    // Convert IP address and subnet mask to integer format
    int ip_int = inet_addr(ip_address);
    int subnet_int = inet_addr(subnet_mask);

    // Get number of subnets from user
    printf("Enter number of subnets: ");
    scanf("%d", &num_subnets);

    // Calculate subnet size
    subnet_size = 32 - (int)log2(num_subnets);

    // Allocate memory for subnet IP addresses
    subnet_ip = (char *)malloc(num_subnets * 16);

    // Generate subnet IP addresses
    for (i = 0; i < num_subnets; i++) {
        valid = 0;
        for (j = 0; j < 4; j++) {
            if ((subnet_int >> (8 * j)) & 0xFF) {
                k = i >> (j * 2);
                if (k % 2 == 0) {
                    subnet_ip[i * 16 + j * 4 + 3] = '0';
                } else {
                    subnet_ip[i * 16 + j * 4 + 3] = '1';
                }
                valid = 1;
            } else {
                subnet_ip[i * 16 + j * 4 + 3] = '0';
            }
        }
        if (!valid) {
            printf("Invalid subnet mask.\n");
            exit(1);
        }
        for (j = 0; j < 4; j++) {
            subnet_ip[i * 16 + j * 4] = '.';
        }
    }

    // Print subnet IP addresses
    printf("Generated subnet IP addresses:\n");
    for (i = 0; i < num_subnets; i++) {
        printf("%s\n", subnet_ip + i * 16);
    }

    // Free memory
    free(subnet_ip);

    return 0;
}