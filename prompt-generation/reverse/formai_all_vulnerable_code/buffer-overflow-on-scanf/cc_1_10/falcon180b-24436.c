//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate subnet mask
void calculate_subnet_mask(int ip_address[], int subnet_mask[]) {
    int i, j;
    for (i = 0; i < 4; i++) {
        if (ip_address[i] == 0) {
            subnet_mask[i] = 0;
        }
        else if (ip_address[i] == 255) {
            subnet_mask[i] = 255;
        }
        else {
            subnet_mask[i] = 255;
        }
    }
}

// Function to check if IP address is valid
int is_valid_ip_address(int ip_address[]) {
    int i;
    for (i = 0; i < 4; i++) {
        if (ip_address[i] < 0 || ip_address[i] > 255) {
            return 0;
        }
    }
    return 1;
}

// Function to print subnet mask
void print_subnet_mask(int subnet_mask[]) {
    int i;
    for (i = 0; i < 4; i++) {
        printf("%d.%d.%d.%d ", subnet_mask[i], subnet_mask[i], subnet_mask[i], subnet_mask[i]);
    }
}

int main() {
    int ip_address[4], subnet_mask[4];
    char input_ip[16];

    // Get IP address from user
    printf("Enter IP address: ");
    scanf("%s", input_ip);

    // Convert input IP address to integer array
    int i, j;
    for (i = 0, j = 0; i < strlen(input_ip); i++) {
        if (input_ip[i] == '.') {
            ip_address[j++] = atoi(input_ip + i + 1);
        }
    }

    // Check if IP address is valid
    if (!is_valid_ip_address(ip_address)) {
        printf("Invalid IP address.\n");
        return 1;
    }

    // Calculate subnet mask
    calculate_subnet_mask(ip_address, subnet_mask);

    // Print subnet mask
    printf("Subnet mask: ");
    print_subnet_mask(subnet_mask);

    return 0;
}