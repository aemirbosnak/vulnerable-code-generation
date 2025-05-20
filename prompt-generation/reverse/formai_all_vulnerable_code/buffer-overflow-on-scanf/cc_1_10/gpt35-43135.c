//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// function to calculate network address
char* calculate_network_address(char* ip_address, char* subnet_mask) {
    struct in_addr addr_ip, addr_subnet, addr_network;
    inet_aton(ip_address, &addr_ip);
    inet_aton(subnet_mask, &addr_subnet);
    addr_network.s_addr = addr_ip.s_addr & addr_subnet.s_addr;
    return inet_ntoa(addr_network);
}

// function to calculate broadcast address
char* calculate_broadcast_address(char* ip_address, char* subnet_mask) {
    struct in_addr addr_ip, addr_subnet, addr_broadcast;
    inet_aton(ip_address, &addr_ip);
    inet_aton(subnet_mask, &addr_subnet);
    addr_broadcast.s_addr = addr_ip.s_addr | ~addr_subnet.s_addr;
    return inet_ntoa(addr_broadcast);
}

// function to calculate number of hosts
int calculate_number_of_hosts(char* subnet_mask) {
    struct in_addr addr_subnet;
    inet_aton(subnet_mask, &addr_subnet);
    return ~addr_subnet.s_addr;
}

int main() {
    char ip_address[16], subnet_mask_str[16];
    int subnet_mask_len, num_of_hosts;
    char *network_address, *broadcast_address;

    // get user input for IP address and subnet mask
    printf("Enter IP Address: ");
    scanf("%s", ip_address);
    printf("Enter Subnet Mask: ");
    scanf("%s", subnet_mask_str);

    // calculate network address
    network_address = calculate_network_address(ip_address, subnet_mask_str);
    printf("\nNetwork Address: %s\n", network_address);

    // calculate broadcast address
    broadcast_address = calculate_broadcast_address(ip_address, subnet_mask_str);
    printf("Broadcast Address: %s\n", broadcast_address);

    // calculate number of hosts
    subnet_mask_len = atoi(strrchr(subnet_mask_str, '.')+1);
    num_of_hosts = calculate_number_of_hosts(subnet_mask_str);
    printf("Number of Hosts: %d\n", num_of_hosts);

    return 0;
}