#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    uint32_t ip, mask, broadcast;

    if (argc != 3) {
        printf("Usage: %s IP_ADDRESS SUBNET_MASK\n", argv[0]);
        return 1;
    }

    if (sscanf(argv[1], "%hhu.%hhu.%hhu.%hhu", &ip, &ip, &ip, &ip) != 4 ||
        sscanf(argv[2], "%hhu.%hhu.%hhu.%hhu", &mask, &mask, &mask, &mask) != 4) {
        printf("Invalid IP address or subnet mask format\n");
        return 1;
    }

    broadcast = htonl(ip | ~(uint32_t)(mask << 32) | ((uint32_t)(ip & mask) << 32));
    printf("Broadcast address in binary: %s\n", inet_ntoa(*(struct in_addr *)&broadcast));

    return 0;
}
