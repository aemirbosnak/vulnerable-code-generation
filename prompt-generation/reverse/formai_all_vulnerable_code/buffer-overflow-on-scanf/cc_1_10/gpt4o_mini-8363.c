//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_INPUT_SIZE 20
#define MAX_SUBNET_SIZE 20

void displaySubnetInfo(const char *ip, const char *subnetMask, const char *networkAddress, const char *broadcastAddress);
void calculateSubnet(const char *ip, const char *subnetMask, char *networkAddress, char *broadcastAddress);
int validateIP(const char *ip);
int validateSubnetMask(const char *subnetMask);
void getUserInput(char *ip, char *subnetMask);

int main() {
    char ip[MAX_INPUT_SIZE];
    char subnetMask[MAX_SUBNET_SIZE];
    char networkAddress[MAX_INPUT_SIZE];
    char broadcastAddress[MAX_INPUT_SIZE];

    printf("Welcome to the C Subnet Calculator!\n");
    printf("Please enter the IP address (e.g., 192.168.1.1) and subnet mask (e.g., 255.255.255.0):\n");

    getUserInput(ip, subnetMask);

    if (validateIP(ip) && validateSubnetMask(subnetMask)) {
        calculateSubnet(ip, subnetMask, networkAddress, broadcastAddress);
        displaySubnetInfo(ip, subnetMask, networkAddress, broadcastAddress);
    } else {
        printf("Invalid IP address or subnet mask. Please try again.\n");
    }

    return 0;
}

void getUserInput(char *ip, char *subnetMask) {
    printf("IP Address: ");
    scanf("%s", ip);
    
    printf("Subnet Mask: ");
    scanf("%s", subnetMask);
}

int validateIP(const char *ip) {
    struct sockaddr_in sa;
    return inet_pton(AF_INET, ip, &(sa.sin_addr)) != 0;
}

int validateSubnetMask(const char *subnetMask) {
    // Check if it is a valid subnet mask
    struct sockaddr_in sa;
    if (inet_pton(AF_INET, subnetMask, &(sa.sin_addr)) == 0) {
        return 0;
    }

    unsigned int mask;
    inet_pton(AF_INET, subnetMask, &mask);
    int consecutiveOnes = 0;
    int foundZero = 0;

    for (int i = 31; i >= 0; i--) {
        if ((mask >> i) & 1) { 
            consecutiveOnes++;
        } else {
            foundZero = 1; 
        }

        if (foundZero && ((mask >> i) & 1)) {
            return 0; 
        }
    }

    return 1; 
}

void calculateSubnet(const char *ip, const char *subnetMask, char *networkAddress, char *broadcastAddress) {
    unsigned char ipParts[4], maskParts[4], networkParts[4], broadcastParts[4];

    sscanf(ip, "%hhu.%hhu.%hhu.%hhu", &ipParts[0], &ipParts[1], &ipParts[2], &ipParts[3]);
    sscanf(subnetMask, "%hhu.%hhu.%hhu.%hhu", &maskParts[0], &maskParts[1], &maskParts[2], &maskParts[3]);

    for (int i = 0; i < 4; i++) {
        networkParts[i] = ipParts[i] & maskParts[i];
        broadcastParts[i] = networkParts[i] | (~maskParts[i] & 0xFF);
    }

    sprintf(networkAddress, "%d.%d.%d.%d", networkParts[0], networkParts[1], networkParts[2], networkParts[3]);
    sprintf(broadcastAddress, "%d.%d.%d.%d", broadcastParts[0], broadcastParts[1], broadcastParts[2], broadcastParts[3]);
}

void displaySubnetInfo(const char *ip, const char *subnetMask, const char *networkAddress, const char *broadcastAddress) {
    printf("\n--- Subnet Information ---\n");
    printf("IP Address:         %s\n", ip);
    printf("Subnet Mask:       %s\n", subnetMask);
    printf("Network Address:    %s\n", networkAddress);
    printf("Broadcast Address:  %s\n", broadcastAddress);
    printf("-------------------------\n");
}