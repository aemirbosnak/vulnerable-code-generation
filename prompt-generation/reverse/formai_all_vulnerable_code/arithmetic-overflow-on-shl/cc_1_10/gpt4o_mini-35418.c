//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_IP_LENGTH 16
#define MAX_SUBNET_MASK_LENGTH 3

void display_intro() {
    printf("=============================================\n");
    printf("  WELCOME TO THE SUBNET CALCULATOR 3000\n");
    printf("=============================================\n");
    printf("> In this neon-lit realm of Cyberpunk, your ");
    printf("IP address defines your existence.\n");
    printf("> Let's calculate the subnet so you can hide,\n");
    printf("  or let your data roam free in the matrix.\n");
    printf("=============================================\n\n");
}

int is_valid_ip(const char *ip) {
    struct sockaddr_in sa;
    return inet_pton(AF_INET, ip, &(sa.sin_addr)) != 0;
}

void calculate_subnet(const char *ip, int subnet_mask) {
    struct sockaddr_in ip_addr;
    inet_pton(AF_INET, ip, &(ip_addr.sin_addr));
    unsigned long ip_decimal = ntohl(ip_addr.sin_addr.s_addr);

    unsigned long subnet = (0xFFFFFFFF << (32 - subnet_mask)) & 0xFFFFFFFF;
    unsigned long network = ip_decimal & subnet;
    unsigned long broadcast = network | ~subnet;

    printf("Network Address: %s\n", inet_ntoa((struct in_addr){htonl(network)}));
    printf("Broadcast Address: %s\n", inet_ntoa((struct in_addr){htonl(broadcast)}));
    printf("Total Usable Hosts: %d\n", ((1 << (32 - subnet_mask)) - 2));
}

int main() {
    char ip[MAX_IP_LENGTH];
    char subnet_mask_str[MAX_SUBNET_MASK_LENGTH];
    int subnet_mask;

    display_intro();

    while (1) {
        printf("Enter the IP Address (or type 'exit' to leave): ");
        scanf("%15s", ip);
        if (strcmp(ip, "exit") == 0) break;

        if (!is_valid_ip(ip)) {
            printf("Invalid IP address. Try again.\n");
            continue;
        }

        printf("Enter the Subnet Mask (e.g., 24 for /24): ");
        scanf("%2s", subnet_mask_str);
        subnet_mask = atoi(subnet_mask_str);

        if (subnet_mask < 0 || subnet_mask > 32) {
            printf("Subnet mask must be between 0 and 32. Try again.\n");
            continue;
        }

        printf("\nCalculating subnet...\n");
        calculate_subnet(ip, subnet_mask);
        printf("\n=============================================\n");
    }

    printf("You have entered the matrix. Stay safe out there!\n");
    return 0;
}