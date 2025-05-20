#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s IP_ADDRESS SUBNET_MASK\n", argv[0]);
        return 1;
    }

    uint32_t ip = inet_addr(argv[1]);
    uint32_t mask = inet_addr(argv[2]);

    uint32_t net = ip & mask;
    uint32_t broadcast = net | ~mask;

    printf("Broadcast Address: %s\n", inet_ntoa(*(struct in_addr *)&broadcast));
    return 0;
}
