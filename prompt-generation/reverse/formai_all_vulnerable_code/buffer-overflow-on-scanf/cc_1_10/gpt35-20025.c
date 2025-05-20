//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: modular
#include <stdio.h>
#include <stdbool.h>

// define MAX_IP_LENGTH to be the maximum allowed length of an IPv4 address
#define MAX_IP_LENGTH 16

// define a struct to represent an IPv4 address
typedef struct {
    unsigned char octets[4];
} IPv4Address;

// function to check if the given IPv4 address is valid
bool isValidIpAddress(const char *ip_address) {
    // validate the input
    if (ip_address == NULL) {
        return false;
    }
    
    // allocate memory on the stack for the temporary copy of the input IP address
    char ip_copy[MAX_IP_LENGTH];
    int ip_copy_length = 0;
    
    // copy the input IP address string into the temporary memory
    while (*ip_address != '\0' && ip_copy_length < MAX_IP_LENGTH) {
        if (*ip_address == '.' || (*ip_address >= '0' && *ip_address <= '9')) {
            ip_copy[ip_copy_length++] = *ip_address;
        } else {
            return false; // invalid character
        }
        ip_address++;
    }
    
    // check if the final length of the copied IP address is valid
    if (ip_copy_length < 7 || ip_copy_length > 15) {
        return false;
    }
    
    // check if the copied IP address is valid (e.g. no octet is greater than 255)
    int start = 0;
    for (int i = 0; i < 4; i++) {
        int octet_value = 0;
        for (int j = start; j < ip_copy_length && ip_copy[j] != '.'; j++) {
            octet_value = octet_value * 10 + (ip_copy[j] - '0');
            if (octet_value > 255) {
                return false;
            }
            start = j + 1;
        }
        if (i < 3 && ip_copy[start] != '.') {
            return false;
        }
    }
    
    return true; // the input IP address is valid
}

// function to read an IPv4 address from the user input
void readIpAddress(IPv4Address *ip_address) {
    char input[MAX_IP_LENGTH];
    printf("Enter an IPv4 address (e.g. 192.168.0.1): ");
    scanf("%s", input);
    
    while (!isValidIpAddress(input)) {
        printf("%s is not a valid IPv4 address. Please try again: ", input);
        scanf("%s", input);
    }
    
    int start = 0;
    for (int i = 0; i < 4; i++) {
        int octet_value = 0;
        for (int j = start; input[j] != '.' && j < MAX_IP_LENGTH; j++) {
            octet_value = octet_value * 10 + (input[j] - '0');
            start = j + 1;
        }
        ip_address->octets[i] = octet_value;
    }
}

// function to print an IPv4 address to the console
void printIpAddress(IPv4Address ip_address) {
    printf("%d.%d.%d.%d", ip_address.octets[0], ip_address.octets[1], ip_address.octets[2], ip_address.octets[3]);
}

// function to calculate the network address for the given IPv4 address and netmask
IPv4Address calculateNetworkAddress(IPv4Address ip_address, IPv4Address netmask) {
    IPv4Address network_address;
    for (int i = 0; i < 4; i++) {
        network_address.octets[i] = ip_address.octets[i] & netmask.octets[i];
    }
    return network_address;
}

// function to calculate the broadcast address for the given IPv4 address and netmask
IPv4Address calculateBroadcastAddress(IPv4Address ip_address, IPv4Address netmask) {
    IPv4Address broadcast_address;
    for (int i = 0; i < 4; i++) {
        broadcast_address.octets[i] = ip_address.octets[i] | ~netmask.octets[i];
    }
    return broadcast_address;
}

// function to calculate the total number of host addresses for the given IPv4 netmask
unsigned int calculateHostsPerNetmask(IPv4Address netmask) {
    unsigned int hosts = 1;
    for (int i = 0; i < 4; i++) {
        hosts *= 256 - netmask.octets[i];
    }
    return hosts;
}

// main function to demonstrate the subnet calculator
int main() {
    IPv4Address ip_address, netmask, network_address, broadcast_address;
    unsigned int prefix_length, hosts_per_netmask;
    
    printf("IPv4 Subnet Calculator\n\n");
    readIpAddress(&ip_address);
    printf("\n");
    
    printf("Enter the prefix length (e.g. 24 if the netmask is 255.255.255.0): ");
    scanf("%u", &prefix_length);
    while (prefix_length < 1 || prefix_length > 32) {
        printf("Invalid prefix length. Please enter a number between 1 and 32: ");
        scanf("%u", &prefix_length);
    }
    printf("\n");
    
    // calculate the netmask based on the prefix length
    for (int i = 0; i < 4; i++) {
        if (prefix_length >= 8) {
            netmask.octets[i] = 255;
            prefix_length -= 8;
        } else if (prefix_length > 0) {
            netmask.octets[i] = 256 - (1 << (8 - prefix_length));
            prefix_length = 0;
        } else {
            netmask.octets[i] = 0;
        }
    }
    
    // calculate the network and broadcast addresses
    network_address = calculateNetworkAddress(ip_address, netmask);
    broadcast_address = calculateBroadcastAddress(ip_address, netmask);
    
    // calculate the total number of host addresses
    hosts_per_netmask = calculateHostsPerNetmask(netmask);
    
    // print the results to the console
    printf("IP Address:          ");
    printIpAddress(ip_address);
    printf("\n");
    
    printf("Netmask:             ");
    printIpAddress(netmask);
    printf("\n");
    
    printf("Network Address:     ");
    printIpAddress(network_address);
    printf("\n");
    
    printf("Broadcast Address:   ");
    printIpAddress(broadcast_address);
    printf("\n");
    
    printf("Hosts per Subnet:    %u\n", hosts_per_netmask);
    
    return 0;
}