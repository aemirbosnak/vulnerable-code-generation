//MISTRAL-7B DATASET v1.0 Category: Subnet Calculator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define IP_SIZE 15
#define MASK_SIZE 5
#define BROADCAST_SIZE IP_SIZE

typedef struct {
    uint8_t ip[IP_SIZE];
    uint8_t mask[MASK_SIZE];
    uint8_t broadcast[BROADCAST_SIZE];
} SubnetInfo;

void binary_to_decimal(uint8_t bin[8], uint8_t dec[4]) {
    int i, j, k;
    uint32_t num = 0;

    for (i = 0; i < 4; i++) {
        dec[i] = 0;
        for (j = 0; j < 8; j++) {
            num <<= 1;
            if (bin[3 - i] & (1 << (7 - j)))
                num += 1;
        }
        dec[i] += num;
        num = 0;
    }
}

void ip_to_binary(uint8_t ip[IP_SIZE], uint8_t bin[IP_SIZE * 8]) {
    int i, j, k;

    for (i = 0; i < IP_SIZE; i++) {
        for (j = 0; j < 8; j++) {
            k = i * 8 + j;
            bin[k] = ip[i] >> j & 1;
        }
    }
}

void subnet_info(uint8_t ip[IP_SIZE]) {
    SubnetInfo info;
    uint8_t mask[MASK_SIZE], bin[IP_SIZE * 8], broadcast[BROADCAST_SIZE];
    uint8_t dec_mask[4];

    memcpy(info.ip, ip, IP_SIZE);

    // Set subnet mask bits to 1
    memset(mask, 255, MASK_SIZE);
    mask[0] = 0;

    ip_to_binary(ip, bin);
    ip_to_binary((uint8_t[]) { 1, 1, 1, 0 }, bin + IP_SIZE * 8); // Add broadcast address binary representation

    binary_to_decimal(mask, dec_mask);

    // Apply subnet mask to IP
    for (int i = 0; i < MASK_SIZE; i++)
        info.ip[i] &= mask[i];

    // Calculate subnet address
    for (int i = 0; i < MASK_SIZE; i++)
        info.ip[i] |= dec_mask[i] < dec_mask[i + 1] ? dec_mask[i + 1] >> (8 - (i + 1)) & 0xF8 : 0;

    // Calculate broadcast address
    for (int i = 0; i < BROADCAST_SIZE; i++) {
        info.broadcast[i] = info.ip[i] | ~(uint8_t)mask[i];
    }

    printf("IP Address: ");
    for (int i = 0; i < IP_SIZE; i++)
        printf("%d.", ip[i]);
    printf("\nSubnet Mask: ");
    for (int i = 0; i < MASK_SIZE; i++)
        printf("%d.", mask[i]);
    printf("\nSubnet Address: ");
    for (int i = 0; i < IP_SIZE; i++)
        printf("%d.", info.ip[i]);
    printf("\nBroadcast Address: ");
    for (int i = 0; i < BROADCAST_SIZE; i++)
        printf("%d.", info.broadcast[i]);
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <IPv4 address in dotted decimal format>\n", argv[0]);
        return 1;
    }

    uint8_t ip[IP_SIZE];
    sscanf(argv[1], "%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);

    subnet_info(ip);

    return 0;
}