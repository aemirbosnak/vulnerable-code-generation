//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MIN_IP "0.0.0.0"
#define MAX_IP "255.255.255.255"
#define MAX_CIDR 32

struct subnet {
    char ip[INET_ADDRSTRLEN];
    char mask[INET_ADDRSTRLEN];
    char broadcast[INET_ADDRSTRLEN];
    char network[INET_ADDRSTRLEN];
};

int validate_ip(char *ip) {
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, ip, &(sa.sin_addr));
    return result != 0;
}

struct subnet calculate_subnet(char *ip, int mask) {
    struct subnet s;
    struct in_addr addr;
    inet_pton(AF_INET, ip, &addr);

    struct in_addr mask_addr = { .s_addr = htonl(~(0xffffffff >> mask)) };
    struct in_addr network_addr = { .s_addr = addr.s_addr & mask_addr.s_addr };
    struct in_addr broadcast_addr = { .s_addr = network_addr.s_addr | ~mask_addr.s_addr };

    strncpy(s.ip, ip, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &mask_addr, s.mask, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &broadcast_addr, s.broadcast, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &network_addr, s.network, INET_ADDRSTRLEN);

    return s;
}

void print_subnet(struct subnet s) {
    printf("IP Address: %s\n", s.ip);
    printf("Netmask: %s\n", s.mask);
    printf("Network Address: %s\n", s.network);
    printf("Broadcast Address: %s\n", s.broadcast);
    printf("\n");
}

int main(int argc, char **argv) {
    int cidr_mask;
    char user_ip[INET_ADDRSTRLEN];

    printf("Enter an IP address from %s to %s: ", MIN_IP, MAX_IP);
    fgets(user_ip, INET_ADDRSTRLEN, stdin);
    user_ip[strcspn(user_ip, "\n")] = '\0';

    if (!validate_ip(user_ip)) {
        printf("Invalid IP address\n");
        exit(1);
    }

    printf("Enter a CIDR mask between 1 and %d: ", MAX_CIDR);
    scanf("%d", &cidr_mask);

    if (cidr_mask < 1 || cidr_mask > MAX_CIDR) {
        printf("Invalid CIDR mask\n");
        exit(1);
    }

    struct subnet s = calculate_subnet(user_ip, cidr_mask);
    print_subnet(s);

    return 0;
}