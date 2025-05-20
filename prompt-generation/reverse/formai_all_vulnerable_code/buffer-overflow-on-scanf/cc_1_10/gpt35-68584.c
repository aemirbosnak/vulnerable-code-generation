//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function prototypes
int subnetMaskToCIDR(char *subnetMask);
void calculateSubnet(char *ipAddress, int cidr);

int main()
{
    char ipAddress[16];     // IPv4 address string
    char subnetMask[16];    // Subnet mask string
    int cidr;               // Subnet mask in CIDR notation

    // Input IPv4 address
    printf("Enter IPv4 address in dotted decimal notation (e.g. 192.168.1.1): ");
    scanf("%s", ipAddress);

    // Input subnet mask
    printf("Enter subnet mask in dotted decimal notation (e.g. 255.255.255.0): ");
    scanf("%s", subnetMask);

    // Convert subnet mask to CIDR notation
    cidr = subnetMaskToCIDR(subnetMask);

    // Calculate and display network address and broadcast address
    calculateSubnet(ipAddress, cidr);

    return 0;
}

// Function to convert subnet mask to CIDR notation
int subnetMaskToCIDR(char *subnetMask)
{
    int i, j, n;
    char *token;
    int octet[4];
    memset(octet, 0, sizeof(octet));

    // Split subnet mask string into octets
    i = 0;
    token = strtok(subnetMask, ".");
    while (token != NULL)
    {
        sscanf(token, "%d", &octet[i]);
        token = strtok(NULL, ".");
        i++;
    }

    // Calculate CIDR notation
    n = 0;
    for (i = 0; i < 4; i++)
    {
        for (j = 7; j >= 0; j--)
        {
            if (octet[i] & (int)pow(2, j))
            {
                n++;
            }
        }
    }

    return n;
}

// Function to calculate network address and broadcast address
void calculateSubnet(char *ipAddress, int cidr)
{
    int i, j;
    unsigned int netAddress, bcastAddress;
    unsigned char octet[4];
    memset(octet, 0, sizeof(octet));

    // Split IP address string into octets
    i = 0;
    char *token = strtok(ipAddress, ".");
    while (token != NULL)
    {
        sscanf(token, "%hhu", &octet[i]);
        token = strtok(NULL, ".");
        i++;
    }

    // Calculate network address and broadcast address
    netAddress = 0;
    bcastAddress = 0;
    for (i = 0; i < 4; i++)
    {
        for (j = 7; j >= 0; j--)
        {
            if (cidr > 0)
            {
                netAddress |= octet[i] & (int)pow(2, j);
                bcastAddress |= octet[i] & (int)pow(2, j);
                cidr--;
            }
            else
            {
                break;
            }
        }
        if (cidr == 0)
        {
            break;
        }
    }

    // Output network address and broadcast address
    printf("\nNetwork Address: %d.%d.%d.%d\n", (netAddress >> 24), ((netAddress >> 16) & 0xFF), ((netAddress >> 8) & 0xFF), (netAddress & 0xFF));
    printf("Broadcast Address: %d.%d.%d.%d\n", (bcastAddress >> 24), ((bcastAddress >> 16) & 0xFF), ((bcastAddress >> 8) & 0xFF), ((bcastAddress & 0xFF) | (int)pow(2, 32 - (i * 8) - 1) - 1));
}