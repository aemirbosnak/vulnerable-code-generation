#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <arpa/inet.h>

int main() {
    char ip[16], subnet[16];
    unsigned int ip_int, subnet_int;
    struct in_addr addr;

    printf("Enter IP Address: ");
    scanf("%s", ip);
    printf("Enter Subnet Mask: ");
    scanf("%s", subnet);

    if (inet_pton(AF_INET, ip, &addr) != 1 || inet_pton(AF_INET, subnet, &addr) != 1) {
        printf("Invalid IP or Subnet Mask\n");
        return 1;
    }

    ip_int = ntohl(addr.s_addr);
    subnet_int = ntohl(addr.s_addr);

    unsigned int network_address = ip_int & subnet_int;
    unsigned int broadcast_address = network_address | (~subnet_int);
    unsigned int num_hosts = (1 << (32 - __builtin_popcount(subnet_int))) - 2;

    printf("Network Address: %s\n", inet_ntoa(*(struct in_addr *)&network_address));
    printf("Broadcast Address: %s\n", inet_ntoa(*(struct in_addr *)&broadcast_address));
    printf("Number of Hosts: %u\n", num_hosts);

    return 0;
}
