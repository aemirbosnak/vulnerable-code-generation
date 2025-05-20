//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_LENGTH 16

void convertMaskToCIDR(char mask[], char cidr[]);
void parseIPAddress(char ipAddress[], int arr[]);
int calculateCIDR(int arr[]);
void calculateSubnetMask(int prefix, int subnetMask[]);
void calculateNetworkAddress(int ipAddress[], int subnetMask[], int networkAddr[]);
void calculateBroadcastAddress(int ipAddress[], int subnetMask[], int broadcastAddr[]);
void calculateHostRange(int networkAddr[], int broadcastAddr[], int hostRange[]);

int main() {
    char ipAddress[MAX_IP_LENGTH];
    char subnetMask[MAX_IP_LENGTH];
    printf("Enter IP Address: ");
    fgets(ipAddress, MAX_IP_LENGTH, stdin);
    printf("Enter Subnet Mask: ");
    fgets(subnetMask, MAX_IP_LENGTH, stdin);
    
    char cidr[MAX_IP_LENGTH];
    convertMaskToCIDR(subnetMask, cidr);
    printf("\nCIDR Notation: %s\n", cidr);
    
    int ipArr[4], subnetArr[4];
    parseIPAddress(ipAddress, ipArr);
    parseIPAddress(subnetMask, subnetArr);
    
    int prefix = calculateCIDR(subnetArr);
    int subnetMaskArr[4], networkAddr[4], broadcastAddr[4], hostRange[4];
    calculateSubnetMask(prefix, subnetMaskArr);
    calculateNetworkAddress(ipArr, subnetMaskArr, networkAddr);
    calculateBroadcastAddress(ipArr, subnetMaskArr, broadcastAddr);
    calculateHostRange(networkAddr, broadcastAddr, hostRange);
    
    printf("\nNetwork Address: %d.%d.%d.%d\n", networkAddr[0], networkAddr[1], networkAddr[2], networkAddr[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n", broadcastAddr[0], broadcastAddr[1], broadcastAddr[2], broadcastAddr[3]);
    printf("Host Range: %d.%d.%d.%d - %d.%d.%d.%d\n", 
            networkAddr[0], networkAddr[1], networkAddr[2], networkAddr[3], 
            broadcastAddr[0], broadcastAddr[1], broadcastAddr[2], broadcastAddr[3]);
    
    return 0;
}

void convertMaskToCIDR(char mask[], char cidr[]) {
    int arr[4];
    sscanf(mask, "%d.%d.%d.%d", &arr[0], &arr[1], &arr[2], &arr[3]);
    int prefix = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 7; j >= 0; j--) {
            if ((arr[i] >> j) & 1) {
                prefix++;
            } else {
                break;
            }
        }
    }
    sprintf(cidr, "/%d", prefix);
}

void parseIPAddress(char ipAddress[], int arr[]) {
    sscanf(ipAddress, "%d.%d.%d.%d", &arr[0], &arr[1], &arr[2], &arr[3]);
}

int calculateCIDR(int arr[]) {
    int prefix = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 7; j >= 0; j--) {
            if ((arr[i] >> j) & 1) {
                prefix++;
            } else {
                break;
            }
        }
    }
    return prefix;
}

void calculateSubnetMask(int prefix, int subnetMask[]) {
    int bits = 0xffffffff << (32 - prefix);
    subnetMask[0] = (bits >> 24) & 0xff;
    subnetMask[1] = (bits >> 16) & 0xff;
    subnetMask[2] = (bits >> 8) & 0xff;
    subnetMask[3] = bits & 0xff;
}

void calculateNetworkAddress(int ipAddress[], int subnetMask[], int networkAddr[]) {
    for (int i = 0; i < 4; i++) {
        networkAddr[i] = ipAddress[i] & subnetMask[i];
    }
}

void calculateBroadcastAddress(int ipAddress[], int subnetMask[], int broadcastAddr[]) {
    int invSubnetMask[4];
    invSubnetMask[0] = subnetMask[0] ^ 255;
    invSubnetMask[1] = subnetMask[1] ^ 255;
    invSubnetMask[2] = subnetMask[2] ^ 255;
    invSubnetMask[3] = subnetMask[3] ^ 255;
    for (int i = 0; i < 4; i++) {
        broadcastAddr[i] = ipAddress[i] | invSubnetMask[i];
    }
}

void calculateHostRange(int networkAddr[], int broadcastAddr[], int hostRange[]) {
    for (int i = 0; i < 4; i++) {
        hostRange[i] = networkAddr[i];
    }
    hostRange[3]++;
    
    for (int i = 3; i >= 0; i--) {
        if (++hostRange[i] > 255) {
            if (i > 0) {
                hostRange[i] = 0;
                hostRange[i - 1]++;
            }
        } else {
            break;
        }
    }
}