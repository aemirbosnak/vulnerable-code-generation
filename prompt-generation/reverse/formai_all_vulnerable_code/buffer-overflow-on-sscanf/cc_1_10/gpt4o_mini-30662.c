//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void calculate_subnet(unsigned char ip[4], unsigned char mask[4]);
void get_input();

int main() {
    get_input();
    return 0;
}

void get_input() {
    unsigned char ip[4], mask[4];
    char ip_str[16], mask_str[16];

    printf("Enter IP address (e.g., 192.168.1.1): ");
    fgets(ip_str, sizeof(ip_str), stdin);
    sscanf(ip_str, "%hhu.%hhu.%hhu.%hhu", &ip[0], &ip[1], &ip[2], &ip[3]);

    printf("Enter Subnet Mask (e.g., 255.255.255.0): ");
    fgets(mask_str, sizeof(mask_str), stdin);
    sscanf(mask_str, "%hhu.%hhu.%hhu.%hhu", &mask[0], &mask[1], &mask[2], &mask[3]);

    calculate_subnet(ip, mask);
}

void calculate_subnet(unsigned char ip[4], unsigned char mask[4]) {
    unsigned char subnet[4], broadcast[4], valid_start[4], valid_end[4];

    // Calculate subnet address
    for (int i = 0; i < 4; i++) {
        subnet[i] = ip[i] & mask[i];
    }

    // Calculate broadcast address
    for (int i = 0; i < 4; i++) {
        broadcast[i] = subnet[i] | (~mask[i] & 0xFF);
    }

    // Calculate valid host range
    valid_start[0] = subnet[0];
    valid_start[1] = subnet[1];
    valid_start[2] = subnet[2];
    valid_start[3] = subnet[3] + 1; // First valid host

    valid_end[0] = broadcast[0];
    valid_end[1] = broadcast[1];
    valid_end[2] = broadcast[2];
    valid_end[3] = broadcast[3] - 1; // Last valid host

    printf("Subnet Address: %d.%d.%d.%d\n", subnet[0], subnet[1], subnet[2], subnet[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n", broadcast[0], broadcast[1], broadcast[2], broadcast[3]);
    printf("Valid Host Range: %d.%d.%d.%d - %d.%d.%d.%d\n", 
        valid_start[0], valid_start[1], valid_start[2], valid_start[3], 
        valid_end[0], valid_end[1], valid_end[2], valid_end[3]);

    // Ask to calculate again or exit
    char choice;
    printf("Do you want to calculate another subnet? (y/n): ");
    scanf(" %c", &choice);
    getchar(); // clear the newline character left by scanf
    if (choice == 'y' || choice == 'Y') {
        get_input();
    } else {
        printf("Exiting the program. Goodbye!\n");
    }
}