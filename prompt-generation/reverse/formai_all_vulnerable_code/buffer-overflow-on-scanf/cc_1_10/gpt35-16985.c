//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: realistic
#include<stdio.h>
#include<stdint.h>
#include<string.h>

/* Function to convert IP address to binary */
void ipToBinary(char* ipStr, uint8_t* ipBin) {
    int position = 0, i;
    char *token = strtok(ipStr, ".");
    while (token!=NULL) {
        ipBin[position++] = atoi(token);
        token = strtok(NULL, ".");
    }
}

/* Function to convert binary address to IP string */
void binaryToIp(uint8_t *ipBin, char *ipStr) {
    sprintf(ipStr, "%d.%d.%d.%d", ipBin[0], ipBin[1], ipBin[2], ipBin[3]);
}

/* Function to calculate Subnet Mask */
void calculateSubnetMask(uint8_t *subnetMask, int subnetPrefix) {
    int i, position=0;
    for (i=0; i<4; i++) {
        if(subnetPrefix >= 8) {
            subnetMask[i] = 255;
            subnetPrefix -= 8;
        }
        else if(subnetPrefix > 0) {
            subnetMask[i] = ~(255 >> subnetPrefix) & 255;
            subnetPrefix = 0;
        }
        else subnetMask[i] = 0;
    }
}

/* Function to perform bitwise AND operation */
void performAnd(uint8_t *dest, uint8_t *ip, uint8_t *subnetMask) {
    int i;
    for (i=0; i<4; i++) {
        dest[i] = ip[i] & subnetMask[i];
    }
}

/* Function to calculate the Broadcast IP */
void calculateBroadcastIP(uint8_t *broadcastIP, uint8_t *networkIP, uint8_t *subnetMask) {
    uint8_t hostMask[4] = {255, 255, 255, 255};
    int i;
    for (i=0; i<4; i++) {
        hostMask[i] &= ~subnetMask[i];
        broadcastIP[i] = networkIP[i] | hostMask[i];
    }
}

int main() {
    char ipAddress[16];
    uint8_t ip[4];
    uint8_t subnetMask[4];
    uint8_t networkIP[4];
    uint8_t broadcastIP[4];

    printf("Enter IP address: ");
    scanf("%s", ipAddress);

    ipToBinary(ipAddress, ip);

    int subnetPrefix;
    printf("Enter subnet prefix: ");
    scanf("%d", &subnetPrefix);

    calculateSubnetMask(subnetMask, subnetPrefix);

    performAnd(networkIP, ip, subnetMask);

    calculateBroadcastIP(broadcastIP, networkIP, subnetMask);

    char subnetMaskStr[16], networkIPStr[16], broadcastIPStr[16];

    binaryToIp(subnetMask, subnetMaskStr);
    binaryToIp(networkIP, networkIPStr);
    binaryToIp(broadcastIP, broadcastIPStr);

    printf("Subnet Mask: %s\n", subnetMaskStr);
    printf("Network IP: %s\n", networkIPStr);
    printf("Broadcast IP: %s\n", broadcastIPStr);

    return 0;
}