//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char ip[17], subnet[17];
    int mask_bits;
    
    printf("Welcome to the Happy Subnet Calculator! Let's brighten up your day!\n\n");
    printf("Enter the IP address: ");
    scanf("%s", ip);
    printf("Enter the subnet mask (in dotted decimal format): ");
    scanf("%s", subnet);
    
    // Parsing the subnet mask into its mask bits representation
    char *nptr;
    nptr = strtok(subnet, ".");
    int oct1 = atoi(nptr);
    nptr = strtok(NULL, ".");
    int oct2 = atoi(nptr);
    nptr = strtok(NULL, ".");
    int oct3 = atoi(nptr);
    nptr = strtok(NULL, ".");
    int oct4 = atoi(nptr);
    mask_bits = 8 * (oct1 == 255 ? 1 : oct2 == 255 ? 2 : oct3 == 255 ? 3 : 4) + (oct1 == 255 ? 0 : oct2 == 255 ? (oct1 & 0x1) * 8 : oct3 == 255 ? (oct2 & 0x7) * 8 : (oct3 & 0xF) * 8 + ((oct4 - 1) & 0x1) * 4 + ((oct4 - 1) & 0x2) * 2 + ((oct4 - 1) & 0x4) * 1);

    // Parsing the IP address into its octets
    nptr = strtok(ip, ".");
    oct1 = atoi(nptr);
    nptr = strtok(NULL, ".");
    oct2 = atoi(nptr);
    nptr = strtok(NULL, ".");
    oct3 = atoi(nptr);
    nptr = strtok(NULL, ".");
    oct4 = atoi(nptr);
    
    // Calculating the network address and broadcast address
    int net_oct1, net_oct2, net_oct3, net_oct4;
    int bcast_oct1, bcast_oct2, bcast_oct3, bcast_oct4;
    net_oct1 = oct1 & (mask_bits >> 24);
    net_oct2 = oct2 & (mask_bits >> 16);
    net_oct3 = oct3 & (mask_bits >> 8);
    net_oct4 = oct4 & mask_bits;
    bcast_oct1 = net_oct1 | ~(mask_bits >> 24) & 0xFF;
    bcast_oct2 = net_oct2 | ~(mask_bits >> 16) & 0xFF;
    bcast_oct3 = net_oct3 | ~(mask_bits >> 8) & 0xFF;
    bcast_oct4 = net_oct4 | ~(mask_bits) & 0xFF;

    printf("\nHappy subnetting!\n\n");
    printf("IP address       : %d.%d.%d.%d\n", oct1, oct2, oct3, oct4);
    printf("Subnet mask      : %s\n", subnet);
    printf("Mask bits        : %d\n", mask_bits);
    printf("Network address  : %d.%d.%d.%d\n", net_oct1, net_oct2, net_oct3, net_oct4);
    printf("Broadcast address: %d.%d.%d.%d\n", bcast_oct1, bcast_oct2, bcast_oct3, bcast_oct4);
    
    return 0;
}