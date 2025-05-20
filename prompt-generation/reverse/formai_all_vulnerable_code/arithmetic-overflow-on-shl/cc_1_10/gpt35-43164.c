//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: rigorous
#include <stdio.h>
#include <stdint.h>

// Function to convert binary to decimal
uint32_t binaryToDecimal(uint32_t binary)
{
    uint32_t decimal = 0, reminder = 0, power = 1;
    while (binary != 0)
    {
        reminder = binary % 10;
        decimal += reminder * power;
        power *= 2;
        binary /= 10;
    }
    return decimal;
}

// Function to convert decimal to binary
uint32_t decimalToBinary(uint32_t decimal)
{
    uint32_t binary = 0, reminder = 0, i = 1;
    while (decimal != 0)
    {
         reminder = decimal % 2;
         decimal /= 2;
         binary += reminder * i;
         i *= 10;
    }
    return binary;
}

// Function to calculate subnet masks
void subnetMask(int prefix, uint32_t *subnetMaskBinary, uint32_t *subnetMaskDecimal)
{
    for (int i = 0; i < 32; i++)
    {
        if (i < prefix)
        {
            *subnetMaskBinary |= 1 << (31 - i);
        }
        else
        {
            *subnetMaskBinary &= ~(1 << (31 - i));
        }
    }
    *subnetMaskDecimal = binaryToDecimal(*subnetMaskBinary);
}

// Function to calculate network address
void networkAddress(uint32_t ipAddressBinary, uint32_t subnetMaskBinary, uint32_t *networkAddressBinary, uint32_t *networkAddressDecimal)
{
    *networkAddressBinary = ipAddressBinary & subnetMaskBinary;
    *networkAddressDecimal = binaryToDecimal(*networkAddressBinary);
}

int main()
{
    uint32_t ipAddressDecimal, ipAddressBinary, subnetMaskDecimal, subnetMaskBinary = 0, networkAddressDecimal, networkAddressBinary;
    int prefix;

    printf("Enter the IP address: ");
    scanf("%u", &ipAddressDecimal);
    ipAddressBinary = decimalToBinary(ipAddressDecimal);

    printf("Enter the prefix: ");
    scanf("%d", &prefix);

    subnetMask(prefix, &subnetMaskBinary, &subnetMaskDecimal);
    networkAddress(ipAddressBinary, subnetMaskBinary, &networkAddressBinary, &networkAddressDecimal);

    printf("The network address is: %u\n", networkAddressDecimal);
    printf("The subnet mask is: %u\n", subnetMaskDecimal);

    return 0;
}