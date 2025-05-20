//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to validate IP address
int validateIP(char *ip) {
    int i, j;
    char *token;
    if (strlen(ip)!= 15) {
        return 0;
    }
    token = strtok(ip, ".");
    for (i = 0; i < 4; i++) {
        if (token == NULL) {
            return 0;
        }
        if (atoi(token) < 0 || atoi(token) > 255) {
            return 0;
        }
        token = strtok(NULL, ".");
    }
    return 1;
}

// Function to calculate subnet mask
void calculateSubnetMask(char *ip, char *subnetMask) {
    int i = 0;
    while (ip[i]!= '.') {
        subnetMask[i] = ip[i];
        i++;
    }
    subnetMask[i] = '\0';
}

// Function to calculate broadcast address
void calculateBroadcastAddress(char *ip, char *subnetMask, char *broadcastAddress) {
    int i = 0;
    while (ip[i]!= '.') {
        broadcastAddress[i] = ip[i];
        i++;
    }
    while (subnetMask[i]!= '.') {
        broadcastAddress[i] = '.';
        i++;
    }
    broadcastAddress[i] = '\0';
}

// Function to calculate number of hosts in subnet
int calculateNumberOfHosts(char *ip, char *subnetMask) {
    int numOfHosts = 0;
    int i = 0;
    while (subnetMask[i]!= '.') {
        if (subnetMask[i] == '1') {
            numOfHosts++;
        }
        i++;
    }
    return numOfHosts;
}

int main() {
    char ip[16];
    char subnetMask[16];
    char broadcastAddress[16];
    int numOfHosts;

    printf("Enter IP address: ");
    scanf("%s", ip);

    if (!validateIP(ip)) {
        printf("Invalid IP address.\n");
        return 0;
    }

    printf("Enter subnet mask: ");
    scanf("%s", subnetMask);

    if (!validateIP(subnetMask)) {
        printf("Invalid subnet mask.\n");
        return 0;
    }

    calculateSubnetMask(ip, subnetMask);
    calculateBroadcastAddress(ip, subnetMask, broadcastAddress);

    numOfHosts = calculateNumberOfHosts(ip, subnetMask);

    printf("Subnet mask: %s\n", subnetMask);
    printf("Broadcast address: %s\n", broadcastAddress);
    printf("Number of hosts: %d\n", numOfHosts);

    return 0;
}