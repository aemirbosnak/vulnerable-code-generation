//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to validate IP address
int isValidIP(char *ip) {
    int i, j;
    int parts = 0;
    char *token;

    // Split IP address into parts
    token = strtok(ip, ".");
    while (token!= NULL) {
        parts++;
        for (i = 0; i < strlen(token); i++) {
            if (!isdigit(token[i])) {
                return 0;
            }
        }
        token = strtok(NULL, ".");
    }

    // Check number of parts
    if (parts!= 4) {
        return 0;
    }

    return 1;
}

// Function to calculate subnet mask
void calculateSubnetMask(int numHosts, char *ip, char *mask) {
    int i, j;
    int hostID = 0;

    // Initialize subnet mask with ones
    for (i = 0; i < strlen(ip); i++) {
        mask[i] = '1';
    }

    // Calculate subnet mask
    for (i = strlen(ip) - 1; i >= 0; i--) {
        if (numHosts > 0) {
            mask[i] = '0';
            numHosts--;
        } else {
            mask[i] = '1';
        }
    }
}

int main() {
    char ip[16];
    char mask[16];

    // Get IP address from user
    printf("Enter IP address: ");
    scanf("%s", ip);

    // Validate IP address
    if (!isValidIP(ip)) {
        printf("Invalid IP address.\n");
        return 1;
    }

    // Get number of hosts from user
    int numHosts;
    printf("Enter number of hosts: ");
    scanf("%d", &numHosts);

    // Calculate subnet mask
    calculateSubnetMask(numHosts, ip, mask);

    // Print results
    printf("IP address: %s\n", ip);
    printf("Subnet mask: %s\n", mask);

    return 0;
}