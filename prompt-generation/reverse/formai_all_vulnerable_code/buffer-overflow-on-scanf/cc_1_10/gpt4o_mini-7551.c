//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_IP_LENGTH 16
#define MAX_MASK_LENGTH 3

void convert_to_binary(int num, char *binary) {
    for (int i = 7; i >= 0; i--) {
        binary[i] = (num % 2) + '0';
        num /= 2;
    }
    binary[8] = '\0';
}

void calculate_subnet_info(const char *ip_str, const char *mask_str) {
    struct in_addr ip_addr, mask_addr, network_addr, broadcast_addr;
    if (inet_pton(AF_INET, ip_str, &ip_addr) != 1 || inet_pton(AF_INET, mask_str, &mask_addr) != 1) {
        printf("Invalid IP address or subnet mask.\n");
        return;
    }

    // Calculate network address
    network_addr.s_addr = ip_addr.s_addr & mask_addr.s_addr;

    // Calculate broadcast address
    broadcast_addr.s_addr = network_addr.s_addr | ~mask_addr.s_addr;

    // Calculate number of hosts
    unsigned int num_hosts = (ntohl(~mask_addr.s_addr)) - 1;

    // Print results
    printf("IP Address: %s\n", inet_ntoa(ip_addr));
    printf("Subnet Mask: %s\n", inet_ntoa(mask_addr));
    printf("Network Address: %s\n", inet_ntoa(network_addr));
    printf("Broadcast Address: %s\n", inet_ntoa(broadcast_addr));
    printf("Number of Hosts: %u\n", num_hosts);
}

int main() {
    char ip[MAX_IP_LENGTH];
    char mask[MAX_MASK_LENGTH];

    printf("Welcome to the C Subnet Calculator!\n");
    while (1) {
        printf("Enter IP Address (or 'exit' to quit): ");
        scanf("%s", ip);
        if (strcmp(ip, "exit") == 0) {
            break;
        }

        printf("Enter Subnet Mask: ");
        scanf("%s", mask);

        calculate_subnet_info(ip, mask);
        printf("\n");
    }

    printf("Thank you for using the C Subnet Calculator. Goodbye!\n");
    return 0;
}