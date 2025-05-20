//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 1000

// Function to validate IP address
int validate_ip(char* ip) {
    char* token = strtok(ip, ".");
    int count = 0;
    while (token!= NULL) {
        if (atoi(token) < 0 || atoi(token) > 255) {
            return 0;
        }
        count++;
        token = strtok(NULL, ".");
    }
    if (count!= 4) {
        return 0;
    }
    return 1;
}

// Function to calculate subnet mask
void calculate_subnet_mask(int subnet_bits, char* subnet_mask) {
    int i = 0;
    while (i < subnet_bits) {
        strcat(subnet_mask, "255");
        i += 8;
    }
    strcat(subnet_mask, ".0.0.0");
}

// Function to calculate number of hosts in a subnet
int calculate_hosts(int subnet_bits) {
    return (int)pow(2, subnet_bits) - 2;
}

// Function to calculate broadcast address
void calculate_broadcast(char* ip, char* subnet_mask, char* broadcast) {
    int i = 0;
    while (i < strlen(ip)) {
        if (ip[i] == '.') {
            strcat(broadcast, "255");
        } else {
            strcat(broadcast, &ip[i]);
        }
        i++;
    }
}

int main() {
    char ip[16];
    char subnet_mask[16];
    char broadcast[16];
    int subnet_bits;
    int i = 0;

    // Get IP address from user
    printf("Enter IP address: ");
    scanf("%s", ip);

    // Validate IP address
    if (!validate_ip(ip)) {
        printf("Invalid IP address\n");
        return 1;
    }

    // Get subnet bits from user
    printf("Enter subnet bits: ");
    scanf("%d", &subnet_bits);

    // Calculate subnet mask
    calculate_subnet_mask(subnet_bits, subnet_mask);

    // Calculate number of hosts in subnet
    int hosts = calculate_hosts(subnet_bits);

    // Calculate broadcast address
    calculate_broadcast(ip, subnet_mask, broadcast);

    // Print results
    printf("\nSubnet mask: %s\n", subnet_mask);
    printf("Broadcast address: %s\n", broadcast);
    printf("Number of hosts: %d\n", hosts);

    return 0;
}