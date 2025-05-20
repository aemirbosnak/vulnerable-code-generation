//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void calculateSubnet(char *ip, int subnetMask) {
    int ip_parts[4];
    sscanf(ip, "%d.%d.%d.%d", &ip_parts[0], &ip_parts[1], &ip_parts[2], &ip_parts[3]);

    // Calculate the network address
    int mask = 0xFFFFFFFF << (32 - subnetMask);
    long long networkAddress = (ip_parts[0] << 24) | (ip_parts[1] << 16) | (ip_parts[2] << 8) | ip_parts[3];
    long long network = networkAddress & mask;

    // Calculate broadcast address
    long long broadcast = network | ~mask;

    // Calculate the number of available hosts
    int hosts = pow(2, (32 - subnetMask)) - 2;

    // Output results in shocking detail!
    printf("🔍 Shockingly Detailed Subnet Information! 🔍\n");
    printf("-----------------------------------------------------\n");
    printf("🌐 IP Address: %s\n", ip);
    printf("📊 Subnet Mask: /%d\n", subnetMask);
    
    // Print the network address in dotted decimal
    printf("🕸️ Network Address: %d.%d.%d.%d\n", 
        (network >> 24) & 0xFF, 
        (network >> 16) & 0xFF, 
        (network >> 8) & 0xFF, 
        network & 0xFF);
    
    // Print the broadcast address in dotted decimal
    printf("📡 Broadcast Address: %d.%d.%d.%d\n", 
        (broadcast >> 24) & 0xFF, 
        (broadcast >> 16) & 0xFF, 
        (broadcast >> 8) & 0xFF, 
        broadcast & 0xFF);
    
    printf("🎉 Available Hosts: %d\n", hosts);
    printf("-----------------------------------------------------\n");
    printf("💥 Let’s conquer the network with this knowledge! 💥\n");
}

int main() {
    char ip[16];
    int subnetMask;

    printf("🎈 Welcome to the Ultimate Subnet Calculator! 🎈\n");
    printf("🎯 Input your IP Address (e.g., 192.168.1.1): ");
    fgets(ip, sizeof(ip), stdin);
    ip[strcspn(ip, "\n")] = 0; // Remove trailing newline

    printf("✅ Now, enter your subnet mask (e.g., 24): ");
    scanf("%d", &subnetMask);

    if (subnetMask < 0 || subnetMask > 32) {
        printf("🚫 Error: Subnet mask must be between 0 and 32! 🚫\n");
        return 1;
    }

    calculateSubnet(ip, subnetMask);

    printf("🤖 Thank you for using the Subnet Calculator! Stay connected! 🤖\n");
    return 0;
}