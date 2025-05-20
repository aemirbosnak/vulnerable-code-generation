//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 255
#define MAX_IP_OCTETS 4
#define MAX_OCTET_VALUE 255

void calculateSubnetMask(char* subnetMask, int subnetBits);
void printSubnets(char** subnets, int numSubnets);

int main() {

    int numHosts, hostBits;
    int subnetBits, numSubnets;
    char ipAddress[MAX_IP_OCTETS+1];
    char subnetMask[MAX_IP_OCTETS+1];
    char** subnets;

    printf("Enter IP address in dotted decimal format: ");
    scanf("%s", ipAddress);

    printf("Enter number of hosts required: ");
    scanf("%d", &numHosts);

    // Calculate number of host bits required to accommodate all host requests
    hostBits = 0;
    while ((1 << hostBits) < numHosts + 2) {
        hostBits++;
    }

    // Calculate number of subnet bits required based on number of available host bits
    subnetBits = MAX_IP_OCTETS * 8 - hostBits;
    numSubnets = (1 << subnetBits);

    // Calculate the subnet mask based on number of subnet bits
    calculateSubnetMask(subnetMask, subnetBits);

    // Allocate memory for subnets array
    subnets = (char**) malloc(numSubnets * sizeof(char*));
    for (int i = 0; i < numSubnets; i++) {
        subnets[i] = (char*) malloc((MAX_IP_OCTETS+1) * sizeof(char));
        memset(subnets[i], 0, (MAX_IP_OCTETS+1) * sizeof(char));
    }

    // Extract network address and broadcast address
    char* ipOctet = strtok(ipAddress, ".");
    int subnetOctet[MAX_IP_OCTETS];
    int i;
    for (i = 0; i < MAX_IP_OCTETS; i++) {
        subnetOctet[i] = atoi(ipOctet);
        ipOctet = strtok(NULL, ".");
    }

    // Calculate network address
    int subnetMaskOctet[MAX_IP_OCTETS];
    ipOctet = strtok(subnetMask, ".");
    for (i = 0; i < MAX_IP_OCTETS; i++) {
        subnetMaskOctet[i] = atoi(ipOctet);
        ipOctet = strtok(NULL, ".");
    }

    int networkOctet[MAX_IP_OCTETS];
    for (i = 0; i < MAX_IP_OCTETS; i++) {
        networkOctet[i] = subnetOctet[i] & subnetMaskOctet[i];
    }

    // Calculate broadcast address
    int broadcastOctet[MAX_IP_OCTETS];
    for (i = 0; i < MAX_IP_OCTETS; i++) {
        broadcastOctet[i] = networkOctet[i] | ~subnetMaskOctet[i];
    }

    // Generate subnets
    for (i = 0; i < numSubnets; i++) {
        int newNetworkOctet[MAX_IP_OCTETS];
        int n = i << hostBits;
        for (int j = 0; j < MAX_IP_OCTETS; j++) {
            newNetworkOctet[j] = networkOctet[j] + (n >> (3-j)*8) & MAX_OCTET_VALUE;
        }
        sprintf(subnets[i], "%d.%d.%d.%d", newNetworkOctet[0], newNetworkOctet[1], newNetworkOctet[2], newNetworkOctet[3]);
    }

    // Print results
    printf("Input IP address with %d hosts required:\n", numHosts);
    printf("%s\n", ipAddress);
    printf("Calculated subnet mask:\n");
    printf("%s\n", subnetMask);
    printf("Calculated network address:\n");
    printf("%d.%d.%d.%d\n", networkOctet[0], networkOctet[1], networkOctet[2], networkOctet[3]);
    printf("Calculated broadcast address:\n");
    printf("%d.%d.%d.%d\n", broadcastOctet[0], broadcastOctet[1], broadcastOctet[2], broadcastOctet[3]);
    printf("Generated subnets:\n");
    printSubnets(subnets, numSubnets);

    // Free allocated memory
    for (i = 0; i < numSubnets; i++) {
        free(subnets[i]);
    }
    free(subnets);

    return 0;
}

// Calculates the subnet mask based on the number of subnet bits
void calculateSubnetMask(char* subnetMask, int subnetBits) {
    int i, octetValue;
    for (i = 0; i < MAX_IP_OCTETS; i++) {
        if (subnetBits >= 8) {
            octetValue = MAX_OCTET_VALUE;
            subnetBits -= 8;
        } else if (subnetBits > 0) {
            octetValue = 0xFF << (8 - subnetBits);
            subnetBits = 0;
        } else {
            octetValue = 0;
        }
        sprintf(subnetMask + strlen(subnetMask), "%d%s", octetValue, i == MAX_IP_OCTETS-1 ? "" : ".");
    }
}

// Prints the generated subnets
void printSubnets(char** subnets, int numSubnets) {
    for (int i = 0; i < numSubnets; i++) {
        printf("%s\n", subnets[i]);
    }
}