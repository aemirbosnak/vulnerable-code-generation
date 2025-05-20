//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to calculate subnet mask from prefix length
void calculate_subnet_mask(int prefix_length, char *subnet_mask) {
    unsigned int mask = 0xFFFFFFFF << (32 - prefix_length);
    sprintf(subnet_mask, "%d.%d.%d.%d",
            (mask >> 24) & 0xFF,
            (mask >> 16) & 0xFF,
            (mask >> 8) & 0xFF,
            mask & 0xFF);
}

// Function to calculate the number of usable hosts in the subnet
int calculate_hosts(int prefix_length) {
    return (int)pow(2, (32 - prefix_length)) - 2; // Subtracting network and broadcast addresses
}

// Function to validate IP address format
int validate_ip(const char *ip) {
    int num, dots = 0;
    const char *ptr = ip;

    while (*ptr) {
        if (*ptr == '.') {
            dots++;
            if (num < 0 || num > 255) return 0;
            num = 0; // Reset for next block
        } else if (*ptr >= '0' && *ptr <= '9') {
            num = num * 10 + (*ptr - '0');
        } else {
            return 0; // Invalid character
        }
        ptr++;
    }
    return (dots == 3 && num >= 0 && num <= 255); // Check for valid last block
}

// Function to get user input for IP address and prefix length
void get_user_input(char *ip, int *prefix_length) {
    printf("Enter the IP Address (X.X.X.X format): ");
    fgets(ip, 16, stdin);
    ip[strcspn(ip, "\n")] = 0; // Remove newline

    printf("Enter Subnet Prefix Length (1-30): ");
    scanf("%d", prefix_length);

    while (*prefix_length < 1 || *prefix_length > 30) {
        printf("Invalid prefix length! Please enter a value (1-30): ");
        scanf("%d", prefix_length);
    }
}

// Main function
int main() {
    char ip[16];
    int prefix_length;
    char subnet_mask[16];
    int usable_hosts;

    get_user_input(ip, &prefix_length);

    if (!validate_ip(ip)) {
        printf("Invalid IP address format!\n");
        return 1;
    }

    calculate_subnet_mask(prefix_length, subnet_mask);
    usable_hosts = calculate_hosts(prefix_length);

    printf("\n--- Subnet Calculator ---\n");
    printf("IP Address: %s\n", ip);
    printf("Subnet Mask: %s\n", subnet_mask);
    printf("Prefix Length: /%d\n", prefix_length);
    printf("Total Usable Hosts: %d\n", usable_hosts);
    
    return 0;
}