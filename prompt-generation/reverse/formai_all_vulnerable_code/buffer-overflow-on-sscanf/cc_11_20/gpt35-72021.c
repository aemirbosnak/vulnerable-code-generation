//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char ip[20], subnet[20];
    int mask, mask_bits, subnet_bits, total_hosts, i, j, k, l;
    int subnet_mask[4], ip_address[4], subnet_address[4], broadcast_address[4], first_address[4], last_address[4];

    printf("Enter IP address: ");
    scanf("%s", ip);

    printf("Enter subnet mask: ");
    scanf("%s", subnet);

    // Parse and validate IP address
    if (sscanf(ip, "%d.%d.%d.%d", &ip_address[0], &ip_address[1], &ip_address[2], &ip_address[3]) != 4)
    {
        printf("Invalid IP address\n");
        return 0;
    }
    for (i = 0; i < 4; i++)
    {
        if (ip_address[i] < 0 || ip_address[i] > 255)
        {
            printf("Invalid IP address\n");
            return 0;
        }
    }

    // Parse and validate subnet mask
    if (sscanf(subnet, "%d.%d.%d.%d", &subnet_mask[0], &subnet_mask[1], &subnet_mask[2], &subnet_mask[3]) != 4)
    {
        printf("Invalid subnet mask\n");
        return 0;
    }
    mask = subnet_mask[0] << 24 | subnet_mask[1] << 16 | subnet_mask[2] << 8 | subnet_mask[3];
    if (mask == 0 || mask == 0xFFFFFFFF || (mask & (mask + 1)) != 0)
    {
        printf("Invalid subnet mask\n");
        return 0;
    }

    // Calculate subnet bits
    for (i = 0; i < 4; i++)
    {
        mask_bits = 0;
        for (j = 7; j >= 0; j--)
        {
            if (((subnet_mask[i] >> j) & 1) == 1)
                mask_bits++;
            else
                break;
        }
        if (mask_bits < 8)
            break;
    }
    subnet_bits = mask_bits + ((3 - i) * 8);

    // Calculate network address, broadcast address, and usable addresses
    for (i = 0; i < 4; i++)
    {
        subnet_address[i] = ip_address[i] & subnet_mask[i];
        broadcast_address[i] = subnet_address[i] | (~subnet_mask[i] & 0xFF);
    }
    total_hosts = (1 << (32 - subnet_bits)) - 2;
    for (i = 0; i < 4; i++)
    {
        first_address[i] = subnet_address[i];
        last_address[i] = broadcast_address[i];
    }
    first_address[3]++;
    last_address[3]--;

    // Output results
    printf("\n");
    printf("IP address: %d.%d.%d.%d\n", ip_address[0], ip_address[1], ip_address[2], ip_address[3]);
    printf("Subnet mask: %d.%d.%d.%d\n", subnet_mask[0], subnet_mask[1], subnet_mask[2], subnet_mask[3]);
    printf("Subnet bits: %d\n", subnet_bits);
    printf("Subnet address: %d.%d.%d.%d\n", subnet_address[0], subnet_address[1], subnet_address[2], subnet_address[3]);
    printf("Broadcast address: %d.%d.%d.%d\n", broadcast_address[0], broadcast_address[1], broadcast_address[2], broadcast_address[3]);
    printf("First usable address: %d.%d.%d.%d\n", first_address[0], first_address[1], first_address[2], first_address[3]);
    printf("Last usable address: %d.%d.%d.%d\n", last_address[0], last_address[1], last_address[2], last_address[3]);
    printf("Total usable addresses: %d\n", total_hosts);

    return 0;
}