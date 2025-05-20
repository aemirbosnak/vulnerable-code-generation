//MISTRAL-7B DATASET v1.0 Category: Subnet Calculator ; Style: puzzling
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { unsigned char ip[4]; } IPv4;

IPv4 mask_gen(unsigned char mask_bits) {
    IPv4 mask;
    memset(mask.ip, 0, sizeof(mask.ip));
    mask.ip[mask_bits] = 255;
    return mask;
}

IPv4 subnet_calc(IPv4 ip, IPv4 mask) {
    int i;
    for (i = 0; i < 4; ++i) {
        ip.ip[i] = (ip.ip[i] & mask.ip[i]) << (8 * (3 - i) - mask.ip[3]);
    }
    return ip;
}

void print_binary(unsigned char b) {
    int i;
    for (i = 7; i >= 0; --i) {
        putchar(i < b ? '1' : '0');
    }
    putchar(' ');
}

void print_ip(IPv4 ip) {
    int i;
    for (i = 0; i < 4; ++i) {
        printf("%d.", ip.ip[i]);
        print_binary(ip.ip[i] >> 4);
        print_binary(ip.ip[i] & 0xF);
        putchar(' ');
    }
    putchar('\n');
}

int main() {
    unsigned int ip, subnet_mask;
    IPv4 ip_bin, mask_bin, subnet;

    printf("Enter IP address in dotted decimal format:\n");
    scanf("%d", &ip);
    printf("Enter subnet mask in dotted decimal format:\n");
    scanf("%d", &subnet_mask);

    ip_bin.ip[0] = ip >> 24;
    ip_bin.ip[1] = (ip >> 16) & 0xFF;
    ip_bin.ip[2] = (ip >> 8) & 0xFF;
    ip_bin.ip[3] = ip & 0xFF;

    mask_bin = mask_gen(subnet_mask);

    subnet = subnet_calc(ip_bin, mask_bin);

    printf("IP address in binary format:\n");
    print_ip(ip_bin);

    printf("Subnet mask in binary format:\n");
    print_ip(mask_bin);

    printf("Subnet number in binary format:\n");
    print_ip(subnet);

    return 0;
}