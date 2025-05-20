//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX_IP_LENGTH 16
#define MAX_SUBNET_LENGTH 4
#define MAX_CIDR_LENGTH 3

void print_welcome_message() {
    printf("🎉 Welcome to the Happy C Subnet Calculator! 🎉\n");
    printf("Let’s explore the world of IP addresses and subnets together!\n\n");
}

int validate_ip(const char *ip) {
    int num, dots = 0;
    char *ptr;

    if (ip == NULL) {
        return 0;
    }

    ptr = strtok((char *)ip, ".");
    if (ptr == NULL) {
        return 0;
    }

    while (ptr) {
        if (!sscanf(ptr, "%d", &num)) {
            return 0;
        }
        if (num < 0 || num > 255) {
            return 0;
        }
        ptr = strtok(NULL, ".");
        dots++;
    }
    
    // An IP address should have exactly 3 dots (4 octets)
    return dots == 4;
}

void get_subnet_mask(int cidr, char *subnet_mask) {
    if (cidr < 0 || cidr > 32) {
        snprintf(subnet_mask, MAX_SUBNET_LENGTH, "Invalid");
        return;
    }
    
    uint32_t mask = 0xFFFFFFFF << (32 - cidr);
    snprintf(subnet_mask, MAX_SUBNET_LENGTH, "%d.%d.%d.%d",
        (mask >> 24) & 0xFF,
        (mask >> 16) & 0xFF,
        (mask >> 8) & 0xFF,
        mask & 0xFF);
}

void calculate_network_details(const char *ip, int cidr) {
    char subnet_mask[MAX_SUBNET_LENGTH];
    get_subnet_mask(cidr, subnet_mask);
    
    if (strcmp(subnet_mask, "Invalid") == 0) {
        printf("😢 Oops! Invalid CIDR value. Please enter a value from 0 to 32.\n");
        return;
    }
    
    printf("💻 Your IP: %s\n", ip);
    printf("🌐 CIDR Notation: /%d\n", cidr);
    printf("📡 Subnet Mask: %s\n", subnet_mask);
    
    // Calculate Network Address
    unsigned int ip_parts[4] = {0};
    sscanf(ip, "%u.%u.%u.%u", &ip_parts[0], &ip_parts[1], &ip_parts[2], &ip_parts[3]);
    
    uint32_t ip_addr = (ip_parts[0] << 24) | (ip_parts[1] << 16) | (ip_parts[2] << 8) | ip_parts[3];
    uint32_t mask = (0xFFFFFFFF << (32 - cidr));
    
    uint32_t network_address = ip_addr & mask;

    // Print Network Address
    printf("🏠 Network Address: %d.%d.%d.%d\n", 
        (network_address >> 24) & 0xFF,
        (network_address >> 16) & 0xFF,
        (network_address >> 8) & 0xFF,
        network_address & 0xFF);
    
    // Calculate Broadcast Address
    uint32_t broadcast_address = network_address | ~mask;
    
    // Print Broadcast Address
    printf("🎉 Broadcast Address: %d.%d.%d.%d\n", 
        (broadcast_address >> 24) & 0xFF,
        (broadcast_address >> 16) & 0xFF,
        (broadcast_address >> 8) & 0xFF,
        broadcast_address & 0xFF);
    
    // Calculate Usable IP Range
    uint32_t first_usable = network_address + 1;
    uint32_t last_usable = broadcast_address - 1;
    
    // Print Usable IP Range
    printf("📈 Usable IP Range:\n");
    printf("   From: %d.%d.%d.%d\n", 
        (first_usable >> 24) & 0xFF,
        (first_usable >> 16) & 0xFF,
        (first_usable >> 8) & 0xFF,
        first_usable & 0xFF);
    
    printf("   To: %d.%d.%d.%d\n", 
        (last_usable >> 24) & 0xFF,
        (last_usable >> 16) & 0xFF,
        (last_usable >> 8) & 0xFF,
        last_usable & 0xFF);
}

int main() {
    print_welcome_message();
    
    char ip[MAX_IP_LENGTH];
    int cidr;
    
    printf("🌈 Please enter an IP address (format: x.x.x.x): ");
    scanf("%s", ip);

    // Validate IP
    if (!validate_ip(ip)) {
        printf("😢 Invalid IP address format! Please try again.\n");
        return 1;
    }

    printf("✏️ Now, please enter the CIDR (0-32): ");
    scanf("%d", &cidr);

    // Calculate and print details
    calculate_network_details(ip, cidr);

    printf("Thank you for using the Happy C Subnet Calculator! Goodbye! 👋\n");
    return 0;
}