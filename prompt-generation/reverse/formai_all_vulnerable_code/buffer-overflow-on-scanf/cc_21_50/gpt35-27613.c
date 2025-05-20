//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char ipAddr[16], subnetMask[16];
    int octets[4], subnet[4], binaryOctets[4], binarySubnet[4], maskSize, subnetSize, hostSize;
    
    printf("\nRETRO STYLE C SUBNET CALCULATOR\n");
    printf("Please enter the IP Address: ");
    scanf("%s", ipAddr);
    
    // Validate IP Address
    int valid = 1, len = strlen(ipAddr), dots = 0;
    for(int i=0; i<len; i++) {
        if(ipAddr[i] == '.') {
            dots++;
        }
        else if(ipAddr[i] < '0' || ipAddr[i] > '9') {
            valid = 0;
            break;
        }
    }
    if(dots != 3 || !valid) {
        printf("\nInvalid IP Address!\n");
        return 0;
    }
    
    // Extract octets from IP Address
    char *ptr = strtok(ipAddr, ".");
    for(int i=0; i<4; i++) {
        octets[i] = atoi(ptr);
        ptr = strtok(NULL, ".");
    }
    
    printf("\nPlease enter the Subnet Mask: ");
    scanf("%s", subnetMask);
    
    // Validate Subnet Mask
    valid = 1, len = strlen(subnetMask), dots = 0;
    for(int i=0; i<len; i++) {
        if(subnetMask[i] == '.') {
            dots++;
        }
        else if(subnetMask[i] < '0' || subnetMask[i] > '9') {
            valid = 0;
            break;
        }
    }
    if(dots != 3 || !valid) {
        printf("\nInvalid Subnet Mask!\n");
        return 0;
    }
    
    // Extract octets from Subnet Mask
    ptr = strtok(subnetMask, ".");
    for(int i=0; i<4; i++) {
        subnet[i] = atoi(ptr);
        ptr = strtok(NULL, ".");
    }
    
    // Convert octets to binary
    for(int i=0; i<4; i++) {
        int num = octets[i], index = 7, temp[8] = {0};
        while(num != 0) {
            temp[index--] = num % 2;
            num /= 2;
        }
        memcpy(binaryOctets+(i*8), temp, 8*sizeof(int));
    }
    
    // Convert subnet mask to binary
    for(int i=0; i<4; i++) {
        int num = subnet[i], index = 7, temp[8] = {0};
        while(num != 0) {
            temp[index--] = num % 2;
            num /= 2;
        }
        memcpy(binarySubnet+(i*8), temp, 8*sizeof(int));
    }
    
    // Calculate mask size
    maskSize = 0;
    for(int i=0; i<32; i++) {
        if(binarySubnet[i]) {
            maskSize++;
        }
    }
    
    printf("\nIP Address: %s\n", ipAddr);
    printf("Subnet Mask: %s\n", subnetMask);
    printf("Mask Size: /%d\n", maskSize);
    
    // Calculate subnet size and host size
    subnetSize = 1;
    for(int i=0; i<maskSize; i++) {
        subnetSize *= 2;
    }
    subnetSize--;
    hostSize = 256 - subnetSize - 2;
    
    printf("Subnet Size: %d\n", subnetSize);
    printf("Host Size: %d\n", hostSize);
    
    return 0;
}