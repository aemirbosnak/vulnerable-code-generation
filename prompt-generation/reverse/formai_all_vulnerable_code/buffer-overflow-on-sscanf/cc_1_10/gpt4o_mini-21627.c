//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to convert IP address from string to array of integers
void ipStringToIntArray(const char *ip, int *ipArray) {
    char *token;
    char ipCopy[16];
    strncpy(ipCopy, ip, sizeof(ipCopy) - 1);
    token = strtok(ipCopy, ".");
    int i = 0;

    while (token != NULL && i < 4) {
        ipArray[i] = atoi(token);
        token = strtok(NULL, ".");
        i++;
    }
}

// Function to calculate subnet mask based on prefix length
void calculateSubnetMask(int prefix, int *subnetArray) {
    for (int i = 0; i < 4; i++) {
        if (prefix >= 8) {
            subnetArray[i] = 255;
            prefix -= 8;
        } else {
            subnetArray[i] = (prefix > 0) ? (256 - (1 << (8 - prefix))) : 0;
            prefix = 0;
        }
    }
}

// Function to calculate the number of hosts in the subnet
int calculateHosts(int prefix) {
    return (int)pow(2, (32 - prefix)) - 2; // 2 addresses reserved
}

// Function to print the result
void printResults(const char *ip, int prefix) {
    int ipArray[4];
    int subnetArray[4];
    
    ipStringToIntArray(ip, ipArray);
    calculateSubnetMask(prefix, subnetArray);
    int numHosts = calculateHosts(prefix);

    printf("Input IP Address: %d.%d.%d.%d/%d\n", ipArray[0], ipArray[1], ipArray[2], ipArray[3], prefix);
    printf("Subnet Mask: %d.%d.%d.%d\n", subnetArray[0], subnetArray[1], subnetArray[2], subnetArray[3]);
    printf("Number of hosts available: %d\n\n", numHosts);
}

int main() {
    char ip[16];
    int prefix;

    while (1) {
        printf("Enter an IP address and subnet prefix (e.g., 192.168.1.0 24) or 'exit' to quit:\n");
        fgets(ip, sizeof(ip), stdin);

        if (strncmp(ip, "exit", 4) == 0) {
            break;
        }

        if (sscanf(ip, "%15s %d", ip, &prefix) != 2) {
            printf("Invalid input! Please use the format: <IP_ADDRESS> <PREFIX>\n");
            continue;
        }

        if (prefix < 0 || prefix > 32) {
            printf("Prefix must be between 0 and 32.\n");
            continue;
        }

        printResults(ip, prefix);
    }

    return 0;
}