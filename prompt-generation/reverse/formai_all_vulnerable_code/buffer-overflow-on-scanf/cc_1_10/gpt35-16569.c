//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void promptIP(char* ip) {
    printf("Enter IP Address: ");
    scanf("%s", ip);
}

int getOctets(char* ip, int* octets) {
    char* token = strtok(ip, ".");
    int octetCount = 0;
    while (token != NULL) {
        int octetVal = atoi(token);
        if (octetVal > 255) {
            printf("Invalid IP Address\n");
            return 0;
        }
        octets[octetCount] = octetVal;
        octetCount++;
        token = strtok(NULL, ".");
    }
    if (octetCount != 4) {
        printf("Invalid IP Address\n");
        return 0;
    }
    return 1;
}

int getPrefix(char* prefixStr, int* prefix) {
    *prefix = atoi(prefixStr);
    if (*prefix < 0 || *prefix > 32) {
        printf("Invalid Prefix\n");
        return 0;
    }
    return 1;
}

void calculateNetwork(int* octets, int prefix, int* network) {
    int i, byte, bit;
    for (i = 0; i < 4; i++) {
        if (prefix >= 8) {
            network[i] = octets[i];
            prefix -= 8;
        }
        else {
            byte = octets[i] >> prefix;
            for (bit = prefix - 1; bit >= 0; bit--) {
                byte &= ~(1 << bit);
            }
            network[i] = byte << prefix;
            prefix = 0;
        }
    }
}

void calculateBroadcast(int* octets, int prefix, int* broadcast) {
    int i, byte, bit;
    for (i = 0; i < 4; i++) {
        if (prefix >= 8) {
            broadcast[i] = octets[i];
            prefix -= 8;
        }
        else {
            byte = octets[i] | ((1 << (8 - prefix)) - 1);
            for (bit = prefix - 1; bit >= 0; bit--) {
                byte &= ~(1 << bit);
            }
            broadcast[i] = byte;
            prefix = 0;
        }
    }
}

void printResults(int* octets, int prefix, int* network, int* broadcast) {
    printf("IP Address: %d.%d.%d.%d\n", octets[0], octets[1], octets[2], octets[3]);
    printf("Prefix: /%d\n", prefix);
    printf("Network Address: %d.%d.%d.%d\n", network[0], network[1], network[2], network[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n", broadcast[0], broadcast[1], broadcast[2], broadcast[3]);
}

int main() {
    char ip[16], prefixStr[3];
    int octets[4], prefix, network[4], broadcast[4];
    
    promptIP(ip);
    if (!getOctets(ip, octets)) {
        return 1;
    }
    
    printf("Enter Network Prefix: ");
    scanf("%s", prefixStr);
    if (!getPrefix(prefixStr, &prefix)) {
        return 1;
    }
    
    calculateNetwork(octets, prefix, network);
    calculateBroadcast(octets, prefix, broadcast);
    printResults(octets, prefix, network, broadcast);
    
    return 0;
}