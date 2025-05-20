//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <arpa/inet.h>

#define MAX_SUBNETS 256
#define IPV4_SIZE 4

typedef struct {
    uint8_t ip[IPV4_SIZE];
    uint8_t mask;
    uint8_t subnet[MAX_SUBNETS][IPV4_SIZE];
    int subnet_count;
} SubnetInfo;

void convert_ip_to_binary(uint8_t *ip, char *binary) {
    for (int i = 0; i < IPV4_SIZE; i++) {
        for (int j = 7; j >= 0; j--) {
            binary[i * 8 + (7 - j)] = (ip[i] & (1 << j)) ? '1' : '0';
        }
    }
    binary[IPV4_SIZE * 8] = '\0';
}

void print_ip(uint8_t *ip) {
    printf("%d.%d.%d.%d", ip[0], ip[1], ip[2], ip[3]);
}

uint8_t calculate_subnet_mask(int bits) {
    return (uint8_t)(~0U >> (32 - bits));
}

void calculate_subnets(SubnetInfo *info) {
    info->subnet_count = 0;
    uint32_t base_ip = *(uint32_t *)info->ip;
    uint32_t subnet_mask = calculate_subnet_mask(info->mask);
    uint32_t subnet_base = base_ip & subnet_mask;

    for (int i = 0; i < (1 << (32 - info->mask)); i++) {
        uint32_t subnet_ip = subnet_base | i;
        memcpy(info->subnet[info->subnet_count], &subnet_ip, IPV4_SIZE);
        info->subnet_count++;
    }
}

void display_subnet_info(SubnetInfo *info) {
    printf("Base IP: ");
    print_ip(info->ip);
    printf("\nSubnet Mask: /%d\n", info->mask);
    printf("Subnets:\n");

    for (int i = 0; i < info->subnet_count; i++) {
        printf("\tSubnet %d: ", i + 1);
        print_ip(info->subnet[i]);
        printf("\n");
    }
}

int validate_ip(char *ip_str, uint8_t *ip) {
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, ip_str, &sa.sin_addr);
    if (result == 1) {
        memcpy(ip, &sa.sin_addr, IPV4_SIZE);
        return 1;
    }
    return 0;
}

int validate_mask(int mask) {
    return (mask >= 0 && mask <= 32);
}

int main() {
    SubnetInfo info;
    char ip_str[16];
    char binary[IPV4_SIZE * 8 + 1];

    printf("Enter an IP address (e.g., 192.168.1.1): ");
    scanf("%15s", ip_str);

    if (!validate_ip(ip_str, info.ip)) {
        fprintf(stderr, "Invalid IP address format.\n");
        return EXIT_FAILURE;
    }

    printf("Enter subnet mask (CIDR notation, e.g., 24): ");
    scanf("%hhu", &info.mask);

    if (!validate_mask(info.mask)) {
        fprintf(stderr, "Invalid subnet mask. It should be between 0 and 32.\n");
        return EXIT_FAILURE;
    }

    calculate_subnets(&info);

    convert_ip_to_binary(info.ip, binary);
    printf("Binary representation of the IP:\n");
    for (int i = 0; i < IPV4_SIZE; i++) {
        printf("%s", binary + i * 8);
        if (i < IPV4_SIZE - 1) printf(".");
    }
    printf("\n");

    display_subnet_info(&info);
    
    return EXIT_SUCCESS;
}