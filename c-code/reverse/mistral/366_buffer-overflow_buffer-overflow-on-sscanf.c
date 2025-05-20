#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

void calculate_subnet(char *ip, char *mask) {
    uint32_t ip_num = inet_addr(ip);
    uint32_t mask_num = (1 << (32 - atoi(mask)));
    uint32_t network = ip_num & mask_num;
    printf("Network: %u\n", network);
}

int main(int argc, char *argv[]) {
    char ip[20], mask[6];

    if (argc != 3) {
        printf("Usage: %s <IP> <Subnet Mask>\n", argv[0]);
        return 1;
    }

    sscanf(argv[1], "%19s", ip);
    sscanf(argv[2], "%5s", mask);

    calculate_subnet(ip, mask);

    return 0;
}
