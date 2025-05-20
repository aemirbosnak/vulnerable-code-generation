//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define IP_ADDRESS_MAX_LENGTH 15

typedef struct {
    char ipAddress[IP_ADDRESS_MAX_LENGTH];
    char subnetMask[IP_ADDRESS_MAX_LENGTH];
    char gateway[IP_ADDRESS_MAX_LENGTH];
    char dns1[IP_ADDRESS_MAX_LENGTH];
    char dns2[IP_ADDRESS_MAX_LENGTH];
} Subnet;

void printSubnet(Subnet *subnet) {
    printf("IP Address: %s\n", subnet->ipAddress);
    printf("Subnet Mask: %s\n", subnet->subnetMask);
    printf("Gateway: %s\n", subnet->gateway);
    printf("DNS 1: %s\n", subnet->dns1);
    printf("DNS 2: %s\n", subnet->dns2);
}

int main() {
    Subnet subnets[MAX_SUBNETS];
    int numSubnets = 0;

    printf("Enter the number of subnets: ");
    scanf("%d", &numSubnets);

    for (int i = 0; i < numSubnets; i++) {
        printf("Enter the IP address for subnet %d: ", i+1);
        scanf("%s", subnets[i].ipAddress);
        printf("Enter the subnet mask for subnet %d: ", i+1);
        scanf("%s", subnets[i].subnetMask);
        printf("Enter the gateway for subnet %d: ", i+1);
        scanf("%s", subnets[i].gateway);
        printf("Enter the DNS 1 for subnet %d: ", i+1);
        scanf("%s", subnets[i].dns1);
        printf("Enter the DNS 2 for subnet %d: ", i+1);
        scanf("%s", subnets[i].dns2);
    }

    printf("\nSubnet details:\n");
    for (int i = 0; i < numSubnets; i++) {
        printSubnet(&subnets[i]);
    }

    return 0;
}