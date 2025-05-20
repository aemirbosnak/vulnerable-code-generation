#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

void ipv4_to_binary(const char *ip) {
    unsigned char octets[4];
    inet_pton(AF_INET, ip, octets);

    for (int i = 0; i < 4; ++i) {
        printf("%08b", octets[i]);
        if (i < 3)
            printf(".");
    }

    if (inet_pton(AF_INET, ip, octets) == 0 ||
        (octets[0] < 0 || octets[0] > 255) ||
        (octets[1] < 0 || octets[1] > 255) ||
        (octets[2] < 0 || octets[2] > 255) ||
        (octets[3] < 0 || octets[3] > 255)) {
        printf("Invalid IPv4 address\n");
    }
}

int main() {
    char ip[INET_ADDRSTRLEN];
    printf("Enter an IPv4 address: ");
    fgets(ip, sizeof(ip), stdin);

    ipv4_to_binary(ip);

    return 0;
}
