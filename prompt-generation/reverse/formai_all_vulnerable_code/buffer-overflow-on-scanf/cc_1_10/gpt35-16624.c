//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: complex
#include <stdio.h>
#include <stdlib.h>

// function to convert decimal to binary
void decimalToBinary(int n, int binary[])
{
    // storing the binary number in an array
    for(int i = 0; i < 8; i++)
    {
        binary[i] = n % 2;
        n = n / 2;
    }
}

// function to calculate subnet mask and range
void calculateSubnet(int prefix, char subnet[], char min_range[], char max_range[])
{
    int subnet_octet1 = 0, subnet_octet2 = 0, subnet_octet3 = 0, subnet_octet4 = 0;
    int i;

    // calculating subnet mask
    for(i = 0; i < prefix; i++)
    {
        if(i < 8)
            subnet_octet1 += 1 << (7 - i);
        else if(i < 16)
            subnet_octet2 += 1 << (7 - i % 8);
        else if(i < 24)
            subnet_octet3 += 1 << (7 - i % 8);
        else
            subnet_octet4 += 1 << (7 - i % 8);
    }

    // converting binary to decimal and storing in subnet array
    sprintf(subnet, "%d.%d.%d.%d", subnet_octet1, subnet_octet2, subnet_octet3, subnet_octet4);

    // calculating minimum range
    sprintf(min_range, "%d.%d.%d.%d", subnet_octet1, subnet_octet2, subnet_octet3, subnet_octet4 + 1);

    // calculating maximum range
    int host_bits = 32 - prefix;
    int max_range_octet4 = subnet_octet4 + (1 << host_bits) - 2;
    if(max_range_octet4 > 255)
        max_range_octet4 = 255;
    sprintf(max_range, "%d.%d.%d.%d", subnet_octet1, subnet_octet2, subnet_octet3, max_range_octet4);
}

int main()
{
    int ip[4];
    char subnet[16], min_range[16], max_range[16];
    int prefix, subnet_binary[8], min_range_binary[8], max_range_binary[8];

    printf("Enter IP address (format: X.X.X.X): ");
    scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);

    printf("Enter prefix: ");
    scanf("%d", &prefix);

    decimalToBinary(ip[0], subnet_binary);
    decimalToBinary(ip[1], subnet_binary + 8);
    decimalToBinary(ip[2], subnet_binary + 16);
    decimalToBinary(ip[3], subnet_binary + 24);

    calculateSubnet(prefix, subnet, min_range, max_range);

    decimalToBinary(subnet[0], min_range_binary);
    decimalToBinary(subnet[1], min_range_binary + 8);
    decimalToBinary(subnet[2], min_range_binary + 16);
    decimalToBinary(subnet[3], min_range_binary + 24);

    decimalToBinary(max_range[0], max_range_binary);
    decimalToBinary(max_range[1], max_range_binary + 8);
    decimalToBinary(max_range[2], max_range_binary + 16);
    decimalToBinary(max_range[3], max_range_binary + 24);

    printf("\nSubnet mask: %s\n", subnet);
    printf("Minimum range: %s\n", min_range);
    printf("Maximum range: %s\n\n", max_range);

    printf("Subnet mask binary: ");
    for(int i = 0; i < 32; i++)
    {
        if(i == 8 || i == 16 || i == 24)
            printf(".");
        printf("%d", subnet_binary[31 - i]);
    }

    printf("\nMinimum range binary: ");
    for(int i = 0; i < 32; i++)
    {
        if(i == 8 || i == 16 || i == 24)
            printf(".");
        printf("%d", min_range_binary[31 - i]);
    }

    printf("\nMaximum range binary: ");
    for(int i = 0; i < 32; i++)
    {
        if(i == 8 || i == 16 || i == 24)
            printf(".");
        printf("%d", max_range_binary[31 - i]);
    }

    return 0;
}