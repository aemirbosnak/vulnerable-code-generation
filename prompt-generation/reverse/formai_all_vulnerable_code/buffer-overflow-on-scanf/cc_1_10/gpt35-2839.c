//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to calculate subnet mask given the prefix length
void calculateSubnetMask(int prefixLength, int* subnetMask) 
{
    int index = 0, i = 0;
    int byte = 0;

    // Initialize the subnet mask
    for (i = 0; i < 4; i++) 
    {
        subnetMask[i] = 0;
    }

    // Set the subnet mask bits
    while (prefixLength > 0) 
    {
        if (prefixLength >= 8) 
        {
            subnetMask[index++] = 255;
            prefixLength -= 8;
        } 
        else 
        {
            for (i = 7; i >= (8 - prefixLength); i--) 
            {
                byte += 1 << i;
            }

            subnetMask[index++] = byte;
            prefixLength = 0;
        }
    }
}

int main(int argc, char* argv[]) 
{
    char ipAddress[16];
    int prefixLength;
    int subnetMask[4];

    // Get the IP address and prefix length from user
    printf("Enter IP address in 0.0.0.0 format: ");
    scanf("%s", ipAddress);

    printf("Enter prefix length: ");
    scanf("%d", &prefixLength);

    // Calculate and display the subnet mask
    calculateSubnetMask(prefixLength, subnetMask);

    printf("\nSubnet mask: %d.%d.%d.%d\n\n", subnetMask[0], subnetMask[1], subnetMask[2], subnetMask[3]);

    return 0;
}