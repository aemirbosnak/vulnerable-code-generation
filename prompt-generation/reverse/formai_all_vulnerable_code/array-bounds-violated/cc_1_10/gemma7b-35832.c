//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int subnet_mask, host_mask, network_address, subnet_number, host_number, i, j;
    char subnet_mask_bin[32], host_mask_bin[32], network_address_bin[32];

    printf("Enter subnet mask in binary (e.g. 255.255.255.0): ");
    scanf("%s", subnet_mask_bin);

    subnet_mask = atoi(subnet_mask_bin);
    subnet_mask_bin[32] = '\0';
    for (i = 0; subnet_mask_bin[i] != '\0'; i++)
    {
        subnet_mask_bin[i] = (subnet_mask_bin[i] - '0') & 1;
    }

    printf("Enter host mask in binary (e.g. 255.255.255.224): ");
    scanf("%s", host_mask_bin);

    host_mask = atoi(host_mask_bin);
    host_mask_bin[32] = '\0';
    for (i = 0; host_mask_bin[i] != '\0'; i++)
    {
        host_mask_bin[i] = (host_mask_bin[i] - '0') & 1;
    }

    network_address = (subnet_mask & host_mask) & ~host_mask;

    network_address_bin[0] = '0';
    network_address_bin[1] = '0';
    network_address_bin[2] = '0';
    network_address_bin[3] = '0';

    for (i = 0; network_address_bin[i] != '\0'; i++)
    {
        network_address_bin[i] = (network_address_bin[i] - '0') & 1;
    }

    printf("Network address: ");
    for (i = 0; network_address_bin[i] != '\0'; i++)
    {
        printf("%d.", network_address_bin[i]);
    }

    printf("\n");

    subnet_number = (subnet_mask & ~host_mask) >> 8;

    printf("Subnet number: %d\n", subnet_number);

    host_number = (subnet_mask & ~host_mask) & 255;

    printf("Host number: %d\n", host_number);

    return 0;
}