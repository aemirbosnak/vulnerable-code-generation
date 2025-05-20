//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_LENGTH 16
#define MAX_SUBNET_LENGTH 3

int convert_to_binary(int dec) {
    int remainder, binary = 0, i = 1;
    while (dec != 0) {
        remainder = dec % 2;
        dec = dec / 2;
        binary = binary + (remainder * i);
        i = i * 10;
    }
    return binary;
}

int main() {
    char ip_address[MAX_IP_LENGTH];
    char subnet_mask[MAX_SUBNET_LENGTH];

    printf("Enter IP address: ");
    fflush(stdout);
    scanf("%s", ip_address);

    printf("Enter Subnet Mask: ");
    fflush(stdout);
    scanf("%s", subnet_mask);

    int num_bits = atoi(subnet_mask);
    int mask = 0xffffffff << (32 - num_bits);

    int octet1, octet2, octet3, octet4;
    sscanf(ip_address, "%d.%d.%d.%d", &octet1, &octet2, &octet3, &octet4);

    int binary_octet1 = convert_to_binary(octet1);
    int binary_octet2 = convert_to_binary(octet2);
    int binary_octet3 = convert_to_binary(octet3);
    int binary_octet4 = convert_to_binary(octet4);

    int binary_mask1 = convert_to_binary(255);
    int binary_mask2 = convert_to_binary(255);
    int binary_mask3 = convert_to_binary(255);
    int binary_mask4 = convert_to_binary(255);

    if (num_bits <= 8) {
        binary_mask1 = convert_to_binary(mask >> 24);
        binary_octet1 = binary_octet1 & binary_mask1;
    } else if (num_bits <= 16) {
        binary_mask1 = convert_to_binary(mask >> 24);
        binary_mask2 = convert_to_binary((mask & 0x00ff0000) >> 16);
        binary_octet1 = binary_octet1 & binary_mask1;
        binary_octet2 = binary_octet2 & binary_mask2;
    } else if (num_bits <= 24) {
        binary_mask1 = convert_to_binary(mask >> 24);
        binary_mask2 = convert_to_binary((mask & 0x00ff0000) >> 16);
        binary_mask3 = convert_to_binary((mask & 0x0000ff00) >> 8);
        binary_octet1 = binary_octet1 & binary_mask1;
        binary_octet2 = binary_octet2 & binary_mask2;
        binary_octet3 = binary_octet3 & binary_mask3;
    } else {
        binary_mask1 = convert_to_binary(mask >> 24);
        binary_mask2 = convert_to_binary((mask & 0x00ff0000) >> 16);
        binary_mask3 = convert_to_binary((mask & 0x0000ff00) >> 8);
        binary_mask4 = convert_to_binary(mask & 0x000000ff);
        binary_octet1 = binary_octet1 & binary_mask1;
        binary_octet2 = binary_octet2 & binary_mask2;
        binary_octet3 = binary_octet3 & binary_mask3;
        binary_octet4 = binary_octet4 & binary_mask4;
    }

    printf("\nIP Address is: %d.%d.%d.%d\n", octet1, octet2, octet3, octet4);
    printf("\nMask is: %d.%d.%d.%d\n", binary_mask1, binary_mask2, binary_mask3, binary_mask4);
    printf("\nNetwork Address is: %d.%d.%d.%d\n", binary_octet1, binary_octet2, binary_octet3, binary_octet4);
    return 0;
}