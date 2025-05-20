#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s IP_ADDRESS SUBNET_MASK\n", argv[0]);
        return 1;
    }

    char ip[32], mask[16];
    sscanf(argv[1], "%s", ip);
    sscanf(argv[2], "%s", mask);

    unsigned int ip_num = inet_addr(ip);
    unsigned int mask_num = inet_addr(mask);

    unsigned int network, broadcast;
    network = ip_num & mask_num;
    broadcast = network | ~mask_num;

    char network_str[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &network, network_str, INET_ADDRSTRLEN);
    char broadcast_str[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &broadcast, broadcast_str, INET_ADDRSTRLEN);

    printf("Network Address: %s\n", network_str);
    printf("Broadcast Address: %s\n", broadcast_str);

    return 0;
}
