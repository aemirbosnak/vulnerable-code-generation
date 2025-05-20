//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

void calculateSubnet(char *ip, char *mask) {
    struct sockaddr_in ip_addr, mask_addr, network_addr, broadcast_addr;
    
    // Convert IP address and subnet mask from string to binary
    inet_pton(AF_INET, ip, &(ip_addr.sin_addr));
    inet_pton(AF_INET, mask, &(mask_addr.sin_addr));

    // Calculate network and broadcast addresses
    network_addr.sin_addr.s_addr = ip_addr.sin_addr.s_addr & mask_addr.sin_addr.s_addr;
    broadcast_addr.sin_addr.s_addr = network_addr.sin_addr.s_addr | ~mask_addr.sin_addr.s_addr;

    // Convert back to string for displaying results
    char network[INET_ADDRSTRLEN];
    char broadcast[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(network_addr.sin_addr), network, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &(broadcast_addr.sin_addr), broadcast, INET_ADDRSTRLEN);

    printf("IP Address: %s\n", ip);
    printf("Subnet Mask: %s\n", mask);
    printf("Network Address: %s\n", network);
    printf("Broadcast Address: %s\n", broadcast);
    
    // Calculate the number of valid hosts
    unsigned int mask_bits = 0;
    for (int i = 0; i < 32; i++) {
        if ((mask_addr.sin_addr.s_addr >> (31 - i)) & 1) {
            mask_bits++;
        } else {
            break;
        }
    }
    unsigned int hosts = (1 << (32 - mask_bits)) - 2; // Subtract 2 for network and broadcast addresses
    printf("Total Valid Hosts: %u\n", hosts);
}

int validateIP(char *ip) {
    struct sockaddr_in sa;
    return inet_pton(AF_INET, ip, &(sa.sin_addr));
}

int validateMask(char *mask) {
    int num = 0;
    int dots = 0;
    char *temp = strtok(mask, ".");

    while (temp != NULL) {
        num = atoi(temp);
        if (num < 0 || num > 255) {
            return 0;
        }
        if (num > 0) {
            dots++;
        }
        temp = strtok(NULL, ".");
    }
    return (dots > 0 && dots <= 4); // Valid subnet mask should have 1 to 4 octets
}

int main() {
    char ip[INET_ADDRSTRLEN];
    char mask[INET_ADDRSTRLEN];

    printf("Welcome to the C Subnet Calculator!\n");
    
    while (1) {
        printf("Enter an IP Address (or type 'exit' to quit): ");
        scanf("%s", ip);
        if (strcmp(ip, "exit") == 0) {
            printf("Exiting...\n");
            break;
        }
        
        if (!validateIP(ip)) {
            printf("Invalid IP Address format. Please try again.\n");
            continue;
        }

        printf("Enter Subnet Mask: ");
        scanf("%s", mask);
        if (!validateMask(mask)) {
            printf("Invalid Subnet Mask format. Please try again.\n");
            continue;
        }

        calculateSubnet(ip, mask);
    }

    return 0;
}