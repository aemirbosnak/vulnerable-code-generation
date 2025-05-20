//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_IP_LENGTH 16 // maximum length of an IP address (xxx.xxx.xxx.xxx format)
#define MAX_CIDR_LENGTH 3 // maximum length of the CIDR notation (xx format)
#define MAX_BINARY_LENGTH 33 // maximum length of a binary address (32-bit address + '\0' terminator)

// function prototypes
int getSubnetMask(int cidr);
void getIPBinary(char *ip, char *binary);
int getWildcardMask(int subnetMask);
void getNetworkAddress(char *ipBinary, int subnetMask, char *networkAddressBinary);
void getBroadcastAddress(char *networkAddressBinary, int wildcardMask, char *broadcastAddressBinary);

int main() {
    char ip[MAX_IP_LENGTH], binary[MAX_BINARY_LENGTH], networkAddressBinary[MAX_BINARY_LENGTH], broadcastAddressBinary[MAX_BINARY_LENGTH];
    int cidr, subnetMask, wildcardMask;

    // get IP address and CIDR notation from the user
    printf("Enter an IP address in the form xxx.xxx.xxx.xxx: ");
    scanf("%s", ip);
    printf("Enter the CIDR notation (ex. 24, 16, 8): ");
    scanf("%d", &cidr);

    // get subnet mask, IP in binary format, wildcard mask, network address in binary format, and broadcast address in binary format
    subnetMask = getSubnetMask(cidr);
    getIPBinary(ip, binary);
    wildcardMask = getWildcardMask(subnetMask);
    getNetworkAddress(binary, subnetMask, networkAddressBinary);
    getBroadcastAddress(networkAddressBinary, wildcardMask, broadcastAddressBinary);

    // display results to the user
    printf("IP Address: %s/%d\n", ip, cidr);
    printf("Subnet Mask: %d.%d.%d.%d\n", (subnetMask >> 24) & 0xFF, (subnetMask >> 16) & 0xFF, (subnetMask >> 8) & 0xFF, subnetMask & 0xFF);
    printf("Wildcard Mask: %d.%d.%d.%d\n", (wildcardMask >> 24) & 0xFF, (wildcardMask >> 16) & 0xFF, (wildcardMask >> 8) & 0xFF, wildcardMask & 0xFF);
    printf("Network Address: %d.%d.%d.%d\n", strtol(networkAddressBinary, NULL, 2) >> 24, (strtol(networkAddressBinary, NULL, 2) >> 16) & 0xFF, (strtol(networkAddressBinary, NULL, 2) >> 8) & 0xFF, strtol(networkAddressBinary, NULL, 2) & 0xFF);
    printf("Broadcast Address: %d.%d.%d.%d\n", strtol(broadcastAddressBinary, NULL, 2) >> 24, (strtol(broadcastAddressBinary, NULL, 2) >> 16) & 0xFF, (strtol(broadcastAddressBinary, NULL, 2) >> 8) & 0xFF, strtol(broadcastAddressBinary, NULL, 2) & 0xFF);

    return 0;
}

// function to get the subnet mask in 32-bit decimal format
int getSubnetMask(int cidr) {
    int subnetMask = 0xFFFFFFFF << (32 - cidr);
    return subnetMask;
}

// function to convert an IP address in xxx.xxx.xxx.xxx format to binary format in 32-bit string format (ex. "11000000101010000000000100000000")
void getIPBinary(char *ip, char *binary) {
    int i = 0, j = 0, k = 0;
    for (i = 0; ip[i] != '\0'; i++) {
        if (ip[i] == '.') {
            binary[k++] = '0'; binary[k++] = '0'; binary[k++] = '0'; binary[k++] = '0';
        } else {
            char octet[4]; int o = 0, octetDecimal = 0;
            for (j = i; ip[j] != '.' && ip[j] != '\0'; j++) {
                octet[o++] = ip[j];
            }
            octet[o] = '\0';
            octetDecimal = atoi(octet);
            for (j = 0; j < 8; j++) {
                binary[k++] = ((octetDecimal >> (7 - j)) & 0x01) + '0';
            }
            i = j - 1;
        }
    }
    binary[k] = '\0';
}

// function to get the wildcard mask in 32-bit decimal format
int getWildcardMask(int subnetMask) {
    int wildcardMask = 0xFFFFFFFF ^ subnetMask;
    return wildcardMask;
}

// function to get the network address in binary format in 32-bit string format (ex. "11000000101010000000000100000000")
void getNetworkAddress(char *ipBinary, int subnetMask, char *networkAddressBinary) {
    char subnetMaskBinary[MAX_BINARY_LENGTH];
    sprintf(subnetMaskBinary, "%d.%d.%d.%d", (subnetMask >> 24) & 0xFF, (subnetMask >> 16) & 0xFF, (subnetMask >> 8) & 0xFF, subnetMask & 0xFF);
    int i = 0;
    for (i = 0; i < MAX_BINARY_LENGTH; i++) {
        if (subnetMaskBinary[i] == '.') {
            networkAddressBinary[i] = '.';
        } else {
            networkAddressBinary[i] = (ipBinary[i] & subnetMaskBinary[i]) + '0';
        }
    }
    networkAddressBinary[i] = '\0';
}

// function to get the broadcast address in binary format in 32-bit string format (ex. "11000000101010000000000100000000")
void getBroadcastAddress(char *networkAddressBinary, int wildcardMask, char *broadcastAddressBinary) {
    char wildcardMaskBinary[MAX_BINARY_LENGTH];
    sprintf(wildcardMaskBinary, "%d.%d.%d.%d", (wildcardMask >> 24) & 0xFF, (wildcardMask >> 16) & 0xFF, (wildcardMask >> 8) & 0xFF, wildcardMask & 0xFF);
    int i = 0;
    for (i = 0; i < MAX_BINARY_LENGTH; i++) {
        if (wildcardMaskBinary[i] == '.') {
            broadcastAddressBinary[i] = '.';
        } else {
            broadcastAddressBinary[i] = (networkAddressBinary[i] | wildcardMaskBinary[i]) + '0';
        }
    }
    broadcastAddressBinary[i] = '\0';
}