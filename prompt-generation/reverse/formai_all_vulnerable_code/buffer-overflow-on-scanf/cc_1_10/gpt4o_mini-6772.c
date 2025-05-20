//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_SUBNETS 100
#define MAX_IP_LENGTH 16

void print_binary(unsigned char byte) {
    for (int i = 7; i >= 0; i--) {
        putchar((byte & (1 << i)) ? '1' : '0');
    }
}

void calculate_subnets(const char *ip, int prefix_length) {
    struct in_addr addr;
    if (inet_pton(AF_INET, ip, &addr) != 1) {
        printf("Invalid IP address format.\n");
        return;
    }

    unsigned int subnet_mask = (0xFFFFFFFF << (32 - prefix_length)) & 0xFFFFFFFF;
    unsigned int network = ntohl(addr.s_addr) & subnet_mask;
    unsigned int broadcast = network | ~subnet_mask;

    printf("\nCalculating for IP: %s/%d\n", ip, prefix_length);
    printf("IP Address: %s\n", ip);
    printf("Subnet Mask: %d.%d.%d.%d\n", 
           (subnet_mask >> 24) & 0xFF, 
           (subnet_mask >> 16) & 0xFF, 
           (subnet_mask >> 8) & 0xFF, 
           subnet_mask & 0xFF);
    printf("Network Address: %d.%d.%d.%d\n", 
           (network >> 24) & 0xFF, 
           (network >> 16) & 0xFF, 
           (network >> 8) & 0xFF, 
           network & 0xFF);
    printf("Broadcast Address: %d.%d.%d.%d\n", 
           (broadcast >> 24) & 0xFF, 
           (broadcast >> 16) & 0xFF, 
           (broadcast >> 8) & 0xFF, 
           broadcast & 0xFF);

    printf("Subnet in Binary:\n");
    for (int i = 0; i < 4; i++) {
        print_binary(((subnet_mask >> (8 * (3 - i))) & 0xFF));
        printf(" ");
    }
    printf("\n");

    printf("Network in Binary:\n");
    for (int i = 0; i < 4; i++) {
        print_binary(((network >> (8 * (3 - i))) & 0xFF));
        printf(" ");
    }
    printf("\n");

    printf("Broadcast in Binary:\n");
    for (int i = 0; i < 4; i++) {
        print_binary(((broadcast >> (8 * (3 - i))) & 0xFF));
        printf(" ");
    }
    printf("\n");
}

int main() {
    char ip_address[MAX_IP_LENGTH];
    int prefix;

    printf("C Subnet Calculator\n");
    printf("====================\n");

    while (1) {
        printf("Enter the IP address and prefix length (format: x.x.x.x/prefix): ");
        if (fgets(ip_address, MAX_IP_LENGTH, stdin) == NULL) {
            break;
        }

        char *slash = strchr(ip_address, '/');
        if (slash != NULL) {
            *slash = '\0';  // Terminate the string at the slash
            prefix = atoi(slash + 1);  // Get the prefix
            if (prefix < 0 || prefix > 32) {
                printf("Invalid prefix length. It must be between 0 and 32.\n");
                continue;
            }
        } else {
            printf("Invalid format. Please use x.x.x.x/prefix\n");
            continue;
        }

        calculate_subnets(ip_address, prefix);
        printf("\nWould you like to calculate another subnet? (y/n): ");
        char response;
        scanf(" %c", &response);
        getchar(); // Clear the newline left by scanf
        if (response != 'y' && response != 'Y') {
            break;
        }
    }

    printf("Thank you for using the C Subnet Calculator. Goodbye!\n");
    return 0;
}