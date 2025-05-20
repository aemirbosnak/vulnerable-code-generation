//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a given string is a valid IP address
int is_valid_ip(char* ip) {
    int i, j;
    char* token;

    // Split the IP address into four parts
    token = strtok(ip, ".");
    if (token == NULL) {
        return 0; // Invalid IP address
    }

    for (i = 0; i < 4; i++) {
        if ((token = strtok(NULL, ".")) == NULL) {
            return 0; // Invalid IP address
        }

        j = strlen(token);
        if (j == 0 || j > 3) {
            return 0; // Invalid IP address
        }

        for (int k = 0; k < j; k++) {
            if (!isdigit(token[k])) {
                return 0; // Invalid IP address
            }
        }
    }

    return 1; // Valid IP address
}

// Function to calculate the subnet mask
void calculate_subnet_mask(char* ip, char* mask) {
    int i, j;
    char* token;

    // Split the IP address into four parts
    token = strtok(ip, ".");
    i = atoi(token);
    for (j = 0; j < 3; j++) {
        token = strtok(NULL, ".");
        if (token == NULL) {
            break;
        }
        i = (i << 8) | atoi(token);
    }

    // Calculate the subnet mask
    sprintf(mask, "255.%d.%d.%d", (255 << (32 - i)) >> 24, (255 << (32 - i)) >> 16, (255 << (32 - i)) >> 8);
}

// Function to print the subnet mask
void print_subnet_mask(char* mask) {
    printf("Subnet mask: %s\n", mask);
}

// Function to print the usage of the program
void print_usage() {
    printf("Usage:./subnet_calculator <IP address>\n");
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        print_usage();
        return 1;
    }

    // Check if the given IP address is valid
    if (!is_valid_ip(argv[1])) {
        printf("Invalid IP address\n");
        return 1;
    }

    // Calculate the subnet mask
    char subnet_mask[16];
    calculate_subnet_mask(argv[1], subnet_mask);

    // Print the subnet mask
    print_subnet_mask(subnet_mask);

    return 0;
}