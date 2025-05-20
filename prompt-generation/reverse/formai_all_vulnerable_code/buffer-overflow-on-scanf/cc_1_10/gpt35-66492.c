//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert binary IP address to decimal
int binary_to_decimal(int binary)
{
    int decimal = 0, base = 1;
    while (binary > 0)
    {
        decimal += (binary % 10) * base;
        binary /= 10;
        base *= 2;
    }
    return decimal;
}

// Function to convert decimal IP address to binary
void decimal_to_binary(int decimal, char* binary)
{
    int i, j;
    for (i = 0; i < 8; i++)
    {
        binary[i] = '0';
    }
    i = 0;
    while (decimal > 0)
    {
        binary[i++] = (decimal % 2) + '0';
        decimal /= 2;
    }
    binary[i] = '\0';
    for (i = 0, j = 7; i < j; i++, j--)
    {
        char temp = binary[i];
        binary[i] = binary[j];
        binary[j] = temp;
    }
}

int main()
{
    int octet1, octet2, octet3, octet4, subnet_bits, i, j;
    char subnet_binary[32], subnet_decimal[4][4];
    printf("Enter IP address in format X.X.X.X: ");
    scanf("%d.%d.%d.%d",&octet1,&octet2,&octet3,&octet4);
    printf("Enter number of subnet bits: ");
    scanf("%d", &subnet_bits);
    if (subnet_bits > 30)
    {
        printf("Invalid number of subnet bits, maximum is 30.\n");
        return 0;
    }
    for (i = 0; i < 32; i++)
    {
        if (i < subnet_bits)
        {
            subnet_binary[i] = '1';
        }
        else
        {
            subnet_binary[i] = '0';
        }
    }
    subnet_binary[32] = '\0';
    printf("Subnet binary: %s\n", subnet_binary);
    strcpy(subnet_decimal[0], strtok(subnet_binary, " "));
    strcpy(subnet_decimal[1], strtok(NULL, " "));
    strcpy(subnet_decimal[2], strtok(NULL, " "));
    strcpy(subnet_decimal[3], strtok(NULL, " "));
    for (i = 0; i < 4; i++)
    {
        int subnet_decimal_int = binary_to_decimal(atoi(subnet_decimal[i]));
        printf("Subnet decimal %d: %d\n", i + 1, subnet_decimal_int);
        if (subnet_decimal_int > 255)
        {
            printf("Invalid subnet address.\n");
            return 0;
        }
    }
    printf("Subnet mask: %d.%d.%d.%d\n", binary_to_decimal(atoi(subnet_decimal[0])), binary_to_decimal(atoi(subnet_decimal[1])), binary_to_decimal(atoi(subnet_decimal[2])), binary_to_decimal(atoi(subnet_decimal[3])));
    int subnet_hosts = (2 << (31 - subnet_bits)) - 2;
    printf("Number of hosts per subnet: %d\n", subnet_hosts);
    char network_binary[32], network_decimal[4][4];
    decimal_to_binary(octet1, network_decimal[0]);
    decimal_to_binary(octet2, network_decimal[1]);
    decimal_to_binary(octet3, network_decimal[2]);
    decimal_to_binary(octet4, network_decimal[3]);
    strcat(network_decimal[0], network_decimal[1]);
    strcat(network_decimal[0], network_decimal[2]);
    strcat(network_decimal[0], network_decimal[3]);
    strcpy(network_binary, network_decimal[0]);
    printf("Network binary: %s\n", network_binary);
    strcpy(network_decimal[0], strtok(network_binary, "0"));
    for (i = 1; i < 4; i++)
    {
        strcpy(network_decimal[i], strtok(NULL, "0"));
    }
    for (i = 0; i < 4; i++)
    {
        int network_decimal_int = binary_to_decimal(atoi(network_decimal[i]));
        printf("Network decimal %d: %d\n", i + 1, network_decimal_int);
    }
    printf("Broadcast address: %d.%d.%d.%d\n", binary_to_decimal(atoi(network_decimal[0])) + ((subnet_hosts + 1) >> 24), binary_to_decimal(atoi(network_decimal[1])) + (((subnet_hosts + 1) << 8) >> 24), binary_to_decimal(atoi(network_decimal[2])) + (((subnet_hosts + 1) << 16) >> 24), binary_to_decimal(atoi(network_decimal[3])) + (((subnet_hosts + 1) << 24) >> 24));
    return 0;

}