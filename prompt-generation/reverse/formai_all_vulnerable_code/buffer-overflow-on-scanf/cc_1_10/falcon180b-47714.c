//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the subnet mask
#define SUBNET_MASK "255.255.255.0"

// Function to calculate the subnet address
void calculate_subnet(char *ip_address) {
    int i, j;
    char subnet_address[16];
    strcpy(subnet_address, ip_address);

    // Convert the IP address to binary
    for (i = 0, j = 0; i < strlen(subnet_address); i++) {
        if (subnet_address[i] == '.') {
            j++;
        } else {
            sprintf(&subnet_address[i], "%d", subnet_address[i] - '0');
        }
    }

    // Apply the subnet mask
    for (i = 0; i < strlen(subnet_address); i++) {
        if (subnet_address[i] == '1') {
            sprintf(&subnet_address[i], "%d", 1);
        } else {
            sprintf(&subnet_address[i], "%d", 0);
        }
    }

    // Convert the subnet address back to decimal
    for (i = 0; i < strlen(subnet_address); i++) {
        if (subnet_address[i] >= '0' && subnet_address[i] <= '9') {
            continue;
        }
        if (subnet_address[i] == '.') {
            j++;
        }
    }
    printf("Subnet Address: %s\n", subnet_address);
}

int main() {
    char ip_address[16];
    printf("Enter the IP address: ");
    scanf("%s", ip_address);
    calculate_subnet(ip_address);
    return 0;
}