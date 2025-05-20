//Falcon2-11B DATASET v1.0 Category: Subnet Calculator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // check if the correct number of arguments is provided
    if (argc!= 2)
    {
        printf("Usage: %s <subnet_mask>\n", argv[0]);
        return 1;
    }

    // check if the subnet mask is valid
    char *subnet_mask = argv[1];
    int subnet_mask_len = strlen(subnet_mask);
    if (subnet_mask_len!= 4 ||!isdigit(subnet_mask[0]) ||!isdigit(subnet_mask[1]) ||!isdigit(subnet_mask[2]) ||!isdigit(subnet_mask[3]))
    {
        printf("Invalid subnet mask\n");
        return 1;
    }

    // convert the subnet mask to binary
    char *subnet_mask_binary = malloc(subnet_mask_len * 3 + 1);
    int subnet_mask_binary_len = 0;
    for (int i = 0; i < subnet_mask_len; i++)
    {
        int digit = subnet_mask[i] - '0';
        subnet_mask_binary_len += (digit == 1)? 1 : 0;
        if (i < subnet_mask_len - 1)
            subnet_mask_binary_len += (digit == 1)? 1 : 0;
        sprintf(&subnet_mask_binary[subnet_mask_binary_len], "%d", digit);
    }
    subnet_mask_binary[subnet_mask_binary_len] = '\0';

    // calculate the network address
    char *network_address = malloc(subnet_mask_len * 3 + 1);
    for (int i = 0; i < subnet_mask_len; i++)
    {
        int digit = subnet_mask[i] - '0';
        sprintf(&network_address[i], "%d", digit);
    }
    network_address[subnet_mask_len] = '\0';

    // calculate the broadcast address
    char *broadcast_address = malloc(subnet_mask_len * 3 + 1);
    for (int i = 0; i < subnet_mask_len; i++)
    {
        int digit = subnet_mask[i] - '0';
        sprintf(&broadcast_address[i], "%d", digit | 0x80);
    }
    broadcast_address[subnet_mask_len] = '\0';

    // print the results
    printf("Subnet mask: %s\n", subnet_mask);
    printf("Network address: %s\n", network_address);
    printf("Broadcast address: %s\n", broadcast_address);

    // free the memory
    free(subnet_mask_binary);
    free(network_address);
    free(broadcast_address);

    return 0;
}