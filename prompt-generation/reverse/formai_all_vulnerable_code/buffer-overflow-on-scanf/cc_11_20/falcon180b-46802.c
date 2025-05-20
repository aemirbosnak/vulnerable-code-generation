//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 30

int main() {

    char ipAddress[16];
    char subnetMask[16];
    char subnet[MAX_SUBNET_SIZE];
    int numSubnets;
    int subnetSize;

    printf("Enter the IP address: ");
    scanf("%s", ipAddress);

    printf("Enter the subnet mask: ");
    scanf("%s", subnetMask);

    printf("How many subnets do you want to create? ");
    scanf("%d", &numSubnets);

    if (numSubnets > MAX_SUBNETS) {
        printf("Error: Maximum number of subnets allowed is %d\n", MAX_SUBNETS);
        return 1;
    }

    if (strlen(ipAddress)!= 15 || strlen(subnetMask)!= 15) {
        printf("Error: IP address and subnet mask must be in the format of xxx.xxx.xxx.xxx\n");
        return 1;
    }

    if (atoi(ipAddress) == 0 || atoi(subnetMask) == 0) {
        printf("Error: IP address and subnet mask must be in the range of 1-255\n");
        return 1;
    }

    for (int i = 0; i < numSubnets; i++) {
        printf("Enter the subnet %d name: ", i+1);
        scanf("%s", subnet);

        if (strlen(subnet) > MAX_SUBNET_SIZE) {
            printf("Error: Subnet name must be less than %d characters\n", MAX_SUBNET_SIZE);
            return 1;
        }

        subnetSize = atoi(subnet);

        if (subnetSize < 1 || subnetSize > 30) {
            printf("Error: Subnet size must be in the range of 1-30\n");
            return 1;
        }

        printf("Subnet %s: ", subnet);

        for (int j = 1; j <= subnetSize; j++) {
            printf("%d.%d.%d.%d ", atoi(ipAddress), atoi(ipAddress), atoi(ipAddress), atoi(ipAddress)+j-1);
        }

        printf("\n");
    }

    return 0;
}