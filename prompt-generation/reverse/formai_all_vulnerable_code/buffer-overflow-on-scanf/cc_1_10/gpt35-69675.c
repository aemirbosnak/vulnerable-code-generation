//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if entered IP address is valid
int isValidIPAddress(char *ipAddress)
{
    int num, dots = 0;
    char *ptr;
    // Invalid if empty string or NULL value
    if (ipAddress == NULL || strlen(ipAddress) == 0)
    {
        return 0;
    }
    // If IP address has alphanumeric characters
    for (int i = 0; ipAddress[i] != '\0'; i++)
    {
        if (isalpha(ipAddress[i]))
        {
            return 0;
        }
    }
    // Check each IP segment
    ptr = strtok(ipAddress, ".");
    if (ptr == NULL)
    {
        return 0;
    }
    while (ptr)
    {
        // Convert each segment to integer
        num = atoi(ptr);
        if (num >= 0 && num <= 255)
        {
            ptr = strtok(NULL, ".");
            if (ptr != NULL)
            {
                dots++;
            }
        }
        else
        {
            return 0;
        }
    }
    // There should be only 3 dots and 4 segments
    if (dots == 3)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Function to calculate the subnet mask based on the subnet mask bits
char *calculateSubnetMask(int bits)
{
    // Allocate memory for the subnet mask
    char *subnetMask = malloc(16);
    int bitmask = 0;
    // Calculate the bitmask based on the number of bits
    for (int i = 0; i < bits; i++)
    {
        bitmask |= (1 << 31 - i);
    }
    // Format the subnet mask to be displayed
    sprintf(subnetMask, "%d.%d.%d.%d", bitmask >> 24 & 255, bitmask >> 16 & 255, bitmask >> 8 & 255, bitmask & 255);
    return subnetMask;
}

// Main function
int main()
{
    int subnetBits;
    char ipAddress[16];
    // Get the IP address from the user
    printf("Enter the IP address: ");
    scanf("%s", ipAddress);
    // Validate the IP address
    if (!isValidIPAddress(ipAddress))
    {
        printf("Invalid IP address.\n");
        return 0;
    }
    // Get the number of subnet bits from the user
    printf("Enter the number of subnet bits: ");
    scanf("%d", &subnetBits);
    // Display the subnet mask
    printf("The subnet mask for %s/%d is %s.\n", ipAddress, subnetBits, calculateSubnetMask(subnetBits));
    return 0;
}