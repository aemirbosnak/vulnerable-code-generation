//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void display_intro() {
    printf("======================================\n");
    printf(" Welcome to the IP Subnet Calculator\n");
    printf(" An Adventure Awaits in Networking!\n");
    printf("======================================\n\n");
}

void calculate_subnet(char *ip, int prefix) {
    unsigned int ip_parts[4];
    unsigned int subnet_mask[4];
    unsigned int network_address[4];
    unsigned int broadcast_address[4];
    unsigned int host_count;

    sscanf(ip, "%u.%u.%u.%u", &ip_parts[0], &ip_parts[1], &ip_parts[2], &ip_parts[3]);

    // Create the subnet mask from the prefix
    for (int i = 0; i < 4; i++) {
        if (prefix >= 8) {
            subnet_mask[i] = 255;
            prefix -= 8;
        } else {
            subnet_mask[i] = (255 << (8 - prefix)) & 255; 
            prefix = 0;
        }
    }

    // Calculate the network address
    for (int i = 0; i < 4; i++) {
        network_address[i] = ip_parts[i] & subnet_mask[i];
    }

    // Calculate the broadcast address
    for (int i = 0; i < 4; i++) {
        broadcast_address[i] = network_address[i] | (~subnet_mask[i] & 255);
    }
    
    // Calculate host count
    host_count = (1 << (32 - (8 * (4 - (prefix / 8)) + (prefix % 8)))) - 2; // -2 for network and broadcast addresses

    // Display the results
    printf("\n--- Subnet Information ---\n");
    printf("  IP Address: %d.%d.%d.%d\n", ip_parts[0], ip_parts[1], ip_parts[2], ip_parts[3]);
    printf("  Subnet Mask: %d.%d.%d.%d\n", subnet_mask[0], subnet_mask[1], subnet_mask[2], subnet_mask[3]);
    printf("  Network Address: %d.%d.%d.%d\n", network_address[0], network_address[1], network_address[2], network_address[3]);
    printf("  Broadcast Address: %d.%d.%d.%d\n", broadcast_address[0], broadcast_address[1], broadcast_address[2], broadcast_address[3]);
    printf("  Total Hosts: %u\n", host_count);
    printf("--------------------------\n\n");
}

int main() {
    display_intro();
    
    char ip[16];
    int prefix;

    while (1) {
        printf("Enter an IP Address (or type 'exit' to quit): ");
        scanf("%s", ip);

        if (strcmp(ip, "exit") == 0) {
            printf("Exiting the adventure. Goodbye!\n");
            break;
        }

        printf("Enter the Subnet Prefix (e.g., 24): ");
        if (scanf("%d", &prefix) != 1 || prefix < 0 || prefix > 32) {
            printf("Invalid prefix! It must be between 0 and 32.\n\n");
            // Clear input buffer
            while(getchar() != '\n');
            continue;
        }

        calculate_subnet(ip, prefix);
    }

    return 0;
}