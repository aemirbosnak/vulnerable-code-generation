//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_IP_LENGTH 15
#define MAX_SUBNET_LENGTH 3

typedef struct {
    int octet[4]; // Store the four octets of an IP address
} IPAddress;

// Function prototypes
void inputIPAddress(IPAddress *ip);
void inputSubnetMask(int *subnetMask);
void calculateSubnet(IPAddress ip, int subnetMask);
void printSubnetDetails(IPAddress baseIP, int subnetMask, int totalHosts);

int main() {
    IPAddress ip;
    int subnetMask;

    printf("Welcome to the C Subnet Calculator!\n");
    printf("=====================================\n");

    // Input the IP address
    inputIPAddress(&ip);
    
    // Input subnet mask
    inputSubnetMask(&subnetMask);
    
    // Calculate and display subnet details
    calculateSubnet(ip, subnetMask);

    return 0;
}

// Function to input an IP address
void inputIPAddress(IPAddress *ip) {
    char input[MAX_IP_LENGTH + 1];
    printf("Enter the IP Address (e.g., 192.168.1.1): ");
    fgets(input, sizeof(input), stdin);
    
    sscanf(input, "%d.%d.%d.%d", &ip->octet[0], &ip->octet[1], 
                                  &ip->octet[2], &ip->octet[3]);
    
    for (int i = 0; i < 4; i++) {
        if (ip->octet[i] < 0 || ip->octet[i] > 255) {
            printf("Invalid IP address! Each octet must be between 0 and 255.\n");
            exit(1);
        }
    }
}

// Function to input a subnet mask
void inputSubnetMask(int *subnetMask) {
    char input[MAX_SUBNET_LENGTH + 1];
    printf("Enter the subnet mask in CIDR notation (e.g., /24): ");
    fgets(input, sizeof(input), stdin);
    
    *subnetMask = atoi(input + 1); // Skip the '/' character
    
    if (*subnetMask < 0 || *subnetMask > 32) {
        printf("Invalid subnet mask! Must be between /0 and /32\n");
        exit(1);
    }
}

// Function to calculate subnet
void calculateSubnet(IPAddress ip, int subnetMask) {
    int prefixBits = 32 - subnetMask;
    int totalHosts = (1 << prefixBits) - 2; // 2 for network and broadcast addresses

    int subnetBase[4] = {0};
    for (int i = 0; i < 4; i++) {
        // Clear the host bits to get the subnet address
        if (i < subnetMask / 8) {
            subnetBase[i] = ip.octet[i];
        } else {
            subnetBase[i] = 0;
        }
    }

    // Calculate the first and last IP addresses of the subnet
    int firstIP[4] = {subnetBase[0], subnetBase[1], subnetBase[2], subnetBase[3] + 1};
    int lastIP[4] = {subnetBase[0], subnetBase[1], subnetBase[2], subnetBase[3] + totalHosts + 1};

    // Print subnet details
    printSubnetDetails(ip, subnetMask, totalHosts);
    printf("Subnet Address: %d.%d.%d.%d/%d\n", 
           subnetBase[0], subnetBase[1], subnetBase[2], subnetBase[3], subnetMask);
    printf("First Usable IP: %d.%d.%d.%d\n", 
           firstIP[0], firstIP[1], firstIP[2], firstIP[3]);
    printf("Last Usable IP: %d.%d.%d.%d\n", 
           lastIP[0], lastIP[1], lastIP[2], lastIP[3] - 1); // Adjust for broadcast
    printf("Total Usable Hosts: %d\n", totalHosts);
}

// Function to print the subnet details
void printSubnetDetails(IPAddress baseIP, int subnetMask, int totalHosts) {
    printf("Calculating subnet details for IP: %d.%d.%d.%d/%d...\n", 
           baseIP.octet[0], baseIP.octet[1], baseIP.octet[2], baseIP.octet[3], subnetMask);
    printf("Number of total hosts possible: %d\n", totalHosts + 2); // including network & broadcast
    printf("Number of usable hosts: %d\n", totalHosts);
    printf("Thank you for using the C Subnet Calculator!\n");
}