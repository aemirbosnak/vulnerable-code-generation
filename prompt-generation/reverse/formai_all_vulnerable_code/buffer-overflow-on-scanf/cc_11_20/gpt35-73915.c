//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Method to validate user input
int validateInput(char *userInput) {
    char *ptr = userInput;
    while(*ptr) {
        if(*ptr < '0' || *ptr > '9') {
            return 0;
        }
        ptr++;
    }
    return 1;
}

int main() {

    printf("Welcome to the C Subnet Calculator example program.\n");

    // Prompt user for IP address
    char ipAddress[16];
    printf("Please enter an IP address (e.g. 192.168.0.1): ");
    scanf("%s", ipAddress);

    // Validate user input
    if(strchr(ipAddress, '.') == NULL) {
        printf("Invalid IP address. Please try again.\n");
        exit(0);
    }

    // Prompt user for subnet mask
    char subnetMask[16];
    printf("Please enter a subnet mask (e.g. 255.255.255.0): ");
    scanf("%s", subnetMask);

    // Validate user input
    if(strchr(subnetMask, '.') == NULL) {
        printf("Invalid subnet mask. Please try again.\n");
        exit(0);
    }

    // Convert user input to integers
    int ip1, ip2, ip3, ip4, sub1, sub2, sub3, sub4;
    sscanf(ipAddress, "%d.%d.%d.%d", &ip1, &ip2, &ip3, &ip4);
    sscanf(subnetMask, "%d.%d.%d.%d", &sub1, &sub2, &sub3, &sub4);

    // Validate integer values
    if(ip1 < 0 || ip2 < 0 || ip3 < 0 || ip4 < 0 || 
        sub1 < 0 || sub2 < 0 || sub3 < 0 || sub4 < 0 ||
        ip1 > 255 || ip2 > 255 || ip3 > 255 || ip4 > 255 ||
        sub1 > 255 || sub2 > 255 || sub3 > 255 || sub4 > 255) {
            printf("Invalid values entered. Please try again.\n");
            exit(0);
    }

    // Calculate subnet mask in binary
    int subnetMaskBinary[32] = {0};
    int i = 0, j = 0;
    for(i = 0; i < 4; i++) {
        int num = 1;
        for(j = 0; j < 8; j++) {
            if(subnetMask[i] & num) {
                subnetMaskBinary[(i * 8) + j] = 1;
            }
            num <<= 1;
        }
    }

    // Calculate subnet address
    int subnetAddress[32] = {0};
    for(i = 0; i < 32; i++) {
        subnetAddress[i] = (ip1 & subnetMaskBinary[i]) & (ip2 & subnetMaskBinary[i]) & (ip3 & subnetMaskBinary[i]) &
         (ip4 & subnetMaskBinary[i]);
    }

    // Calculate number of hosts in subnet
    int numHosts = 1;
    for(i = 0; i < 32; i++) {
        if(!subnetMaskBinary[i]) {
            numHosts <<= 1;
        }
    }
    numHosts -= 2;

    // Display results
    printf("Subnet Address: %d.%d.%d.%d\n", subnetAddress[0], subnetAddress[8], subnetAddress[16], subnetAddress[24]);
    printf("Number of Hosts: %d\n", numHosts);

    return 0;
}