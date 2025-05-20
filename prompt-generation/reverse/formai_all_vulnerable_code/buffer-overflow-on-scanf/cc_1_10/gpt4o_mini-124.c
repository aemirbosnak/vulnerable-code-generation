//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

// Structure to hold subnet data
struct SubnetInfo {
    char ipAddress[16];
    char subnetMask[16];
    char networkAddress[16];
    char broadcastAddress[16];
};

void calculateSubnet(struct SubnetInfo *info);
void printSubnetInfo(struct SubnetInfo *info);
void convertToBinary(char *ip, char *binary);
void bitwiseAnd(char *ip1, char *ip2, char *result);
void bitwiseOr(char *ip1, char *ip2, char *result);

int main() {
    struct SubnetInfo subnet;
    char proceed[3];

    printf("Welcome to the Magical C Subnet Calculator!\n");

    do {
        printf("\nEnter an IP Address (e.g., 192.168.1.1): ");
        scanf("%s", subnet.ipAddress);

        printf("Enter a Subnet Mask (e.g., 255.255.255.0): ");
        scanf("%s", subnet.subnetMask);

        calculateSubnet(&subnet);
        printSubnetInfo(&subnet);

        printf("\nDo you wish to calculate another subnet? (yes/no): ");
        scanf("%s", proceed);
    } while (strcmp(proceed, "yes") == 0 || strcmp(proceed, "Yes") == 0);

    printf("Thank you for using the Magical C Subnet Calculator!\n");

    return 0;
}

void calculateSubnet(struct SubnetInfo *info) {
    char binaryIp[35];
    char binaryMask[35];
    char networkBinary[35];
    char broadcastBinary[35];
    
    // Convert IP and subnet mask to binary
    convertToBinary(info->ipAddress, binaryIp);
    convertToBinary(info->subnetMask, binaryMask);
    
    // Perform bitwise AND to find Network Address
    bitwiseAnd(binaryIp, binaryMask, networkBinary);
    
    // Perform bitwise OR to find Broadcast Address
    bitwiseOr(networkBinary, binaryMask, broadcastBinary);
    
    // Convert binary results back to decimal
    inet_ntop(AF_INET, &(info->ipAddress), info->networkAddress, sizeof(info->networkAddress));
    inet_ntop(AF_INET, &(info->subnetMask), info->broadcastAddress, sizeof(info->broadcastAddress));
}

void printSubnetInfo(struct SubnetInfo *info) {
    printf("\nSubnet Calculation Results:\n");
    printf("IP Address: %s\n", info->ipAddress);
    printf("Subnet Mask: %s\n", info->subnetMask);
    printf("Network Address: %s\n", info->networkAddress);
    printf("Broadcast Address: %s\n\n", info->broadcastAddress);
}

void convertToBinary(char *ip, char *binary) {
    struct in_addr ipAddr;
    inet_pton(AF_INET, ip, &ipAddr);
    
    unsigned char *bytes = (unsigned char *)&ipAddr;
    sprintf(binary, "%08d.%08d.%08d.%08d",
            bytes[0], bytes[1], bytes[2], bytes[3]);
}

void bitwiseAnd(char *ip1, char *ip2, char *result) {
    // Logic for bitwise AND operation of the two binary strings
}

void bitwiseOr(char *ip1, char *ip2, char *result) {
    // Logic for bitwise OR operation of the two binary strings
}