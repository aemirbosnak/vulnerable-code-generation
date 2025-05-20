//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: active
// C Subnet Calculator
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Function to calculate network and broadcast IDs
void calc_net_bcast(int IP[], int subnet_mask[], int *network_id, int *broadcast_id)
{
    int subnet_bits = 0, i = 0;

    // Calculate number of subnet bits
    for(i = 0; i < 4; i++)
    {
        int octet = subnet_mask[i];
        if(octet == 0)
            subnet_bits += 0;
        else
        {
            switch(octet)
            {
                case 128: subnet_bits += 1; break;
                case 192: subnet_bits += 2; break;
                case 224: subnet_bits += 3; break;
                case 240: subnet_bits += 4; break;
                case 248: subnet_bits += 5; break;
                case 252: subnet_bits += 6; break;
                case 254: subnet_bits += 7; break;
                case 255: subnet_bits += 8; break;
            }
        }
    }

    // Calculate network ID
    for(i = 0; i < 4; i++)
    {
        network_id[i] = IP[i] & subnet_mask[i];
    }

    // Calculate broadcast ID
    for(i = 0; i < 4; i++)
    {
        if(subnet_bits <= 0)
            broadcast_id[i] = network_id[i] | 255;
        else if(subnet_bits >= 8)
            broadcast_id[i] = network_id[i];
        else
        {
            int bits_left = 8 - subnet_bits;
            int octet = subnet_mask[i];
            octet <<= bits_left;
            octet = ~octet;
            broadcast_id[i] = network_id[i] | octet;
        }
    }
}

// Function to print binary representation of an IP address
void print_binary(int IP[])
{
    printf("Binary representation: ");
    int i = 0;
    for(i = 0; i < 4; i++)
    {
        int j = 0;
        for(j = 0; j < 8; j++)
        {
            printf("%d", (IP[i] & (int)pow(2, j)) ? 1 : 0);
            if(j == 3)
                printf(" ");
        }
        printf(".");
    }
    printf("\n");
}

int main()
{
    printf("C Subnet Calculator\n");

    int IP[4], subnet_mask[4], network_id[4], broadcast_id[4];
    printf("\nEnter IP Address in Decimal format:\n");
    scanf("%d.%d.%d.%d", &IP[0], &IP[1], &IP[2], &IP[3]);

    printf("\nEnter Subnet Mask in Decimal format:\n");
    scanf("%d.%d.%d.%d", &subnet_mask[0], &subnet_mask[1], &subnet_mask[2], &subnet_mask[3]);

    printf("\nIP Address: %d.%d.%d.%d\n", IP[0], IP[1], IP[2], IP[3]);
    print_binary(IP);

    printf("\nSubnet Mask: %d.%d.%d.%d\n", subnet_mask[0], subnet_mask[1], subnet_mask[2], subnet_mask[3]);
    print_binary(subnet_mask);

    // Call function to calculate network and broadcast IDs
    calc_net_bcast(IP, subnet_mask, network_id, broadcast_id);

    printf("\nNetwork ID: %d.%d.%d.%d\n", network_id[0], network_id[1], network_id[2], network_id[3]);
    print_binary(network_id);

    printf("\nBroadcast ID: %d.%d.%d.%d\n", broadcast_id[0], broadcast_id[1], broadcast_id[2], broadcast_id[3]);
    print_binary(broadcast_id);

    return 0;
}