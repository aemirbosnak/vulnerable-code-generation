//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IPV4_LENGTH 4
#define SUBNET_MASK_MAX_LENGTH 32

void parse_ip(const char *ip_str, unsigned char *ip);
void parse_subnet(const char *subnet_str, unsigned char *subnet);
void calculate_network_broadcast(const unsigned char *ip, const unsigned char *subnet, 
                                  unsigned char *network, unsigned char *broadcast);
void display_results(const unsigned char *ip, const unsigned char *subnet,
                     const unsigned char *network, const unsigned char *broadcast);

int main() {
    char ip_str[16], subnet_str[SUBNET_MASK_MAX_LENGTH];
    unsigned char ip[IPV4_LENGTH], subnet[IPV4_LENGTH];
    unsigned char network[IPV4_LENGTH], broadcast[IPV4_LENGTH];

    // Input IP Address
    printf("Enter an IP address (e.g., 192.168.1.1): ");
    scanf("%15s", ip_str);
    
    // Input Subnet Mask
    printf("Enter a subnet mask (e.g., 255.255.255.0): ");
    scanf("%31s", subnet_str);

    // Parse IP address
    parse_ip(ip_str, ip);
    // Parse Subnet mask
    parse_subnet(subnet_str, subnet);

    // Calculate Network and Broadcast addresses
    calculate_network_broadcast(ip, subnet, network, broadcast);

    // Display the results
    display_results(ip, subnet, network, broadcast);

    return 0;
}

void parse_ip(const char *ip_str, unsigned char *ip) {
    int parts[IPV4_LENGTH];
    sscanf(ip_str, "%d.%d.%d.%d", &parts[0], &parts[1], &parts[2], &parts[3]);
    for (int i = 0; i < IPV4_LENGTH; i++) {
        ip[i] = (unsigned char)parts[i];
    }
}

void parse_subnet(const char *subnet_str, unsigned char *subnet) {
    int parts[IPV4_LENGTH];
    sscanf(subnet_str, "%d.%d.%d.%d", &parts[0], &parts[1], &parts[2], &parts[3]);
    for (int i = 0; i < IPV4_LENGTH; i++) {
        subnet[i] = (unsigned char)parts[i];
    }
}

void calculate_network_broadcast(const unsigned char *ip, const unsigned char *subnet,
                                  unsigned char *network, unsigned char *broadcast) {
    // Calculate Network Address
    for (int i = 0; i < IPV4_LENGTH; i++) {
        network[i] = ip[i] & subnet[i];
    }

    // Calculate Broadcast Address
    for (int i = 0; i < IPV4_LENGTH; i++) {
        broadcast[i] = network[i] | (~subnet[i] & 0xFF);
    }
}

void display_results(const unsigned char *ip, const unsigned char *subnet,
                     const unsigned char *network, const unsigned char *broadcast) {
    printf("\nResults:\n");
    printf("IP Address: %d.%d.%d.%d\n", ip[0], ip[1], ip[2], ip[3]);
    printf("Subnet Mask: %d.%d.%d.%d\n", subnet[0], subnet[1], subnet[2], subnet[3]);
    printf("Network Address: %d.%d.%d.%d\n", network[0], network[1], network[2], network[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n", broadcast[0], broadcast[1], broadcast[2], broadcast[3]);
    printf("Valid Host IP Range: %d.%d.%d.%d - %d.%d.%d.%d\n",
           network[0], network[1], network[2], network[3] + 1,
           broadcast[0], broadcast[1], broadcast[2], broadcast[3] - 1);
}