//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_LENGTH 16
#define MAX_SUBNET_LENGTH 3

// Function prototypes
void get_ip_and_prefix(char *ip, int *prefix);
void calculate_subnet_details(const char *ip, int prefix);
void ip_to_binary(const char *ip, char *binary);
void binary_to_ip(const char *binary, char *ip);
void calculate_network_address(const char *binary_ip, int prefix, char *network);
void calculate_broadcast_address(const char *binary_ip, int prefix, char *broadcast);
void calculate_host_range(const char *network, const char *broadcast, char *first_host, char *last_host);

int main() {
    char ip[MAX_IP_LENGTH];
    int prefix;

    printf("Welcome to the Subnet Calculator!\n");
    get_ip_and_prefix(ip, &prefix);
    calculate_subnet_details(ip, prefix);

    return 0;
}

void get_ip_and_prefix(char *ip, int *prefix) {
    printf("Enter IP Address (format: x.x.x.x): ");
    scanf("%s", ip);
    printf("Enter Subnet Prefix Length (e.g., /24): ");
    scanf("%d", prefix);
}

void calculate_subnet_details(const char *ip, int prefix) {
    char binary_ip[35]; // 32 bits + 3 dots
    char network[35], broadcast[35], first_host[35], last_host[35];

    ip_to_binary(ip, binary_ip);
    calculate_network_address(binary_ip, prefix, network);
    calculate_broadcast_address(binary_ip, prefix, broadcast);
    calculate_host_range(network, broadcast, first_host, last_host);

    printf("\nSubnet Details:\n");
    printf("IP Address: %s\n", ip);
    printf("Subnet Prefix: /%d\n", prefix);
    printf("Network Address: %s\n", network);
    printf("Broadcast Address: %s\n", broadcast);
    printf("Valid Host Range: %s - %s\n\n", first_host, last_host);
}

void ip_to_binary(const char *ip, char *binary) {
    unsigned int octets[4];
    sscanf(ip, "%u.%u.%u.%u", &octets[0], &octets[1], &octets[2], &octets[3]);
    binary[0] = '\0';

    for (int i = 0; i < 4; i++) {
        char temp[9];
        snprintf(temp, sizeof(temp), "%08u", octets[i]);
        strcat(binary, temp);
        if (i < 3)
            strcat(binary, ".");
    }
}

void calculate_network_address(const char *binary_ip, int prefix, char *network) {
    int ip_parts[4] = {0};
    sscanf(binary_ip, "%d.%d.%d.%d", &ip_parts[0], &ip_parts[1], &ip_parts[2], &ip_parts[3]);

    for (int i = 0; i < 4; i++) {
        if (i * 8 < prefix) {
            network[i] = ip_parts[i];
        } else {
            network[i] = 0;
        }
    }

    sprintf(network, "%d.%d.%d.%d", network[0], network[1], network[2], network[3]);
}

void calculate_broadcast_address(const char *binary_ip, int prefix, char *broadcast) {
    char temp[35];
    int ip_parts[4];
    sscanf(binary_ip, "%d.%d.%d.%d", &ip_parts[0], &ip_parts[1], &ip_parts[2], &ip_parts[3]);

    int host_bits = 32 - prefix;
    for (int i = 0; i < 4; i++) {
        if (host_bits > 0) {
            broadcast[i] = 255;
            host_bits -= 8;
        } else {
            broadcast[i] = ip_parts[i];
        }
    }

    sprintf(broadcast, "%d.%d.%d.%d", broadcast[0], broadcast[1], broadcast[2], broadcast[3]);
}

void calculate_host_range(const char *network, const char *broadcast, char *first_host, char *last_host) {
    int n_parts[4], b_parts[4];
    sscanf(network, "%d.%d.%d.%d", &n_parts[0], &n_parts[1], &n_parts[2], &n_parts[3]);
    sscanf(broadcast, "%d.%d.%d.%d", &b_parts[0], &b_parts[1], &b_parts[2], &b_parts[3]);

    sprintf(first_host, "%d.%d.%d.%d", n_parts[0], n_parts[1], n_parts[2], n_parts[3] + 1);
    sprintf(last_host, "%d.%d.%d.%d", b_parts[0], b_parts[1], b_parts[2], b_parts[3] - 1);
}