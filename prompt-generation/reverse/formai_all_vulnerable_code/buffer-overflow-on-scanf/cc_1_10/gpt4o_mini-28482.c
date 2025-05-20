//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

void display_menu() {
    printf("Welcome to the Silly Subnet Calculator! 🥳\n");
    printf("Let's find out how many friends (hosts) you can invite!\n");
    printf("-----------------------------------------------------\n");
    printf("1. Calculate Subnet\n");
    printf("2. Check IP Validity\n");
    printf("3. Exit\n");
    printf("What would you like to do? (Enter 1, 2, or 3): ");
}

int is_valid_ip(const char *ip) {
    struct sockaddr_in sa;
    return inet_pton(AF_INET, ip, &(sa.sin_addr));
}

void calculate_subnet(const char *ip, const char *subnet_mask) {
    unsigned int mask = atoi(subnet_mask);
    if (mask < 0 || mask > 32) {
        printf("Uh-oh! Is that subnet mask a valid number? (0-32)\n");
        return;
    }

    unsigned long number_of_hosts = (1UL << (32 - mask)) - 2; // -2 for network and broadcast addresses
    printf("With a subnet mask of /%s, you can invite %lu friends to your network party!\n", subnet_mask, number_of_hosts);
}

int main() {
    while (1) {
        display_menu();

        int choice;
        scanf("%d", &choice);
        getchar(); // Consume newline left by scanf

        if (choice == 1) {
            char ip[16]; // IPv4 addresses are max 15 characters + 1 for null terminator
            char subnet_mask[3]; // Subnet mask in CIDR notation, fits 0-32

            printf("Enter the IP address (e.g., 192.168.1.1): ");
            fgets(ip, sizeof(ip), stdin);
            strtok(ip, "\n"); // Remove trailing newline

            if (!is_valid_ip(ip)) {
                printf("Oops! That doesn't look like a valid IP address. 😳\n");
                continue;
            }

            printf("Enter the subnet mask (between 0 and 32): ");
            fgets(subnet_mask, sizeof(subnet_mask), stdin);
            strtok(subnet_mask, "\n"); // Remove trailing newline

            calculate_subnet(ip, subnet_mask);
        } else if (choice == 2) {
            char ip[16];
            printf("Enter the IP address to check: ");
            fgets(ip, sizeof(ip), stdin);
            strtok(ip, "\n"); // Remove trailing newline

            if (is_valid_ip(ip)) {
                printf("The IP address %s is valid! 🎉 You can pan-fry packets here!\n", ip);
            } else {
                printf("Nope! The IP address %s is fishy! 🐟 Try again!\n", ip);
            }
        } else if (choice == 3) {
            printf("Thanks for stopping by the Silly Subnet Calculator! Bye! 👋\n");
            break;
        } else {
            printf("Whoa there! Please choose a valid option! 🕵️‍♂️\n");
        }
    }

    return 0;
}