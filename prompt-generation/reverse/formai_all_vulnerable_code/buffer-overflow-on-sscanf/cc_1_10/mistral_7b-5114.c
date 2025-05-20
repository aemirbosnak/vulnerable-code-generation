//MISTRAL-7B DATASET v1.0 Category: Subnet Calculator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <IP_ADDRESS> <SUBNET_SIZE>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Parse IP address and subnet size from command line arguments
    char ip_str[INET_ADDRSTRLEN];
    int subnet_size;

    if (inet_pton(AF_INET, argv[1], &((struct in_addr){.s_addr = htonl(INADDR_ANY)})) <= 0 ||
        sscanf(argv[3], "%d", &subnet_size) != 1) {
        error("Invalid arguments\n");
    }

    // Parse IP address to binary form
    int ip[4];
    char ip_bin[16][9];

    memset(ip, 0, sizeof ip);
    sscanf(ip_str, "%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);

    for (int i = 0; i < 4; ++i) {
        int byte = ip[i];
        for (int j = 0; j < 8; ++j) {
            int bit = (byte >> j) & 1;
            sprintf(ip_bin[i], "%s%d", bit ? "1" : "0", j < 7 ? 1 : 0);
        }
    }

    // Calculate subnet mask
    int mask_bits = 32 - subnet_size;
    int mask[4];
    char mask_bin[16][9];

    memset(mask, 0xFF, sizeof mask);
    memset(mask_bin, "1", sizeof mask_bin * 4 * 8);

    for (int i = 0; i < mask_bits; ++i) {
        mask[3 - (i / 8)] &= ~(1 << (7 - (i % 8)));
        mask_bin[3 - (i / 8)][7 - (i % 8)] = '0';
    }

    // Print results
    printf("IP address: %s\n", ip_str);
    printf("Subnet size: %d\n", subnet_size);
    printf("Subnet mask: ");

    for (int i = 0; i < 4; ++i) {
        printf("%s.", ip_bin[i]);
        for (int j = 0; j < 8; ++j) {
            printf("%s", mask_bin[i][j]);
        }
    }
    printf("\n");
    printf("Broadcast address: ");

    for (int i = 0; i < 4; ++i) {
        int byte = ip[i] + mask[i] & ~mask[i];
        for (int j = 0; j < 8; ++j) {
            int bit = (byte >> j) & 1;
            printf("%s", bit ? "1" : "0");
        }
        printf(".");
    }

    return EXIT_SUCCESS;
}