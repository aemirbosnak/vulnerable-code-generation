//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SUBNETS 32

typedef struct {
    char ip[16];       // IP Address
    int subnet;       // Subnet Mask
} Subnet;

void calculateSubnetDetails(Subnet *subnet) {
    unsigned int ip[4], mask[4] = {0, 0, 0, 0};
    int submaskLength = subnet->subnet;

    // Convert IP address to integer array
    sscanf(subnet->ip, "%u.%u.%u.%u", &ip[0], &ip[1], &ip[2], &ip[3]);

    // Create subnet mask based on the given subnet
    for(int i = 0; i < 4; i++) {
        if(submaskLength >= 8) {
            mask[i] = 255; // 8 bits -> 255
            submaskLength -= 8;
        } else {
            mask[i] = (submaskLength == 0) ? 0 : (255 << (8 - submaskLength)) & 255;
            break;
        }
    }

    // Calculate Network IP and Broadcast IP
    unsigned int network[4], broadcast[4];
    for(int i = 0; i < 4; i++) {
        network[i] = ip[i] & mask[i];
        broadcast[i] = network[i] | (~mask[i] & 255);
    }

    // Display the results
    printf("IP: %s\n", subnet->ip);
    printf("Subnet Mask: %u.%u.%u.%u\n", mask[0], mask[1], mask[2], mask[3]);
    printf("Network IP: %u.%u.%u.%u\n", network[0], network[1], network[2], network[3]);
    printf("Broadcast IP: %u.%u.%u.%u\n", broadcast[0], broadcast[1], broadcast[2], broadcast[3]);
    printf("Available Hosts: %d\n\n", (int)(pow(2, (32 - subnet->subnet)) - 2));
}

void displayWelcomeMessage() {
    printf("==================================\n");
    printf("     Welcome to Subnet Calculator  \n");
    printf("==================================\n\n");
}

int getValidSubnet() {
    int subnetMask;
    do {
        printf("Please enter a subnet mask (0 - 30): ");
        scanf("%d", &subnetMask);
    } while (subnetMask < 0 || subnetMask > 30);
    return subnetMask;
}

void getInputIP(Subnet *subnet) {
    printf("Enter a valid IP address (X.X.X.X): ");
    scanf("%s", subnet->ip);
}

int main() {
    Subnet subnetList[MAX_SUBNETS];
    int i;

    displayWelcomeMessage();

    for (i = 0; i < MAX_SUBNETS; i++) {
        printf("Subnet %d:\n", i + 1);
        subnetList[i].subnet = getValidSubnet();
        getInputIP(&subnetList[i]);
        calculateSubnetDetails(&subnetList[i]);

        char continueInput[4];
        printf("Do you want to add another subnet? (yes/no): ");
        scanf("%s", continueInput);
        if (strcmp(continueInput, "no") == 0) {
            break;
        }
    }

    printf("Thank you for using the Subnet Calculator. Goodbye!\n");
    return 0;

}