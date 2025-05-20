//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_IP_LEN 16
#define MAX_MASK_LEN 3

typedef struct {
    unsigned char octets[4];
} ip_address_t;

typedef struct {
    unsigned char octets[4];
    unsigned int prefix_length;
} subnet_mask_t;

void print_ip_address(ip_address_t *ip) {
    printf("%u.%u.%u.%u\n", ip->octets[0], ip->octets[1], ip->octets[2], ip->octets[3]);
}

void print_subnet_mask(subnet_mask_t *mask) {
    printf("%u.%u.%u.%u/%u\n", mask->octets[0], mask->octets[1], mask->octets[2], mask->octets[3], mask->prefix_length);
}

int validate_ip_address(char *ip_str) {
    ip_address_t ip;
    int octets_parsed = sscanf(ip_str, "%hhu.%hhu.%hhu.%hhu", &ip.octets[0], &ip.octets[1], &ip.octets[2], &ip.octets[3]);

    if (octets_parsed != 4) {
        return 0;
    }

    for (int i = 0; i < 4; i++) {
        if (ip.octets[i] > 255) {
            return 0;
        }
    }

    return 1;
}

int validate_subnet_mask(char *mask_str) {
    subnet_mask_t mask;
    int octets_parsed = sscanf(mask_str, "%hhu.%hhu.%hhu.%hhu/%u", &mask.octets[0], &mask.octets[1], &mask.octets[2], &mask.octets[3], &mask.prefix_length);

    if (octets_parsed != 5) {
        return 0;
    }

    for (int i = 0; i < 4; i++) {
        if (mask.octets[i] > 255) {
            return 0;
        }
    }

    if (mask.prefix_length > 32) {
        return 0;
    }

    return 1;
}

int calculate_network_address(ip_address_t *ip, subnet_mask_t *mask, ip_address_t *network_address) {
    for (int i = 0; i < 4; i++) {
        network_address->octets[i] = ip->octets[i] & mask->octets[i];
    }

    return 1;
}

int calculate_broadcast_address(ip_address_t *ip, subnet_mask_t *mask, ip_address_t *broadcast_address) {
    for (int i = 0; i < 4; i++) {
        broadcast_address->octets[i] = ip->octets[i] | ~mask->octets[i];
    }

    return 1;
}

int calculate_number_of_hosts(subnet_mask_t *mask) {
    return (int) pow(2, 32 - mask->prefix_length) - 2;
}

int main() {
    char ip_str[MAX_IP_LEN];
    char mask_str[MAX_MASK_LEN];
    ip_address_t ip;
    subnet_mask_t mask;
    ip_address_t network_address;
    ip_address_t broadcast_address;
    int number_of_hosts;

    printf("Enter the IP address: ");
    scanf("%s", ip_str);
    if (!validate_ip_address(ip_str)) {
        printf("Invalid IP address.\n");
        return 1;
    }

    printf("Enter the subnet mask: ");
    scanf("%s", mask_str);
    if (!validate_subnet_mask(mask_str)) {
        printf("Invalid subnet mask.\n");
        return 1;
    }

    sscanf(ip_str, "%hhu.%hhu.%hhu.%hhu", &ip.octets[0], &ip.octets[1], &ip.octets[2], &ip.octets[3]);
    sscanf(mask_str, "%hhu.%hhu.%hhu.%hhu/%u", &mask.octets[0], &mask.octets[1], &mask.octets[2], &mask.octets[3], &mask.prefix_length);

    printf("\nIP address: ");
    print_ip_address(&ip);

    printf("Subnet mask: ");
    print_subnet_mask(&mask);

    printf("\nNetwork address: ");
    calculate_network_address(&ip, &mask, &network_address);
    print_ip_address(&network_address);

    printf("Broadcast address: ");
    calculate_broadcast_address(&ip, &mask, &broadcast_address);
    print_ip_address(&broadcast_address);

    printf("\nNumber of hosts: %d\n", calculate_number_of_hosts(&mask));

    return 0;
}