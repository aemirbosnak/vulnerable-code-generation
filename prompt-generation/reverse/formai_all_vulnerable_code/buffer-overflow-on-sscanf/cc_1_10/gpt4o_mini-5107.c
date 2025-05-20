//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_LENGTH 15
#define MAX_MASK_LENGTH 2

void split_ip(const char *ip, int *octets);
void calculate_subnet(int *ip, int *mask, int *network, int *broadcast);
void print_ip(int *ip);
void print_host_range(int *network, int *broadcast);

int main() {
    char input_ip[MAX_IP_LENGTH + 1];
    char input_mask[MAX_MASK_LENGTH + 1];
    int ip[4], mask[4], network[4], broadcast[4];

    printf("Welcome to the C Subnet Calculator!\n");
    printf("Please enter an IP address (x.x.x.x): ");
    fgets(input_ip, sizeof(input_ip), stdin);
    input_ip[strcspn(input_ip, "\n")] = 0;  // Remove trailing newline

    printf("Please enter a subnet mask (x.x.x.x or /prefix): ");
    fgets(input_mask, sizeof(input_mask), stdin);
    input_mask[strcspn(input_mask, "\n")] = 0;  // Remove trailing newline

    if (strchr(input_mask, '/')) {
        int prefix_length;
        sscanf(input_mask, "/%d", &prefix_length);
        if (prefix_length < 0 || prefix_length > 32) {
            fprintf(stderr, "Invalid subnet prefix length!\n");
            return 1;
        }
        for (int i = 0; i < 4; i++) {
            if (i < (prefix_length / 8)) {
                mask[i] = 255;
            } else if (i == (prefix_length / 8)) {
                mask[i] = (1 << (8 - (prefix_length % 8))) - 1;
                mask[i] = ~mask[i];
            } else {
                mask[i] = 0;
            }
        }
    } else {
        split_ip(input_mask, mask);
    }

    split_ip(input_ip, ip);

    // Calculate network address and broadcast address
    calculate_subnet(ip, mask, network, broadcast);

    // Display results
    printf("IP Address: ");
    print_ip(ip);
    printf("Subnet Mask: ");
    print_ip(mask);
    printf("Network Address: ");
    print_ip(network);
    printf("Broadcast Address: ");
    print_ip(broadcast);
    print_host_range(network, broadcast);

    return 0;
}

void split_ip(const char *ip, int *octets) {
    sscanf(ip, "%d.%d.%d.%d", &octets[0], &octets[1], &octets[2], &octets[3]);
}

void calculate_subnet(int *ip, int *mask, int *network, int *broadcast) {
    for (int i = 0; i < 4; i++) {
        network[i] = ip[i] & mask[i];
        broadcast[i] = network[i] | ~mask[i] & 255;
    }
}

void print_ip(int *ip) {
    printf("%d.%d.%d.%d\n", ip[0], ip[1], ip[2], ip[3]);
}

void print_host_range(int *network, int *broadcast) {
    int first_host[4], last_host[4];
    
    for (int i = 0; i < 4; i++) {
        first_host[i] = network[i];
        last_host[i] = broadcast[i];
    }
    
    // Adjust first and last hosts
    first_host[3] += 1; // Increment last octet for first valid host
    last_host[3] -= 1;  // Decrement last octet for last valid host

    printf("Valid Host Range: ");
    print_ip(first_host);
    printf(" to ");
    print_ip(last_host);
}