//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MAX_IP_ADDRESS_LENGTH 16

bool validate_num_of_bits(int bits);
bool validate_ip_address_format(char *ip_address);
int calculate_subnet_mask(int num_of_bits);
void print_subnet_details(char *ip_address, int num_of_bits);

int main()
{
    char ip_address[MAX_IP_ADDRESS_LENGTH];
    int num_of_bits;

    printf("Enter IP address: ");
    scanf("%s", ip_address);

    printf("Enter number of bits for Subnet Mask: ");
    scanf("%d", &num_of_bits);

    if (!validate_ip_address_format(ip_address))
    {
        printf("Invalid IP address format!\n");
        return 1;
    }

    if (!validate_num_of_bits(num_of_bits))
    {
        printf("Invalid number of bits!\n");
        return 1;
    }

    int subnet_mask = calculate_subnet_mask(num_of_bits);

    printf("\n");
    print_subnet_details(ip_address, num_of_bits);
    printf("Subnet Mask: %d.%d.%d.%d\n",
           (subnet_mask >> 24) & 0xFF,
           (subnet_mask >> 16) & 0xFF,
           (subnet_mask >> 8) & 0xFF,
           subnet_mask & 0xFF);

    return 0;
}

bool validate_num_of_bits(int bits)
{
    if (bits < 0 || bits > 32)
    {
        return false;
    }
    return true;
}

bool validate_ip_address_format(char *ip_address)
{
    int num_of_segments = 0;

    for (int i = 0; i < strlen(ip_address); i++)
    {
        if (ip_address[i] == '.')
        {
            num_of_segments++;
        }
    }

    if (num_of_segments != 3)
    {
        return false;
    }

    char *segment = strtok(ip_address, ".");
    while (segment != NULL)
    {
        int num = atoi(segment);
        if (num < 0 || num > 255)
        {
            return false;
        }
        segment = strtok(NULL, ".");
    }

    return true;
}

int calculate_subnet_mask(int num_of_bits)
{
    int subnet_mask = 0xFFFFFFFF << (32 - num_of_bits);
    return subnet_mask;
}

void print_subnet_details(char *ip_address, int num_of_bits)
{
    printf("IP Address: %s\n", ip_address);
    printf("Number of bits for Subnet Mask: %d\n", num_of_bits);

    int num_of_segments = 0;
    char *segment = strtok(ip_address, ".");
    while (segment != NULL)
    {
        printf("Segment %d: %s\n", num_of_segments + 1, segment);
        num_of_segments++;
        segment = strtok(NULL, ".");
    }

    int num_of_hosts = pow(2, 32 - num_of_bits) - 2;
    printf("Number of hosts per subnet: %d\n", num_of_hosts);
}