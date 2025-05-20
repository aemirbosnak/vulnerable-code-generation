//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string is a valid IP address
int isValidIP(char* ip) {
    int i = 0;
    char* p;
    int dots = 0;

    // Check for leading zeros
    while(ip[i] == '0' && i < strlen(ip)) {
        i++;
    }

    // Check for octet values
    while(ip[i]!= '.' && i < strlen(ip)) {
        if(!isdigit(ip[i])) {
            return 0;
        }
        i++;
    }

    // Check for number of octets
    while(ip[i] == '.' && i < strlen(ip)) {
        dots++;
        i++;
    }

    if(dots!= 3) {
        return 0;
    }

    // Check remaining octets
    p = strtok(ip, ".");
    while(p!= NULL) {
        if(atoi(p) < 0 || atoi(p) > 255) {
            return 0;
        }
        p = strtok(NULL, ".");
    }

    return 1;
}

// Function to calculate subnet mask
void calculateSubnet(int ip[], int subnetBits) {
    int i;
    int mask = 0;

    // Calculate subnet mask
    for(i = 0; i < subnetBits; i++) {
        mask |= (1 << i);
    }

    // Apply subnet mask to IP address
    ip[3] &= mask;
}

// Function to display IP address and subnet mask
void displayIP(int ip[]) {
    printf("IP Address: %d.%d.%d.%d\n", ip[0], ip[1], ip[2], ip[3]);
    printf("Subnet Mask: %d.%d.%d.%d\n", ip[0], ip[1], ip[2], ip[3]);
}

int main() {
    char ip[16];
    int subnetBits;

    // Get IP address from user
    printf("Enter IP Address: ");
    scanf("%s", ip);

    // Check if IP address is valid
    if(!isValidIP(ip)) {
        printf("Invalid IP Address\n");
        return 1;
    }

    // Get subnet bits from user
    printf("Enter Subnet Bits: ");
    scanf("%d", &subnetBits);

    // Convert IP address string to integer array
    int ipArray[4];
    ipArray[0] = atoi(strtok(ip, "."));
    ipArray[1] = atoi(strtok(NULL, "."));
    ipArray[2] = atoi(strtok(NULL, "."));
    ipArray[3] = atoi(strtok(NULL, "."));

    // Calculate subnet mask
    calculateSubnet(ipArray, subnetBits);

    // Display IP address and subnet mask
    displayIP(ipArray);

    return 0;
}