//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: imaginative
#include <stdio.h>
#include <math.h>

// Function to convert decimal to binary
void decimalToBinary(int decimal, int binary[])
{
    int i = 0;
    while (decimal > 0)
    {
        binary[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
    }
}

// Function to convert binary to decimal
int binaryToDecimal(int binary[])
{
    int decimal = 0;
    for (int i = 0; i < 8; i++)
    {
        decimal += binary[i] * pow(2, i);
    }
    return decimal;
}

int main()
{
    int ip[4], subnetMask;
    int binaryIp[4][8];
    int defaultBinarySubnetMask[32] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int binarySubnetMask[32];
    int hostBits, numberOfAddresses, usableAddresses;
    int binaryNetworkAddress[4][8], binaryBroadcastAddress[4][8];
    int networkAddress[4], broadcastAddress[4];

    // Get the IP address from the user
    printf("Enter the IP address (format: x.x.x.x): ");
    scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);

    // Ensure that the IP address is valid
    for (int i = 0; i < 4; i++)
    {
        if (ip[i] < 0 || ip[i] > 255)
        {
            printf("Invalid IP address\n");
            return 0;
        }
    }

    // Get the subnet mask from the user
    printf("Enter the subnet mask (in bits): ");
    scanf("%d", &subnetMask);

    // Ensure that the subnet mask is valid
    if (subnetMask < 1 || subnetMask > 30)
    {
        printf("Invalid subnet mask\n");
        return 0;
    }

    // Calculate the number of host bits
    hostBits = 32 - subnetMask;

    // Calculate the number of addresses
    numberOfAddresses = pow(2, hostBits);

    // Calculate the usable addresses
    usableAddresses = numberOfAddresses - 2;

    // Convert the IP address from decimal to binary
    for (int i = 0; i < 4; i++)
    {
        decimalToBinary(ip[i], binaryIp[i]);
    }

    // Convert the default subnet mask from binary to decimal
    for (int i = 0; i < 32; i++)
    {
        binarySubnetMask[i] = defaultBinarySubnetMask[i];
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            binarySubnetMask[i * 8 + j] *= pow(2, 7 - j);
        }
        int decimalPart = binaryToDecimal(binarySubnetMask + i * 8);
        networkAddress[i] = ip[i] & decimalPart;
    }

    // Calculate the binary network address
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            binaryNetworkAddress[i][j] = binaryIp[i][j] & binarySubnetMask[i * 8 + j];
        }
    }

    // Calculate the binary broadcast address
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            binaryBroadcastAddress[i][j] = binaryIp[i][j] | (binarySubnetMask[i * 8 + j] ^ 1);
        }
    }

    // Convert the binary network address and binary broadcast address to decimal
    for (int i = 0; i < 4; i++)
    {
        networkAddress[i] = binaryToDecimal(binaryNetworkAddress[i]);
        broadcastAddress[i] = binaryToDecimal(binaryBroadcastAddress[i]);
    }

    // Print the results
    printf("IP address: %d.%d.%d.%d\n", ip[0], ip[1], ip[2], ip[3]);
    printf("Subnet mask: ");
    for (int i = 0; i < 32; i++)
    {
        if (i % 8 == 0 && i > 0)
        {
            printf(".");
        }
        printf("%d", binarySubnetMask[i]);
    }
    printf("\n");
    printf("Host bits: %d\n", hostBits);
    printf("Number of addresses: %d\n", numberOfAddresses);
    printf("Usable addresses: %d\n", usableAddresses);
    printf("Network address: %d.%d.%d.%d\n", networkAddress[0], networkAddress[1], networkAddress[2], networkAddress[3]);
    printf("Broadcast address: %d.%d.%d.%d\n", broadcastAddress[0], broadcastAddress[1], broadcastAddress[2], broadcastAddress[3]);

    return 0;
}