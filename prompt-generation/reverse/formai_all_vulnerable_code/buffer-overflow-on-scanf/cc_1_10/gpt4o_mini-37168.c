//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <math.h>

void print_binary(int num) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}

void calculate_subnet(const char *ip, const char *subnet_mask) {
    struct in_addr ip_addr, mask_addr, network_addr;
    inet_pton(AF_INET, ip, &ip_addr);
    inet_pton(AF_INET, subnet_mask, &mask_addr);

    // Calculate Network Address
    network_addr.s_addr = ip_addr.s_addr & mask_addr.s_addr;

    printf("IP Address: %s\n", ip);
    printf("Subnet Mask: %s\n", subnet_mask);
    printf("Network Address: %s\n", inet_ntoa(network_addr));
    
    printf("Subnet in Binary:\n");
    printf("IP Address: ");
    print_binary(ip_addr.s_addr >> 24);
    printf(".");
    print_binary((ip_addr.s_addr >> 16) & 0xFF);
    printf(".");
    print_binary((ip_addr.s_addr >> 8) & 0xFF);
    printf(".");
    print_binary(ip_addr.s_addr & 0xFF);
    printf("\n");

    printf("Subnet Mask: ");
    print_binary(mask_addr.s_addr >> 24);
    printf(".");
    print_binary((mask_addr.s_addr >> 16) & 0xFF);
    printf(".");
    print_binary((mask_addr.s_addr >> 8) & 0xFF);
    printf(".");
    print_binary(mask_addr.s_addr & 0xFF);
    printf("\n");
}

void cidr_to_mask(int cidr, char *subnet_mask) {
    unsigned int mask = 0xFFFFFFFF << (32 - cidr);
    sprintf(subnet_mask, "%d.%d.%d.%d",
            (mask >> 24) & 0xFF,
            (mask >> 16) & 0xFF,
            (mask >> 8) & 0xFF,
            mask & 0xFF);
}

void print_menu() {
    printf("************************************************************\n");
    printf("*                 C Subnet Calculator                        *\n");
    printf("************************************************************\n");
    printf("1. Calculate Subnet\n");
    printf("2. Convert CIDR to Subnet Mask\n");
    printf("3. Exit\n");
    printf("************************************************************\n");
    printf("Select an option: ");
}

int main() {
    int option;
    char ip[16], subnet_mask[16];
    int cidr;

    while (1) {
        print_menu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter IP Address (e.g., 192.168.1.1): ");
                scanf("%s", ip);
                printf("Enter Subnet Mask (e.g., 255.255.255.0): ");
                scanf("%s", subnet_mask);
                calculate_subnet(ip, subnet_mask);
                break;

            case 2:
                printf("Enter CIDR notation (e.g., 24): ");
                scanf("%d", &cidr);
                cidr_to_mask(cidr, subnet_mask);
                printf("Subnet Mask for CIDR /%d is %s\n", cidr, subnet_mask);
                break;

            case 3:
                printf("Exiting... Thank you for using the C Subnet Calculator!\n");
                return 0;

            default:
                printf("Invalid option, please try again.\n");
        }
        printf("\n");
    }

    return 0;
}