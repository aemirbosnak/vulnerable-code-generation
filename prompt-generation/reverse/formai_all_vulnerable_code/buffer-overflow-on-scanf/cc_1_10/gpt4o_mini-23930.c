//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <arpa/inet.h>

#define IPV4_MASK_LENGTH 32
#define MAX_IP_LENGTH 16   // e.g., "255.255.255.255"

void validate_ip(const char *ip) {
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, ip, &(sa.sin_addr));
    if (result != 1) {
        fprintf(stderr, "Invalid IP address format: %s\n", ip);
        exit(EXIT_FAILURE);
    }
}

void validate_mask(int mask) {
    if(mask < 0 || mask > IPV4_MASK_LENGTH) {
        fprintf(stderr, "Invalid subnet mask: %d\n", mask);
        exit(EXIT_FAILURE);
    }
}

void calculate_subnet(const char *ip, int mask) {
    uint32_t ip_int, subnet_int, broadcast_int;
    struct sockaddr_in sa;

    // Convert IP address to uint32_t
    inet_pton(AF_INET, ip, &(sa.sin_addr));
    ip_int = ntohl(sa.sin_addr.s_addr);

    // Calculate subnet
    subnet_int = ip_int & (0xFFFFFFFF << (IPV4_MASK_LENGTH - mask));
    broadcast_int = subnet_int | ~((0xFFFFFFFF << (IPV4_MASK_LENGTH - mask)));

    // Output results
    struct in_addr subnet_addr, broadcast_addr;
    subnet_addr.s_addr = htonl(subnet_int);
    broadcast_addr.s_addr = htonl(broadcast_int);

    printf("IP Address: %s\n", ip);
    printf("Subnet Mask: /%d\n", mask);
    printf("Subnet Address: %s\n", inet_ntoa(subnet_addr));
    printf("Broadcast Address: %s\n", inet_ntoa(broadcast_addr));
}

int main() {
    char ip[MAX_IP_LENGTH];
    int mask;

    printf("Enter the IP address (e.g., 192.168.1.1): ");
    if (fgets(ip, sizeof(ip), stdin) == NULL) {
        fprintf(stderr, "Error reading IP address.\n");
        return EXIT_FAILURE;
    }
    
    // Remove any trailing newline character
    ip[strcspn(ip, "\n")] = 0;

    validate_ip(ip);

    printf("Enter the subnet mask (0-32): ");
    if (scanf("%d", &mask) != 1) {
        fprintf(stderr, "Error reading subnet mask. Make sure to enter a number.\n");
        return EXIT_FAILURE;
    }

    validate_mask(mask);

    calculate_subnet(ip, mask);
    
    return EXIT_SUCCESS;
}