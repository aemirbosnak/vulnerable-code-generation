//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define IPV4_LENGTH 4 // In bytes
#define MAX_SUBNET_SIZE 32
#define MAX_INPUT_LENGTH 16

typedef struct {
    unsigned char octets[IPV4_LENGTH];
} IPAddress;

IPAddress stringToIPAddress(const char *str) {
    IPAddress ip;
    if (inet_pton(AF_INET, str, &ip) != 1) {
        fprintf(stderr, "Error: Invalid IP address format.\n");
        exit(EXIT_FAILURE);
    }
    return ip;
}

void printBinary(unsigned int n, int bits) {
    for (int i = bits - 1; i >= 0; i--) {
        putchar((n & (1 << i)) ? '1' : '0');
    }
}

unsigned int calculateNetworkAddress(IPAddress ip, unsigned int subnetMask) {
    unsigned int ipInt = (ip.octets[0] << 24) | (ip.octets[1] << 16) |
                         (ip.octets[2] << 8) | ip.octets[3];
    return ipInt & subnetMask;
}

unsigned int calculateBroadcastAddress(IPAddress ip, unsigned int subnetMask) {
    unsigned int ipInt = (ip.octets[0] << 24) | (ip.octets[1] << 16) |
                         (ip.octets[2] << 8) | ip.octets[3];
    return ipInt | ~(subnetMask);
}

void calculateSubnet(const char *ipStr, int prefixLength) {
    IPAddress ip = stringToIPAddress(ipStr);

    // Calculate subnet mask in integer form
    unsigned int subnetMask = (0xFFFFFFFF << (MAX_SUBNET_SIZE - prefixLength)) & 0xFFFFFFFF;

    unsigned int networkAddress = calculateNetworkAddress(ip, subnetMask);
    unsigned int broadcastAddress = calculateBroadcastAddress(ip, subnetMask);

    printf("Subnet calculations for IP address: %s/%d\n", ipStr, prefixLength);
    printf("Network Address: %d.%d.%d.%d\n",
           (networkAddress >> 24) & 0xFF,
           (networkAddress >> 16) & 0xFF,
           (networkAddress >> 8) & 0xFF,
           networkAddress & 0xFF);
    
    printf("Broadcast Address: %d.%d.%d.%d\n",
           (broadcastAddress >> 24) & 0xFF,
           (broadcastAddress >> 16) & 0xFF,
           (broadcastAddress >> 8) & 0xFF,
           broadcastAddress & 0xFF);
    
    printf("Usable Host Range: %d.%d.%d.%d - %d.%d.%d.%d\n",
           (networkAddress >> 24) & 0xFF,
           (networkAddress >> 16) & 0xFF,
           (networkAddress >> 8) & 0xFF,
           (networkAddress & 0xFF) + 1,
           (broadcastAddress >> 24) & 0xFF,
           (broadcastAddress >> 16) & 0xFF,
           (broadcastAddress >> 8) & 0xFF,
           (broadcastAddress & 0xFF) - 1);

    printf("Subnet Mask: ");
    printBinary(subnetMask, MAX_SUBNET_SIZE);
    putchar('\n');
}

int main() {
    char ipInput[MAX_INPUT_LENGTH];
    int prefixLength;

    printf("Enter an IPv4 address (e.g., 192.168.1.1): ");
    fgets(ipInput, sizeof(ipInput), stdin);
    ipInput[strcspn(ipInput, "\n")] = '\0'; // Remove trailing newline

    printf("Enter prefix length (0-32): ");
    scanf("%d", &prefixLength);
    
    if (prefixLength < 0 || prefixLength > MAX_SUBNET_SIZE) {
        fprintf(stderr, "Error: Invalid prefix length.\n");
        return EXIT_FAILURE;
    }

    calculateSubnet(ipInput, prefixLength);
    return EXIT_SUCCESS;
}