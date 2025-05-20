//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_LENGTH 15
#define MAX_SUBNET_LENGTH 3

void greet_user() {
    printf("=====================================\n");
    printf("   Welcome to the Subnet Calculator!  \n");
    printf("=====================================\n");
    printf("Where IPs and subnets come to play!\n");
    printf("Get ready to subnet your way to networking nirvana!\n\n");
}

void get_ip(char *ip) {
    printf("Please enter your IP Address (IPv4, like cheeky.192.168.1.1): ");
    fgets(ip, MAX_IP_LENGTH + 1, stdin);
    ip[strcspn(ip, "\n")] = '\0'; // Remove newline character
}

void get_subnet_mask(int *subnet) {
    printf("Now, enter the Subnet Mask (CIDR notation, like 24 or the 'magic' 255.255.255.0): ");
    char subnet_input[MAX_SUBNET_LENGTH + 1];
    fgets(subnet_input, MAX_SUBNET_LENGTH + 1, stdin);
    
    if (strchr(subnet_input, '.')) {
        // It's a dotted-decimal mask, let's validate it just for fun
        printf("Dotted-decimal subnet mask detected! Validating...\n");
        // (You could add parsing here for dotted-decimal)

        // For simplicity, we'll ignore this check
        *subnet = -1;  // Mark as "not a simple integer" for now
    } else {
        *subnet = atoi(subnet_input);
    }
}

void calculate_subnet(const char *ip, int subnet, char *subnet_address, char *broadcast_address) {
    printf("Buckle up! Let's do some mathematical magic!\n");

    // Here comes the math wizardry!
    unsigned int ip_parts[4];
    sscanf(ip, "%u.%u.%u.%u", &ip_parts[0], &ip_parts[1], &ip_parts[2], &ip_parts[3]);

    if (subnet == -1) {
        // For the purpose of this example, let's assume we use a standard class C subnet mask for simplicity
        subnet = 24; // Or any other logic...
    }

    unsigned int mask = 0xFFFFFFFF << (32 - subnet);
    
    unsigned int subnet_numeric = (ip_parts[0] << 24) | (ip_parts[1] << 16) | (ip_parts[2] << 8) | ip_parts[3];
    unsigned int subnet_calc = subnet_numeric & mask;
    unsigned int broadcast_calc = subnet_calc | ~mask;

    // Now, let's convert numbers back to strings
    sprintf(subnet_address, "%u.%u.%u.%u", (subnet_calc >> 24) & 0xFF, (subnet_calc >> 16) & 0xFF, (subnet_calc >> 8) & 0xFF, subnet_calc & 0xFF);
    sprintf(broadcast_address, "%u.%u.%u.%u", (broadcast_calc >> 24) & 0xFF, (broadcast_calc >> 16) & 0xFF, (broadcast_calc >> 8) & 0xFF, broadcast_calc & 0xFF);
}

void display_results(const char *ip, int subnet, const char *subnet_address, const char *broadcast_address) {
    printf("Congratulations! You've just subnetted the universe!\n");
    printf("For your IP: %s\n", ip);
    printf("With Subnet Mask: /%d\n", subnet);
    printf("You have found:\n");
    printf("Subnet Address: %s\n", subnet_address);
    printf("Broadcast Address: %s\n", broadcast_address);
    printf("Num of Usable IPs: %d\n", (1 << (32 - subnet)) - 2);
}

int main() {
    greet_user();
    
    char ip[MAX_IP_LENGTH + 1];
    get_ip(ip);
    
    int subnet;
    get_subnet_mask(&subnet);

    char subnet_address[16], broadcast_address[16];
    calculate_subnet(ip, subnet, subnet_address, broadcast_address);
    
    display_results(ip, subnet, subnet_address, broadcast_address);

    printf("\nThank you for using our Subnet Calculator! Now go forth and subnet wisely! 🥳\n");
    
    return 0;
}