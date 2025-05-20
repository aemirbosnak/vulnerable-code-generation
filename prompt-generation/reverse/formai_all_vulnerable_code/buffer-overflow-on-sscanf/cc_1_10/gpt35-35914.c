//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

// Function to convert IP address to binary
void ipToBinary(char ip[], char binary[])
{
    int a, b, c, d;
    sscanf(ip, "%d.%d.%d.%d", &a, &b, &c, &d);
    sprintf(binary, "%08d%08d%08d%08d", toBinary(a), toBinary(b), toBinary(c), toBinary(d));
}

// Function to convert decimal number to binary
int toBinary(int decimal)
{
    int binary = 0, position = 1;
    while (decimal)
    {
        binary += (decimal % 2) * position;
        decimal /= 2;
        position *= 10;
    }
    return binary;
}

int main()
{
    char ip[16], binaryIP[33];

    printf("Enter IP address: ");
    scanf("%s", ip);

    // Convert IP address to binary
    ipToBinary(ip, binaryIP);

    printf("\nIP address: %s", ip);
    printf("\nBinary IP: %s", binaryIP);

    int subnetMask;
    printf("\nEnter subnet mask (in bits): ");
    scanf("%d", &subnetMask);

    char binarySubnetMask[33];
    memset(binarySubnetMask, '0', sizeof(binarySubnetMask));

    for (int i = 0; i < 32; i++)
    {
        if (i < subnetMask)
            binarySubnetMask[i] = '1';
    }

    printf("\nBinary subnet mask: %s", binarySubnetMask);

    int subnets = toDecimal(binarySubnetMask);
    int hosts = 32 - subnetMask;

    printf("\nNumber of subnets: %d", subnets);
    printf("\nNumber of hosts: %d\n", (int)(pow(2, hosts) - 2));

    return 0;
}

// Function to convert binary to decimal number
int toDecimal(char binary[])
{
    int decimal = 0, base = 1;
    for (int i = 31; i >= 0; i--)
    {
        if (binary[i] == '1')
            decimal += base;
        base *= 2;
    }
    return decimal;
}