//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct IPAddress {
    int octet1;
    int octet2;
    int octet3;
    int octet4;
};

struct Subnet {
    int mask;
    int bits;
};

void print_IPAddress(struct IPAddress ip_addr) {
    printf("%d.%d.%d.%d", ip_addr.octet1, ip_addr.octet2, ip_addr.octet3, ip_addr.octet4);
}

void print_Subnet(struct Subnet subnet) {
    printf("/%d", subnet.bits);
}

struct IPAddress get_IPAddress_from_input(char* input) {
    struct IPAddress ip_addr;
    char* octets_str[4];
    int i = 0;

    octets_str[0] = strtok(input, ".");
    for (i = 1; i < 4; i++) {
        octets_str[i] = strtok(NULL, ".");
    }

    ip_addr.octet1 = atoi(octets_str[0]);
    ip_addr.octet2 = atoi(octets_str[1]);
    ip_addr.octet3 = atoi(octets_str[2]);
    ip_addr.octet4 = atoi(octets_str[3]);

    return ip_addr;
}

struct Subnet get_subnet_from_input(char* input) {
    struct Subnet subnet;
    char* mask_str = strtok(input, "/");
    char* bits_str = strtok(NULL, "/");

    subnet.mask = atoi(mask_str);
    subnet.bits = atoi(bits_str);

    return subnet;
}

struct IPAddress calculate_network_address(struct IPAddress ip_addr, struct Subnet subnet) {
    struct IPAddress network_addr;

    int mask = subnet.mask;
    int bits = subnet.bits;

    int net_octet1 = ip_addr.octet1 & (0xFF << (8 - bits));
    int net_octet2 = ip_addr.octet2 & (0xFF << (8 - bits % 8));
    int net_octet3 = ip_addr.octet3 & (0xFF << (8 - bits % 8));
    int net_octet4 = ip_addr.octet4 & (0xFF << (8 - bits % 8));

    network_addr.octet1 = net_octet1 & (0xFF << (bits >= 8 ? 0 : 8 - bits));
    network_addr.octet2 = net_octet2 & (0xFF << (bits >= 8 ? bits - 8 : 0));
    network_addr.octet3 = net_octet3 & (0xFF << (bits >= 16 ? bits - 16 : 0));
    network_addr.octet4 = net_octet4 & (0xFF << (bits >= 24 ? bits - 24 : 0));

    return network_addr;
}

void print_network_address(struct IPAddress network_addr) {
    print_IPAddress(network_addr);
    printf("\n");
}

struct IPAddress calculate_broadcast_address(struct IPAddress network_addr, struct Subnet subnet) {
    struct IPAddress broadcast_addr;
    int bits = subnet.bits;

    int bcast_octet1 = network_addr.octet1 | ~(0xFF << (8 - bits));
    int bcast_octet2 = network_addr.octet2 | ~(0xFF << (bits >= 8 ? bits - 8 : 0));
    int bcast_octet3 = network_addr.octet3 | ~(0xFF << (bits >= 16 ? bits - 16 : 0));
    int bcast_octet4 = network_addr.octet4 | ~(0xFF << (bits >= 24 ? bits - 24 : 0));

    broadcast_addr.octet1 = bcast_octet1;
    broadcast_addr.octet2 = bcast_octet2;
    broadcast_addr.octet3 = bcast_octet3;
    broadcast_addr.octet4 = bcast_octet4;

    return broadcast_addr;
}

void print_broadcast_address(struct IPAddress broadcast_addr) {
    print_IPAddress(broadcast_addr);
    printf("\n");
}

int main() {
    char ip_addr_input[15];
    char subnet_input[4];
    struct IPAddress ip_addr;
    struct Subnet subnet;
    struct IPAddress network_addr;
    struct IPAddress broadcast_addr;

    printf("Please enter an IP address: ");
    scanf("%s", ip_addr_input);
    fflush(stdin);
    ip_addr = get_IPAddress_from_input(ip_addr_input);

    printf("Please enter a subnet: ");
    scanf("%s", subnet_input);
    fflush(stdin);
    subnet = get_subnet_from_input(subnet_input);

    network_addr = calculate_network_address(ip_addr, subnet);
    printf("Network Address: ");
    print_network_address(network_addr);

    broadcast_addr = calculate_broadcast_address(network_addr, subnet);
    printf("Broadcast Address: ");
    print_broadcast_address(broadcast_addr);

    return 0;
}