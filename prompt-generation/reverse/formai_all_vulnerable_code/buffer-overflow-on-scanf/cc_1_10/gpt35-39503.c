//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: secure
#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

// Constants
#define BITS_IN_BYTE 8

// Function to convert CIDR notation to netmask in dotted decimal format
void cidr_to_netmask(uint8_t cidr, char* netmask) {
    uint32_t mask = 0xffffffff << (32 - cidr);
    uint8_t* bytes = (uint8_t*)&mask;
    snprintf(netmask, 16, "%d.%d.%d.%d", bytes[0], bytes[1], bytes[2], bytes[3]);
}

// Function to calculate the number of available IP addresses in a subnet
uint32_t available_ips(uint8_t cidr) {
    return 1 << (32 - cidr);
}

// Function to calculate the network and broadcast addresses for a given IP address and CIDR notation
void network_and_broadcast(char* ip_address, uint8_t cidr, char* network, char* broadcast) {
    uint32_t ip = ntohl(inet_addr(ip_address));
    uint32_t mask = 0xffffffff << (32 - cidr);
    uint32_t network_ip = ip & mask;
    uint32_t broadcast_ip = network_ip | ~mask;
    struct in_addr addr_network = { .s_addr = htonl(network_ip) };
    struct in_addr addr_broadcast = { .s_addr = htonl(broadcast_ip) };
    snprintf(network, 16, "%s", inet_ntoa(addr_network));
    snprintf(broadcast, 16, "%s", inet_ntoa(addr_broadcast));
}

// Function to print the subnet information
void print_subnet_info(char* ip_address, uint8_t cidr) {
    char netmask[16];
    char network[16];
    char broadcast[16];
    cidr_to_netmask(cidr, netmask);
    network_and_broadcast(ip_address, cidr, network, broadcast);
    printf("\n================================================================\n");
    printf("Subnet information for %s/%d\n\n", ip_address, cidr);
    printf("Netmask:              %s\n", netmask);
    printf("Network address:      %s\n", network);
    printf("Broadcast address:    %s\n", broadcast);
    printf("Number of available IP addresses:  %u\n", available_ips(cidr));
    printf("================================================================\n");
}

int main() {
    char ip_address[16];
    uint8_t cidr;
    printf("Enter an IP address in dotted decimal format: ");
    scanf("%s", ip_address);
    printf("Enter the CIDR notation (0-32): ");
    scanf("%hhu", &cidr);
    print_subnet_info(ip_address, cidr);
    return 0;
}