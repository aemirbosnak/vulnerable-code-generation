//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_LEN 16
#define MAX_SUBNET_LEN 3

void display_usage() {
    printf("Usage: ./subnet_calculator <IP_addr> <Subnet_mask>\n");
    printf("Example: ./subnet_calculator 192.168.1.1 255.255.255.0\n");
}

void parse_ip(const char *ip_str, unsigned char ip[4]) {
    sscanf(ip_str, "%hhu.%hhu.%hhu.%hhu", &ip[0], &ip[1], &ip[2], &ip[3]);
}

void parse_subnet(const char *subnet_str, unsigned char subnet[4]) {
    sscanf(subnet_str, "%hhu.%hhu.%hhu.%hhu", &subnet[0], &subnet[1], &subnet[2], &subnet[3]);
}

void calculate_network(unsigned char ip[4], unsigned char subnet[4], unsigned char network[4]) {
    for (int i = 0; i < 4; i++) {
        network[i] = ip[i] & subnet[i];
    }
}

void calculate_broadcast(unsigned char network[4], unsigned char subnet[4], unsigned char broadcast[4]) {
    for (int i = 0; i < 4; i++) {
        broadcast[i] = network[i] | (~subnet[i] & 0xFF);
    }
}

void display_ip(unsigned char ip[4]) {
    printf("%hhu.%hhu.%hhu.%hhu", ip[0], ip[1], ip[2], ip[3]);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        display_usage();
        return 1;
    }

    unsigned char ip[4];
    unsigned char subnet[4];
    unsigned char network[4];
    unsigned char broadcast[4];

    parse_ip(argv[1], ip);
    parse_subnet(argv[2], subnet);

    calculate_network(ip, subnet, network);
    calculate_broadcast(network, subnet, broadcast);

    printf("IP Address: ");
    display_ip(ip);
    printf("\nSubnet Mask: ");
    display_ip(subnet);
    printf("\nNetwork Address: ");
    display_ip(network);
    printf("\nBroadcast Address: ");
    display_ip(broadcast);
    printf("\n");

    return 0;
}