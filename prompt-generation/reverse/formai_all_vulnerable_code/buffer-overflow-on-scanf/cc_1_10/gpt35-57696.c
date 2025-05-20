//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>

//Function to convert IP Address to Binary

uint8_t* convert_IpAddress_to_Binary(char *ipAddress) {
    uint8_t *binaryIpAddress = malloc(32 * sizeof(uint8_t));
    int i = 0;
    char *token = strtok(ipAddress, ".");
    while(token != NULL) {
        binaryIpAddress[i] = atoi(token);
        token = strtok(NULL, ".");
        i++;
    }
    return binaryIpAddress;
}

//Function to calculate the Subnet Mask based on subnet bits

uint8_t* calculate_Subnet_Mask(int subnet_bits) {
    uint8_t *subnetMask = malloc(32 * sizeof(uint8_t));
    int i = 0;
    while(i < 32) {
        if(i < subnet_bits) {
            subnetMask[i] = 1;
        }
        else {
            subnetMask[i] = 0;
        }
        i++;
    }
    return subnetMask;
}

//Function to calculate the Subnet ID based on IP Address and Subnet Mask

uint8_t* calculate_Subnet_Id(uint8_t *binaryIpAddress, uint8_t *subnetMask) {
    uint8_t *subnetId = malloc(32 * sizeof(uint8_t));
    int i = 0;
    while(i < 32) {
        subnetId[i] = binaryIpAddress[i] & subnetMask[i];
        i++;
    }
    return subnetId;
}

//Function to display Subnet Mask and Subnet ID

void display_Subnet_Address(uint8_t *subnetMask, uint8_t *subnetId) {
    printf("\nSubnet Mask: ");
    int i = 0;
    while(i < 32) {
        if(i % 8 == 0 && i > 0) {
            printf(".");
        }
        printf("%d", subnetMask[i]);
        i++;
    }
    printf("\nSubnet ID:   ");
    i = 0;
    while(i < 32) {
        if(i % 8 == 0 && i > 0) {
            printf(".");
        }
        printf("%d", subnetId[i]);
        i++;
    }
    printf("\n");
}

//Main Function

int main() {
    char ipAddress[16];
    printf("Enter IP Address: ");
    scanf("%s", ipAddress);
    int subnet_bits;
    printf("Enter No. of Subnet Bits: ");
    scanf("%d", &subnet_bits);
    if(subnet_bits < 0 || subnet_bits > 32) {
        printf("Invalid No. of Subnet Bits! Exiting...\n");
        exit(0);
    }
    uint8_t *binaryIpAddress = convert_IpAddress_to_Binary(ipAddress);
    uint8_t *subnetMask = calculate_Subnet_Mask(subnet_bits);
    uint8_t *subnetId = calculate_Subnet_Id(binaryIpAddress, subnetMask);
    display_Subnet_Address(subnetMask, subnetId);
    return 0;
}