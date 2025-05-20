//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

void calculateSubnet(char* ipAddress, char* subnetMask) {
    struct sockaddr_in ip, mask, network, broadcast;
    
    // Convert IP Address and Subnet Mask from string to binary form
    inet_pton(AF_INET, ipAddress, &(ip.sin_addr));
    inet_pton(AF_INET, subnetMask, &(mask.sin_addr));
    
    // Calculate Network Address: IP AND Subnet Mask
    network.sin_addr.s_addr = ip.sin_addr.s_addr & mask.sin_addr.s_addr;
    
    // Calculate Broadcast Address: Network OR (NOT Subnet Mask)
    broadcast.sin_addr.s_addr = network.sin_addr.s_addr | ~mask.sin_addr.s_addr;

    // Convert the results back to string format
    char netAddr[INET_ADDRSTRLEN];
    char broadAddr[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &network.sin_addr, netAddr, sizeof(netAddr));
    inet_ntop(AF_INET, &broadcast.sin_addr, broadAddr, sizeof(broadAddr));
    
    // Calculate usable hosts
    unsigned int totalHosts = ntohl(~mask.sin_addr.s_addr) - 1;
    
    printf("🎉 Subnet Calculator 🎉\n");
    printf("=========================================\n");
    printf("IP Address:      %s\n", ipAddress);
    printf("Subnet Mask:     %s\n", subnetMask);
    printf("Network Address: %s\n", netAddr);
    printf("Broadcast Address: %s\n", broadAddr);
    printf("Total Usable Hosts: %u\n", totalHosts);
    printf("=========================================\n");
}

int main() {
    char ipAddress[INET_ADDRSTRLEN];
    char subnetMask[INET_ADDRSTRLEN];

    // Welcome Message
    printf("🌐 Welcome to the Exciting C Subnet Calculator! 🌐\n");
    
    // Input the IP Address
    printf("Please enter the IP address (e.g., 192.168.1.1): ");
    scanf("%s", ipAddress);

    // Input the Subnet Mask
    printf("Please enter the Subnet Mask (e.g., 255.255.255.0): ");
    scanf("%s", subnetMask);

    // Validate IP Address and Subnet Mask
    if (inet_pton(AF_INET, ipAddress, &(struct sockaddr_in){0}) <= 0 ||
        inet_pton(AF_INET, subnetMask, &(struct sockaddr_in){0}) <= 0) {
        printf("❌ Invalid IP Address or Subnet Mask! ❌\n");
        return 1;
    }
  
    // Calculate Subnet Information
    calculateSubnet(ipAddress, subnetMask);
    
    // Farewell Message
    printf("🚀 Thank you for using the Subnet Calculator! 🚀\n");
    return 0;
}