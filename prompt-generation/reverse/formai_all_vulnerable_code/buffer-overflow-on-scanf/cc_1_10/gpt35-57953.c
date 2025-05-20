//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert IP address to binary
int *ipToBinary(char *ipAddr)
{
    static int binary[32];
    char *ipCopy = strdup(ipAddr);
    char *token;
    
    // Parse the IP address string to get the octets
    int i = 0;
    token = strtok(ipCopy, ".");
    while (token != NULL)
    {
        binary[i++] = atoi(token);
        token = strtok(NULL, ".");
    }
    free(ipCopy);
    
    // Convert each octet to binary and store in array
    for (int j = 0; j < 4; j++)
    {
        int octet = binary[j];
        for (int k = 7; k >= 0; k--)
        {
            binary[j*8+(7-k)] = octet & (1 << k) ? 1 : 0;
        }
    }
    return binary;
}

int main()
{
    char ipAddr[16];
    int mask;

    printf("Enter IP address (e.g. 192.168.2.1): ");
    scanf("%15s", ipAddr);
    
    printf("Enter subnet mask (e.g. 24): ");
    scanf("%d", &mask);
    
    // Convert IP address to binary
    int *ipBinary = ipToBinary(ipAddr);
    
    // Create the subnet mask
    int maskBinary[32];
    for (int i = 0; i < 32; i++)
    {
        maskBinary[i] = i < mask ? 1 : 0;
    }
    
    // Apply subnet mask to IP address
    int subnet[32];
    for (int i = 0; i < 32; i++)
    {
        subnet[i] = ipBinary[i] & maskBinary[i];
    }
    
    // Convert subnet address back to IP format
    int subnetOctets[4];
    for (int i = 0; i < 4; i++)
    {
        int octet = 0;
        for (int j = 0; j < 8; j++)
        {
            octet += subnet[i*8+j] * (1 << (7-j));
        }
        subnetOctets[i] = octet;
    }
    
    // Print subnet address and mask
    printf("\nSubnet Address: %d.%d.%d.%d\n", subnetOctets[0], subnetOctets[1], subnetOctets[2], subnetOctets[3]);
    printf("Subnet Mask: %d.%d.%d.%d\n", maskBinary[0]*255+maskBinary[1]*128+maskBinary[2]*64+maskBinary[3]*32+maskBinary[4]*16+maskBinary[5]*8+maskBinary[6]*4+maskBinary[7]*2+maskBinary[8]*1,
                                         maskBinary[9]*255+maskBinary[10]*128+maskBinary[11]*64+maskBinary[12]*32+maskBinary[13]*16+maskBinary[14]*8+maskBinary[15]*4+maskBinary[16]*2+maskBinary[17]*1,
                                         maskBinary[18]*255+maskBinary[19]*128+maskBinary[20]*64+maskBinary[21]*32+maskBinary[22]*16+maskBinary[23]*8+maskBinary[24]*4+maskBinary[25]*2+maskBinary[26]*1,
                                         maskBinary[27]*255+maskBinary[28]*128+maskBinary[29]*64+maskBinary[30]*32+maskBinary[31]*16);
    
    return 0;
}