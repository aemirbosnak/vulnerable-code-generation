//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int subnet_mask, host_bits, network_bits, subnet_address, host_address, broadcast_address;
    char subnet_mask_str[32], host_bits_str[32], network_bits_str[32], subnet_address_str[32], host_address_str[32], broadcast_address_str[32];

    printf("Enter the subnet mask (in binary): ");
    scanf("%s", subnet_mask_str);

    subnet_mask = atoi(subnet_mask_str);

    network_bits = 32 - subnet_mask;
    network_bits_str[0] = 'N';
    network_bits_str[1] = 'etwork';
    network_bits_str[2] = ' bits: ';
    network_bits_str[3] = '\n';

    subnet_address = (subnet_mask & 0xFF) >> 8;
    subnet_address_str[0] = 'S';
    subnet_address_str[1] = 'ubnet ';
    subnet_address_str[2] = 'address: ';
    subnet_address_str[3] = '\n';

    host_bits = subnet_mask & 0xFF;
    host_bits_str[0] = 'H';
    host_bits_str[1] = 'ost';
    host_bits_str[2] = ' bits: ';
    host_bits_str[3] = '\n';

    host_address = (subnet_mask & 0xFF) & ~0xFF;
    host_address_str[0] = 'H';
    host_address_str[1] = 'ost ';
    host_address_str[2] = 'address: ';
    host_address_str[3] = '\n';

    broadcast_address = ((subnet_mask & 0xFF) | 0xFF) & ~0xFF;
    broadcast_address_str[0] = 'B';
    broadcast_address_str[1] = 'roadcast ';
    broadcast_address_str[2] = 'address: ';
    broadcast_address_str[3] = '\n';

    printf("%s", network_bits_str);
    printf("%s", subnet_address_str);
    printf("%s", host_bits_str);
    printf("%s", host_address_str);
    printf("%s", broadcast_address_str);

    return 0;
}