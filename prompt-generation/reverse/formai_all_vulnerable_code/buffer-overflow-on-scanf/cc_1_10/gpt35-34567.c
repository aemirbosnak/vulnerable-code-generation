//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool isValidIpAddress(char *);
bool isValidSubnetMask(char *);
void calculateSubnet(char *, char *);

int main() {
    printf("Welcome to Subnet Calculator\n");

    // Get the IP address from user
    char ipAddress[15];
    printf("Enter IP Address: ");
    scanf("%s", ipAddress);

    // Check if the IP address is valid
    if (!isValidIpAddress(ipAddress)) {
        printf("Invalid IP Address. Please enter a valid IP Address.\n");
        return EXIT_FAILURE;
    }

    // Get the subnet mask from user
    char subnetMask[15];
    printf("Enter Subnet Mask: ");
    scanf("%s", subnetMask);

    // Check if the subnet mask is valid
    if (!isValidSubnetMask(subnetMask)) {
        printf("Invalid Subnet Mask. Please enter a valid Subnet Mask.\n");
        return EXIT_FAILURE;
    }

    // Calculate the subnet using IP address and subnet mask
    calculateSubnet(ipAddress, subnetMask);

    return EXIT_SUCCESS;
}

bool isValidIpAddress(char *ipAddress) {
    int num;
    char digit[4];
    int i, j = 0;

    for (i = 0; ipAddress[i] != '\0'; i++) {
        if (ipAddress[i] == '.') {
            digit[j] = '\0';
            j = 0;
            num = atoi(digit);

            if (num < 0 || num > 255) {
                return false;
            }
        } else if (isdigit(ipAddress[i])) {
            digit[j++] = ipAddress[i];
        } else {
            return false;
        }
    }

    digit[j] = '\0';
    num = atoi(digit);

    if (num < 0 || num > 255) {
        return false;
    }

    return true;
}

bool isValidSubnetMask(char *subnetMask) {
    int num;
    char digit[4];
    int i, j = 0;
    int zeroFlag = 0;
    int oneFlag = 0;

    for (i = 0; subnetMask[i] != '\0'; i++) {
        if (subnetMask[i] == '.') {
            digit[j] = '\0';
            j = 0;
            num = atoi(digit);

            if (num == 0) {
                zeroFlag = 1;
            } else if (num == 255) {
                oneFlag = 1;
            } else {
                return false;
            }
        } else if (isdigit(subnetMask[i])) {
            digit[j++] = subnetMask[i];
        } else {
            return false;
        }
    }

    digit[j] = '\0';
    num = atoi(digit);

    if (num == 0) {
        zeroFlag = 1;
    } else if (num == 255) {
        oneFlag = 1;
    } else {
        return false;
    }

    if (zeroFlag && oneFlag) {
        return true;
    } else {
        return false;
    }
}

void calculateSubnet(char *ipAddress, char *subnetMask) {
    char *token;
    char *ptr;
    int ip[4];
    int mask[4];
    int network[4];
    int i;

    // Split the IP address into 4 octets
    token = strtok(ipAddress, ".");
    i = 0;
    while (token != NULL) {
        ip[i++] = atoi(token);
        token = strtok(NULL, ".");
    }

    // Split the subnet mask into 4 octets
    token = strtok(subnetMask, ".");
    i = 0;
    while (token != NULL) {
        mask[i++] = atoi(token);
        token = strtok(NULL, ".");
    }

    // Calculate the network address
    for (i = 0; i < 4; i++) {
        network[i] = ip[i] & mask[i];
    }

    printf("Network Address: %d.%d.%d.%d\n", network[0], network[1], network[2], network[3]);
}