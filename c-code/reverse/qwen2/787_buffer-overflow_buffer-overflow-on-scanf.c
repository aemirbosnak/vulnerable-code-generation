#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>

void printSubnetDetails(char *ip) {
    struct in_addr addr;
    if (inet_pton(AF_INET, ip, &addr) <= 0) {
        printf("Invalid IP address\n");
        return;
    }

    unsigned int ipInt = ntohl(addr.s_addr);
    unsigned char octets[4];
    octets[0] = (ipInt >> 24) & 0xFF;
    octets[1] = (ipInt >> 16) & 0xFF;
    octets[2] = (ipInt >> 8) & 0xFF;
    octets[3] = ipInt & 0xFF;

    printf("IP Address: %d.%d.%d.%d\n", octets[0], octets[1], octets[2], octets[3]);
}

int main() {
    char ip[16];
    printf("Enter an IP address: ");
    fgets(ip, sizeof(ip), stdin);

    // Remove newline character if present
    size_t len = strlen(ip);
    if (len > 0 && ip[len - 1] == '\n') {
        ip[len - 1] = '\0';
    }

    printSubnetDetails(ip);

    return 0;
}
