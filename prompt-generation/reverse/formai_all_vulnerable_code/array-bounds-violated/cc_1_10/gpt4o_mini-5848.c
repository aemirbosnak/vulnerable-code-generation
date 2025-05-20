//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_OCTETS 4
#define MAX_BITMASK 32

// Function to check if the input IP address is valid
int is_valid_ip(const char *ip) {
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, ip, &(sa.sin_addr));
    return result != 0;
}

// Function to split the CIDR notation into base IP and subnet mask
void split_cidr(const char *cidr, char *ip, int *mask) {
    char *slash = strchr(cidr, '/');
    if (slash != NULL) {
        *slash = '\0';  // Temporarily null-terminate the string
        strcpy(ip, cidr);
        *mask = atoi(slash + 1);
    }
}

// Function to calculate subnet and broadcast addresses
void calculate_subnet(const char *ip, int mask, char *subnet, char *broadcast) {
    unsigned int ip_parts[MAX_OCTETS], subnet_parts[MAX_OCTETS], broadcast_parts[MAX_OCTETS];
    sscanf(ip, "%u.%u.%u.%u", &ip_parts[0], &ip_parts[1], &ip_parts[2], &ip_parts[3]);

    for (int i = 0; i < MAX_OCTETS; i++) {
        if (mask >= 8) {
            subnet_parts[i] = ip_parts[i];
            broadcast_parts[i] = ip_parts[i];
        } else {
            subnet_parts[i] = ip_parts[i] & (255 << (8 - mask));
            broadcast_parts[i] = subnet_parts[i] | ~(255 << (8 - mask));
        }
        mask -= 8;
        if (mask < 0) break;
    }

    sprintf(subnet, "%u.%u.%u.%u", subnet_parts[0], subnet_parts[1], subnet_parts[2], subnet_parts[3]);
    sprintf(broadcast, "%u.%u.%u.%u", broadcast_parts[0], broadcast_parts[1], broadcast_parts[2], broadcast_parts[3]);
}

int main() {
    char cidr[50], ip[20], subnet[20], broadcast[20];
    int mask;

    printf("Welcome to the Paranoid C Subnet Calculator!\n");
    printf("Please enter a valid CIDR notation (e.g., 192.168.1.0/24): ");

    // Safety check for input
    if (fgets(cidr, sizeof(cidr), stdin) == NULL) {
        fprintf(stderr, "Input error detected, safely exiting.\n");
        return EXIT_FAILURE;
    }
    
    // Remove new line character if present
    size_t len = strlen(cidr);
    if (cidr[len - 1] == '\n') {
        cidr[len - 1] = '\0';
    }

    // Validate IP before processing
    split_cidr(cidr, ip, &mask);
    if (!is_valid_ip(ip) || mask < 0 || mask > MAX_BITMASK) {
        fprintf(stderr, "Invalid input detected! Please check your CIDR notation.\n");
        return EXIT_FAILURE;
    }

    calculate_subnet(ip, mask, subnet, broadcast);

    printf("Calculated Subnet: %s\n", subnet);
    printf("Calculated Broadcast: %s\n", broadcast);

    return EXIT_SUCCESS;
}