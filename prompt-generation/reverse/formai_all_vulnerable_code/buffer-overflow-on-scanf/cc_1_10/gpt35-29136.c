//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: grateful
#include <stdio.h>
#include <math.h>
#include <string.h>

// function to convert IP address from string to binary
void convert_to_binary(char *ip_address, int *binary_address)
{
    int i, j, n, k;
    char temp[4];
    for(i=0, j=0; ip_address[i]!='\0'; i++)
    {
        if(ip_address[i] == '.')
        {
            temp[j]='\0';
            n=atoi(temp); // convert string to integer
            j=0;
            for(k=7; k>=0; k--)
            {
                binary_address[(i/4)*8 + (7-k)] = n % 2;
                n = n / 2;
            }
        }
        else
        {
            temp[j]=ip_address[i];
            j++;
        }
    }
    temp[j]='\0';
    n=atoi(temp); // convert last string to integer
    for(k=7; k>=0; k--)
    {
        binary_address[(i/4)*8 + (7-k)] = n % 2;
        n = n / 2;
    }
}

// function to calculate subnet mask
void calculate_subnet_mask(int prefix_length, int *subnet_mask)
{
    int i;
    for(i=0; i<prefix_length; i++)
    {
        subnet_mask[i] = 1;
    }
    for(i=prefix_length; i<32; i++)
    {
        subnet_mask[i] = 0;
    }
}

// function to calculate network address
void calculate_network_address(int *binary_address, int *subnet_mask, int *network_address)
{
    int i;
    for(i=0; i<32; i++)
    {
        network_address[i] = binary_address[i] & subnet_mask[i];
    }
}

// function to convert binary address to string
void convert_to_string(int *binary_address, char *ip_address)
{
    int i, j, n, k;
    for(i=0, j=0; i<32; i=i+8, j++)
    {
        n = 0;
        for(k=0; k<8; k++)
        {
            n = n + binary_address[i+k] * pow(2, 7-k);
        }
        sprintf(ip_address + strlen(ip_address), "%d", n);
        if(j<3)
        {
            sprintf(ip_address + strlen(ip_address), ".");
        }
    }
}

int main()
{
    char ip_address[16];
    printf("Enter IP address: ");
    scanf("%s",ip_address);
    int prefix_length;
    printf("Enter prefix length: ");
    scanf("%d",&prefix_length);

    int binary_address[32];
    convert_to_binary(ip_address, binary_address);

    int subnet_mask[32];
    calculate_subnet_mask(prefix_length, subnet_mask);

    int network_address[32];
    calculate_network_address(binary_address, subnet_mask, network_address);

    char network_address_string[16];
    strcpy(network_address_string, "");
    convert_to_string(network_address, network_address_string);

    printf("Network Address: %s/%d\n", network_address_string, prefix_length);

    return 0;
}