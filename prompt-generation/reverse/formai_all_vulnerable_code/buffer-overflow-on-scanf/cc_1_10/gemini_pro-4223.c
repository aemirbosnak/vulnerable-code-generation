//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_IP_LEN 16
#define MAX_MASK_LEN 32

typedef struct {
    unsigned int ip;
    unsigned int mask;
} ip_mask;

int main() {
    char ip_str[MAX_IP_LEN];
    char mask_str[MAX_MASK_LEN];
    ip_mask ip_mask;

    printf("Enter IP address (e.g., 192.168.1.1): ");
    scanf("%s", ip_str);

    printf("Enter subnet mask (e.g., 255.255.255.0): ");
    scanf("%s", mask_str);

    if (!parse_ip_mask(ip_str, mask_str, &ip_mask)) {
        printf("Invalid IP address or subnet mask.\n");
        return EXIT_FAILURE;
    }

    printf("IP address: %u.%u.%u.%u\n",
           (ip_mask.ip >> 24) & 0xFF,
           (ip_mask.ip >> 16) & 0xFF,
           (ip_mask.ip >> 8) & 0xFF,
           ip_mask.ip & 0xFF);

    printf("Subnet mask: %u.%u.%u.%u\n",
           (ip_mask.mask >> 24) & 0xFF,
           (ip_mask.mask >> 16) & 0xFF,
           (ip_mask.mask >> 8) & 0xFF,
           ip_mask.mask & 0xFF);

    printf("Network address: %u.%u.%u.%u\n",
           (ip_mask.ip & ip_mask.mask) >> 24,
           (ip_mask.ip & ip_mask.mask) >> 16,
           (ip_mask.ip & ip_mask.mask) >> 8,
           (ip_mask.ip & ip_mask.mask) & 0xFF);

    printf("Broadcast address: %u.%u.%u.%u\n",
           (ip_mask.ip | ~ip_mask.mask) >> 24,
           (ip_mask.ip | ~ip_mask.mask) >> 16,
           (ip_mask.ip | ~ip_mask.mask) >> 8,
           (ip_mask.ip | ~ip_mask.mask) & 0xFF);

    printf("Number of hosts: %u\n",
           pow(2, 32 - count_ones(ip_mask.mask)) - 2);

    return EXIT_SUCCESS;
}

int parse_ip_mask(char *ip_str, char *mask_str, ip_mask *ip_mask) {
    unsigned int ip_parts[4];
    unsigned int mask_parts[4];
    int i;

    if (sscanf(ip_str, "%u.%u.%u.%u", &ip_parts[0], &ip_parts[1], &ip_parts[2], &ip_parts[3]) != 4) {
        return 0;
    }

    if (sscanf(mask_str, "%u.%u.%u.%u", &mask_parts[0], &mask_parts[1], &mask_parts[2], &mask_parts[3]) != 4) {
        return 0;
    }

    for (i = 0; i < 4; i++) {
        if (ip_parts[i] > 255 || mask_parts[i] > 255) {
            return 0;
        }
    }

    ip_mask->ip = (ip_parts[0] << 24) | (ip_parts[1] << 16) | (ip_parts[2] << 8) | ip_parts[3];
    ip_mask->mask = (mask_parts[0] << 24) | (mask_parts[1] << 16) | (mask_parts[2] << 8) | mask_parts[3];

    return 1;
}

int count_ones(unsigned int mask) {
    int count = 0;
    while (mask) {
        mask &= mask - 1;
        count++;
    }
    return count;
}