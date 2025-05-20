//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a given string is an IP address
int is_ip_address(char *ip) {
    int i, j, parts = 0;
    char *token;

    // Split the string into parts using dots as delimiters
    token = strtok(ip, ".");
    while (token!= NULL) {
        parts++;
        token = strtok(NULL, ".");
    }

    // Check if there are exactly four parts
    if (parts!= 4)
        return 0;

    // Check if each part is a number
    for (i = 0; i < 4; i++) {
        for (j = 0; j < strlen(token); j++) {
            if (!isdigit(token[j]))
                return 0;
        }
        token = strtok(NULL, ".");
    }

    return 1;
}

int main() {
    char ip[16], mask[16];
    int i, j, k, parts, subnet_size;

    // Get the IP address and subnet mask from the user
    printf("Enter the IP address: ");
    scanf("%s", ip);
    printf("Enter the subnet mask: ");
    scanf("%s", mask);

    // Check if the IP address and subnet mask are valid
    if (!is_ip_address(ip)) {
        printf("Invalid IP address.\n");
        return 1;
    }
    if (!is_ip_address(mask)) {
        printf("Invalid subnet mask.\n");
        return 1;
    }

    // Convert the IP address and subnet mask to binary
    for (i = 0; i < strlen(ip); i++) {
        if (ip[i] == '.') {
            parts++;
        }
    }
    for (i = 0; i < strlen(mask); i++) {
        if (mask[i] == '.') {
            parts++;
        }
    }
    for (i = 0; i < strlen(ip); i++) {
        if (ip[i] == '.') {
            for (j = 0; j < 3; j++) {
                sprintf(&ip[i+1+j*4], "%d", (int)ip[i+j*4] & 0xff);
            }
        }
    }
    for (i = 0; i < strlen(mask); i++) {
        if (mask[i] == '.') {
            for (j = 0; j < 3; j++) {
                sprintf(&mask[i+1+j*4], "%d", (int)mask[i+j*4] & 0xff);
            }
        }
    }

    // Calculate the subnet size
    subnet_size = 0;
    for (i = 0; i < strlen(mask); i++) {
        if (mask[i] == '1') {
            subnet_size++;
        }
    }

    // Calculate the subnet ID
    for (i = 0; i < strlen(ip); i++) {
        if (ip[i] == '.') {
            for (j = 0; j < subnet_size; j++) {
                k = i - j * 4;
                if (k >= 0 && k < strlen(ip)) {
                    sprintf(&ip[k], "%d", (int)ip[k] | (0xff << (8 - (j * 8))));
                }
            }
        }
    }

    // Print the results
    printf("IP address: %s\n", ip);
    printf("Subnet mask: %s\n", mask);
    printf("Subnet ID: %s\n", ip);
    printf("Subnet size: %d\n", subnet_size);

    return 0;
}