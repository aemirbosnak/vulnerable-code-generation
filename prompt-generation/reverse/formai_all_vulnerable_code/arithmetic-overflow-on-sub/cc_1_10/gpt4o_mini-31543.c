//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

void loveLetter(char *message);
uint32_t ipToDecimal(char *ip);
void decimalToIp(uint32_t decimal, char *ip);
void calculateSubnet(char* ip, char* subnetMask);

int main() {
    char ip[16], subnetMask[16];

    loveLetter("O fair IP, I beseech thee to cast thy digits to the world!");
    printf("Enter your IP address (e.g., 192.168.0.1): ");
    fgets(ip, sizeof(ip), stdin);
    ip[strcspn(ip, "\n")] = 0; // remove newline character

    loveLetter("Oh sweet Subnet Mask, guide us to our destiny!");
    printf("Enter your Subnet Mask (e.g., 255.255.255.0): ");
    fgets(subnetMask, sizeof(subnetMask), stdin);
    subnetMask[strcspn(subnetMask, "\n")] = 0; // remove newline character

    calculateSubnet(ip, subnetMask);
    
    loveLetter("Alas, eternal unity of networks is destined!");

    return 0;
}

void loveLetter(char *message) {
    printf("** %s **\n", message);
}

uint32_t ipToDecimal(char *ip) {
    uint32_t decimal = 0;
    int octet;
    char *token = strtok(ip, ".");

    while (token != NULL) {
        octet = atoi(token);
        decimal = (decimal << 8) + octet;
        token = strtok(NULL, ".");
    }

    return decimal;
}

void decimalToIp(uint32_t decimal, char *ip) {
    sprintf(ip, "%u.%u.%u.%u",
        (decimal >> 24) & 0xFF,
        (decimal >> 16) & 0xFF,
        (decimal >> 8) & 0xFF,
        decimal & 0xFF);
}

void calculateSubnet(char* ip, char* subnetMask) {
    uint32_t ipDecimal = ipToDecimal(ip);
    uint32_t subnetDecimal = ipToDecimal(subnetMask);

    uint32_t networkAddress = ipDecimal & subnetDecimal;
    uint32_t broadcastAddress = networkAddress | ~subnetDecimal;

    char networkIp[16], broadcastIp[16];
    decimalToIp(networkAddress, networkIp);
    decimalToIp(broadcastAddress, broadcastIp);

    printf("In everlasting bonds, our union is as follows:\n");
    printf("Network Address: %s\n", networkIp);
    printf("Broadcast Address: %s\n", broadcastIp);
    
    printf("In sweet eternity of subnetting, embrace holds,\n");
    printf("The number of possible hosts: %lu\n", (uint32_t)(pow(2, 32 - (32 - (int)(log2(subnetDecimal & -subnetDecimal)))) - 2));
}