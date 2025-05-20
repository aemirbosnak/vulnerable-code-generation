//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_IP_LEN 16
#define MAX_MASK_LEN 3

// Function to validate IP address
int validate_ip(const char* ip) {
    struct sockaddr_in sa;
    return inet_pton(AF_INET, ip, &(sa.sin_addr)) != 0;
}

// Function to calculate the number of hosts in a subnet
unsigned int calculate_hosts(int subnet_mask) {
    return (1 << (32 - subnet_mask)) - 2; // -2 for network and broadcast addresses
}

// Function to calculate the subnet info
void calculate_subnet(const char* ip, int subnet_mask) {
    struct sockaddr_in sa;
    inet_pton(AF_INET, ip, &(sa.sin_addr));

    unsigned int ip_num = ntohl(sa.sin_addr.s_addr);
    unsigned int netmask_num = (0xFFFFFFFF >> subnet_mask) ^ 0xFFFFFFFF;
    unsigned int subnet_address = ip_num & netmask_num;
    unsigned int broadcast_address = subnet_address | ~netmask_num;

    char subnet_ip[MAX_IP_LEN];
    char broadcast_ip[MAX_IP_LEN];

    inet_ntop(AF_INET, &subnet_address, subnet_ip, sizeof(subnet_ip));
    inet_ntop(AF_INET, &broadcast_address, broadcast_ip, sizeof(broadcast_ip));

    unsigned int total_hosts = calculate_hosts(subnet_mask);

    printf("IP Address: %s\n", ip);
    printf("Subnet Mask: /%d\n", subnet_mask);
    printf("Subnet Address: %s\n", subnet_ip);
    printf("Broadcast Address: %s\n", broadcast_ip);
    printf("Total Usable Hosts: %u\n", total_hosts);
}

// Function to display menu and get user input
void display_menu() {
    char ip[MAX_IP_LEN];
    int subnet_mask;

    printf("=== C Subnet Calculator ===\n");
    printf("Enter the IP address (format: X.X.X.X): ");
    fgets(ip, sizeof(ip), stdin);
    ip[strcspn(ip, "\n")] = 0; // Remove newline character

    if (!validate_ip(ip)) {
        printf("Invalid IP address format.\n");
        return;
    }

    printf("Enter the subnet mask (1-30): ");
    scanf("%d", &subnet_mask);
    if (subnet_mask < 1 || subnet_mask > 30) {
        printf("Invalid subnet mask. Please enter a value between 1-30.\n");
        return;
    }

    calculate_subnet(ip, subnet_mask);
}

// Main function
int main() {
    int continue_calculating = 1;

    while (continue_calculating) {
        display_menu();
        printf("\nDo you want to perform another calculation? (1 for Yes, 0 for No): ");
        scanf("%d", &continue_calculating);
        printf("\n");
    }

    printf("Thank you for using the C Subnet Calculator!\n");

    return 0;
}