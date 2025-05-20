//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_subnet_details(unsigned char* subnet_bits) {
    printf("\nSubnet Mask Details:\n\n");
    printf("Network Address: %d.%d.%d.%d\n", subnet_bits[0], subnet_bits[1], subnet_bits[2], 0);
    printf("Subnet Mask: %d.%d.%d.%d\n", subnet_bits[0], subnet_bits[1], subnet_bits[2], subnet_bits[3]);
    printf("First Usable IP Address: %d.%d.%d.%d\n", subnet_bits[0], subnet_bits[1], subnet_bits[2], subnet_bits[3] + 1);
    printf("Last Usable IP Address: %d.%d.%d.%d\n", subnet_bits[0], subnet_bits[1], subnet_bits[2], subnet_bits[3] + 2);
    printf("Broadcast Address: %d.%d.%d.%d\n\n", subnet_bits[0], subnet_bits[1], subnet_bits[2], subnet_bits[3] + 3);
}

void calculate_subnet_mask(int subnet_bits, unsigned char* subnet_octets) {
    int i, octet_index, bit_pos;
    unsigned char mask_bits[32] = {0};

    for (i = 0; i < subnet_bits; i++) {
        mask_bits[i] = 1;
    }

    octet_index = 0;
    bit_pos = 7;
    for (i = 0; i < 32; i++) {
        if (mask_bits[i] == 1) {
            subnet_octets[octet_index] |= (1 << bit_pos);
        }
        bit_pos--;
        if (bit_pos < 0) {
            octet_index++;
            bit_pos = 7;
        }
    }
    print_subnet_details(subnet_octets);
}

int main() {
    char ip_address[16], subnet[3];
    int subnet_bits;
    unsigned char subnet_octets[4] = {0};
    unsigned char ip_octets[4] = {0};

    printf("Enter IP address in dotted decimal format (xxx.xxx.xxx.xxx):");
    scanf("%s", ip_address);
    sscanf(ip_address, "%hhu.%hhu.%hhu.%hhu", &ip_octets[0], &ip_octets[1], &ip_octets[2], &ip_octets[3]);

    printf("Enter number of subnet bits (1 to 24):");
    scanf("%d", &subnet_bits);

    calculate_subnet_mask(subnet_bits, subnet_octets);

    return 0;
}