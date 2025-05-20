//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_IP_LENGTH 16 // maximum length for an IP address string
#define MAX_CIDR_LENGTH 3 // maximum length for a CIDR notation string
#define SUBNET_MASK_LENGTH 32 // length of the subnet mask

// Function to convert string to integer
int stringToInt(char *s) {
    int len = strlen(s);
    int result = 0;
    for (int i = 0; i < len; i++) {
        if (!isdigit(s[i])) {
            printf("Error: Invalid input\n");
            exit(0);
        }
        result = result * 10 + (s[i] - '0');
    }
    return result;
}

// Function to validate IP address
void validateIP(char *ip) {
    char *copy = strdup(ip);
    char *token;
    int count = 0;
    token = strtok(copy, ".");
    while (token != NULL) {
        if (count > 3 || strlen(token) > 3) {
            printf("Error: Invalid IP address\n");
            exit(0);
        }
        int num = stringToInt(token);
        if (num < 0 || num > 255) {
            printf("Error: Invalid IP address\n");
            exit(0);
        }
        token = strtok(NULL, ".");
        count++;
    }
    if (count != 4) {
        printf("Error: Invalid IP address\n");
        exit(0);
    }
}

// Function to validate CIDR notation
void validateCIDR(char *cidr) {
    int num = stringToInt(cidr);
    if (num < 1 || num > 32) {
        printf("Error: Invalid CIDR notation\n");
        exit(0);
    }
}

int main() {
    char ip[MAX_IP_LENGTH];
    char cidr[MAX_CIDR_LENGTH];
    char subnetMask[MAX_IP_LENGTH];
    int ipAddress[4]; // array to store IP address
    int cidrNotation; // CIDR notation
    int subnetMaskBits[SUBNET_MASK_LENGTH]; // array to store subnet mask bits
    int numHosts; // number of hosts in the subnet
    int i, j;
    printf("\nEnter IP address and CIDR notation separated by a space: ");
    scanf("%s %s", ip, cidr);
    validateIP(ip);
    validateCIDR(cidr);
    // Store IP address in array
    sscanf(ip, "%d.%d.%d.%d", &ipAddress[0], &ipAddress[1], &ipAddress[2], &ipAddress[3]);
    cidrNotation = stringToInt(cidr);
    // Set subnet mask bits
    for (i = 0; i < SUBNET_MASK_LENGTH; i++) {
        if (i < cidrNotation) {
            subnetMaskBits[i] = 1;
        } else {
            subnetMaskBits[i] = 0;
        }
    }
    // Calculate subnet mask
    for (i = 0; i < 4; i++) {
        subnetMask[i] = 0;
        for (j = 0; j < 8; j++) {
            int bit = subnetMaskBits[i * 8 + j];
            if (bit) {
                subnetMask[i] |= (1 << (7 - j));
            }
        }
    }
    printf("\nSubnet Mask: %d.%d.%d.%d", subnetMask[0], subnetMask[1], subnetMask[2], subnetMask[3]);
    // Calculate number of hosts in the subnet
    numHosts = (1 << (32 - cidrNotation)) - 2;
    printf("\nNumber of Hosts: %d\n", numHosts);
    return 0;
}