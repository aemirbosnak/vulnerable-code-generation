//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BINARY_IP_LEN 32
#define MAX_INPUT_LEN 20

void convert_decimal_to_binary(int decimal, int binary[8]) {
    for (int i = 7; i >= 0; i--) {
        binary[i] = decimal % 2;
        decimal /= 2;
    }
}

void get_network_address(int ip_binary[32], int subnet_binary[32], int network_address[32]) {
    for (int i = 0; i < BINARY_IP_LEN; i++) {
        network_address[i] = ip_binary[i] & subnet_binary[i];
    }
}

void get_broadcast_address(int network_address[32], int subnet_binary[32], int broadcast_address[32]) {
    for (int i = 0; i < BINARY_IP_LEN; i++) {
        broadcast_address[i] = network_address[i] | (subnet_binary[i] ^ 1);
    }
}

int get_number_of_hosts(int subnet_binary[32]) {
    int hosts_bits = 0;
    for (int i = 0; i < BINARY_IP_LEN; i++) {
        if (subnet_binary[i] == 1) {
            hosts_bits++;
        }
    }
    return (1 << (BINARY_IP_LEN - hosts_bits)) - 2;
}

int main() {
    // Get IP address
    char ip_address[MAX_INPUT_LEN];
    printf("Enter IP Address: ");
    scanf("%s", ip_address);

    // Validate IP address
    char* token = strtok(ip_address, ".");
    int ip_octets[4];
    for (int i = 0; i < 4; i++) {
        if (token == NULL) {
            printf("Invalid IP address\n");
            return 1;
        }
        int octet = atoi(token);
        if (octet < 0 || octet > 255) {
            printf("Invalid IP address\n");
            return 1;
        }
        ip_octets[i] = octet;
        token = strtok(NULL, ".");
    }

    // Get subnet mask
    char subnet_mask[MAX_INPUT_LEN];
    printf("Enter Subnet Mask: ");
    scanf("%s", subnet_mask);

    // Validate subnet mask
    token = strtok(subnet_mask, ".");
    int subnet_octets[4];
    int subnet_binary[32] = {0};
    for (int i = 0; i < 4; i++) {
        if (token == NULL) {
            printf("Invalid subnet mask\n");
            return 1;
        }
        int octet = atoi(token);
        if (octet < 0 || octet > 255) {
            printf("Invalid subnet mask\n");
            return 1;
        }
        subnet_octets[i] = octet;
        int binary_octet[8];
        convert_decimal_to_binary(octet, binary_octet);
        memcpy(subnet_binary + i * 8, binary_octet, sizeof(int) * 8);
        token = strtok(NULL, ".");
    }

    // Get network and broadcast addresses
    int ip_binary[32] = {0};
    int network_address[32] = {0};
    int broadcast_address[32] = {0};

    for (int i = 0; i < 4; i++) {
        int binary_octet[8];
        convert_decimal_to_binary(ip_octets[i], binary_octet);
        memcpy(ip_binary + i * 8, binary_octet, sizeof(int) * 8);
    }

    get_network_address(ip_binary, subnet_binary, network_address);
    get_broadcast_address(network_address, subnet_binary, broadcast_address);

    // Get number of hosts
    int number_of_hosts = get_number_of_hosts(subnet_binary);

    // Print results
    printf("\nNetwork Address: ");
    for (int i = 0; i < 4; i++) {
        int decimal_octet = 0;
        for (int j = 0; j < 8; j++) {
            decimal_octet += network_address[i * 8 + j] << (7 - j);
        }
        printf("%d", decimal_octet);
        if (i < 3) {
            printf(".");
        }
    }

    printf("\nBroadcast Address: ");
    for (int i = 0; i < 4; i++) {
        int decimal_octet = 0;
        for (int j = 0; j < 8; j++) {
            decimal_octet += broadcast_address[i * 8 + j] << (7 - j);
        }
        printf("%d", decimal_octet);
        if (i < 3) {
            printf(".");
        }
    }

    printf("\nNumber of Hosts: %d\n", number_of_hosts);

    return 0;
}