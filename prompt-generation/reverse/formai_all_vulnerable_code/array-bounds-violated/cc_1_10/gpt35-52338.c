//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char ip_address[20], subnet_mask[20];
    int subnet_bits, i, j, k, decimal_octet[4], binary_octet[4];
    char *ptr;

    // get IP address and subnet mask from user
    printf("Enter IP address in dotted decimal format: ");
    scanf("%s", ip_address);
    printf("Enter subnet mask in dotted decimal format: ");
    scanf("%s", subnet_mask);

    // convert IP address from string to decimal octet format
    ptr = strtok(ip_address, ".");
    i = 0;
    while (ptr != NULL) {
        decimal_octet[i++] = atoi(ptr);
        ptr = strtok(NULL, ".");
    }

    // convert subnet mask from string to decimal octet format
    ptr = strtok(subnet_mask, ".");
    i = 0;
    while (ptr != NULL) {
        decimal_octet[i++] &= atoi(ptr);
        ptr = strtok(NULL, ".");
    }

    // calculate number of subnet bits
    subnet_bits = 0;
    i = decimal_octet[0];
    while (i > 0) {
        ++subnet_bits;
        i >>= 1;
    }

    // calculate number of host bits
    int host_bits = 32 - subnet_bits;

    // calculate subnet mask in binary octet format
    for (i = 0; i < 4; ++i) {
        for (j = 7, k = decimal_octet[i]; j >= 0; --j) {
            binary_octet[8*i+j] = k % 2;
            k >>= 1;
        }
    }

    // print results
    printf("\nIP Address: %s\n", ip_address);
    printf("Subnet Mask: %s\n", subnet_mask);
    printf("Number of subnet bits: %d\n", subnet_bits);
    printf("Number of host bits: %d\n", host_bits);
    printf("Subnet Mask (binary): ");
    for (i = 0; i < 32; ++i) {
        printf("%d", binary_octet[i]);
        if (i % 8 == 7) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}