//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void printBinary(unsigned int num) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 8 == 0) printf(" ");
    }
}

unsigned int ipToDecimal(const char *ip) {
    unsigned int decimal = 0;
    int octet;
    char *token;
    char ipCopy[16];
    
    strncpy(ipCopy, ip, sizeof(ipCopy));
    token = strtok(ipCopy, ".");
    
    for (int i = 3; i >= 0 && token != NULL; i--) {
        octet = atoi(token);
        decimal += octet << (i * 8);
        token = strtok(NULL, ".");
    }
    return decimal;
}

void decimalToIp(unsigned int decimal, char *ip) {
    sprintf(ip, "%d.%d.%d.%d", 
            (decimal >> 24) & 0xFF, 
            (decimal >> 16) & 0xFF,
            (decimal >> 8) & 0xFF,
            decimal & 0xFF);
}

void calculateSubnet(unsigned int ipDecimal, unsigned int maskDecimal, unsigned int *network, unsigned int *broadcast) {
    *network = ipDecimal & maskDecimal;
    *broadcast = *network | ~maskDecimal;
}

void calculateHosts(unsigned int maskDecimal) {
    int bits = 0;
    for (int i = 0; i < 32; i++) {
        if ((maskDecimal & (1 << i)) == 0) {
            bits++;
        }
    }
    printf("Number of usable hosts: %d\n", (int)pow(2, bits) - 2);
}

void displaySubnetDetails(const char *ip, const char *mask) {
    unsigned int ipDecimal = ipToDecimal(ip);
    unsigned int maskDecimal = ipToDecimal(mask);
    unsigned int network, broadcast;

    calculateSubnet(ipDecimal, maskDecimal, &network, &broadcast);

    char networkIp[16], broadcastIp[16];
    decimalToIp(network, networkIp);
    decimalToIp(broadcast, broadcastIp);

    printf("Subnet details:\n");
    printf("IP Address: %s\n", ip);
    printf("Subnet Mask: %s\n", mask);
    printf("Network Address: %s\n", networkIp);
    printf("Broadcast Address: %s\n", broadcastIp);
    calculateHosts(maskDecimal);
}

int main() {
    char ip[16], mask[16];

    printf("Welcome to C Subnet Calculator!\n");
    
    while (1) {
        printf("\nEnter an IP Address (or type 'exit' to quit): ");
        scanf("%s", ip);
        
        if (strcmp(ip, "exit") == 0) {
            break;
        }

        printf("Enter the Subnet Mask (e.g., 255.255.255.0): ");
        scanf("%s", mask);
        
        if (strcmp(mask, "exit") == 0) {
            break;
        } 
        
        displaySubnetDetails(ip, mask);
        
        unsigned int ipDecimal = ipToDecimal(ip);
        unsigned int maskDecimal = ipToDecimal(mask);
        
        printf("IP Address in Decimal: "); 
        printBinary(ipDecimal);
        printf("\n");
        
        printf("Subnet Mask in Decimal: "); 
        printBinary(maskDecimal);
        printf("\n");
    }

    printf("Thank you for using the C Subnet Calculator!\n");
    return 0;
}