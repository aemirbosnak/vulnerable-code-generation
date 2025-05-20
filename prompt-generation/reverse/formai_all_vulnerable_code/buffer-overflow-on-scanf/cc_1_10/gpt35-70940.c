//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal to binary
void decimalToBinary(int decimal, char *binary)
{
    int i = 0;
    while (decimal > 0)
    {
        binary[i++] = decimal % 2 + '0';
        decimal /= 2;
    }
    // Fill the rest with zeros
    while (i < 8)
    {
        binary[i++] = '0';
    }
    // Reverse the binary string
    int left = 0, right = i - 1;
    while (left < right)
    {
        char temp = binary[left];
        binary[left++] = binary[right];
        binary[right--] = temp;
    }
    binary[i] = '\0';
}

int main()
{
    // Get the IP address and subnet mask from user
    char ipAddress[20], subnetMask[20];
    printf("Enter IP Address: ");
    scanf("%s", ipAddress);
    printf("Enter Subnet Mask: ");
    scanf("%s", subnetMask);

    // Convert IP Address and Subnet Mask to decimal values
    int ipDecimal[4], subnetDecimal[4];
    sscanf(ipAddress, "%d.%d.%d.%d", &ipDecimal[0], &ipDecimal[1], &ipDecimal[2], &ipDecimal[3]);
    sscanf(subnetMask, "%d.%d.%d.%d", &subnetDecimal[0], &subnetDecimal[1], &subnetDecimal[2], &subnetDecimal[3]);

    // Convert IP Address and Subnet Mask to binary strings
    char ipBinary[32], subnetBinary[32];
    for (int i = 0; i < 4; i++)
    {
        decimalToBinary(ipDecimal[i], &ipBinary[i * 8]);
        decimalToBinary(subnetDecimal[i], &subnetBinary[i * 8]);
    }

    // Calculate Network Address and Broadcast Address
    char network[20], broadcast[20];
    for (int i = 0; i < 32; i++)
    {
        network[i] = ipBinary[i] & subnetBinary[i];
        broadcast[i] = ipBinary[i] | ~subnetBinary[i];
    }

    // Convert Network Address and Broadcast Address to decimal values
    int networkDecimal[4], broadcastDecimal[4];
    for (int i = 0; i < 4; i++)
    {
        networkDecimal[i] = strtol(&network[i * 8], NULL, 2);
        broadcastDecimal[i] = strtol(&broadcast[i * 8], NULL, 2);
    }

    // Print the results
    printf("\nIP Address: %s\n", ipAddress);
    printf("Subnet Mask: %s\n", subnetMask);
    printf("Network Address: %d.%d.%d.%d\n", networkDecimal[0], networkDecimal[1], networkDecimal[2], networkDecimal[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n", broadcastDecimal[0], broadcastDecimal[1], broadcastDecimal[2], broadcastDecimal[3]);

    return 0;
}