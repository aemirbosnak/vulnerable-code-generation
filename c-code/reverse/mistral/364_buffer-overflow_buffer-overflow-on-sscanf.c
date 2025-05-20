#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    char ip[32], mask[16];
    int ip_int, mask_int, i, j;
    unsigned long broadcast;

    if (argc != 3) {
        printf("Usage: %s <IP_ADDRESS> <SUBNET_MASK>\n", argv[0]);
        return 1;
    }

    strcpy(ip, argv[1]);
    strcpy(mask, argv[2]);

    if (sscanf(ip, "%d.%d.%d.%d", &i, &j, &ip_int, &j) != 4 ||
        sscanf(mask, "%d.%d.%d.%d", &i, &j, &mask_int, &j) != 4) {
        printf("Invalid IP or Subnet Mask format.\n");
        return 1;
    }

    broadcast = (ip_int & mask_int) | ~mask_int;

    printf("Broadcast Address: %lu.%lu.%lu.%lu\n",
           (broadcast >> 24) & 0xFF,
           (broadcast >> 16) & 0xFF,
           (broadcast >> 8) & 0xFF,
           broadcast & 0xFF);

    return 0;
}
