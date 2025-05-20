//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_IP_LENGTH 16
#define MAX_MASK_LENGTH 3

typedef struct {
    char ip[MAX_IP_LENGTH];
    int subnetMask;
} SubnetCalculator;

void convertToBinary(int num, char *binaryStr) {
    for (int i = 0; i < 8; i++) {
        binaryStr[7 - i] = (num & (1 << i)) ? '1' : '0';
    }
    binaryStr[8] = '\0'; 
}

void calculateSubnet(SubnetCalculator *sc) {
    int ipParts[4];
    char binary[33] = "";
    char binaryMask[9] = "";
    
    sscanf(sc->ip, "%d.%d.%d.%d", &ipParts[0], &ipParts[1], &ipParts[2], &ipParts[3]);

    for (int i = 0; i < 4; i++) {
        convertToBinary(ipParts[i], binary + i * 8);
    }

    int totalHosts = pow(2, 32 - sc->subnetMask) - 2; // excluding network and broadcast
    int networkPart = sc->subnetMask / 8;
    
    int netParts[4] = {0};
    int numBitsInSubnet = sc->subnetMask % 8;
    
    for (int i = 0; i < networkPart; i++) {
        netParts[i] = ipParts[i];
    }
    
    if (numBitsInSubnet > 0) {
        netParts[networkPart] = (ipParts[networkPart] & (255 << (8 - numBitsInSubnet)));
    }
    
    int broadcastParts[4] = {0};
    for (int i = 0; i < 4; i++) {
        if (i < networkPart) {
            broadcastParts[i] = ipParts[i];
        } else {
            broadcastParts[i] = (ipParts[i] | (255 >> numBitsInSubnet));
        }
    }

    printf("Network Address: %d.%d.%d.%d\n", netParts[0], netParts[1], netParts[2], netParts[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n", broadcastParts[0], broadcastParts[1], broadcastParts[2], broadcastParts[3]);
    printf("Total Valid Hosts: %d\n", totalHosts);
    printf("Valid Host Range: %d.%d.%d.%d - %d.%d.%d.%d\n", netParts[0], netParts[1], netParts[2], netParts[3] + 1, broadcastParts[0], broadcastParts[1], broadcastParts[2], broadcastParts[3] - 1);
}

int main() {
    SubnetCalculator sc;

    printf("Welcome to the C Subnet Calculator!\n");
    printf("Please enter an IP address followed by the subnet mask (e.g., 192.168.1.1/24):\n");
    fgets(sc.ip, sizeof(sc.ip), stdin);
    char *slash = strchr(sc.ip, '/');
    
    if (slash != NULL) {
        *slash = '\0'; // Split IP and mask
        sc.subnetMask = atoi(slash + 1);
    } else {
        printf("Invalid input format. Use the format: <IP>/subnetmask\n");
        return 1;
    }

    if (sc.subnetMask < 1 || sc.subnetMask > 30) {
        printf("Subnet mask is invalid. Please provide a value between 1 and 30.\n");
        return 1;
    }

    calculateSubnet(&sc);
    
    return 0;
}