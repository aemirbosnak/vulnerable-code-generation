#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

void print_subnet(char *ip) {
    unsigned int ip_num = inet_addr(ip);
    unsigned int network, subnet_mask, subnet, broadcast;

    network = ip_num & 0xFFFFFF00;
    subnet_mask = 0xFFFFFF00;
    subnet = network >> 8;
    broadcast = subnet | ~subnet_mask;

    printf("IP Address: %s\n", ip);
    printf("Network Address: %s\n", inet_ntoa(*(struct in_addr*)&network));
    printf("Subnet Mask: %s\n", inet_ntoa(*(struct in_addr*)&subnet_mask));
    printf("Subnet: %s\n", inet_ntoa(*(struct in_addr*)&subnet));
    printf("Broadcast: %s\n", inet_ntoa(*(struct in_addr*)&broadcast));
}

int main() {
    char ip[256];
    printf("Enter IP address: ");
    scanf("%s", ip);
    print_subnet(ip);
    return 0;
}
