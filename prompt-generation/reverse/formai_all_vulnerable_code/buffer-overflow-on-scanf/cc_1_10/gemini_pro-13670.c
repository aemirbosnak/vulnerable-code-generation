//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_IP_LEN 16
#define MAX_SUBNET_LEN 8

// Data structure to store IP address and subnet mask
typedef struct {
    unsigned char ip[4];
    unsigned char subnet[4];
} IPSubnet;

// Function to check if the IP address is valid
int isValidIP(char *ip) {
    int octets = 0;
    char *token = strtok(ip, ".");
    while (token) {
        int octet = atoi(token);
        if (octet < 0 || octet > 255) {
            return 0;
        }
        octets++;
        token = strtok(NULL, ".");
    }
    return octets == 4;
}

// Function to convert IP address string to IPSubnet struct
IPSubnet ipSubnetFromString(char *ip, char *subnet) {
    IPSubnet ipSubnet;
    char *token;

    // Convert IP address to octets
    token = strtok(ip, ".");
    for (int i = 0; i < 4; i++) {
        ipSubnet.ip[i] = atoi(token);
        token = strtok(NULL, ".");
    }

    // Convert subnet mask to octets
    token = strtok(subnet, ".");
    for (int i = 0; i < 4; i++) {
        ipSubnet.subnet[i] = atoi(token);
        token = strtok(NULL, ".");
    }

    return ipSubnet;
}

// Function to calculate the network address
void calculateNetworkAddress(IPSubnet *ipSubnet) {
    for (int i = 0; i < 4; i++) {
        ipSubnet->ip[i] &= ipSubnet->subnet[i];
    }
}

// Function to calculate the broadcast address
void calculateBroadcastAddress(IPSubnet *ipSubnet) {
    for (int i = 0; i < 4; i++) {
        ipSubnet->ip[i] |= ~ipSubnet->subnet[i];
    }
}

// Function to calculate the number of hosts
int calculateNumberOfHosts(IPSubnet *ipSubnet) {
    int numHosts = 0;
    for (int i = 0; i < 4; i++) {
        numHosts += (ipSubnet->subnet[i] ^ 255);
    }
    return numHosts + 1;
}

// Function to calculate the wildcard mask
void calculateWildcardMask(IPSubnet *ipSubnet) {
    for (int i = 0; i < 4; i++) {
        ipSubnet->subnet[i] = ~ipSubnet->subnet[i];
    }
}

// Function to print the IPSubnet struct
void printIPSubnet(IPSubnet *ipSubnet) {
    printf("IP Address: %d.%d.%d.%d\n", ipSubnet->ip[0], ipSubnet->ip[1], ipSubnet->ip[2], ipSubnet->ip[3]);
    printf("Subnet Mask: %d.%d.%d.%d\n", ipSubnet->subnet[0], ipSubnet->subnet[1], ipSubnet->subnet[2], ipSubnet->subnet[3]);
    printf("Network Address: %d.%d.%d.%d\n", ipSubnet->ip[0] & ipSubnet->subnet[0], ipSubnet->ip[1] & ipSubnet->subnet[1], ipSubnet->ip[2] & ipSubnet->subnet[2], ipSubnet->ip[3] & ipSubnet->subnet[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n", ipSubnet->ip[0] | ~ipSubnet->subnet[0], ipSubnet->ip[1] | ~ipSubnet->subnet[1], ipSubnet->ip[2] | ~ipSubnet->subnet[2], ipSubnet->ip[3] | ~ipSubnet->subnet[3]);
    printf("Number of Hosts: %d\n", calculateNumberOfHosts(ipSubnet));
    printf("Wildcard Mask: %d.%d.%d.%d\n", ~ipSubnet->subnet[0], ~ipSubnet->subnet[1], ~ipSubnet->subnet[2], ~ipSubnet->subnet[3]);
}

int main() {
    char ip[MAX_IP_LEN];
    char subnet[MAX_SUBNET_LEN];

    // Get IP address and subnet mask from the user
    printf("Enter IP address: ");
    scanf("%s", ip);
    printf("Enter subnet mask: ");
    scanf("%s", subnet);

    // Check if the IP address and subnet mask are valid
    if (!isValidIP(ip) || !isValidIP(subnet)) {
        printf("Invalid IP address or subnet mask\n");
        return 1;
    }

    // Convert IP address and subnet mask to IPSubnet struct
    IPSubnet ipSubnet = ipSubnetFromString(ip, subnet);

    // Calculate the network address, broadcast address, and number of hosts
    calculateNetworkAddress(&ipSubnet);
    calculateBroadcastAddress(&ipSubnet);
    calculateWildcardMask(&ipSubnet);

    // Print the IPSubnet struct
    printIPSubnet(&ipSubnet);

    return 0;
}