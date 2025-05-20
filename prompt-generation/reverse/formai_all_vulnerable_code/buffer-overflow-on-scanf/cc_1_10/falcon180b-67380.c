//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NETWORK_NUMBER 16
#define MAX_SUBNET_MASK 32

typedef struct {
    char network_number[MAX_NETWORK_NUMBER];
    char subnet_mask[MAX_SUBNET_MASK];
} subnet_info;

void print_subnet_info(subnet_info *subnet) {
    printf("Network Number: %s\n", subnet->network_number);
    printf("Subnet Mask: %s\n", subnet->subnet_mask);
}

int main() {
    subnet_info subnet;
    char ip[16];
    int i, j;

    printf("Enter IP Address: ");
    scanf("%s", ip);

    // Check if IP address is valid
    for (i = 0; i < strlen(ip); i++) {
        if (ip[i] < '0' || ip[i] > '9' || ip[i] == '.') {
            printf("Invalid IP Address.\n");
            return 1;
        }
    }

    // Extract network number and subnet mask
    for (i = 0, j = 0; i < strlen(ip); i++) {
        if (ip[i] == '.') {
            subnet.network_number[j] = '\0';
            j++;
        } else {
            strncat(subnet.network_number, &ip[i], 1);
        }
    }
    subnet.network_number[j] = '\0';

    for (i = 0; i < strlen(ip); i++) {
        if (ip[i] == '.') {
            subnet.subnet_mask[i] = '1';
            j++;
        } else if (ip[i] == '.' && j == 0) {
            subnet.subnet_mask[i] = '1';
            j++;
        } else {
            subnet.subnet_mask[i] = '0';
        }
    }

    printf("Network Number: %s\n", subnet.network_number);
    printf("Subnet Mask: %s\n", subnet.subnet_mask);

    return 0;
}