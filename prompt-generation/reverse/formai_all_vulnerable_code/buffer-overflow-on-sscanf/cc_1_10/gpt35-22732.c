//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: expert-level
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function to convert decimal to binary
void dec2bin(int n, char *bin) {
    int i = 0;
    while (n > 0) {
        bin[i++] = n % 2 + '0';
        n = n / 2;
    }
    bin[i] = '\0';
    // Reverse the binary string
    int len = strlen(bin);
    for (int j = 0; j < len/2; j++) {
        char temp = bin[j];
        bin[j] = bin[len-j-1];
        bin[len-j-1] = temp;
    }
}

// Function to convert binary to decimal
int bin2dec(char *bin) {
    int num = 0;
    int len = strlen(bin);
    for (int i = 0; i < len; i++) {
        if (bin[i] == '1') {
            num += (1 << (len-i-1));
        }
    }
    return num;
}

// Function to calculate subnet mask and broadcast address
void calc_subnet_mask_and_broadcast_address(char *ip_address, int num_bits, char *subnet_mask, char *broadcast_address) {
    // Extract octets from IP address
    int octet1, octet2, octet3, octet4;
    sscanf(ip_address, "%d.%d.%d.%d", &octet1, &octet2, &octet3, &octet4);
    // Calculate subnet mask
    for (int i = 0; i < num_bits; i++) {
        if (i < 8) {
            subnet_mask[i] = '1';
        } else if (i < 16) {
            subnet_mask[i] = '1';
        } else if (i < 24) {
            subnet_mask[i] = '1';
        } else {
            subnet_mask[i] = '1';
        }
    }
    subnet_mask[num_bits] = '\0';
    // Calculate broadcast address
    char binary_ip_address[33], binary_subnet_mask[33];
    dec2bin(octet1, binary_ip_address);
    dec2bin(octet2, binary_ip_address + 8);
    dec2bin(octet3, binary_ip_address + 16);
    dec2bin(octet4, binary_ip_address + 24);
    int num_zeros = 32 - num_bits;
    for (int i = 0; i < num_zeros; i++) {
        binary_subnet_mask[i] = '0';
    }
    binary_subnet_mask[num_zeros] = '\0';
    strcat(binary_subnet_mask, subnet_mask + num_zeros);
    int broadcast_octet1 = bin2dec(binary_ip_address) | (~bin2dec(binary_subnet_mask) & 0xff);
    int broadcast_octet2 = bin2dec(binary_ip_address + 8) | ((~bin2dec(binary_subnet_mask) >> 8) & 0xff);
    int broadcast_octet3 = bin2dec(binary_ip_address + 16) | ((~bin2dec(binary_subnet_mask) >> 16) & 0xff);
    int broadcast_octet4 = bin2dec(binary_ip_address + 24) | ((~bin2dec(binary_subnet_mask) >> 24) & 0xff);
    sprintf(broadcast_address, "%d.%d.%d.%d", broadcast_octet1, broadcast_octet2, broadcast_octet3, broadcast_octet4);
}
    
int main() {
    char ip_address[16], subnet_mask[33], broadcast_address[16];
    int num_bits;
    printf("Enter IP address: ");
    scanf("%s", ip_address);
    printf("Enter number of bits in subnet mask: ");
    scanf("%d", &num_bits);
    calc_subnet_mask_and_broadcast_address(ip_address, num_bits, subnet_mask, broadcast_address);
    printf("Subnet mask: %s\n", subnet_mask);
    printf("Broadcast address: %s\n", broadcast_address);
    return 0;
}