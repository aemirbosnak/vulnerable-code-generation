//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_SUBNETS 16

// Structure to hold subnet information
typedef struct {
    char ip[16];
    char subnetMask[16];
    char networkAddress[16];
    char broadcastAddress[16];
    int numHosts;
} Subnet;

// Function declarations
void calculateSubnet(Subnet* subnet, const char* ip, const char* mask);
void printSubnetInfo(const Subnet* subnet);
void promptUserForInput(char* ip, char* mask);
void displayMenu();
int handleUserInput();

int main() {
    Subnet subnets[MAX_SUBNETS];
    int subnetCount = 0;
    int option;

    while (1) {
        displayMenu();
        option = handleUserInput();
        
        switch (option) {
            case 1:
                if (subnetCount < MAX_SUBNETS) {
                    char ip[16];
                    char mask[16];
                    promptUserForInput(ip, mask);
                    calculateSubnet(&subnets[subnetCount], ip, mask);
                    subnetCount++;
                } else {
                    printf("Maximum number of subnets reached.\n");
                }
                break;
            case 2:
                for (int i = 0; i < subnetCount; i++) {
                    printSubnetInfo(&subnets[i]);
                }
                break;
            case 3:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n--- Subnet Calculator ---\n");
    printf("1. Add New Subnet\n");
    printf("2. Display Subnet Information\n");
    printf("3. Exit\n");
    printf("Select an option: ");
}

int handleUserInput() {
    int option;
    scanf("%d", &option);
    return option;
}

void promptUserForInput(char* ip, char* mask) {
    printf("Enter IP Address (e.g., 192.168.1.1): ");
    scanf("%s", ip);
    printf("Enter Subnet Mask (e.g., 255.255.255.0): ");
    scanf("%s", mask);
}

void calculateSubnet(Subnet* subnet, const char* ip, const char* mask) {
    struct in_addr ipAddr, maskAddr;
    
    // Convert IP and Mask strings to in_addr
    inet_pton(AF_INET, ip, &ipAddr);
    inet_pton(AF_INET, mask, &maskAddr);
    
    // Calculate network and broadcast address
    struct in_addr networkAddr;
    struct in_addr broadcastAddr;
    
    networkAddr.s_addr = ipAddr.s_addr & maskAddr.s_addr;
    broadcastAddr.s_addr = networkAddr.s_addr | ~maskAddr.s_addr;

    // Fill in the subnet details
    strcpy(subnet->ip, ip);
    strcpy(subnet->subnetMask, mask);
    strcpy(subnet->networkAddress, inet_ntoa(networkAddr));
    strcpy(subnet->broadcastAddress, inet_ntoa(broadcastAddr));
    subnet->numHosts = ntohl(~maskAddr.s_addr) - 1;

    // Output results to user
    printf("Subnet details calculated successfully.\n");
}

void printSubnetInfo(const Subnet* subnet) {
    printf("\n----- Subnet Information -----\n");
    printf("IP Address: %s\n", subnet->ip);
    printf("Subnet Mask: %s\n", subnet->subnetMask);
    printf("Network Address: %s\n", subnet->networkAddress);
    printf("Broadcast Address: %s\n", subnet->broadcastAddress);
    printf("Number of Usable Hosts: %d\n", subnet->numHosts);
}