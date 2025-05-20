//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SUBNETS 10
#define IP_ADDRESS_LENGTH 15

typedef struct {
    char ipAddress[IP_ADDRESS_LENGTH];
    int subnetMask;
    int numberOfHosts;
} Subnet;

void printSubnets(Subnet subnets[], int numSubnets) {
    for (int i = 0; i < numSubnets; i++) {
        printf("%s / %d (%d hosts)\n", subnets[i].ipAddress, subnets[i].subnetMask, subnets[i].numberOfHosts);
    }
}

int main() {
    char ipAddress[IP_ADDRESS_LENGTH];
    int numSubnets;
    int i;

    printf("Enter the IP address: ");
    scanf("%s", ipAddress);

    printf("Enter the number of subnets: ");
    scanf("%d", &numSubnets);

    if (numSubnets > MAX_SUBNETS) {
        printf("Error: Maximum number of subnets is %d.\n", MAX_SUBNETS);
        return 1;
    }

    Subnet subnets[MAX_SUBNETS];

    int numHosts = 0;
    for (i = 0; i < numSubnets; i++) {
        subnets[i].subnetMask = (int) pow(2, 32 - i * 8);
        numHosts += subnets[i].subnetMask;
    }

    if (numHosts > 254) {
        printf("Error: Total number of hosts is greater than 254.\n");
        return 1;
    }

    int j = 0;
    int k = 0;
    int ipPart[4];
    strcpy(ipPart, ipAddress);
    for (i = 0; i < strlen(ipAddress); i++) {
        if (ipAddress[i] == '.') {
            ipPart[k] = '\0';
            subnets[j].ipAddress[k] = ipPart[0];
            k++;
            ipPart[k] = '\0';
            subnets[j].subnetMask = atoi(ipPart);
            subnets[j].numberOfHosts = numHosts / numSubnets;
            j++;
            k = 0;
        } else {
            ipPart[k] = ipAddress[i];
            k++;
        }
    }

    printf("Subnets:\n");
    printSubnets(subnets, j);

    return 0;
}