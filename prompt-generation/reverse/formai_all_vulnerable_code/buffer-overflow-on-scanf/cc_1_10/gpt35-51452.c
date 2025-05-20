//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to convert IP address to binary form
void convertToBinary(char *ip, char *binaryIp)
{
  int a, b, c, d;
  sscanf(ip, "%d.%d.%d.%d", &a, &b, &c, &d);
  sprintf(binaryIp, "%08d%08d%08d%08d", toBinary(a), toBinary(b), toBinary(c), toBinary(d));
}

// Function to convert decimal numbers to binary string of length 8
int toBinary(int decimal)
{
    int binary = 0, base = 1;
    while (decimal > 0)
    {
        binary += (decimal % 2) * base;
        decimal /= 2;
        base *= 10;
    }
    return binary;
}

// Function to calculate network address
void calculateNetworkAddress(char *binaryIp, int netMask, char *networkAddress)
{
    char temp[33]; 
    strncpy(temp, binaryIp, netMask); 
    temp[netMask] = '\0'; 
    sprintf(networkAddress, "%s", temp); 
}

// Function to calculate broadcast address
void calculateBroadcastAddress(char *binaryIp, int netMask, char *broadcastAddress)
{
    char temp[33]; 
    strncpy(temp, binaryIp, netMask); 
    
    for (int i = netMask; i < 32; i++)
        temp[i] = '1'; 
    
    temp[32] = '\0'; 
    sprintf(broadcastAddress, "%s", temp); 
}

// Function to calculate number of hosts
int calculateNumberOfHosts(int netMask)
{
    return pow(2, (32 - netMask)) - 2; 
}

// Main function
int main()
{
    char ipAddress[16], binaryIp[33];
    printf("Enter IP address: ");
    scanf("%s", ipAddress);

    int netMask;
    printf("Enter network mask (in bits): ");
    scanf("%d", &netMask);

    convertToBinary(ipAddress, binaryIp);
    printf("\nIP Address (binary): %s", binaryIp);

    char networkAddress[33];
    calculateNetworkAddress(binaryIp, netMask, networkAddress);
    printf("\nNetwork Address: %s", networkAddress);

    char broadcastAddress[33];
    calculateBroadcastAddress(binaryIp, netMask, broadcastAddress); 
    printf("\nBroadcast Address: %s", broadcastAddress);

    int numberOfHosts = calculateNumberOfHosts(netMask);
    printf("\nNumber of Hosts: %d", numberOfHosts);

    return 0; 
}