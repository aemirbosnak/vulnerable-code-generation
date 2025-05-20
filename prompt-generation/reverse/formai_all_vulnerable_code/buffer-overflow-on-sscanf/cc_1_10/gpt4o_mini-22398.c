//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_LENGTH 16
#define MAX_SUBNET_LENGTH 3

// Structure to hold an IP address and its corresponding subnet
typedef struct {
    char ip[MAX_IP_LENGTH];
    char subnet[MAX_SUBNET_LENGTH];
} KnightNetwork;

// Function to calculate the network address from the given IP and subnet mask
void calculateNetworkAddress(KnightNetwork *knight) {
    int ipParts[4], subnetParts[4];

    // Split the IP and Subnet into their respective components
    sscanf(knight->ip, "%d.%d.%d.%d", &ipParts[0], &ipParts[1], &ipParts[2], &ipParts[3]);
    int subnetMask = atoi(knight->subnet);
    
    for (int i = 0; i < 4; i++) {
        if (subnetMask >= 8) {
            subnetParts[i] = ipParts[i]; // Keep the octet
            subnetMask -= 8;
        } else {
            subnetParts[i] = 0; // Set to zero
        }
    }

    printf("Hark! The network address is: %d.%d.%d.%d\n", subnetParts[0], subnetParts[1], subnetParts[2], subnetParts[3]);
}

// Function to display the noble knight's properties 
void displayKnightNetwork(KnightNetwork *knight) {
    printf("Behold the illustrious IP Address of the noble knight: %s\n", knight->ip);
    printf("And the enchanted Subnet Mask: %s\n", knight->subnet);
}

// Function to gather data from the worthy user
void gatherData() {
    KnightNetwork knight;

    printf("Entrust thy noble IP address (format: xxx.xxx.xxx.xxx): ");
    scanf("%s", knight.ip);
    
    printf("Now bestow upon us the Subnet Mask (as a number): ");
    scanf("%s", knight.subnet);

    displayKnightNetwork(&knight);
    calculateNetworkAddress(&knight);
}

int main() {
    printf("Welcome, brave soul, to the C Subnet Calculator of Yore!\n");
    printf("This enchanted program shall aid you in conquering the realms of IP Addressing!\n");
    
    char choice;

    do {
        gatherData();
        printf("Dost thou wish to calculate another? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("Fare thee well, noble warrior of the network!\n");
    return 0;
}