//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

// Function to calculate network address 
void calculateNetworkAddress(char *ipAddr, char *subnetMask) 
{ 
    char networkAddress[20];
    char *ipAddrPart, *subnetMaskPart;
    int counter = 0;

    // Break IP address string into individual parts 
    ipAddrPart = strtok(ipAddr, ".");
    subnetMaskPart = strtok(subnetMask, ".");

    // Loop through each part of the IP address 
    while (ipAddrPart != NULL && subnetMaskPart != NULL) 
    { 
        int ipAddrPartValue = atoi(ipAddrPart);
        int subnetMaskPartValue = atoi(subnetMaskPart);
        
        // Check if subnet mask has a value greater than 0 
        if (subnetMaskPartValue > 0) 
        {
            // Calculate network address 
            int networkAddressPart = (ipAddrPartValue & subnetMaskPartValue);
            char str[3];
            sprintf(str, "%d", networkAddressPart);
            strcat(networkAddress, str);
        }
        else 
        {
            strcat(networkAddress, "0");
        }
        
        // Add period after each part of the network address 
        if (counter < 3) 
        {
            strcat(networkAddress, ".");
        }
        
        // Move to next part of the IP address and subnet mask 
        ipAddrPart = strtok(NULL, ".");
        subnetMaskPart = strtok(NULL, ".");
        
        counter++;
    }

    printf("Network Address = %s\n", networkAddress);
} 

// Function to calculate broadcast address 
void calculateBroadcastAddress(char *ipAddr, char *subnetMask) 
{ 
    char broadcastAddress[20];
    char *ipAddrPart, *subnetMaskPart;
    int counter = 0;

    // Break IP address string into individual parts 
    ipAddrPart = strtok(ipAddr, ".");
    subnetMaskPart = strtok(subnetMask, ".");

    // Loop through each part of the IP address 
    while (ipAddrPart != NULL && subnetMaskPart != NULL) 
    { 
        int ipAddrPartValue = atoi(ipAddrPart);
        int subnetMaskPartValue = atoi(subnetMaskPart);
        
        // Check if subnet mask has a value greater than 0 
        if (subnetMaskPartValue > 0) 
        { 
            // Calculate broadcast address 
            int broadcastAddressPart = (ipAddrPartValue | (~subnetMaskPartValue & 0xFF)); 
            char str[3];
            sprintf(str, "%d", broadcastAddressPart);
            strcat(broadcastAddress, str);
        }
        else 
        {
            strcat(broadcastAddress, "255");
        }
        
        // Add period after each part of the broadcast address 
        if (counter < 3) 
        {
            strcat(broadcastAddress, ".");
        }
        
        // Move to next part of the IP address and subnet mask 
        ipAddrPart = strtok(NULL, ".");
        subnetMaskPart = strtok(NULL, ".");
        
        counter++;
    }

    printf("Broadcast Address = %s\n", broadcastAddress);
}

// Function to calculate total number of hosts 
void calculateTotalNumberOfHosts(char *subnetMask) 
{ 
    uint32_t subnetMaskValue = 0xFFFFFF00; 
    int totalNumberOfHosts = (~subnetMaskValue & atoi(subnetMask)) - 1; 
    printf("Total Number of Hosts = %d\n", totalNumberOfHosts);
} 

int main() 
{ 
    char ipAddr[20];
    char subnetMask[20];
    bool validInputs = false;

    // Loop until valid IP address and subnet mask are entered 
    while (!validInputs) 
    { 
        // Get IP address and subnet mask from user 
        printf("\nEnter IP Address: ");
        scanf("%s", ipAddr);
        printf("Enter Subnet Mask: ");
        scanf("%s", subnetMask);

        // Ensure IP address and subnet mask are valid 
        if (strcmp(ipAddr, "") != 0 && strcmp(subnetMask, "") != 0) 
        { 
            validInputs = true;
        }
        else 
        { 
            printf("\nInvalid Input. Please try again.\n");
        } 
    }

    // Calculate and display network address, broadcast address, and total number of hosts 
    calculateNetworkAddress(ipAddr, subnetMask);
    calculateBroadcastAddress(ipAddr, subnetMask);
    calculateTotalNumberOfHosts(subnetMask);

    return 0; 
}