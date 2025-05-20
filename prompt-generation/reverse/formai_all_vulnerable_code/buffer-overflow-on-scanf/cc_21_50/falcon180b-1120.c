//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: creative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void main() {
    char ip[16];
    char mask[16];
    char *ptr;
    int i, j, k, num, mask_len;

    // Get the IP address input from the user
    printf("Enter the IP address: ");
    scanf("%s", ip);

    // Check if the IP address is valid
    if (strlen(ip)!= 15 || ip[0] == '0' && ip[0]!= '1' || ip[0] == '2' && ip[0] > '2' || ip[0] == '3' && ip[0] > '3') {
        printf("Invalid IP address\n");
        exit(0);
    }

    // Get the subnet mask input from the user
    printf("Enter the subnet mask: ");
    scanf("%s", mask);

    // Check if the subnet mask is valid
    if (strlen(mask)!= 15 || mask[0] == '0' && mask[0]!= '1' || mask[0] == '2' && mask[0] > '2' || mask[0] == '3' && mask[0] > '3') {
        printf("Invalid subnet mask\n");
        exit(0);
    }

    // Convert the IP address and subnet mask to integers
    for (i = 0, j = 0; i < strlen(ip); i++) {
        if (ip[i] == '.') {
            ip[i] = '\0';
            num = atoi(ip + j);
            if (num < 0 || num > 255) {
                printf("Invalid IP address\n");
                exit(0);
            }
            j = i + 1;
        }
    }
    num = atoi(ip + j);
    if (num < 0 || num > 255) {
        printf("Invalid IP address\n");
        exit(0);
    }

    for (i = 0, j = 0; i < strlen(mask); i++) {
        if (mask[i] == '.') {
            mask[i] = '\0';
            num = atoi(mask + j);
            if (num < 0 || num > 255) {
                printf("Invalid subnet mask\n");
                exit(0);
            }
            j = i + 1;
        }
    }
    num = atoi(mask + j);
    if (num < 0 || num > 255) {
        printf("Invalid subnet mask\n");
        exit(0);
    }

    // Calculate the subnet ID
    mask_len = 32 - atoi(mask);
    for (i = 0; i < mask_len; i++) {
        ip[i] = '0';
    }

    // Calculate the broadcast address
    for (i = 0; i < mask_len; i++) {
        ip[strlen(ip) - 1 - i] = '255';
    }

    printf("IP address: %s\n", ip);
    printf("Subnet mask: %s\n", mask);
    printf("Subnet ID: %s\n", ip);
    printf("Broadcast address: %s\n", ip);
}