//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void calculate_subnet(char* ip_address, char* subnet_mask);
void convert_to_binary(char* octet, char* binary);
int binary_to_decimal(char* binary);

int main() {
    char ip_address[16], subnet_mask[16];

    printf("Enter IP address: ");
    scanf("%s", ip_address);

    printf("Enter subnet mask: ");
    scanf("%s", subnet_mask);

    calculate_subnet(ip_address, subnet_mask);

    return 0;
}

void calculate_subnet(char* ip_address, char* subnet_mask) {
    int subnet_bits = 0, i;
    char octet[9], binary_mask[33], subnet_address[16], broadcast_address[16];

    // Convert subnet mask to binary
    convert_to_binary(subnet_mask, binary_mask);

    // Calculate number of subnet bits
    for (i = 0; i < strlen(binary_mask); i++) {
        if (binary_mask[i] == '1') {
            subnet_bits++;
        }
    }

    // Calculate subnet address
    strncpy(subnet_address, ip_address, 16);
    for (i = subnet_bits; i < 32; i++) {
        subnet_address[i/8] &= ~(1 << (7 - i % 8));
    }

    // Calculate broadcast address
    strncpy(broadcast_address, ip_address, 16);
    for (i = subnet_bits; i < 32; i++) {
        broadcast_address[i/8] |= 1 << (7 - i % 8);
    }

    printf("IP Address: %s\n", ip_address);
    printf("Subnet Mask: %s\n", subnet_mask);
    printf("Subnet Address: %d.%d.%d.%d\n", binary_to_decimal(subnet_address), binary_to_decimal(subnet_address+8), binary_to_decimal(subnet_address+16), binary_to_decimal(subnet_address+24));
    printf("Broadcast Address: %d.%d.%d.%d\n", binary_to_decimal(broadcast_address), binary_to_decimal(broadcast_address+8), binary_to_decimal(broadcast_address+16), binary_to_decimal(broadcast_address+24));
}

void convert_to_binary(char* octet, char* binary) {
    int i;
    for (i = 0; i < strlen(octet); i++) {
        int decimal_value = octet[i] - '0';
        int j;
        for (j = 7; j >= 0; j--) {
            binary[(i*8)+(7-j)] = decimal_value / (int)pow(2, j) + '0';
            decimal_value %= (int)pow(2, j);
        }
    }
    binary[32] = '\0';
}

int binary_to_decimal(char* binary) {
    int decimal = 0, i;
    for (i = 0; i < 8; i++) {
        decimal += (binary[i] - '0') * (int)pow(2, 7-i);
    }
    return decimal;
}