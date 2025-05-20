//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

void print_binary(unsigned char octet) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (octet >> i) & 1);
    }
}

void calculate_subnet(const char *ip_str, const char *mask_str) {
    struct sockaddr_in ip_addr, mask_addr;

    inet_pton(AF_INET, ip_str, &(ip_addr.sin_addr));
    inet_pton(AF_INET, mask_str, &(mask_addr.sin_addr));

    unsigned int ip = ntohl(ip_addr.sin_addr.s_addr);
    unsigned int mask = ntohl(mask_addr.sin_addr.s_addr);
    
    unsigned int network = ip & mask;
    unsigned int broadcast = network | ~mask;

    printf("\nInput IP Address: %s\n", ip_str);
    printf("Input Subnet Mask: %s\n\n", mask_str);
    
    printf("IP Address in binary: ");
    for (int i = 0; i < 4; i++) {
        print_binary((ip_addr.sin_addr.s_addr >> (i * 8)) & 0xFF);
        if (i < 3) printf(".");
    }
    printf("\n");

    printf("Subnet Mask in binary: ");
    for (int i = 0; i < 4; i++) {
        print_binary((mask_addr.sin_addr.s_addr >> (i * 8)) & 0xFF);
        if (i < 3) printf(".");
    }
    printf("\n");
    
    printf("Network Address in binary: ");
    for (int i = 0; i < 4; i++) {
        print_binary((network >> (i * 8)) & 0xFF);
        if (i < 3) printf(".");
    }
    printf("\n");

    printf("Broadcast Address in binary: ");
    for (int i = 0; i < 4; i++) {
        print_binary((broadcast >> (i * 8)) & 0xFF);
        if (i < 3) printf(".");
    }
    printf("\n");

    printf("Total Hosts in the subnet: %u\n", (1 << (32 - __builtin_popcount(mask))) - 2);
}

int main() {
    char ip[16];
    char mask[16];

    printf("Subnet Calculator\n");
    printf("=================\n");
    
    printf("Enter IP Address (e.g. 192.168.1.1): ");
    scanf("%15s", ip);
    
    printf("Enter Subnet Mask (e.g. 255.255.255.0): ");
    scanf("%15s", mask);

    calculate_subnet(ip, mask);

    return 0;
}