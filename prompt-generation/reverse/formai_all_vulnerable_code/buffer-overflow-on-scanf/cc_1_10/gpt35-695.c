//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_LENGTH 15 // Max length of an IP address
#define MAX_CIDR_LENGTH 2 // Max length of CIDR notation value
#define BINARY_IP_SIZE 32 // Size of a binary IP address

struct subnet {
    char network_address[MAX_IP_LENGTH + 1];
    char broadcast_address[MAX_IP_LENGTH + 1];
    char subnet_mask[MAX_IP_LENGTH + 1];
    char wildcard_mask[MAX_IP_LENGTH + 1];
    char host_range[2][MAX_IP_LENGTH + 1];
    int total_hosts;
    int prefix_length;
};

struct binary_subnet {
    int network_address[BINARY_IP_SIZE];
    int broadcast_address[BINARY_IP_SIZE];
    int subnet_mask[BINARY_IP_SIZE];
    int wildcard_mask[BINARY_IP_SIZE];
    int prefix_length;
};

// Function to convert an IP address from string format to integer format
void ip_to_int(char* ip_address, int* ip) {
    // Split IP string by "." character
    char* split = strtok(ip_address, ".");
    int i = 0;
    while (split != NULL) {
        ip[i] = atoi(split);
        i++;
        split = strtok(NULL, ".");
    }
}

// Function to convert an IP address from integer format to string format
void int_to_ip(int* ip, char* ip_address) {
    sprintf(ip_address, "%d.%d.%d.%d", ip[0], ip[1], ip[2], ip[3]);
}

// Function to convert CIDR notation value to subnet mask
void cidr_to_subnet(int prefix_length, int* subnet_mask) {
    int i;
    for (i = 0; i < BINARY_IP_SIZE; i++) {
        if (i < prefix_length) {
            subnet_mask[i] = 1;
        } else {
            subnet_mask[i] = 0;
        }
    }
}

// Function to compute the wildcard mask of a network from its subnet mask
void subnet_mask_to_wildcard(int* subnet_mask, int* wildcard_mask) {
    int i;
    for (i = 0; i < BINARY_IP_SIZE; i++) {
        wildcard_mask[i] = !subnet_mask[i];
    }
}

// Function to compute the network address from an IP address and subnet mask
void get_network_address(int* ip, int* subnet_mask, int* network_address) {
    int i;
    for (i = 0; i < BINARY_IP_SIZE; i++) {
        network_address[i] = ip[i] & subnet_mask[i];
    }
}

// Function to compute the broadcast address from an IP address and wildcard mask
void get_broadcast_address(int* ip, int* wildcard_mask, int* broadcast_address) {
    int i;
    for (i = 0; i < BINARY_IP_SIZE; i++) {
        broadcast_address[i] = ip[i] | wildcard_mask[i];
    }
}

// Function to compute the total number of hosts in a subnet from its prefix length
int get_total_hosts(int prefix_length) {
    return (1 << (BINARY_IP_SIZE - prefix_length)) - 2;
}

// Function to compute the host range from a network address and broadcast address
void get_host_range(int* network_address, int* broadcast_address, char host_range[][MAX_IP_LENGTH + 1]) {
    int i;
    int first_host_ip[BINARY_IP_SIZE], last_host_ip[BINARY_IP_SIZE];
    for (i = 0; i < BINARY_IP_SIZE; i++) {
        if (i == BINARY_IP_SIZE-1) {
            first_host_ip[i] = network_address[i] + 1;
            last_host_ip[i] = broadcast_address[i] - 1;
        } else {
            first_host_ip[i] = network_address[i];
            last_host_ip[i] = broadcast_address[i];
        }
    }
    int_to_ip(first_host_ip, host_range[0]);
    int_to_ip(last_host_ip, host_range[1]);
}

int main() {
    // Initialize variables
    char ip_address[MAX_IP_LENGTH+1];
    char cidr[MAX_CIDR_LENGTH+1];
    printf("Enter IP address and CIDR notation value: ");
    scanf("%s/%s", ip_address, cidr);

    // Convert IP address to integer format
    int ip[BINARY_IP_SIZE];
    ip_to_int(ip_address, ip);

    // Convert CIDR notation value to integer prefix length
    int prefix_length = atoi(cidr);
    if (prefix_length > BINARY_IP_SIZE) {
        printf("Invalid CIDR notation value\n");
        return 0;
    }

    // Compute binary subnet data
    struct binary_subnet binary_data;
    cidr_to_subnet(prefix_length, binary_data.subnet_mask);
    subnet_mask_to_wildcard(binary_data.subnet_mask, binary_data.wildcard_mask);
    get_network_address(ip, binary_data.subnet_mask, binary_data.network_address);
    get_broadcast_address(ip, binary_data.wildcard_mask, binary_data.broadcast_address);
    binary_data.prefix_length = prefix_length;

    // Compute subnet data in string format
    struct subnet data;
    int_to_ip(binary_data.network_address, data.network_address);
    int_to_ip(binary_data.broadcast_address, data.broadcast_address);
    int_to_ip(binary_data.subnet_mask, data.subnet_mask);
    int_to_ip(binary_data.wildcard_mask, data.wildcard_mask);
    get_host_range(binary_data.network_address, binary_data.broadcast_address, data.host_range);
    data.total_hosts = get_total_hosts(binary_data.prefix_length);
    data.prefix_length = binary_data.prefix_length;

    // Print subnet data
    printf("\nSubnet data:\n");
    printf("Network address: %s\n", data.network_address);
    printf("Broadcast address: %s\n", data.broadcast_address);
    printf("Subnet mask: %s\n", data.subnet_mask);
    printf("Wildcard mask: %s\n", data.wildcard_mask);
    printf("Host range: %s - %s\n", data.host_range[0], data.host_range[1]);
    printf("Total hosts: %d\n", data.total_hosts);
    printf("Prefix length: /%d\n", data.prefix_length);

    return 0;
}