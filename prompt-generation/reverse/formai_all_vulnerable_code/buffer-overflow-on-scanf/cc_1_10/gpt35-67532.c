//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_IP_ADDRESS_LENGTH 15
#define MAX_SUBNET_MASK_LENGTH 3

int is_valid_ip_address(char *ip_address);
int is_valid_subnet_mask(char *subnet_mask);
unsigned char* get_binary_ip_address(char *ip_address);
unsigned char* get_binary_subnet_mask(char *subnet_mask);
unsigned char* get_network_address(unsigned char *binary_ip_address, unsigned char *binary_subnet_mask);
unsigned char* get_broadcast_address(unsigned char *binary_ip_address, unsigned char *binary_subnet_mask);
unsigned int get_number_of_hosts(unsigned char *binary_subnet_mask);

int main(void)
{
    char ip_address[MAX_IP_ADDRESS_LENGTH + 1];
    char subnet_mask[MAX_SUBNET_MASK_LENGTH + 1];
    unsigned char *binary_ip_address;
    unsigned char *binary_subnet_mask;
    unsigned char *network_address;
    unsigned char *broadcast_address;
    unsigned int number_of_hosts;

    printf("Enter IP address: ");
    scanf("%s", ip_address);

    if(!is_valid_ip_address(ip_address))
    {
        printf("Invalid IP address!\n");
        exit(1);
    }

    printf("Enter subnet mask: ");
    scanf("%s", subnet_mask);

    if(!is_valid_subnet_mask(subnet_mask))
    {
        printf("Invalid subnet mask!\n");
        exit(1);
    }

    binary_ip_address = get_binary_ip_address(ip_address);
    binary_subnet_mask = get_binary_subnet_mask(subnet_mask);

    network_address = get_network_address(binary_ip_address, binary_subnet_mask);
    broadcast_address = get_broadcast_address(binary_ip_address, binary_subnet_mask);
    number_of_hosts = get_number_of_hosts(binary_subnet_mask);

    printf("Network address: %d.%d.%d.%d\n", network_address[0], network_address[1], network_address[2], network_address[3]);
    printf("Broadcast address: %d.%d.%d.%d\n", broadcast_address[0], broadcast_address[1], broadcast_address[2], broadcast_address[3]);
    printf("Number of hosts: %u\n", number_of_hosts);

    free(binary_ip_address);
    free(binary_subnet_mask);
    free(network_address);
    free(broadcast_address);

    return 0;
}

int is_valid_ip_address(char *ip_address)
{
    int quads[4];
    int i, j, num_chars;

    num_chars = strlen(ip_address);

    if(num_chars > MAX_IP_ADDRESS_LENGTH)
    {
        return 0;
    }

    j = 0;

    for(i = 0; i < num_chars; i++)
    {
        if(ip_address[i] == '.')
        {
            if(j >= 3)
            {
                return 0;
            }

            j++;

            continue;
        }

        if(!isdigit(ip_address[i]))
        {
            return 0;
        }
    }

    if(j != 3)
    {
        return 0;
    }

    j = 0;
    quads[0] = quads[1] = quads[2] = quads[3] = 0;

    for(i = 0; i < num_chars; i++)
    {
        if(ip_address[i] == '.')
        {
            j++;
            continue;
        }

        quads[j] *= 10;
        quads[j] += ip_address[i] - '0';

        if(quads[j] > 255)
        {
            return 0;
        }
    }

    if(quads[0] == 0)
    {
        return 0;
    }

    return 1;
}

int is_valid_subnet_mask(char *subnet_mask)
{
    int quads[4];
    int i, j, num_chars;
    unsigned int mask_value;
    unsigned char *binary_subnet_mask;

    num_chars = strlen(subnet_mask);

    if(num_chars > MAX_SUBNET_MASK_LENGTH)
    {
        return 0;
    }

    j = 0;

    for(i = 0; i < num_chars; i++)
    {
        if(subnet_mask[i] == '.')
        {
            if(j >= 3)
            {
                return 0;
            }

            j++;

            continue;
        }

        if(!isdigit(subnet_mask[i]))
        {
            return 0;
        }
    }

    if(j != 3)
    {
        return 0;
    }

    j = 0;
    quads[0] = quads[1] = quads[2] = quads[3] = 0;
    binary_subnet_mask = get_binary_subnet_mask(subnet_mask);
    mask_value = ((unsigned int)binary_subnet_mask[0] << 24) | ((unsigned int)binary_subnet_mask[1] << 16) | ((unsigned int)binary_subnet_mask[2] << 8) | (unsigned int)binary_subnet_mask[3];

    if(mask_value == 0 || mask_value % 2 == 1)
    {
        return 0;
    }

    while(mask_value)
    {
        if(mask_value & 1)
        {
            mask_value >>= 1;
        }
        else
        {
            break;
        }
    }

    if(mask_value)
    {
        return 0;
    }

    return 1;
}

unsigned char* get_binary_ip_address(char *ip_address)
{
    int quads[4];
    int i, j, num_chars;
    unsigned char *binary_ip_address;

    binary_ip_address = (unsigned char*)malloc(4);

    num_chars = strlen(ip_address);
    j = 0;
    quads[0] = quads[1] = quads[2] = quads[3] = 0;

    for(i = 0; i < num_chars; i++)
    {
        if(ip_address[i] == '.')
        {
            j++;
            continue;
        }

        quads[j] *= 10;
        quads[j] += ip_address[i] - '0';
    }

    binary_ip_address[0] = (unsigned char)quads[0];
    binary_ip_address[1] = (unsigned char)quads[1];
    binary_ip_address[2] = (unsigned char)quads[2];
    binary_ip_address[3] = (unsigned char)quads[3];

    return binary_ip_address;
}

unsigned char* get_binary_subnet_mask(char *subnet_mask)
{
    int quads[4];
    int i, j, num_chars;
    unsigned char *binary_subnet_mask;

    binary_subnet_mask = (unsigned char*)malloc(4);

    num_chars = strlen(subnet_mask);
    j = 0;
    quads[0] = quads[1] = quads[2] = quads[3] = 0;

    for(i = 0; i < num_chars; i++)
    {
        if(subnet_mask[i] == '.')
        {
            j++;
            continue;
        }

        quads[j] *= 10;
        quads[j] += subnet_mask[i] - '0';
    }

    binary_subnet_mask[0] = (unsigned char)quads[0];
    binary_subnet_mask[1] = (unsigned char)quads[1];
    binary_subnet_mask[2] = (unsigned char)quads[2];
    binary_subnet_mask[3] = (unsigned char)quads[3];

    return binary_subnet_mask;
}

unsigned char* get_network_address(unsigned char *binary_ip_address, unsigned char *binary_subnet_mask)
{
    int i;
    unsigned char *network_address;

    network_address = (unsigned char*)malloc(4);

    for(i = 0; i < 4; i++)
    {
        network_address[i] = binary_ip_address[i] & binary_subnet_mask[i];
    }

    return network_address;
}

unsigned char* get_broadcast_address(unsigned char *binary_ip_address, unsigned char *binary_subnet_mask)
{
    int i;
    unsigned char *broadcast_address;

    broadcast_address = (unsigned char*)malloc(4);

    for(i = 0; i < 4; i++)
    {
        broadcast_address[i] = binary_ip_address[i] | ~binary_subnet_mask[i];
    }

    return broadcast_address;
}

unsigned int get_number_of_hosts(unsigned char *binary_subnet_mask)
{
    unsigned int mask_value;
    unsigned int number_of_hosts;

    mask_value = ((unsigned int)binary_subnet_mask[0] << 24) | ((unsigned int)binary_subnet_mask[1] << 16) | ((unsigned int)binary_subnet_mask[2] << 8) | (unsigned int)binary_subnet_mask[3];
    number_of_hosts = ~mask_value - 1;

    return number_of_hosts;
}