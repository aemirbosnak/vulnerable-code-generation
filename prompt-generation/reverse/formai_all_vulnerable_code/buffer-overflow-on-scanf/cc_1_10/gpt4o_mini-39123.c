//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

void displayHeader() {
    printf("========================================\n");
    printf("        FUTURISTIC SUBNET CALCULATOR    \n");
    printf("========================================\n");
    printf("Welcome to the Intergalactic Network!\n");
    printf("Enter your Classless IPv4 Address to optimize your routing protocols.\n");
}

void convertToBinary(unsigned int num, char *binary) {
    for (int i = 0; i < 32; i++) {
        binary[31 - i] = (num & (1 << i)) ? '1' : '0';
    }
    binary[32] = '\0';
}

void calculateSubnet(const char *ipAddress, const char *subnetMask) {
    struct in_addr ipAddr, subnetAddr, networkAddr, broadcastAddr;
    
    inet_pton(AF_INET, ipAddress, &ipAddr);
    inet_pton(AF_INET, subnetMask, &subnetAddr);
    
    // Calculate Network Address
    networkAddr.s_addr = ipAddr.s_addr & subnetAddr.s_addr;
    
    // Calculate Broadcast Address
    broadcastAddr.s_addr = networkAddr.s_addr | ~subnetAddr.s_addr;
    
    // Display Results
    char binaryIp[33], binaryMask[33], binaryNetwork[33], binaryBroadcast[33];
    convertToBinary(ntohl(ipAddr.s_addr), binaryIp);
    convertToBinary(ntohl(subnetAddr.s_addr), binaryMask);
    convertToBinary(ntohl(networkAddr.s_addr), binaryNetwork);
    convertToBinary(ntohl(broadcastAddr.s_addr), binaryBroadcast);
    
    printf("\n----- Subnetting Analysis Results -----\n");
    printf("IP Address:       %s\n", ipAddress);
    printf("Subnet Mask:      %s\n", subnetMask);
    printf("Network Address:  %s\n", inet_ntoa(networkAddr));
    printf("Broadcast Address: %s\n", inet_ntoa(broadcastAddr));
    
    printf("\n----- Binary Representation -----\n");
    printf("IP Address (Binary):       %s\n", binaryIp);
    printf("Subnet Mask (Binary):      %s\n", binaryMask);
    printf("Network Address (Binary):  %s\n", binaryNetwork);
    printf("Broadcast Address (Binary): %s\n", binaryBroadcast);
}

void askForInput() {
    char ipAddress[16], subnetMask[16];

    printf("Enter IPv4 Address [x.x.x.x]: ");
    scanf("%s", ipAddress);
    printf("Enter Subnet Mask [x.x.x.x]: ");
    scanf("%s", subnetMask);

    calculateSubnet(ipAddress, subnetMask);
}

void displayFooter() {
    printf("\nThank you for using the Futuristic Subnet Calculator!\n");
    printf("Stay connected in the digital cosmos.\n");
}

int main() {
    displayHeader();
    askForInput();
    displayFooter();
    
    return 0;
}