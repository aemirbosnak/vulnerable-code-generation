//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_SUBNETS 10

void printBinaryIP(unsigned int ip) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (ip >> i) & 1);
        if (i % 8 == 0) {
            printf(" ");
        }
    }
    printf("\n");
}

unsigned int cidrToSubnetMask(int cidr) {
    return (unsigned int)(~((1 << (32 - cidr)) - 1));
}

void calculateSubnets(const char *ip_addr, int cidr) {
    unsigned int subnet_mask = cidrToSubnetMask(cidr);
    struct in_addr addr;

    inet_pton(AF_INET, ip_addr, &addr);
    unsigned int base_ip = ntohl(addr.s_addr) & subnet_mask;
    
    printf("Base IP Address: %s\n", ip_addr);
    printf("Subnet Mask (CIDR /%d): ", cidr);
    printBinaryIP(subnet_mask);

    printf("Subnets:\n");
    for (int i = 0; i < MAX_SUBNETS; i++) {
        unsigned int subnet_ip = base_ip + (i * (1 << (32 - cidr)));
        struct in_addr subnet_addr;
        subnet_addr.s_addr = htonl(subnet_ip);
        printf("Subnet %d: %s\n", i + 1, inet_ntoa(subnet_addr));
    }
}

void displayMenu() {
    printf("Subnet Calculator\n");
    printf("===================\n");
    printf("1. Calculate Subnets\n");
    printf("2. Exit\n");
}

int main() {
    char ip_addr[16];
    int cidr;
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the IP Address (e.g., 192.168.1.1): ");
                scanf("%s", ip_addr);
                printf("Enter CIDR notation (e.g., 24): ");
                scanf("%d", &cidr);

                if (cidr < 0 || cidr > 32) {
                    printf("Invalid CIDR notation. It should be between 0 and 32.\n");
                    break;
                }

                calculateSubnets(ip_addr, cidr);
                break;
            case 2:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        printf("\n");
    }

    return 0;
}