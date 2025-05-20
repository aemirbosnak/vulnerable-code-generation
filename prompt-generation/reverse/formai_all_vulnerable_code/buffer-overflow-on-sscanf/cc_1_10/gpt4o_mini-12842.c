//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct IPAddress {
    unsigned char bytes[4];
};

void printBinary(unsigned char byte) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (byte >> i) & 1);
    }
}

struct IPAddress parseIP(char *ip) {
    struct IPAddress address;
    sscanf(ip, "%hhu.%hhu.%hhu.%hhu", &address.bytes[0], &address.bytes[1], &address.bytes[2], &address.bytes[3]);
    return address;
}

void displaySubnetInfo(struct IPAddress ip, struct IPAddress mask) {
    struct IPAddress network, broadcast;

    // Calculate the network address
    for (int i = 0; i < 4; i++) {
        network.bytes[i] = ip.bytes[i] & mask.bytes[i];
    }

    // Calculate the broadcast address
    for (int i = 0; i < 4; i++) {
        broadcast.bytes[i] = network.bytes[i] | (~mask.bytes[i] & 0xFF);
    }

    // Calculate the number of hosts
    int hostBits = 0;
    for (int i = 0; i < 4; i++) {
        hostBits += __builtin_popcount(~mask.bytes[i]);
    }
    int totalHosts = pow(2, hostBits) - 2; // subtracting network and broadcast

    // Display results
    printf("\n✨✨✨✨✨ Subnet Information ✨✨✨✨✨\n");
    printf("IP Address: %d.%d.%d.%d\n", ip.bytes[0], ip.bytes[1], ip.bytes[2], ip.bytes[3]);
    printf("Subnet Mask: %d.%d.%d.%d\n", mask.bytes[0], mask.bytes[1], mask.bytes[2], mask.bytes[3]);
    printf("Network Address: %d.%d.%d.%d\n", network.bytes[0], network.bytes[1], network.bytes[2], network.bytes[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n", broadcast.bytes[0], broadcast.bytes[1], broadcast.bytes[2], broadcast.bytes[3]);
    printf("Total Hosts: %d\n", totalHosts);
    printf("✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨\n\n");
}

int main() {
    char inputIP[16], inputMask[16];
    
    printf("🌟 Welcome to the Subnet Calculator! 🌟\n");
    printf("Please enter the IP address (e.g., 192.168.1.1): ");
    scanf("%s", inputIP);
    
    printf("Please enter the Subnet Mask (e.g., 255.255.255.0): ");
    scanf("%s", inputMask);
    
    struct IPAddress ipAddress = parseIP(inputIP);
    struct IPAddress subnetMask = parseIP(inputMask);
    
    displaySubnetInfo(ipAddress, subnetMask);

    printf("🎉 Thank you for using the Subnet Calculator! 🎉\n");
    
    return 0;
}