//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_IP_LEN 16
#define MAX_SUBNET_LEN 5

// Function prototypes
int get_ip_address(char *ip);
int get_subnet_mask(char *subnet);
void print_subnet_info(char *ip, char *subnet, int num_hosts);

// Main function
int main() {
    // Declare variables
    char ip[MAX_IP_LEN];
    char subnet[MAX_SUBNET_LEN];
    int num_hosts;

    // Get the IP address from the user
    printf("Enter an IP address: ");
    if (get_ip_address(ip) == 0) {
        printf("Invalid IP address.\n");
        return 1;
    }

    // Get the subnet mask from the user
    printf("Enter a subnet mask: ");
    if (get_subnet_mask(subnet) == 0) {
        printf("Invalid subnet mask.\n");
        return 1;
    }

    // Calculate the number of hosts on the subnet
    num_hosts = pow(2, 32 - atoi(subnet)) - 2;

    // Print the subnet information
    print_subnet_info(ip, subnet, num_hosts);

    return 0;
}

// Get the IP address from the user
int get_ip_address(char *ip) {
    // Check if the IP address is valid
    if (strlen(ip) > MAX_IP_LEN) {
        return 0;
    }
    for (int i = 0; i < strlen(ip); i++) {
        if (ip[i] < '0' || ip[i] > '9' || (i > 0 && ip[i] == '.')) {
            return 0;
        }
    }

    // Convert the IP address to a binary string
    char binary[33];
    int octets[4];
    sscanf(ip, "%d.%d.%d.%d", &octets[0], &octets[1], &octets[2], &octets[3]);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            binary[i * 8 + j] = (octets[i] & (1 << (7 - j))) ? '1' : '0';
        }
    }
    binary[32] = '\0';

    // Copy the binary string to the IP address buffer
    strcpy(ip, binary);

    return 1;
}

// Get the subnet mask from the user
int get_subnet_mask(char *subnet) {
    // Check if the subnet mask is valid
    if (strlen(subnet) > MAX_SUBNET_LEN) {
        return 0;
    }
    for (int i = 0; i < strlen(subnet); i++) {
        if (subnet[i] < '0' || subnet[i] > '9') {
            return 0;
        }
    }

    // Convert the subnet mask to a binary string
    char binary[33];
    int mask = atoi(subnet);
    for (int i = 0; i < mask; i++) {
        binary[i] = '1';
    }
    for (int i = mask; i < 32; i++) {
        binary[i] = '0';
    }
    binary[32] = '\0';

    // Copy the binary string to the subnet mask buffer
    strcpy(subnet, binary);

    return 1;
}

// Print the subnet information
void print_subnet_info(char *ip, char *subnet, int num_hosts) {
    // Print the IP address
    printf("IP address: ");
    for (int i = 0; i < 32; i++) {
        printf("%c", ip[i]);
        if (i % 8 == 7) {
            printf(".");
        }
    }
    printf("\n");

    // Print the subnet mask
    printf("Subnet mask: ");
    for (int i = 0; i < 32; i++) {
        printf("%c", subnet[i]);
        if (i % 8 == 7) {
            printf(".");
        }
    }
    printf("\n");

    // Print the number of hosts on the subnet
    printf("Number of hosts: %d\n", num_hosts);
}