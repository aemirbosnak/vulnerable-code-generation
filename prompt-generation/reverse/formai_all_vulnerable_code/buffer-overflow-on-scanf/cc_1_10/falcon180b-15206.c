//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int num_subnets, host_bits;
    char ip_address[16];
    char subnet_mask[16];

    // Get IP address input from user
    printf("Enter an IP address: ");
    scanf("%s", ip_address);

    // Get number of subnets input from user
    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    // Calculate number of host bits
    host_bits = 32 - num_subnets;

    // Convert IP address to binary
    char* binary_ip = malloc(16 * sizeof(char));
    sprintf(binary_ip, "%d.%d.%d.%d", (ip_address[0] - '0'), (ip_address[1] - '0'), (ip_address[2] - '0'), (ip_address[3] - '0'));

    // Convert binary IP to decimal
    long decimal_ip = 0;
    for (int i = 0; i < strlen(binary_ip); i++) {
        decimal_ip += (binary_ip[i] - '0') * pow(256, strlen(binary_ip) - i - 1);
    }

    // Calculate subnet mask
    long subnet_mask_decimal = 0;
    int subnet_bits = 32 - host_bits;
    for (int i = 0; i < subnet_bits; i++) {
        subnet_mask_decimal += pow(256, i);
    }

    // Convert subnet mask to binary
    sprintf(subnet_mask, "%d.%d.%d.%d", (subnet_mask_decimal >> 24) & 0xFF, (subnet_mask_decimal >> 16) & 0xFF, (subnet_mask_decimal >> 8) & 0xFF, subnet_mask_decimal & 0xFF);

    // Print results
    printf("IP Address: %s\n", ip_address);
    printf("Decimal IP: %ld\n", decimal_ip);
    printf("Subnet Mask: %s\n", subnet_mask);
    printf("Number of Subnets: %d\n", num_subnets);
    printf("Number of Host Bits: %d\n", host_bits);

    // Free memory
    free(binary_ip);

    return 0;
}