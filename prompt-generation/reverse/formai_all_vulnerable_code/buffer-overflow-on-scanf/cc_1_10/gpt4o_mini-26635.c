//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define IP_SIZE 16  // Max size of an IPv4 address string

// Function prototypes
void calculateSubnet(const char *ip, const char *subnet);
void printSubnetInfo(const char *network, const char *broadcast, int validHosts, const char *ipRange);
unsigned int convertIpToDecimal(const char *ip);
void convertDecimalToIp(unsigned int decimal, char *ip);

int main() {
    char ip[IP_SIZE];
    char subnet[IP_SIZE];

    printf("Welcome to the C Subnet Calculator!\n");
    printf("Please enter an IP address (e.g., 192.168.1.1): ");
    scanf("%s", ip);
    
    printf("Please enter a subnet mask (e.g., 255.255.255.0 or CIDR e.g. /24): ");
    scanf("%s", subnet);
    
    calculateSubnet(ip, subnet);
    
    return 0;
}

void calculateSubnet(const char *ip, const char *subnet) {
    struct in_addr ipAddr, subnetMask, networkAddr, broadcastAddr;
    
    // Convert IP address and subnet mask to binary form
    if (inet_pton(AF_INET, ip, &ipAddr) != 1) {
        fprintf(stderr, "Invalid IP address format.\n");
        return;
    }
    
    if (strchr(subnet, '/') != NULL) {
        int prefixLen = atoi(strchr(subnet, '/') + 1);
        unsigned int mask = (0xFFFFFFFF << (32 - prefixLen)) & 0xFFFFFFFF;
        subnetMask.s_addr = htonl(mask);
    } else {
        if (inet_pton(AF_INET, subnet, &subnetMask) != 1) {
            fprintf(stderr, "Invalid subnet mask format.\n");
            return;
        }
    }
    
    // Calculate Network address
    networkAddr.s_addr = ipAddr.s_addr & subnetMask.s_addr;
    
    // Calculate Broadcast address
    broadcastAddr.s_addr = networkAddr.s_addr | ~subnetMask.s_addr;
    
    int validHosts = (ntohl(broadcastAddr.s_addr) - ntohl(networkAddr.s_addr)) - 1;
    char ipRange[50];
    snprintf(ipRange, sizeof(ipRange), "%s - %s", 
             inet_ntoa((struct in_addr){htonl(ntohl(networkAddr.s_addr) + 1)}),
             inet_ntoa((struct in_addr){htonl(ntohl(broadcastAddr.s_addr) - 1)}));
    
    printSubnetInfo(inet_ntoa(networkAddr), inet_ntoa(broadcastAddr), validHosts, ipRange);
}

void printSubnetInfo(const char *network, const char *broadcast, int validHosts, const char *ipRange) {
    printf("\nSubnet Information:\n");
    printf("Network Address: %s\n", network);
    printf("Broadcast Address: %s\n", broadcast);
    printf("Number of Valid Hosts: %d\n", validHosts);
    printf("Valid IP Address Range: %s\n", ipRange);
}

unsigned int convertIpToDecimal(const char *ip) {
    unsigned int decimal = 0;
    int octet;
    char *ipCopy = strdup(ip);
    char *token = strtok(ipCopy, ".");
    while (token != NULL) {
        octet = atoi(token);
        decimal = (decimal << 8) | (octet & 0xFF);
        token = strtok(NULL, ".");
    }
    free(ipCopy);
    return decimal;
}

void convertDecimalToIp(unsigned int decimal, char *ip) {
    sprintf(ip, "%u.%u.%u.%u", 
            (decimal >> 24) & 0xFF,
            (decimal >> 16) & 0xFF,
            (decimal >> 8) & 0xFF,
            decimal & 0xFF);
}