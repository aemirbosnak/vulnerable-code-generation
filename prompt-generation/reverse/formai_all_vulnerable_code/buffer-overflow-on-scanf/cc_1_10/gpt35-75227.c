//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function Declarations
long ip_to_int(char *address);
void int_to_ip(long int number, char *address);
int count_bits(long int number);
long int bits_to_mask(int bits);
long int address_to_network(long int ip_address, long int subnet_mask);
long int address_to_broadcast(long int ip_address, long int subnet_mask);

int main()
{
    char ip_address[20];
    char subnet_mask[20];
    long int ip_int = 0;
    long int mask_int = 0;
    long int network_address = 0;
    long int broadcast_address = 0;
    int bits = 0;

    printf("Subnet Calculator v1.0\n");
    printf("----------------------\n");

    // Prompt user for IP address
    printf("\nEnter IP address: ");
    scanf("%s", ip_address);
    ip_int = ip_to_int(ip_address);

    // Prompt user for subnet mask
    printf("Enter Subnet Mask: ");
    scanf("%s", subnet_mask);
    mask_int = ip_to_int(subnet_mask);

    // Calculate network address and broadcast address
    network_address = address_to_network(ip_int, mask_int);
    broadcast_address = address_to_broadcast(ip_int, mask_int);

    // Calculate number of bits in subnet mask
    bits = count_bits(mask_int);

    // Display results
    printf("\nNetwork Address: ");
    int_to_ip(network_address, ip_address);
    printf("%s\n", ip_address);

    printf("Broadcast Address: ");
    int_to_ip(broadcast_address, ip_address);
    printf("%s\n", ip_address);

    printf("Subnet Mask: ");
    int_to_ip(mask_int, subnet_mask);
    printf("%s\n", subnet_mask);

    printf("Number of Bits: %d\n", bits);

    return 0;
}

// Function to convert IP address from string to integer
long ip_to_int(char *address)
{
    int i;
    long int number = 0, octet = 0;

    for (i = 0; i < strlen(address); i++)
    {
        if (address[i] == '.')
        {
            number = (number * 256) + octet;
            octet = 0;
        }
        else
        {
            octet = (octet * 10) + (address[i] - '0');
        }
    }

    number = (number * 256) + octet;
    return number;
}

// Function to convert integer to IP address
void int_to_ip(long int number, char *address)
{
    int i;
    long int octet = 0;

    for (i = 3; i >= 0; i--)
    {
        octet = (long int)(number / pow(256, i));
        number = number - (octet * pow(256, i));
        sprintf(address, "%s%d", address, (int)octet);

        if (i != 0)
            sprintf(address, "%s.", address);
    }
}

// Function to count number of bits in subnet mask
int count_bits(long int number)
{
    int count = 0;
    while(number)
    {
        count += number & 1;
        number >>= 1;
    }

    return count;
}

// Function to convert number of bits to subnet mask integer
long int bits_to_mask(int bits)
{
    long int mask = 0;
    int i;

    for (i = 0; i < bits; i++)
        mask = (mask << 1) + 1;

    for (; i < 32; i++)
        mask = mask << 1;

    return mask;
}

// Function to calculate network address from IP address and subnet mask
long int address_to_network(long int ip_address, long int subnet_mask)
{
    long int network_address = 0;
    network_address = ip_address & subnet_mask;
    return network_address;
}

// Function to calculate broadcast address from IP address and subnet mask
long int address_to_broadcast(long int ip_address, long int subnet_mask)
{
    long int broadcast_address = 0;
    broadcast_address = ip_address | (~subnet_mask);
    return broadcast_address;
}