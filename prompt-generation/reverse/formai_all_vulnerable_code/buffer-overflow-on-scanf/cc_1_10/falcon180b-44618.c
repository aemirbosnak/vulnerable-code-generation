//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the subnet mask
void calculateSubnet(char* ipAddress, char* subnetMask) {
    int i, j;
    char octet[3];

    // Copy the IP address to a temporary string
    strcpy(octet, ipAddress);

    // Extract the first octet
    i = 0;
    j = 0;
    while (octet[i]!= '.') {
        subnetMask[j] = octet[i];
        i++;
        j++;
    }
    subnetMask[j] = '\0';

    // Extract the second and third octets
    i++;
    while (octet[i]!= '.') {
        subnetMask[j] = octet[i];
        i++;
        j++;
    }
    subnetMask[j] = '\0';

    // Extract the fourth octet
    i++;
    while (octet[i]!= '\0') {
        subnetMask[j] = octet[i];
        i++;
        j++;
    }
    subnetMask[j] = '\0';
}

int main() {
    char ipAddress[16];
    char subnetMask[16];

    // Get the IP address from the user
    printf("Enter the IP address: ");
    scanf("%s", ipAddress);

    // Calculate the subnet mask
    calculateSubnet(ipAddress, subnetMask);

    // Print the subnet mask
    printf("Subnet mask: %s\n", subnetMask);

    return 0;
}