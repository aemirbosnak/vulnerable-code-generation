//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function prototype declarations
int checkValidSubnet(int subnet[]);
void convertBinary(int num, int binary[]);
void printBinary(int binary[]);
void printSubnet(int subnet[]);
int calculateSubnetMask(int subnet[]);
void calculateSubnet(int subnet[], int subnetMask, int networkAddress[], int broadcastAddress[]);

// Main function
int main()
{
    int subnet[4] = {0}; // Array to hold the inputted subnet values
    int subnetMask; // Variable to hold the calculated subnet mask value
    int networkAddress[4] = {0}; // Array to hold the calculated network address
    int broadcastAddress[4] = {0}; // Array to hold the calculated broadcast address

    printf("Enter the subnet address in decimal format: ");
    scanf("%d.%d.%d.%d", &subnet[0], &subnet[1], &subnet[2], &subnet[3]);

    // Check if the inputted subnet is valid
    if (checkValidSubnet(subnet) == 0)
    {
        printf("Invalid subnet address entered.\n");
        return 0;
    }

    // Calculate the subnet mask value
    subnetMask = calculateSubnetMask(subnet);

    // Calculate the network and broadcast addresses
    calculateSubnet(subnet, subnetMask, networkAddress, broadcastAddress);

    // Print out the subnet information
    printf("\nInputted Subnet Address: ");
    printSubnet(subnet);
    printf("Calculated Subnet Mask: %d\n", subnetMask);
    printf("Calculated Network Address: ");
    printSubnet(networkAddress);
    printf("Calculated Broadcast Address: ");
    printSubnet(broadcastAddress);

    return 0;
}

/**
 * Function to check if the inputted subnet address is valid 
 * (between 0 and 255, inclusive)
 **/
int checkValidSubnet(int subnet[])
{
    int i;

    for (i = 0; i < 4; i++)
    {
        if (subnet[i] < 0 || subnet[i] > 255)
        {
            return 0;
        }
    }

    return 1;
}

/**
 * Function to convert a decimal number to a binary array
 **/
void convertBinary(int num, int binary[])
{
    int i;

    for (i = 7; i >= 0; i--)
    {
        binary[i] = num % 2;
        num = num / 2;
    }
}

/**
 * Function to print out a binary array (for testing purposes)
 **/
void printBinary(int binary[])
{
    int i;

    for (i = 0; i < 8; i++)
    {
        printf("%d ", binary[i]);
    }
    printf("\n");
}

/**
 * Function to print out a subnet array
 **/
void printSubnet(int subnet[])
{
    printf("%d.%d.%d.%d\n", subnet[0], subnet[1], subnet[2], subnet[3]);
}

/**
 * Function to calculate the subnet mask value
 **/
int calculateSubnetMask(int subnet[])
{
    int binarySubnet[32] = {0}; // Array to hold the binary representation of the subnet address
    int i, j, k = 0;
    int subnetMask = 0; // Variable to hold the calculated subnet mask value

    // Convert each subnet address to its binary representation
    for (i = 0; i < 4; i++)
    {
        int binary[8] = {0};
        convertBinary(subnet[i], binary);
        for (j = 0; j < 8; j++)
        {
            binarySubnet[k] = binary[j];
            k++;
        }
    }

    // Count the number of 1s in the binary subnet array
    for (i = 0; i < 32; i++)
    {
        if (binarySubnet[i] == 1)
        {
            subnetMask++;
        }
    }

    return subnetMask;
}

/**
 * Function to calculate the network and broadcast addresses
 **/
void calculateSubnet(int subnet[], int subnetMask, int networkAddress[], int broadcastAddress[])
{   
    int binarySubnet[32] = {0}; // Array to hold the binary representation of the subnet address
    int binaryNetwork[32] = {0}; // Array to hold the binary representation of the network address
    int binaryBroadcast[32] = {0}; // Array to hold the binary representation of the broadcast address
    int i, j, k = 0;
    int subnetBits = 32 - subnetMask; // Calculate the number of bits that represent the host address
    int numberOfHosts = pow(2, subnetBits) - 2; // Calculate the number of hosts in the subnet

    // Convert each subnet address to its binary representation
    for (i = 0; i < 4; i++)
    {
        int binary[8] = {0};
        convertBinary(subnet[i], binary);
        for (j = 0; j < 8; j++)
        {
            binarySubnet[k] = binary[j];
            k++;
        }
    }

    // Calculate the binary representation of the network address
    for (i = 0; i < 32; i++)
    {
        if (i < subnetMask)
        {
            binaryNetwork[i] = binarySubnet[i];
        }
        else
        {
            binaryNetwork[i] = 0;
        }
    }

    k = 0;
    // Calculate the decimal representation of the network address
    for (i = 0; i < 4; i++)
    {
        int decimal = 0;
        for (j = 7; j >= 0; j--)
        {
            decimal += binaryNetwork[k] * pow(2, j);
            k++;
        }
        networkAddress[i] = decimal;
    }

    k = 0;
    // Calculate the binary representation of the broadcast address
    for (i = 0; i < 32; i++)
    {
        if (i < subnetMask)
        {
            binaryBroadcast[i] = binarySubnet[i];
        }
        else if (i == subnetMask)
        {
            binaryBroadcast[i] = 1;
        }
        else
        {
            binaryBroadcast[i] = 0;
        }
    }

    k = 0;
    // Calculate the decimal representation of the broadcast address
    for (i = 0; i < 4; i++)
    {
        int decimal = 0;
        for (j = 7; j >= 0; j--)
        {
            decimal += binaryBroadcast[k] * pow(2, j);
            k++;
        }
        broadcastAddress[i] = decimal;
    }
}