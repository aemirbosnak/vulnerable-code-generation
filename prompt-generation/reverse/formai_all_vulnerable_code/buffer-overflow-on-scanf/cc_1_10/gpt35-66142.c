//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BITS_IN_OCTET 8

/*
 * Calculate the network and broadcast addresses
 */
void calcNetworkAndBroadcastIP(char *ip, char *subnetMask, char *networkIP, char *broadcastIP)
{
    unsigned long ipAddress = inet_addr(ip);                   // Convert IP address to int
    unsigned long maskAddress = inet_addr(subnetMask);          // Convert Subnet mask to int

    unsigned long networkAddress = ipAddress & maskAddress;     // Calculate the Network IP
    unsigned long invertedMask = ~maskAddress;
    unsigned long broadcastAddress = ipAddress | invertedMask;  // Calculate the broadcast IP

    // Convert the int to IP string and store it in the appropriate variable
    sprintf(networkIP, "%lu.%lu.%lu.%lu", 
        (networkAddress>>24)&0xFF, 
        (networkAddress>>16)&0xFF, 
        (networkAddress>>8)&0xFF, 
        (networkAddress)&0xFF);

    sprintf(broadcastIP, "%lu.%lu.%lu.%lu", 
        (broadcastAddress>>24)&0xFF, 
        (broadcastAddress>>16)&0xFF, 
        (broadcastAddress>>8)&0xFF, 
        (broadcastAddress)&0xFF);
}

/*
 * Calculate the number of hosts in a subnet
 */
unsigned long calcNumberOfHosts(char *subnetMask)
{
    unsigned long maskAddress = inet_addr(subnetMask);   // Convert Subnet mask to int
    unsigned long numberOfHosts = ~(maskAddress) & 0xFFFFFFFF;
    return numberOfHosts - 1;                           // Return the number of hosts (-1 is for the broadcast address)
}

/*
 * Calculate the subnet mask from CIDR notation
 */
void calcSubnetMaskFromCIDR(char *cidr, char *subnetMask)
{
    int prefixLength = atoi(cidr);
    int i = 0;
    while (prefixLength >= BITS_IN_OCTET)
    {
        subnetMask[i++] = 0xFF;     // Add 8 bits (255) in the respective octet
        prefixLength -= BITS_IN_OCTET;
    }
    if (prefixLength > 0)           // Add the remaining bits in the last octet
        subnetMask[i] = 0xFF << (BITS_IN_OCTET - prefixLength);
}

/*
 * Print the formatted output
 */
void printOutput(char *ip, char *cidr)
{
    char subnetMask[16], networkIP[16], broadcastIP[16];
    calcSubnetMaskFromCIDR(cidr, subnetMask);
    calcNetworkAndBroadcastIP(ip, subnetMask, networkIP, broadcastIP);

    printf("\nIP Address: %s",ip);
    printf("\nCIDR: %s",cidr);
    printf("\nSubnet Mask: %s",subnetMask);
    printf("\nNetwork IP: %s",networkIP);
    printf("\nBroadcast IP: %s",broadcastIP);
    printf("\nNumber of Hosts: %lu",calcNumberOfHosts(subnetMask));
}

/*
 * Driver program to test the subnet calculator
 */
int main()
{
    char ip[16], cidr[4];
    printf("Enter IP address in xxx.xxx.xxx.xxx format: ");
    scanf("%s",ip);
    printf("Enter CIDR notation (e.g. /24): ");
    scanf("%s",cidr);

    printOutput(ip, cidr);
    
    return 0;
}