//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_SUBNET 32

void showMenu() {
    printf("Welcome to the Curious C Subnet Calculator!\n");
    printf("Please choose an option:\n");
    printf("1. Calculate Subnet Details\n");
    printf("2. Exit\n");
}

void calculateSubnet(char *ip, int prefix) {
    struct in_addr addr;
    inet_pton(AF_INET, ip, &addr);
    
    unsigned int mask = 0xFFFFFFFF << (MAX_SUBNET - prefix);
    unsigned int network = ntohl(addr.s_addr) & mask;

    struct in_addr networkAddr;
    networkAddr.s_addr = htonl(network);

    printf("Calculating details for IP: %s/%d\n", ip, prefix);
    printf("-------------------------------------------------\n");
    printf("Network Address: %s\n", inet_ntoa(networkAddr));
    printf("Subnet Mask: %s\n", inet_ntoa((struct in_addr){htonl(mask)}));

    unsigned int firstHost = network + 1;
    unsigned int lastHost = network + ~mask + 1 - 1;
    unsigned int broadcastAddr = lastHost + 1;

    printf("First Host IP: %s\n", inet_ntoa((struct in_addr){htonl(firstHost)}));
    printf("Last Host IP: %s\n", inet_ntoa((struct in_addr){htonl(lastHost)}));
    printf("Broadcast Address: %s\n", inet_ntoa((struct in_addr){htonl(broadcastAddr)}));
    printf("Total Number of Hosts: %d\n", (~mask) - 1);
}

int main() {
    char ip[16];
    int prefix;
    int choice;

    while (1) {
        showMenu();
        printf("Your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter the IP address (e.g., 192.168.1.1): ");
            scanf("%s", ip);
            printf("Enter the subnet prefix (0 - 32): ");
            scanf("%d", &prefix);

            if (prefix < 0 || prefix > MAX_SUBNET) {
                printf("Invalid subnet prefix! Please enter a value between 0 and 32.\n");
            } else {
                calculateSubnet(ip, prefix);
            }
        } else if (choice == 2) {
            printf("Exiting the Curious C Subnet Calculator. Bye!\n");
            exit(0);
        } else {
            printf("Invalid option! Please choose again.\n");
        }

        printf("\n-------------------------------------------------\n");
    }
    
    return 0;
}