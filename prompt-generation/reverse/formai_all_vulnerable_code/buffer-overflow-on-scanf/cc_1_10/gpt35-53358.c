//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_IP_LENGTH 15
#define MAX_BINARY_IP_LENGTH 33
#define MAX_SUBNET_MASK 32

/**
 * Function to convert IP address to binary format
 */
void convertIPtoBinary(char *ipAddr, char *binaryIP) {
    char *token;
    int i = 0;
    token = strtok(ipAddr, ".");
    while(token != NULL) {
        int octet = atoi(token);
        char binaryOctet[9] = {0};
        for(int j=0; j<8; j++) {
            binaryOctet[7-j] = (octet & (1 << j)) ? '1' : '0';
        }
        strncat(binaryIP, binaryOctet, sizeof(binaryOctet)-1);
        token = strtok(NULL, ".");
        i++;
    }
}

/**
 * Function to validate IP address entered by user
 */
int isValidIPAddress(char *ipAddr) {
    if(ipAddr == NULL) {
        return 0;
    }
    int length = strlen(ipAddr);
    if(length < 7 || length > MAX_IP_LENGTH) {
        return 0;
    }
    char *token;
    int i = 0;
    token = strtok(ipAddr, ".");
    while(token != NULL) {
        int octet = atoi(token);
        if(octet < 0 || octet > 255) {
            return 0;
        }
        token = strtok(NULL, ".");
        i++;
    }
    if(i != 4) {
        return 0;
    }
    return 1;
}

/**
 * Function to validate Subnet Mask
 */
int isValidSubnetMask(char *subnetMask) {
    if(subnetMask == NULL) {
        return 0;
    }
    int mask = atoi(subnetMask);
    if(mask < 0 || mask > MAX_SUBNET_MASK) {
        return 0;
    }
    return 1;
}

int main() {
    char ipAddress[MAX_IP_LENGTH+1];
    char subnetMask[MAX_IP_LENGTH+1];
    char binaryIP[MAX_BINARY_IP_LENGTH] = {0};

    printf("Enter IP Address: ");
    scanf("%s", ipAddress);
    if(!isValidIPAddress(ipAddress)) {
        printf("Invalid IP Address Entered!\n");
        return 1;
    }

    printf("Enter Subnet Mask: ");
    scanf("%s", subnetMask);
    if(!isValidSubnetMask(subnetMask)) {
        printf("Invalid Subnet Mask Entered!\n");
        return 1;
    }

    // Convert IP address to binary format
    convertIPtoBinary(ipAddress, binaryIP);

    // Calculate number of hosts
    int noOfHosts = (int)(pow(2, MAX_SUBNET_MASK - atoi(subnetMask))) - 2;
    
    // Display results
    printf("\n---------- Network Details ---------\n");
    printf("IP Address: %s\n", ipAddress);
    printf("Binary IP Address: %s\n", binaryIP);
    printf("Subnet Mask: %s\n", subnetMask);
    printf("Number of Hosts: %d\n", noOfHosts);

    return 0;
}