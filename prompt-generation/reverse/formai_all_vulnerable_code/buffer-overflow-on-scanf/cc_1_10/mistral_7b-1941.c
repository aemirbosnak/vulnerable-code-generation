//MISTRAL-7B DATASET v1.0 Category: Subnet Calculator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define IP_SIZE 4
#define BITS_PER_BYTE 8

typedef struct {
    unsigned int ip[IP_SIZE];
    unsigned int subnet_mask[IP_SIZE];
    unsigned int broadcast_address[IP_SIZE];
} Subnet;

void binary_representation(unsigned int number, int size) {
    int i;
    for (i = size - 1; i >= 0; i--) {
        printf("%d", (number >> i) & 1);
    }
    printf(" ");
}

void ip_to_binary(unsigned int ip[]) {
    int i;
    for (i = 0; i < IP_SIZE; i++) {
        binary_representation(ip[i], IP_SIZE * BITS_PER_BYTE);
        printf(".");
    }
    printf("\n");
}

void calculate_subnet_information(unsigned int ip[], unsigned int subnet_size) {
    int i;
    unsigned int subnet_mask[IP_SIZE], broadcast_address[IP_SIZE];

    for (i = 0; i < IP_SIZE; i++) {
        subnet_mask[i] = ip[i] | ~((1 << subnet_size) - 1);
        broadcast_address[i] = ip[i] | (~0 << (BITS_PER_BYTE * IP_SIZE - subnet_size));
    }

    printf("Subnet Address : ");
    ip_to_binary(ip);
    printf("Subnet Mask : ");
    ip_to_binary(subnet_mask);
    printf("Broadcast Address : ");
    ip_to_binary(broadcast_address);
}

int main() {
    unsigned int ip[IP_SIZE], subnet_size;

    printf("Enter the IP address : ");
    for (int i = 0; i < IP_SIZE; i++) {
        scanf("%d", &ip[i]);
    }

    printf("Enter the subnet size (in bits) : ");
    scanf("%d", &subnet_size);

    calculate_subnet_information(ip, subnet_size);

    return 0;
}