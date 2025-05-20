//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to calculate the number of hosts from the mask
int calculate_hosts(int mask) {
    return pow(2, (32 - mask)) - 2;
}

// Function to convert dotted-decimal IP to binary string
void ip_to_binary(const char *ip, char *binary) {
    int octets[4];
    sscanf(ip, "%d.%d.%d.%d", &octets[0], &octets[1], &octets[2], &octets[3]);
    binary[0] = '\0';
    for (int i = 0; i < 4; i++) {
        for (int b = 7; b >= 0; b--) {
            strcat(binary, ((octets[i] & (1 << b)) ? "1" : "0"));
        }
        if (i < 3) strcat(binary, ".");
    }
}

// Function to convert binary string to dotted-decimal IP
void binary_to_ip(const char *binary, char *ip) {
    int octets[4] = {0};
    sscanf(binary, "%d.%d.%d.%d", &octets[0], &octets[1], &octets[2], &octets[3]);
    sprintf(ip, "%d.%d.%d.%d", octets[0], octets[1], octets[2], octets[3]);
}

// Function to compute the network address from IP and subnet mask
void compute_network_address(const char *ip, int mask, char *network) {
    int octets_ip[4], octets_net[4];
    sscanf(ip, "%d.%d.%d.%d", &octets_ip[0], &octets_ip[1], &octets_ip[2], &octets_ip[3]);

    for (int i = 0; i < 4; i++) {
        if (mask >= 8) {
            octets_net[i] = octets_ip[i];
            mask -= 8;
        } else {
            octets_net[i] = (octets_ip[i] >> (8 - mask)) << (8 - mask);
            break;
        }
    }
    sprintf(network, "%d.%d.%d.%d", octets_net[0], octets_net[1], octets_net[2], octets_net[3]);
}

// Function to compute the broadcast address from network address and mask
void compute_broadcast_address(const char *network, int mask, char *broadcast) {
    int octets_net[4], octets_broadcast[4];
    sscanf(network, "%d.%d.%d.%d", &octets_net[0], &octets_net[1], &octets_net[2], &octets_net[3]);

    for (int i = 0; i < 4; i++) {
        if (mask >= 8) {
            octets_broadcast[i] = octets_net[i] | 255;
            mask -= 8;
        } else {
            octets_broadcast[i] = octets_net[i] | (255 >> mask);
            break;
        }
    }
    sprintf(broadcast, "%d.%d.%d.%d", octets_broadcast[0], octets_broadcast[1], octets_broadcast[2], octets_broadcast[3]);
}

// Function to display the results
void display_results(const char *ip, int mask) {
    char network[16];
    char broadcast[16];
    int hosts;

    compute_network_address(ip, mask, network);
    compute_broadcast_address(network, mask, broadcast);
    hosts = calculate_hosts(mask);

    printf("IP Address: %s/%d\n", ip, mask);
    printf("Network Address: %s\n", network);
    printf("Broadcast Address: %s\n", broadcast);
    printf("Number of Hosts: %d\n", hosts);
}

int main() {
    // Variables for input
    char ip[16];
    int mask;

    // User input
    printf("Enter IP Address (xx.xx.xx.xx): ");
    scanf("%15s", ip);
    printf("Enter Subnet Mask (CIDR notation): ");
    scanf("%d", &mask);
    
    // Validate the input mask
    if (mask < 0 || mask > 32) {
        fprintf(stderr, "Invalid subnet mask! Please enter a value between 0 and 32.\n");
        return 1;
    }

    // Display the result
    display_results(ip, mask);
    return 0;
}