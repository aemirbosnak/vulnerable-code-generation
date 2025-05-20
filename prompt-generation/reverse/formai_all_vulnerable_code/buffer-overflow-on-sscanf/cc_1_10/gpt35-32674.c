//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    char ip_address[20], subnet_mask[20];
    int octet1, octet2, octet3, octet4;
    int subnet_octet1, subnet_octet2, subnet_octet3, subnet_octet4;
    int subnet_size, network_address, broadcast_address, valid_host_ips, wildcard_mask;

    printf("\nEnter the IP address (example: 192.168.1.1): ");
    scanf("%s", ip_address);

    printf("\nEnter the subnet mask (example: 255.255.255.0): ");
    scanf("%s", subnet_mask);

    // Parsing IP address
    sscanf(ip_address, "%d.%d.%d.%d", &octet1, &octet2, &octet3, &octet4);

    // Parsing subnet mask
    sscanf(subnet_mask, "%d.%d.%d.%d", &subnet_octet1, &subnet_octet2, &subnet_octet3, &subnet_octet4);

    // Calculating subnet size
    int subnet_bits = 0;
    for(int i=0; i<4; i++)
    {
        int octet = (i == 0) ? subnet_octet1 : (i == 1) ? subnet_octet2 : (i == 2) ? subnet_octet3 : subnet_octet4;
        if(octet == 0)
            break;
        subnet_bits += log2(octet);
    }
    subnet_size = pow(2, 32 - subnet_bits);

    // Calculating network address
    network_address = ((octet1 & subnet_octet1) << 24) | ((octet2 & subnet_octet2) << 16) | ((octet3 & subnet_octet3) << 8) | (octet4 & subnet_octet4);
    
    // Calculating broadcast address
    broadcast_address = network_address + subnet_size - 1;

    // Calculating valid host IPs
    valid_host_ips = (subnet_size - 2 > 0) ? subnet_size - 2 : 0;

    // Calculating wildcard mask
    wildcard_mask = 0xFFFFFFFF ^ (subnet_octet1 << 24 | subnet_octet2 << 16 | subnet_octet3 << 8 | subnet_octet4);

    printf("\n--------------------------------------\n");
    printf("IP Address: %s\n", ip_address);
    printf("Subnet Mask: %s\n", subnet_mask);
    printf("--------------------------------------\n");
    printf("Subnet Size: %d\n", subnet_size);
    printf("Network Address: %d.%d.%d.%d\n", (network_address >> 24) & 0xFF, (network_address >> 16) & 0xFF, (network_address >> 8) & 0xFF, network_address & 0xFF);
    printf("Broadcast Address: %d.%d.%d.%d\n", (broadcast_address >> 24) & 0xFF, (broadcast_address >> 16) & 0xFF, (broadcast_address >> 8) & 0xFF, broadcast_address & 0xFF);
    printf("Valid Host IP Range: %d.%d.%d.%d - %d.%d.%d.%d\n", ((network_address + 1) >> 24) & 0xFF, ((network_address + 1) >> 16) & 0xFF, ((network_address + 1) >> 8) & 0xFF, (network_address + 1) & 0xFF, ((broadcast_address - 1) >> 24) & 0xFF, ((broadcast_address - 1) >> 16) & 0xFF, ((broadcast_address - 1) >> 8) & 0xFF, (broadcast_address - 1) & 0xFF);
    printf("Valid Host IPs: %d\n", valid_host_ips);
    printf("Wildcard Mask: %d.%d.%d.%d\n", (wildcard_mask >> 24) & 0xFF, (wildcard_mask >> 16) & 0xFF, (wildcard_mask >> 8) & 0xFF, wildcard_mask & 0xFF);
    printf("--------------------------------------\n");

    return 0;
}