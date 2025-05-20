//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to convert decimal to binary
void decimal_to_binary(unsigned int decimal, char *binary) {
    for (int i = 0; i < 8; i++) {
        binary[i] = '0';
    }
    int index = 7;
    while (decimal > 0) {
        binary[index--] = decimal % 2 + '0';
        decimal /= 2;
    }
}

// function to convert binary to decimal
unsigned int binary_to_decimal(char *binary) {
    int power = 1, decimal = 0;
    for (int i = 7; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += power;
        }
        power *= 2;
    }
    return decimal;
}

int main() {
    // get network address from user
    char network_address_str[16];
    printf("Enter network address (ex: 192.168.1.0): ");
    scanf("%s", network_address_str);

    // convert network address to binary
    char network_address_bin[33];
    int i, j;
    for (i = 0; network_address_str[i] != '\0'; i++) {
        if (network_address_str[i] == '.') {
            continue;
        }
        decimal_to_binary(network_address_str[i] - '0', &network_address_bin[(i-1)*8]);
    }

    // get subnet mask from user
    char subnet_mask_str[16];
    printf("Enter subnet mask (ex: 255.255.255.0): ");
    scanf("%s", subnet_mask_str);

    // convert subnet mask to binary
    char subnet_mask_bin[33];
    for (i = 0, j = 0; subnet_mask_str[i] != '\0'; i++) {
        if (subnet_mask_str[i] == '.') {
            continue;
        }
        decimal_to_binary(subnet_mask_str[i] - '0', &subnet_mask_bin[(j-1)*8]);
        j++;
    }

    // calculate network address and broadcast address
    char network_address_bin_res[33], broadcast_address_bin[33];
    for (i = 0; i < 32; i++) {
        if (network_address_bin[i] == '1' && subnet_mask_bin[i] == '1') {
            network_address_bin_res[i] = '1';
            broadcast_address_bin[i] = '1';
        } else {
            network_address_bin_res[i] = '0';
            broadcast_address_bin[i] = '1';
        }
    }
    network_address_bin_res[32] = '\0';
    broadcast_address_bin[32] = '\0';

    // convert network address and broadcast address to decimal
    char network_address[16], broadcast_address[16];
    for (i = 0, j = 0; i < 32; i += 8, j++) {
        snprintf(&network_address[j*4], 4, "%u", binary_to_decimal(&network_address_bin_res[i]));
        snprintf(&broadcast_address[j*4], 4, "%u", binary_to_decimal(&broadcast_address_bin[i]));
        if (i < 24) {
            network_address[j*4 + 3] = '.';
            broadcast_address[j*4 + 3] = '.';
        }
    }

    // calculate number of hosts
    unsigned int number_of_hosts = 0;
    for (i = 24; i < 32; i++) {
        if (subnet_mask_bin[i] == '0') {
            number_of_hosts += (1 << (8 - (i % 8)));
        }
    }

    // print results
    printf("\n");
    printf("Network Address: %s\n", network_address);
    printf("Broadcast Address: %s\n", broadcast_address);
    printf("Number of Hosts: %u\n", number_of_hosts);

    return 0;
}