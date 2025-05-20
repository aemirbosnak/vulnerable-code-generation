//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

// Function to calculate subnet mask
void calculate_subnet_mask(int subnet_prefix) {
    unsigned int mask = (0xFFFFFFFF << (32 - subnet_prefix)) & 0xFFFFFFFF;
    struct in_addr addr;
    addr.s_addr = htonl(mask);
    printf("Subnet Mask: %s\n", inet_ntoa(addr));
}

// Function to calculate the network address
void calculate_network_address(const char *ip, int subnet_prefix) {
    struct in_addr ip_addr;
    inet_aton(ip, &ip_addr);
    unsigned int mask = (0xFFFFFFFF << (32 - subnet_prefix)) & 0xFFFFFFFF;
    
    unsigned int network_address = ip_addr.s_addr & htonl(mask);
    struct in_addr network_addr;
    network_addr.s_addr = network_address;    
    printf("Network Address: %s\n", inet_ntoa(network_addr));
}

// Function to calculate broadcast address
void calculate_broadcast_address(const char *ip, int subnet_prefix) {
    struct in_addr ip_addr;
    inet_aton(ip, &ip_addr);
    
    unsigned int mask = (0xFFFFFFFF << (32 - subnet_prefix)) & 0xFFFFFFFF;
    unsigned int broadcast_address = (ip_addr.s_addr & htonl(mask)) | ~htonl(mask);
    
    struct in_addr broadcast_addr;
    broadcast_addr.s_addr = broadcast_address;
    printf("Broadcast Address: %s\n", inet_ntoa(broadcast_addr));
}

// Function to calculate total number of hosts
void calculate_total_hosts(int subnet_prefix) {
    int number_of_hosts = (1 << (32 - subnet_prefix)) - 2; // Subtracting 2 for network and broadcast address
    printf("Total Hosts: %d\n", number_of_hosts);
}

// Function to validate IP address
int is_valid_ip(const char *ip) {
    struct in_addr ip_addr;
    return inet_aton(ip, &ip_addr);
}

// Function to display menu
void display_menu() {
    printf("\n----- C Subnet Calculator -----\n");
    printf("1. Calculate Subnet Mask\n");
    printf("2. Calculate Network Address\n");
    printf("3. Calculate Broadcast Address\n");
    printf("4. Calculate Total Hosts\n");
    printf("5. Exit\n");
    printf("-------------------------------\n");
    printf("Enter your choice: ");
}

int main() {
    char ip[16];
    int subnet_prefix;
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        if (choice == 5) {
            break;
        }

        printf("Enter IP address (e.g., 192.168.1.1): ");
        scanf("%s", ip);

        if (!is_valid_ip(ip)) {
            printf("Invalid IP Address. Please enter a valid IP.\n");
            continue;
        }

        printf("Enter Subnet Prefix (e.g., 24): ");
        scanf("%d", &subnet_prefix);

        if (subnet_prefix < 0 || subnet_prefix > 32) {
            printf("Invalid subnet prefix. Please enter a value between 0 and 32.\n");
            continue;
        }

        switch (choice) {
            case 1:
                calculate_subnet_mask(subnet_prefix);
                break;
            case 2:
                calculate_network_address(ip, subnet_prefix);
                break;
            case 3:
                calculate_broadcast_address(ip, subnet_prefix);
                break;
            case 4:
                calculate_total_hosts(subnet_prefix);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    printf("Exiting Subnet Calculator. Thank you!\n");
    return 0;
}