//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: ephemeral
/*
Ephemeral C Subnet Calculator
Author: [Your Name]
Date: [Date]

This program is a subnet calculator that takes an IP address and subnet mask as inputs and outputs various information about the network.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_IP_OCTETS 4
#define MAX_SUBNET_OCTETS 4
#define MAX_DECIMAL 255
#define MAX_BIT_MASK 32

// Function prototypes
int* decimalToBinary(int decimalNum);
int binaryToDecimal(int* binaryNum);
int* calculateNetworkAddress(int* ipAddress, int* subnetMask);
int* calculateBroadcastAddress(int* ipAddress, int* subnetMask);
int getNumberOfHosts(int subnetMask);
int validateInput(int* arr, int maxOctets, int maxDecimal);
void printIpAddress(int* ipAddress);

// Main function
int main() {
    // Declare variables
    char userChoice = 'y';
    int ipAddress[MAX_IP_OCTETS];
    int subnetMask[MAX_SUBNET_OCTETS];
    int* networkAddress = NULL;
    int* broadcastAddress = NULL;
    int numberOfHosts = 0;
    
    // Display welcome message and instructions
    printf("Welcome to the Ephemeral C Subnet Calculator!\n");
    printf("Please enter the IP address and subnet mask below.\n");
    
    do {
        // Get input from user
        printf("\nEnter IP address (e.g. 192.168.0.1): ");
        scanf("%d.%d.%d.%d", &ipAddress[0], &ipAddress[1], &ipAddress[2], &ipAddress[3]);
        
        // Validate IP address input
        if (validateInput(ipAddress, MAX_IP_OCTETS, MAX_DECIMAL)) {
            // Get input from user
            printf("Enter subnet mask (e.g. 255.255.255.0): ");
            scanf("%d.%d.%d.%d", &subnetMask[0], &subnetMask[1], &subnetMask[2], &subnetMask[3]);
            
            // Validate subnet mask input
            if (validateInput(subnetMask, MAX_SUBNET_OCTETS, MAX_DECIMAL)) {
                // Calculate network address and broadcast address
                networkAddress = calculateNetworkAddress(ipAddress, subnetMask);
                broadcastAddress = calculateBroadcastAddress(ipAddress, subnetMask);
                
                // Calculate number of hosts
                numberOfHosts = getNumberOfHosts(binaryToDecimal(subnetMask));
                
                // Print results
                printf("\nResults:\n");
                printf("IP Address: ");
                printIpAddress(ipAddress);
                printf("Subnet Mask: ");
                printIpAddress(subnetMask);
                printf("Network Address: ");
                printIpAddress(networkAddress);
                printf("Broadcast Address: ");
                printIpAddress(broadcastAddress);
                printf("Number of Hosts: %d\n", numberOfHosts);
                
                // Free memory
                free(networkAddress);
                free(broadcastAddress);
            } else {
                printf("Invalid subnet mask input. Please try again.\n");
            }
        } else {
            printf("Invalid IP address input. Please try again.\n");
        }
        
        // Ask user if they want to calculate another network
        printf("\nDo you want to calculate another network? (y/n): ");
        scanf(" %c", &userChoice);
    } while (userChoice == 'y' || userChoice == 'Y');
    
    printf("\nThank you for using the Ephemeral C Subnet Calculator!\n");
    
    return 0;
}

/*
 * Function: decimalToBinary
 * -------------------------
 * Converts a decimal number to a binary array.
 *
 * decimalNum: the decimal number to convert
 *
 * returns: a pointer to the binary array
 */
int* decimalToBinary(int decimalNum) {
    int* binaryArray = malloc(MAX_BIT_MASK * sizeof(int));
    int i = 0;
    
    // Convert decimal number to binary
    while (decimalNum > 0) {
        binaryArray[i++] = decimalNum % 2;
        decimalNum /= 2;
    }
    
    // Fill in remaining bits with 0's
    while (i < MAX_BIT_MASK) {
        binaryArray[i++] = 0;
    }
    
    return binaryArray;
}

/*
 * Function: binaryToDecimal
 * -------------------------
 * Converts a binary array to a decimal number.
 *
 * binaryNum: a pointer to the binary array to convert
 *
 * returns: the decimal number
 */
int binaryToDecimal(int* binaryNum) {
    int decimalNum = 0;
    int i;
    
    // Convert binary array to decimal
    for (i = 0; i < MAX_BIT_MASK; i++) {
        decimalNum += binaryNum[i] * (1 << i);
    }
    
    return decimalNum;
}

/*
 * Function: calculateNetworkAddress
 * ---------------------------------
 * Calculates the network address from the given IP address and subnet mask.
 *
 * ipAddress: a pointer to the IP address array
 * subnetMask: a pointer to the subnet mask array
 *
 * returns: a pointer to the network address array
 */
int* calculateNetworkAddress(int* ipAddress, int* subnetMask) {
    int* networkAddress = malloc(MAX_IP_OCTETS * sizeof(int));
    int i;
    
    // Calculate network address
    for (i = 0; i < MAX_IP_OCTETS; i++) {
        networkAddress[i] = ipAddress[i] & subnetMask[i];
    }
    
    return networkAddress;
}

/*
 * Function: calculateBroadcastAddress
 * ------------------------------------
 * Calculates the broadcast address from the given IP address and subnet mask.
 *
 * ipAddress: a pointer to the IP address array
 * subnetMask: a pointer to the subnet mask array
 *
 * returns: a pointer to the broadcast address array
 */
int* calculateBroadcastAddress(int* ipAddress, int* subnetMask) {
    int* broadcastAddress = malloc(MAX_IP_OCTETS * sizeof(int));
    int i;
    
    // Calculate network address complement
    int* subnetMaskCompl = malloc(MAX_IP_OCTETS * sizeof(int));
    for (i = 0; i < MAX_IP_OCTETS; i++) {
        subnetMaskCompl[i] = MAX_DECIMAL - subnetMask[i];
    }
    
    // Calculate broadcast address
    for (i = 0; i < MAX_IP_OCTETS; i++) {
        broadcastAddress[i] = ipAddress[i] | subnetMaskCompl[i];
    }
    
    // Free memory
    free(subnetMaskCompl);
    
    return broadcastAddress;
}

/*
 * Function: getNumberOfHosts
 * --------------------------
 * Calculates the number of hosts based on the subnet mask.
 *
 * subnetMask: the decimal representation of the subnet mask
 *
 * returns: the number of hosts
 */
int getNumberOfHosts(int subnetMask) {
    return (1 << (MAX_BIT_MASK - subnetMask)) - 2;
}

/*
 * Function: validateInput
 * -----------------------
 * Validates the user input.
 *
 * arr: a pointer to the input array
 * maxOctets: the maximum number of IP/subnet octets
 * maxDecimal: the maximum decimal value allowed
 *
 * returns: 1 if input is valid, 0 otherwise
 */
int validateInput(int* arr, int maxOctets, int maxDecimal) {
    int i;
    
    for (i = 0; i < maxOctets; i++) {
        if (arr[i] < 0 || arr[i] > maxDecimal) {
            return 0;
        }
    }
    
    return 1;
}

/*
 * Function: printIpAddress
 * ------------------------
 * Prints an IP address array in dotted decimal notation.
 *
 * ipAddress: a pointer to the IP address array to print
 */
void printIpAddress(int* ipAddress) {
    int i;
    
    for (i = 0; i < MAX_IP_OCTETS-1; i++) {
        printf("%d.", ipAddress[i]);
    }
    
    printf("%d\n", ipAddress[i]);
}