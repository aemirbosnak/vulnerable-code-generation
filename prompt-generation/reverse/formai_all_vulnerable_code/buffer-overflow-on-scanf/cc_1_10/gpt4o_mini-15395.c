//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to calculate number of hosts
int calculate_hosts(int subnet_mask) {
    return pow(2, (32 - subnet_mask)) - 2;
}

// Function to validate if the IP address is valid
int is_valid_ip(const char *ip) {
    int segments = 0;
    int segment_value = 0;
    const char *ptr = ip;
    
    while (*ptr) {
        if (*ptr == '.') {
            if (segment_value < 0 || segment_value > 255)
                return 0;
            segments++;
            segment_value = 0;
        } else if (*ptr >= '0' && *ptr <= '9') {
            segment_value = segment_value * 10 + (*ptr - '0');
        } else {
            return 0;
        }
        ptr++;
    }

    if (segment_value < 0 || segment_value > 255)
        return 0;
    
    return segments == 3;
}

// Function to validate subnet mask
int is_valid_subnet_mask(int mask) {
    return mask >= 0 && mask <= 32;
}

// Function to convert subnet mask to binary
void print_subnet_mask(int subnet_mask) {
    for (int i = 0; i < 32; i++) {
        if (i < subnet_mask) {
            printf("1");
        } else {
            printf("0");
        }
        if ((i + 1) % 8 == 0 && i < 31) {
            printf(".");
        }
    }
}

// Function to calculate the network address
void calculate_network_address(const char *ip, int subnet_mask) {
    int ip_segments[4];
    sscanf(ip, "%d.%d.%d.%d", &ip_segments[0], &ip_segments[1], &ip_segments[2], &ip_segments[3]);
    
    printf("Network Address: ");
    for (int i = 0; i < 4; i++) {
        if (i < subnet_mask / 8) {
            printf("%d", ip_segments[i]);
        } else if (i == subnet_mask / 8) {
            int mask_offset = subnet_mask % 8;
            printf("%d", ip_segments[i] & (255 << mask_offset));
        } else {
            printf("0");
        }
        if (i < 3) {
            printf(".");
        }
    }
    printf("\n");
}

// Function to calculate the broadcast address
void calculate_broadcast_address(const char *ip, int subnet_mask) {
    int ip_segments[4];
    sscanf(ip, "%d.%d.%d.%d", &ip_segments[0], &ip_segments[1], &ip_segments[2], &ip_segments[3]);

    printf("Broadcast Address: ");
    for (int i = 0; i < 4; i++) {
        if (i < subnet_mask / 8) {
            printf("%d", ip_segments[i]);
        } else if (i == subnet_mask / 8) {
            int mask_offset = subnet_mask % 8;
            printf("%d", (ip_segments[i] & (255 << mask_offset)) + (255 >> (8 - mask_offset)));
        } else {
            printf("255");
        }
        if (i < 3) {
            printf(".");
        }
    }
    printf("\n");
}

// Function to display all subnet information
void display_subnet_info(const char *ip, int subnet_mask) {
    if (!is_valid_ip(ip)) {
        printf("Invalid IP address. Please enter a valid one.\n");
        return;
    }

    if (!is_valid_subnet_mask(subnet_mask)) {
        printf("Invalid subnet mask. Please enter a valid one between 0 and 32.\n");
        return;
    }

    printf("\nIP Address: %s\n", ip);
    printf("Subnet Mask: "); 
    print_subnet_mask(subnet_mask);
    printf("\nNumber of Hosts: %d\n", calculate_hosts(subnet_mask));
    calculate_network_address(ip, subnet_mask);
    calculate_broadcast_address(ip, subnet_mask);
}

int main() {
    char ip[16];
    int subnet_mask;

    printf("C Subnet Calculator\n");
    printf("====================\n");
    printf("Enter IP Address (x.x.x.x): ");
    fgets(ip, sizeof(ip), stdin);
    ip[strcspn(ip, "\n")] = 0; // Remove newline character

    printf("Enter Subnet Mask (0-32): ");
    scanf("%d", &subnet_mask);

    display_subnet_info(ip, subnet_mask);

    return 0;
}