//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: expert-level
// C Subnet Calculator

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Function to validate IP address
int validate_ip(char *ip) {
    int i, j, k = 0;
    char *ptr;

    for (i = 0; i < strlen(ip); i++) {
        if (ip[i] == '.') {
            k++;
        }
    }

    if (k!= 3) {
        return 0;
    }

    for (i = 0; i < strlen(ip); i++) {
        if (!isdigit(ip[i])) {
            if (ip[i]!= '.') {
                return 0;
            }
        }
    }

    return 1;
}

// Function to calculate subnet mask
void calculate_subnet_mask(int subnet_bits, char *ip, char *mask) {
    int i, j;

    for (i = 0; i < 4; i++) {
        if (i == subnet_bits - 1) {
            strcat(mask, "255");
        } else {
            strcat(mask, "0");
        }
        strcat(mask, ".");
    }

    strcat(mask, "0");
}

// Function to calculate broadcast address
void calculate_broadcast_address(char *ip, char *mask) {
    int i, j;

    for (i = 0; i < strlen(ip); i++) {
        if (ip[i] == '.') {
            strcat(mask, "255");
        } else {
            strcat(mask, "0");
        }
        strcat(mask, ".");
    }

    strcat(mask, "255");
}

// Function to calculate number of hosts in subnet
int calculate_hosts(int subnet_bits) {
    int hosts = 0;

    for (int i = 0; i < subnet_bits; i++) {
        hosts += pow(2, i);
    }

    return hosts;
}

int main() {
    char ip[16], mask[16];

    // Get IP address from user
    printf("Enter IP address: ");
    scanf("%s", ip);

    // Validate IP address
    if (!validate_ip(ip)) {
        printf("Invalid IP address.\n");
        return 0;
    }

    // Get subnet bits from user
    int subnet_bits;
    printf("Enter subnet bits: ");
    scanf("%d", &subnet_bits);

    // Calculate subnet mask
    calculate_subnet_mask(subnet_bits, ip, mask);

    // Calculate broadcast address
    calculate_broadcast_address(ip, mask);

    // Calculate number of hosts in subnet
    int hosts = calculate_hosts(subnet_bits);

    // Print results
    printf("\nIP address: %s\n", ip);
    printf("Subnet mask: %s\n", mask);
    printf("Broadcast address: %s\n", mask);
    printf("Number of hosts: %d\n", hosts);

    return 0;
}