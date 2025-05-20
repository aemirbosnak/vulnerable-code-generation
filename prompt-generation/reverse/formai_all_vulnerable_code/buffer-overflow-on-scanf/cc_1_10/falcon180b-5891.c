//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SIZE 1000

// Function to check if a string is a valid IP address
int is_valid_ip(char *ip) {
    int i, j;
    char *ptr;
    int nums = 0;
    int dots = 0;

    for (i = 0; i < strlen(ip); i++) {
        if (isdigit(ip[i])) {
            nums++;
        } else if (ip[i] == '.') {
            dots++;
        }
    }

    if (nums!= 4 || dots!= 3) {
        return 0;
    }

    for (i = 0; i < strlen(ip); i++) {
        if (ip[i] == '.') {
            ptr = strchr(ip, '.') + 1;
            if (atoi(ptr) < 0 || atoi(ptr) > 255) {
                return 0;
            }
        }
    }

    return 1;
}

// Function to calculate the subnet mask
void calculate_subnet_mask(int ip_address[], int subnet_mask[], int subnet_bits) {
    int i;
    int mask = (int)pow(2, subnet_bits) - 1;

    for (i = 0; i < 4; i++) {
        subnet_mask[i] = mask;
        mask >>= 8;
    }
}

// Function to print the subnet mask
void print_subnet_mask(int subnet_mask[]) {
    int i;

    for (i = 0; i < 4; i++) {
        printf("%d. ", subnet_mask[i]);
    }
}

// Function to print the IP address
void print_ip_address(int ip_address[]) {
    int i;

    for (i = 0; i < 4; i++) {
        printf("%d. ", ip_address[i]);
    }
}

int main() {
    char ip_str[MAX_SIZE];
    int ip_address[4];
    int subnet_bits;
    int subnet_mask[4];
    int i;

    printf("Enter the IP address: ");
    scanf("%s", ip_str);

    if (!is_valid_ip(ip_str)) {
        printf("Invalid IP address!\n");
        return 1;
    }

    for (i = 0; i < 4; i++) {
        ip_address[i] = atoi(strtok(ip_str, "."));
    }

    printf("Enter the number of subnet bits: ");
    scanf("%d", &subnet_bits);

    calculate_subnet_mask(ip_address, subnet_mask, subnet_bits);

    printf("IP address: ");
    print_ip_address(ip_address);

    printf("Subnet mask: ");
    print_subnet_mask(subnet_mask);

    return 0;
}