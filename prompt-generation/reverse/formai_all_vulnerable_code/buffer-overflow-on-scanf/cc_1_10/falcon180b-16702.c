//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define IP_ADDRESS_LENGTH 15

// Function prototypes
void parseIPAddress(char* ipAddress, int* subnet);
void printSubnet(int subnet);

int main() {
    char ipAddress[IP_ADDRESS_LENGTH];
    int subnet[MAX_SUBNETS];
    int numSubnets = 0;

    printf("Enter IP address: ");
    scanf("%s", ipAddress);

    // Parse IP address and calculate subnet
    parseIPAddress(ipAddress, subnet);

    // Print subnet information
    while (numSubnets < MAX_SUBNETS) {
        printf("Subnet %d: ", numSubnets + 1);
        printSubnet(subnet[numSubnets]);
        numSubnets++;
    }

    return 0;
}

// Parse IP address and calculate subnet
void parseIPAddress(char* ipAddress, int* subnet) {
    int i = 0;
    int j = 0;
    int k = strlen(ipAddress) - 1;

    while (i < 4) {
        j = k;
        while (j >= 0 && ipAddress[j]!= '.') {
            j--;
        }
        subnet[i] = atoi(ipAddress + j + 1);
        i++;
        k = j - 1;
    }
}

// Print subnet information
void printSubnet(int subnet) {
    printf("%d.%d.%d.%d\n", (subnet >> 24) & 0xFF, (subnet >> 16) & 0xFF, (subnet >> 8) & 0xFF, subnet & 0xFF);
}