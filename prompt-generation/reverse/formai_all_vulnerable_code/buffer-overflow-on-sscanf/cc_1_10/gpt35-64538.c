//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_BITS 32

void convert_to_binary(int decimal, char binary[]) {
    for (int i = MAX_BITS - 1; i >= 0; i--) {
        if (decimal >= pow(2, i)) {
            decimal -= pow(2, i);
            binary[MAX_BITS - 1 - i] = '1';
        } else {
            binary[MAX_BITS - 1 - i] = '0';
        }
    }
}

void convert_to_decimal(char binary[], int* decimal) {
    for (int i = MAX_BITS - 1; i >= 0; i--) {
        if (binary[MAX_BITS - 1 - i] == '1') {
            *decimal += pow(2, i);
        }
    }
}

int calculate_subnet_mask(int prefix_length) {
    int subnet_mask = 0;
    for (int i = 0; i < prefix_length; i++) {
        subnet_mask += pow(2, MAX_BITS - 1 - i);
    }
    return subnet_mask;
}

void calculate_network_address(char ip_address[], int prefix_length, char network_address[]) {
    int ip_decimal[MAX_BITS] = {0};
    char binary_ip[MAX_BITS] = {0};
    char binary_subnet[MAX_BITS] = {0};
    
    // Convert IP address to decimal
    sscanf(ip_address, "%d.%d.%d.%d", &ip_decimal[0], &ip_decimal[1], &ip_decimal[2], &ip_decimal[3]);
    
    // Convert IP address to binary
    for (int i = 0; i < 4; i++) {
        char binary_octet[MAX_BITS / 4] = {0};
        convert_to_binary(ip_decimal[i], binary_octet);
        strcat(binary_ip, binary_octet);
    }
    
    // Calculate subnet mask
    int subnet_mask_decimal = calculate_subnet_mask(prefix_length);
    convert_to_binary(subnet_mask_decimal, binary_subnet);
    
    // Calculate network address
    for (int i = 0; i < MAX_BITS; i++) {
        if (binary_ip[i] == '1' && binary_subnet[i] == '1') {
            network_address[i] = '1';
        } else {
            network_address[i] = '0';
        }
    }
}

int main() {
    // Get user input
    char ip_address[20];
    int prefix_length;
    printf("Enter IP address: ");
    scanf("%s", ip_address);
    printf("Enter prefix length: ");
    scanf("%d", &prefix_length);
    
    // Calculate network address
    char network_address[MAX_BITS] = {0};
    calculate_network_address(ip_address, prefix_length, network_address);
    
    // Convert network address to decimal
    int network_decimal = 0;
    convert_to_decimal(network_address, &network_decimal);
    
    // Output results
    printf("\nNetwork address: %d.%d.%d.%d/%d\n", (network_decimal >> 24) & 0xFF, (network_decimal >> 16) & 0xFF, (network_decimal >> 8) & 0xFF, network_decimal & 0xFF, prefix_length);
    
    return 0;
}