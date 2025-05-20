#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

void printBinary(unsigned int num) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP Address> <Subnet Mask>\n", argv[0]);
        return 1;
    }

    struct in_addr ipAddr, subnetMask, broadcastAddr;

    if (inet_pton(AF_INET, argv[1], &ipAddr) <= 0 || inet_pton(AF_INET, argv[2], &subnetMask) <= 0) {
        fprintf(stderr, "Invalid IP address or subnet mask format.\n");
        return 1;
    }

    broadcastAddr.s_addr = ipAddr.s_addr | (~subnetMask.s_addr);

    printf("IP Address: ");
    printBinary(ntohl(ipAddr.s_addr));
    printf("\n");

    printf("Subnet Mask: ");
    printBinary(ntohl(subnetMask.s_addr));
    printf("\n");

    printf("Broadcast Address: ");
    printBinary(ntohl(broadcastAddr.s_addr));
    printf("\n");

    return 0;
}
