//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_IP_LENGTH 16
#define MAX_MASK_LENGTH 3

void get_user_input(char *ip, char *mask);
int validate_ip(const char *ip);
int validate_mask(const char *mask);
void calculate_subnet(const char *ip, const char *mask, char *network, char *broadcast, int *valid_hosts);
void print_results(const char *network, const char *broadcast, int valid_hosts);

int main() {
    char ip[MAX_IP_LENGTH];
    char mask[MAX_MASK_LENGTH];
    char network[MAX_IP_LENGTH];
    char broadcast[MAX_IP_LENGTH];
    int valid_hosts = 0;

    get_user_input(ip, mask);

    // Validate inputs
    if (!validate_ip(ip) || !validate_mask(mask)) {
        fprintf(stderr, "Invalid IP address or subnet mask.\n");
        return EXIT_FAILURE;
    }

    calculate_subnet(ip, mask, network, broadcast, &valid_hosts);
    print_results(network, broadcast, valid_hosts);

    return EXIT_SUCCESS;
}

void get_user_input(char *ip, char *mask) {
    printf("Enter IP Address (x.x.x.x): ");
    fgets(ip, MAX_IP_LENGTH, stdin);
    ip[strcspn(ip, "\n")] = 0; // Remove newline

    printf("Enter Subnet Mask (e.g., 24): ");
    fgets(mask, MAX_MASK_LENGTH, stdin);
    mask[strcspn(mask, "\n")] = 0; // Remove newline
}

int validate_ip(const char *ip) {
    struct sockaddr_in sa;
    return inet_pton(AF_INET, ip, &(sa.sin_addr)) != 0;
}

int validate_mask(const char *mask) {
    int mask_value;
    if (sscanf(mask, "%d", &mask_value) != 1) {
        return 0;
    }
    return mask_value >= 0 && mask_value <= 32;
}

void calculate_subnet(const char *ip, const char *mask, char *network, char *broadcast, int *valid_hosts) {
    struct sockaddr_in sa;
    uint32_t ip_addr, mask_addr;
    
    inet_pton(AF_INET, ip, &(sa.sin_addr));
    ip_addr = ntohl(sa.sin_addr.s_addr);

    int mask_length = atoi(mask);
    mask_addr = (mask_length == 0) ? 0 : htonl((~0U) << (32 - mask_length));

    uint32_t network_addr = ip_addr & mask_addr;
    uint32_t broadcast_addr = network_addr | ~mask_addr;

    sprintf(network, "%u.%u.%u.%u", network_addr >> 24 & 0xFF, network_addr >> 16 & 0xFF, network_addr >> 8 & 0xFF, network_addr & 0xFF);
    sprintf(broadcast, "%u.%u.%u.%u", broadcast_addr >> 24 & 0xFF, broadcast_addr >> 16 & 0xFF, broadcast_addr >> 8 & 0xFF, broadcast_addr & 0xFF);

    *valid_hosts = (1 << (32 - mask_length)) - 2; // Subtracting network and broadcast addresses
}

void print_results(const char *network, const char *broadcast, int valid_hosts) {
    printf("\n---- Subnet Calculation Results ----\n");
    printf("Network Address:   %s\n", network);
    printf("Broadcast Address: %s\n", broadcast);
    printf("Valid Hosts:       %d\n", valid_hosts);
    printf("------------------------------------\n");
}