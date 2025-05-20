//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_OCTETS 4
#define MAX_BITS 32

void clear_stdin() {
    while(getchar() != '\n'); // Clear input buffer
}

void print_intro() {
    printf("Welcome to the Creative C Subnet Calculator!\n");
    printf("------------------------------------------------\n");
    printf("This tool helps you find subnet information based on the provided IP address and subnet mask.\n\n");
}

void get_ip_address(char *ip) {
    printf("Please enter a valid IPv4 address (e.g., 192.168.1.1): ");
    fgets(ip, 16, stdin);
    ip[strcspn(ip, "\n")] = 0; // Remove newline character
}

void get_subnet_mask(char *subnet) {
    printf("Please enter the subnet mask in CIDR notation (e.g., /24): ");
    fgets(subnet, 4, stdin);
    subnet[strcspn(subnet, "\n")] = 0; // Remove newline character
}

int validate_ip(const char *ip) {
    int octets[MAX_OCTETS], scanned;
    char extra;

    scanned = sscanf(ip, "%d.%d.%d.%d%c", &octets[0], &octets[1], &octets[2], &octets[3], &extra);
    if (scanned != 4 || extra != '\0') return 0;

    for (int i = 0; i < MAX_OCTETS; i++) {
        if (octets[i] < 0 || octets[i] > 255) return 0;
    }
    return 1;
}

int validate_subnet(const char *subnet) {
    int cidr;
    return sscanf(subnet, "/%d", &cidr) == 1 && cidr >= 0 && cidr <= MAX_BITS;
}

void calculate_subnet(const char *ip, const char *subnet, char *network, char *broadcast, int *first_host, int *last_host) {
    int octets[MAX_OCTETS], cidr;
    sscanf(subnet, "/%d", &cidr);
    sscanf(ip, "%d.%d.%d.%d", &octets[0], &octets[1], &octets[2], &octets[3]);

    int mask = ~(0xFFFFFFFF >> cidr); // Create subnet mask
    int network_int = (octets[0] << 24) | (octets[1] << 16) | (octets[2] << 8) | octets[3];

    int network_address = network_int & mask;
    int broadcast_address = network_address | ~mask;
    
    sprintf(network, "%d.%d.%d.%d", (network_address >> 24) & 0xFF, (network_address >> 16) & 0xFF, (network_address >> 8) & 0xFF, network_address & 0xFF);
    sprintf(broadcast, "%d.%d.%d.%d", (broadcast_address >> 24) & 0xFF, (broadcast_address >> 16) & 0xFF, (broadcast_address >> 8) & 0xFF, broadcast_address & 0xFF);

    *first_host = network_address + 1;
    *last_host = broadcast_address - 1;
}

void display_results(const char *ip, const char *subnet, const char *network, const char *broadcast, int first_host, int last_host) {
    printf("------------------------------------------------\n");
    printf("Subnet Information for IP: %s and Subnet Mask: %s\n", ip, subnet);
    printf("------------------------------------------------\n");
    printf("Network Address: %s\n", network);
    printf("Broadcast Address: %s\n", broadcast);
    printf("First usable host: %d.%d.%d.%d\n", (first_host >> 24) & 0xFF, (first_host >> 16) & 0xFF, (first_host >> 8) & 0xFF, first_host & 0xFF);
    printf("Last usable host: %d.%d.%d.%d\n", (last_host >> 24) & 0xFF, (last_host >> 16) & 0xFF, (last_host >> 8) & 0xFF, last_host & 0xFF);
    printf("------------------------------------------------\n");
}

int main() {
    char ip[16], subnet[4];
    char network[16], broadcast[16];
    int first_host, last_host;

    print_intro();

    // Get Valid IP Address
    do {
        get_ip_address(ip);
    } while (!validate_ip(ip));

    // Get Valid Subnet Mask
    do {
        get_subnet_mask(subnet);
    } while (!validate_subnet(subnet));

    // Calculate Subnet Information
    calculate_subnet(ip, subnet, network, broadcast, &first_host, &last_host);

    // Display Results
    display_results(ip, subnet, network, broadcast, first_host, last_host);

    return 0;
}