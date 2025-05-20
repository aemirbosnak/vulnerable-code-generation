//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_ADDRS 10

void subnet_calc(char ip[], char mask[]);
void validate_ip_addr(char ip[]);
void validate_subnet_mask(char mask[]);

int main() {
    char ip[MAX_ADDRS][16], mask[MAX_ADDRS][16];
    int num_addrs, i;

    printf("Enter the number of IP addresses you want to calculate for (up to %d): ", MAX_ADDRS);
    scanf("%d", &num_addrs);

    for (i = 0; i < num_addrs; i++) {
        printf("\nEnter IP address #%d: ", i+1);
        scanf("%s", ip[i]);
        validate_ip_addr(ip[i]);

        printf("Enter subnet mask #%d: ", i+1);
        scanf("%s", mask[i]);
        validate_subnet_mask(mask[i]);
    }

    printf("\n%-18s%-18s%-18s%-18s%-18s\n", "IP Address", "Subnet Mask", "Network ID", "Broadcast ID", "Hosts / Network");

    for (i = 0; i < num_addrs; i++) {
        subnet_calc(ip[i], mask[i]);
    }

    return 0;
}

void subnet_calc(char ip[], char mask[]) {
    uint32_t prefix, subnet_mask, network_id, broadcast_id, num_hosts;
    char binary_mask[33], binary_ip[33], binary_network[33], binary_broadcast[33], network[16], broadcast[16];

    inet_pton(AF_INET, ip, &prefix); // convert IP address to binary
    subnet_mask = 0xffffffff << (32 - atoi(mask)); // calculate subnet mask in binary
    network_id = prefix & subnet_mask; // calculate network ID in binary
    broadcast_id = network_id | (~subnet_mask & 0xffffffff); // calculate broadcast ID in binary
    num_hosts = pow(2, 32 - atoi(mask)) - 2; // calculate number of hosts per network

    sprintf(binary_mask, "%s", inet_ntoa(*(struct in_addr*)&subnet_mask)); // convert mask to dotted decimal notation
    sprintf(binary_ip, "%s", inet_ntoa(*(struct in_addr*)&prefix)); // convert IP address to dotted decimal notation
    sprintf(binary_network, "%s", inet_ntoa(*(struct in_addr*)&network_id)); // convert network ID to dotted decimal notation
    sprintf(binary_broadcast, "%s", inet_ntoa(*(struct in_addr*)&broadcast_id)); // convert broadcast ID to dotted decimal notation
    sprintf(network, "%s/%s", binary_network, mask); // create network/mask pair
    sprintf(broadcast, "%s/%s", binary_broadcast, mask); // create broadcast/mask pair

    printf("%-18s%-18s%-18s%-18s%-18u\n", binary_ip, binary_mask, network, broadcast, num_hosts);
}

void validate_ip_addr(char ip[]) {
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, ip, &(sa.sin_addr));
    if (result == 0) {
        printf("Invalid IP address entered, exiting...\n");
        exit(1);
    }
}

void validate_subnet_mask(char mask[]) {
    int result = atoi(mask);
    if (result < 0 || result > 32) {
        printf("Invalid subnet mask entered, exiting...\n");
        exit(1);
    }
}