//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_IPADDR_LENGTH 16 //Maximum length of an IP address
#define MAX_SUBNETMASK_LENGTH 3 //Maximum length of a subnet mask

//Function to validate IP address format
bool validateIPAddress(char *ipAddress) {
    int num, dots=0;
    char *ptr;
    if (ipAddress == NULL) {
        return false;
    }
    ptr = strtok(ipAddress, ".");
    if (ptr == NULL) {
        return false;
    }
    while (ptr) {
        if (!isdigit(*ptr)) {
            return false;
        }
        num = atoi(ptr);
        if (num >= 0 && num <= 255) {
            ptr = strtok(NULL, ".");
            if (ptr != NULL) {
                ++dots;
            }    
        }
        else {
            return false;
        }
    }
    if (dots != 3) {
        return false;
    }
    return true;
}

//Function to validate subnet mask format
bool validateSubnetMask(char *subMask) {
    int num, dots=0;
    char *ptr;
    if (subMask == NULL) {
        return false;
    }
    ptr = strtok(subMask, ".");
    if (ptr == NULL) {
        return false;
    }
    while (ptr) {
        if (!isdigit(*ptr)) {
            return false;
        }
        num = atoi(ptr);
        if (num == 0 || num == 128 || num == 192 || num == 224 || num == 240 || num == 248 || num == 252 || num == 254 || num == 255) {
            ptr = strtok(NULL, ".");
            if (ptr != NULL) {
                ++dots;
            }    
        }
        else {
            return false;
        }
    }
    if (dots != 3) {
        return false;
    }
    return true;
}

//Function to convert binary IP address to decimal form
long long int binaryToDecimal(const char *binary) {
    int len = strlen(binary);
    long long int decimal = 0, j=1;
    for(int i=len-1; i>=0; i--) {
        decimal += (binary[i] - '0') * j;
        j *= 2;
    }
    return decimal;
}

//Function to calculate network ID
void computeNetworkID(char *ipAddress, char *subnetMask, char *networkID) {
    long long int netID[4], ipAddrDec[4], subMaskDec[4];
    char *ptr;
    if (ipAddress == NULL || subnetMask == NULL || networkID == NULL) {
        return;
    }
    ptr = strtok(ipAddress, ".");
    for(int i=0; i<4; i++) {
        ipAddrDec[i] = atoi(ptr);
        ptr = strtok(NULL, ".");
    }
    ptr = strtok(subnetMask, ".");
    for(int i=0; i<4; i++) {
        subMaskDec[i] = atoi(ptr);
        ptr = strtok(NULL, ".");
    }
    for(int i=0; i<4; i++) {
        netID[i] = ipAddrDec[i] & subMaskDec[i];
    }
    sprintf(networkID, "%lld.%lld.%lld.%lld", netID[0], netID[1], netID[2], netID[3]);
}

int main() {
    char ipAddress[MAX_IPADDR_LENGTH];
    char subnetMask[MAX_SUBNETMASK_LENGTH];
    char networkID[MAX_IPADDR_LENGTH];
    bool validIP, validSubnet;
    printf("\nEnter IP address: ");
    scanf("%s", ipAddress);
    validIP = validateIPAddress(ipAddress);
    while (!validIP) {
        printf("Invalid IP address format. Please enter a valid IP address: ");
        scanf("%s", ipAddress);
        validIP = validateIPAddress(ipAddress);
    }
    printf("Enter subnet mask: ");
    scanf("%s", subnetMask);
    validSubnet = validateSubnetMask(subnetMask);
    while (!validSubnet) {
        printf("Invalid subnet mask format. Please enter a valid subnet mask: ");
        scanf("%s", subnetMask);
        validSubnet = validateSubnetMask(subnetMask);
    }
    computeNetworkID(ipAddress, subnetMask, networkID);
    printf("Network ID of %s with subnet mask %s is %s\n", ipAddress, subnetMask, networkID);
    return 0;
}