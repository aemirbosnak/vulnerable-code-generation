//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define MAX_SUBNETS 10

// Function to validate IP address format
int validateIP(char *ip) {
    char *ptr;
    int i, j;
    i = 0;
    j = 0;
    while (i < strlen(ip)) {
        if (ip[i] == '.') {
            if (++j > 3) {
                return 0;
            }
        } else {
            if (!isdigit(ip[i])) {
                return 0;
            }
        }
        i++;
    }
    if (j!= 3) {
        return 0;
    }
    return 1;
}

// Function to calculate subnet mask
void subnetMask(char *ip, char *mask) {
    int i, j;
    for (i = 0, j = 0; i < strlen(ip); i++) {
        if (ip[i] == '.') {
            mask[j] = '.';
            j++;
        } else {
            mask[j] = ip[i];
            j++;
        }
    }
    mask[j] = '\0';
}

// Function to calculate subnet addresses
void subnetAddresses(char *ip, char *mask, char *subnets[], int numSubnets) {
    int i, j, k;
    for (i = 0; i < numSubnets; i++) {
        for (j = 0; j < strlen(ip); j++) {
            if (ip[j] == '.') {
                k = j;
                break;
            }
        }
        for (j = 0; j < strlen(mask); j++) {
            if (mask[j] == '.') {
                k = j;
                break;
            }
        }
        if (k > 0) {
            for (j = 0; j <= k; j++) {
                subnets[i][j] = ip[j];
            }
            for (j = k + 1; j < strlen(ip); j++) {
                subnets[i][j] = ip[j-1] + 1;
            }
        } else {
            for (j = 0; j < strlen(ip); j++) {
                subnets[i][j] = ip[j];
            }
        }
        subnets[i][strlen(ip)] = '\0';
    }
}

int main() {
    int numSubnets;
    char ip[MAX_SIZE], mask[MAX_SIZE], subnets[MAX_SUBNETS][MAX_SIZE];

    printf("Enter IP address: ");
    scanf("%s", ip);

    if (!validateIP(ip)) {
        printf("Invalid IP address format.\n");
        return 1;
    }

    printf("Enter subnet mask: ");
    scanf("%s", mask);

    if (!validateIP(mask)) {
        printf("Invalid subnet mask format.\n");
        return 1;
    }

    printf("Enter number of subnets: ");
    scanf("%d", &numSubnets);

    if (numSubnets > MAX_SUBNETS || numSubnets <= 0) {
        printf("Invalid number of subnets.\n");
        return 1;
    }

    subnetMask(ip, mask);

    subnetAddresses(ip, mask, subnets, numSubnets);

    printf("Subnet addresses:\n");
    for (int i = 0; i < numSubnets; i++) {
        printf("%s\n", subnets[i]);
    }

    return 0;
}