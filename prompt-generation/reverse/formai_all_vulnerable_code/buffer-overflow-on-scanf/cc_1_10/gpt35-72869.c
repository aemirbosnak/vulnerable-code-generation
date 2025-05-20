//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void getNetworkAddress(int IP[], int subnet[], int networkAddress[]) {
    for (int i = 0; i < 4; i++) {
        networkAddress[i] = IP[i] & subnet[i];
    }
}

void getBroadcastAddress(int IP[], int subnet[], int broadcastAddress[]) {
    int invertedSubnet[4];
    for (int i = 0; i < 4; i++) {
        invertedSubnet[i] = ~subnet[i];
    }
    int hostPart[4];
    for (int i = 0; i < 4; i++) {
        hostPart[i] = IP[i] & invertedSubnet[i];
    }
    for (int i = 0; i < 4; i++) {
        broadcastAddress[i] = hostPart[i] | subnet[i];
    }
}

void getWildCardMask(int subnet[], int wildCardMask[]) {
    for (int i = 0; i < 4; i++) {
        wildCardMask[i] = ~subnet[i];
    }
}

void printIPAddress(int IP[]) {
    printf("%d.%d.%d.%d\n", IP[0], IP[1], IP[2], IP[3]);
}

void printSubnetMask(int subnet[]) {
    printf("%d.%d.%d.%d\n", subnet[0], subnet[1], subnet[2], subnet[3]);
}

void printNetworkAddress(int networkAddress[]) {
    printf("Network Address: %d.%d.%d.%d\n", networkAddress[0], networkAddress[1], networkAddress[2], networkAddress[3]);
}

void printBroadcastAddress(int broadcastAddress[]) {
    printf("Broadcast Address: %d.%d.%d.%d\n", broadcastAddress[0], broadcastAddress[1], broadcastAddress[2], broadcastAddress[3]);
}

void printWildCardMask(int wildCardMask[]) {
    printf("Wildcard Mask: %d.%d.%d.%d\n", wildCardMask[0], wildCardMask[1], wildCardMask[2], wildCardMask[3]);
}

void printClass(int IP[]) {
    int firstOctet = IP[0];
    if (firstOctet <= 127) {
        printf("Class A\n");
    } else if (firstOctet >= 128 && firstOctet <= 191) {
        printf("Class B\n");
    } else if (firstOctet >= 192 && firstOctet <= 223) {
        printf("Class C\n");
    } else if (firstOctet >= 224 && firstOctet <= 239) {
        printf("Class D\n");
    } else if (firstOctet >= 240 && firstOctet <= 255) {
        printf("Class E\n");
    }
}

void printNetworkType(int IP[]) {
    if (IP[0] == 10) {
        printf("Private (Class A)\n");
    } else if (IP[0] == 172 && IP[1] >= 16 && IP[1] <= 31) {
        printf("Private (Class B)\n");
    } else if (IP[0] == 192 && IP[1] == 168) {
        printf("Private (Class C)\n");
    } else if (IP[0] == 169 && IP[1] == 254) {
        printf("Link Local\n");
    } else if (IP[0] == 127) {
        printf("Loopback\n");
    } else {
        printf("Public\n");
    }
}

void printNumHosts(int subnet[]) {
    int numHostBits = 32;
    for (int i = 0; i < 4; i++) {
        int octet = subnet[i];
        for (int j = 0; j < 8; j++) {
            if ((octet & 0x80) == 0) {
                break;
            } else {
                numHostBits--;
                octet <<= 1;
            }
        }
    }
    printf("Number of Hosts: %d\n", (int)pow(2, numHostBits) - 2);
}

void printError() {
    printf("\nInvalid input. Please try again with a valid IP address and subnet mask.\n");
}

void subnetCalculator() {
    int IP[4];
    int subnetMask[4];
    printf("Enter IP address: ");
    if (scanf("%d.%d.%d.%d", &IP[0], &IP[1], &IP[2], &IP[3]) != 4) {
        printError();
        return;
    }
    printf("Enter subnet mask: ");
    if (scanf("%d.%d.%d.%d", &subnetMask[0], &subnetMask[1], &subnetMask[2], &subnetMask[3]) != 4) {
        printError();
        return;
    }
    int networkAddress[4];
    getNetworkAddress(IP, subnetMask, networkAddress);
    int broadcastAddress[4];
    getBroadcastAddress(IP, subnetMask, broadcastAddress);
    int wildCardMask[4];
    getWildCardMask(subnetMask, wildCardMask);
    printf("\n");
    printf("IP Address: ");
    printIPAddress(IP);
    printf("Subnet Mask: ");
    printSubnetMask(subnetMask);
    printNetworkAddress(networkAddress);
    printBroadcastAddress(broadcastAddress);
    printWildCardMask(wildCardMask);
    printClass(IP);
    printNetworkType(IP);
    printNumHosts(subnetMask);
}

int main() {
    subnetCalculator();
    return 0;
}