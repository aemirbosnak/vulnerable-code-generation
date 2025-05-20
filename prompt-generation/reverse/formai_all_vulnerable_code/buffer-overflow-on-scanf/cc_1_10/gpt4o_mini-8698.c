//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

void calculateSubnet(char *ip, char *mask) {
    struct in_addr ipAddr, maskAddr, networkAddr, broadcastAddr;

    // Convert string IP to in_addr
    if (inet_pton(AF_INET, ip, &ipAddr) <= 0) {
        printf("Invalid IP address format!\n");
        return;
    }
    
    // Convert string mask to in_addr
    if (inet_pton(AF_INET, mask, &maskAddr) <= 0) {
        printf("Invalid Mask format!\n");
        return;
    }

    // Calculate Network Address
    networkAddr.s_addr = ipAddr.s_addr & maskAddr.s_addr;

    // Calculate Broadcast Address
    broadcastAddr.s_addr = networkAddr.s_addr | ~maskAddr.s_addr;

    // Calculate Number of Hosts
    unsigned int numHosts = ntohl(~maskAddr.s_addr) - 1;

    // Display the results
    printf("\nSubnet Calculation Results:\n");
    printf("---------------------------------------------------\n");
    printf("IP Address:       %s\n", inet_ntoa(ipAddr));
    printf("Subnet Mask:      %s\n", inet_ntoa(maskAddr));
    printf("Network Address:  %s\n", inet_ntoa(networkAddr));
    printf("Broadcast Address: %s\n", inet_ntoa(broadcastAddr));
    printf("Usable Hosts:     %u\n", numHosts);
    printf("---------------------------------------------------\n");
}

int main() {
    char ip[16], mask[16];
    
    printf("Welcome to the C Subnet Calculator!\n");
    printf("Let's play around with some IPs and masks, shall we?\n");
    
    while (1) {
        printf("\nEnter IP Address (or 'exit' to quit): ");
        scanf("%s", ip);
        
        if (strcmp(ip, "exit") == 0) {
            printf("Thanks for using the Subnet Calculator! Bye!\n");
            break;
        }

        printf("Now enter the Subnet Mask: ");
        scanf("%s", mask);
        
        calculateSubnet(ip, mask);
    }
    
    return 0;
}