//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_LENGTH 16
#define MAX_SUBNET_MASK 32

void parse_ip(const char *ip, int *octets) {
    sscanf(ip, "%d.%d.%d.%d", &octets[0], &octets[1], &octets[2], &octets[3]);
}

unsigned int ip_to_int(int *octets) {
    return (octets[0] << 24) | (octets[1] << 16) | (octets[2] << 8) | octets[3];
}

void int_to_ip(unsigned int ip_int, char *ip) {
    sprintf(ip, "%d.%d.%d.%d", (ip_int >> 24) & 0xFF, (ip_int >> 16) & 0xFF, (ip_int >> 8) & 0xFF, ip_int & 0xFF);
}

void calculate_subnet(const char *ip, int subnet_mask) {
    int octets[4];
    parse_ip(ip, octets);
    unsigned int ip_int = ip_to_int(octets);
    
    unsigned int mask = (subnet_mask == 32) ? 0xFFFFFFFF : (0xFFFFFFFF << (32 - subnet_mask));
    unsigned int network = ip_int & mask;
    unsigned int broadcast = network | ~mask;
    
    char network_ip[MAX_IP_LENGTH], broadcast_ip[MAX_IP_LENGTH];
    int_to_ip(network, network_ip);
    int_to_ip(broadcast, broadcast_ip);
    
    unsigned int first_usable = network + 1;
    unsigned int last_usable = broadcast - 1;

    char first_usable_ip[MAX_IP_LENGTH], last_usable_ip[MAX_IP_LENGTH];
    int_to_ip(first_usable, first_usable_ip);
    int_to_ip(last_usable, last_usable_ip);
    
    printf("Network Address: %s\n", network_ip);
    printf("Broadcast Address: %s\n", broadcast_ip);
    printf("First Usable IP: %s\n", first_usable_ip);
    printf("Last Usable IP: %s\n", last_usable_ip);
}

int is_valid_ip(const char *ip) {
    int octets[4];
    parse_ip(ip, octets);
    for (int i = 0; i < 4; i++) {
        if (octets[i] < 0 || octets[i] > 255) {
            return 0;
        }
    }
    return 1;
}

int is_valid_subnet_mask(int subnet_mask) {
    return subnet_mask >= 0 && subnet_mask <= MAX_SUBNET_MASK;
}

int main() {
    char ip[MAX_IP_LENGTH];
    int subnet_mask;

    printf("Enter an IP address (e.g., 192.168.1.1): ");
    fgets(ip, sizeof(ip), stdin);
    ip[strcspn(ip, "\n")] = '\0'; // Remove newline character

    if (!is_valid_ip(ip)) {
        printf("Invalid IP address format.\n");
        return EXIT_FAILURE;
    }

    printf("Enter the subnet mask (0-32): ");
    if (scanf("%d", &subnet_mask) != 1 || !is_valid_subnet_mask(subnet_mask)) {
        printf("Invalid subnet mask. Please enter a number between 0 and 32.\n");
        return EXIT_FAILURE;
    }

    calculate_subnet(ip, subnet_mask);
    return EXIT_SUCCESS;
}