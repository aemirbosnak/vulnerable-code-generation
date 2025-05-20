//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_IP_LENGTH 16
#define MAX_MASK_LENGTH 3
#define MAX_OPTION_LENGTH 2

void parse_ip(const char *ip, int *octets);
void calculate_subnet(int *ip, int *mask, int *network, int *broadcast, int *valid_hosts);
int ip_is_valid(int *octets);
void display_results(int *ip, int *mask, int *network, int *broadcast, int valid_hosts);
void show_menu();
void execute_option(int choice);

int main() {
    int choice;

    do {
        show_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 5) {
            printf("Exiting program...\n");
            break;
        }
        execute_option(choice);
    } while (1);
    
    return 0;
}

void show_menu() {
    printf("\n--- Subnet Calculator ---\n");
    printf("1. Calculate Subnet\n");
    printf("2. Display Options\n");
    printf("3. Help\n");
    printf("4. About\n");
    printf("5. Exit\n");
}

void execute_option(int choice) {
    static char ip[MAX_IP_LENGTH];
    static char mask[MAX_MASK_LENGTH];

    switch (choice) {
        case 1:
            printf("Enter IP Address (x.x.x.x): ");
            scanf("%s", ip);
            printf("Enter Subnet Mask (255.255.255.0 or CIDR format): ");
            scanf("%s", mask);
            if (strlen(mask) > 2 && strchr(mask, '.')) {
                int octets[4] = {0};
                parse_ip(ip, octets);
                int subnet[4] = {0};
                parse_ip(mask, subnet);
                int network[4] = {0}, broadcast[4] = {0}, valid_hosts = 0;
                
                if (ip_is_valid(octets) && ip_is_valid(subnet)) {
                    calculate_subnet(octets, subnet, network, broadcast, &valid_hosts);
                    display_results(octets, subnet, network, broadcast, valid_hosts);
                } else {
                    printf("Invalid IP or Subnet Mask\n");
                }
            } else {
                // Assume CIDR format, convert to subnet mask
                int cidr = atoi(mask);
                if (cidr < 0 || cidr > 32) {
                    printf("Invalid CIDR notation\n");
                    return;
                }
                int subnet[4] = {0};
                for (int i = 0; i < 4; i++) {
                    if (cidr >= 8) {
                        subnet[i] = 255;
                        cidr -= 8;
                    } else {
                        subnet[i] = (1 << cidr) - 1 << (8 - cidr);
                        cidr = 0;
                    }
                }
                int octets[4] = {0};
                parse_ip(ip, octets);
                int network[4] = {0}, broadcast[4] = {0}, valid_hosts = 0;

                if (ip_is_valid(octets)) {
                    calculate_subnet(octets, subnet, network, broadcast, &valid_hosts);
                    display_results(octets, subnet, network, broadcast, valid_hosts);
                } else {
                    printf("Invalid IP Address\n");
                }
            }
            break;
        case 2:
            printf("Subnet calculation involves finding:\n");
            printf("- Network Address\n");
            printf("- Broadcast Address\n");
            printf("- Valid Hosts\n");
            break;
        case 3:
            printf("This program calculates subnet information based on IP addresses and subnet masks.\n");
            break;
        case 4:
            printf("Subnet Calculator Version 1.0\n");
            printf("Developed by OpenAI\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}

void parse_ip(const char *ip, int *octets) {
    sscanf(ip, "%d.%d.%d.%d", &octets[0], &octets[1], &octets[2], &octets[3]);
}

void calculate_subnet(int *ip, int *mask, int *network, int *broadcast, int *valid_hosts) {
    for (int i = 0; i < 4; i++) {
        network[i] = ip[i] & mask[i];
        broadcast[i] = network[i] | (~mask[i] & 255);
    }
    *valid_hosts = (1 << (32 - (mask[0] + mask[1] + mask[2] + mask[3]))) - 2; // -2 for network and broadcast
}

int ip_is_valid(int *octets) {
    for (int i = 0; i < 4; i++) {
        if (octets[i] < 0 || octets[i] > 255) {
            return 0;
        }
    }
    return 1;
}

void display_results(int *ip, int *mask, int *network, int *broadcast, int valid_hosts) {
    printf("\n--- Subnet Calculation Results ---\n");
    printf("IP Address: %d.%d.%d.%d\n", ip[0], ip[1], ip[2], ip[3]);
    printf("Subnet Mask: %d.%d.%d.%d\n", mask[0], mask[1], mask[2], mask[3]);
    printf("Network Address: %d.%d.%d.%d\n", network[0], network[1], network[2], network[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n", broadcast[0], broadcast[1], broadcast[2], broadcast[3]);
    printf("Number of Valid Hosts: %d\n", valid_hosts);
}