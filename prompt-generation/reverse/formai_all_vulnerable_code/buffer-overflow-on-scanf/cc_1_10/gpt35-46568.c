//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_IP_LENGTH 15
#define MAX_SUBNET_LENGTH 2
#define MAX_BINARY_LENGTH 8

/* function to calculate subnet mask in binary */
char* calculateSubnetMaskBinary(int subnet) {

    int offset = 8, i, j;
    char* subnetMaskBinary = (char*) malloc((MAX_IP_LENGTH + 1) * sizeof(char));
    memset(subnetMaskBinary, 0, MAX_IP_LENGTH + 1);

    for (i = 0; i < MAX_BINARY_LENGTH * MAX_SUBNET_LENGTH; i++) {
        if (i>=subnet) {subnetMaskBinary[i+offset] = '0';}
        else {subnetMaskBinary[i+offset] = '1';}
        if ((i+1) % MAX_BINARY_LENGTH == 0) {offset -= MAX_BINARY_LENGTH;}
    }

    return subnetMaskBinary;
}

/* function to calculate network address in binary */
char* calculateNetworkAddressBinary(char* ipAddressBinary, char* subnetMaskBinary) {

    int i;
    char* networkAddressBinary = (char*) malloc((MAX_IP_LENGTH + 1) * sizeof(char));
    memset(networkAddressBinary, 0, MAX_IP_LENGTH + 1);

    for (i = 0; i < MAX_IP_LENGTH; i++) {
        if (ipAddressBinary[i] == '1' && subnetMaskBinary[i] == '1') {
            networkAddressBinary[i] = '1';
        } else {
            networkAddressBinary[i] = '0';
        }
    }

    return networkAddressBinary;
}

/* function to calculate broadcast address in binary */
char* calculateBroadcastAddressBinary(char* networkAddressBinary, char* subnetMaskBinary) {

    int i;
    char* broadcastAddressBinary = (char*) malloc((MAX_IP_LENGTH + 1) * sizeof(char));
    memset(broadcastAddressBinary, 0, MAX_IP_LENGTH + 1);

    for (i = 0; i < MAX_IP_LENGTH; i++) {
        if (subnetMaskBinary[i] == '0') {
            broadcastAddressBinary[i] = '1';
        } else {
            broadcastAddressBinary[i] = networkAddressBinary[i];
        }
    }

    return broadcastAddressBinary;
}

/* function to convert binary to decimal */
int binaryToDecimal(char* binary, int length) {

    int i, result = 0, base = 1;

    for (i = length - 1; i >= 0; i--) {
        result += ((int) binary[i] - '0') * base;
        base *= 2;
    }

    return result;
}

/* function to display calculated values */
void displayResult(char* ipAddress, int subnet) {

    int i, j;
    char octet[MAX_IP_LENGTH/4 + 1];
    char subnetMaskBinary[MAX_IP_LENGTH + 1];
    char networkAddressBinary[MAX_IP_LENGTH + 1];
    char broadcastAddressBinary[MAX_IP_LENGTH + 1];

    printf("\nCIDR notation: /%d", subnet);

    /* display subnet mask in decimal */
    sprintf(subnetMaskBinary, "%s", calculateSubnetMaskBinary(subnet));
    printf("\nSubnet mask (binary):\t%s", subnetMaskBinary);

    memset(octet, 0, MAX_IP_LENGTH/4 + 1);
    for (i = 0, j = 0; i < MAX_IP_LENGTH; i++) {
        if (i!=0 && i % MAX_BINARY_LENGTH == 0) {
            binaryToDecimal(octet, strlen(octet));
            printf("%d",binaryToDecimal(octet, strlen(octet)));
            memset(octet, 0, MAX_IP_LENGTH/4 + 1);
            if (i!=MAX_IP_LENGTH-1) {printf(".");}
            j=0;
        }
        octet[j++] = subnetMaskBinary[i];
    }

    /* calculate network and broadcast addresses */
    sprintf(networkAddressBinary, "%s", calculateNetworkAddressBinary(ipAddress, subnetMaskBinary));
    sprintf(broadcastAddressBinary, "%s", calculateBroadcastAddressBinary(networkAddressBinary, subnetMaskBinary));

    /* display network address */
    printf("\nNetwork address:\t");
    memset(octet, 0, MAX_IP_LENGTH/4 + 1);
    for (i = 0, j = 0; i < MAX_IP_LENGTH; i++) {
        if (i!=0 && i % MAX_BINARY_LENGTH == 0) {
            printf("%d",binaryToDecimal(octet, strlen(octet)));
            memset(octet, 0, MAX_IP_LENGTH/4 + 1);
            if (i!=MAX_IP_LENGTH-1) {printf(".");}
            j=0;
        }
        octet[j++] = networkAddressBinary[i];
    }

    /* display broadcast address */
    printf("\nBroadcast address:\t");
    memset(octet, 0, MAX_IP_LENGTH/4 + 1);
    for (i = 0, j = 0; i < MAX_IP_LENGTH; i++) {
        if (i!=0 && i % MAX_BINARY_LENGTH == 0) {
            printf("%d",binaryToDecimal(octet, strlen(octet)));
            memset(octet, 0, MAX_IP_LENGTH/4 + 1);
            if (i!=MAX_IP_LENGTH-1) {printf(".");}
            j=0;
        }
        octet[j++] = broadcastAddressBinary[i];
    }

    printf("\n");
}

int main() {

    char ipAddress[MAX_IP_LENGTH + 1];
    char octet[MAX_IP_LENGTH/4 + 1];
    int subnet;

    /* get IP address from user */
    printf("Enter IP address: ");
    scanf("%s", ipAddress);

    /* get subnet from user */
    printf("Enter subnet (cidr notation): /");
    scanf("%d", &subnet);

    /* validate user input */
    if (subnet < 0 || subnet > 32) {
        printf("Invalid subnet");
        exit(1);
    }

    /* convert IP address to binary */
    char ipAddressBinary[MAX_IP_LENGTH + 1];
    memset(ipAddressBinary, 0, MAX_IP_LENGTH + 1);
    memset(octet, 0, MAX_IP_LENGTH/4 + 1);
    int i,j;
    for (i = 0, j = 0; i < MAX_IP_LENGTH; i++) {
        if (i!=0 && i % MAX_BINARY_LENGTH == 0) {
            ipAddressBinary[j++] = binaryToDecimal(octet, strlen(octet)) + '0';
            memset(octet, 0, MAX_IP_LENGTH/4 + 1);
        }
        octet[i % MAX_BINARY_LENGTH] = ipAddress[i];
    }
    ipAddressBinary[j] = binaryToDecimal(octet, strlen(octet)) + '0';

    /* display calculated values */
    displayResult(ipAddressBinary, subnet);

    return 0;
}