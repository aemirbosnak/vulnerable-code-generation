//MISTRAL-7B DATASET v1.0 Category: Subnet Calculator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OCTETS 4
#define NETMASK_LEN 4
#define MAX_IPS 16

void print_binary(unsigned char octet) {
    for (int i = 7; i >= 0; --i) {
        putchar(i < octet ? '0' : '1');
    }
    putchar(' ');
}

void binary_to_decimal(unsigned char octet[MAX_OCTETS], int len) {
    int decimal = 0;
    for (int i = 0; i < len; ++i) {
        decimal += octet[i] << (7 - i);
    }
    printf("%d", decimal);
}

void calculate_subnet(unsigned char ip[MAX_OCTETS], unsigned char netmask[NETMASK_LEN]) {
    unsigned char subnet[MAX_OCTETS];
    for (int i = 0; i < MAX_OCTETS; ++i) {
        subnet[i] = ip[i] & netmask[i];
    }
    printf("Subnet: ");
    for (int i = 0; i < MAX_OCTETS; ++i) {
        print_binary(subnet[i]);
    }
    printf("\n");
}

void calculate_broadcast(unsigned char ip[MAX_OCTETS], unsigned char netmask[NETMASK_LEN]) {
    unsigned char broadcast[MAX_OCTETS];
    for (int i = 0; i < MAX_OCTETS; ++i) {
        broadcast[i] = ip[i] | ~netmask[i];
    }
    printf("Broadcast: ");
    for (int i = 0; i < MAX_OCTETS; ++i) {
        print_binary(broadcast[i]);
    }
    printf("\n");
}

int main() {
    unsigned char ip[MAX_OCTETS];
    unsigned char netmask[NETMASK_LEN];

    printf("Enter IP address: ");
    for (int i = 0; i < MAX_OCTETS; ++i) {
        scanf("%hhu", &ip[i]);
    }

    printf("Enter netmask: ");
    for (int i = 0; i < NETMASK_LEN; ++i) {
        scanf("%hhu", &netmask[i]);
    }

    calculate_subnet(ip, netmask);
    calculate_broadcast(ip, netmask);

    return 0;
}