//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: ultraprecise
#include <stdio.h>
#include <math.h>

/* Bitwise AND mask for IP address */
#define IP_MASK 0xFF

/* Bitwise shift to retrieve octet from IP address */
#define IP_OCTET_SHIFT 8

/* Maximum value for a single octet */
#define MAX_OCTET_VALUE 255

/* Bitwise shift to perform subnet calculation */
#define SUBNET_SHIFT 32

/* Calculate subnet mask for given prefix length */
unsigned int calculate_subnet_mask(int prefix_length)
{
    unsigned int subnet_mask = 0;
    int i = 0;
    
    /* Calculate subnet mask */
    for (i = 0; i < prefix_length; i++) {
        subnet_mask |= (1 << (SUBNET_SHIFT - i - 1));
    }
    
    return subnet_mask;
}

/* Calculate number of hosts based on subnet mask */
unsigned int calculate_host_count(unsigned int subnet_mask)
{
    return pow(2, SUBNET_SHIFT - __builtin_popcount(subnet_mask));
}

/* Calculate network address based on IP address and subnet mask */
unsigned int calculate_network_address(unsigned int ip_address, unsigned int subnet_mask)
{
    return ip_address & subnet_mask;
}

/* Calculate broadcast address based on IP address and subnet mask */
unsigned int calculate_broadcast_address(unsigned int ip_address, unsigned int subnet_mask)
{
    return calculate_network_address(ip_address, subnet_mask) | ~subnet_mask;
}

/* Main function */
int main()
{
    unsigned int ip_address = 0;
    unsigned int subnet_mask = 0;
    int prefix_length = 0;
    
    /* Prompt for IP address */
    printf("Enter IP address: ");
    scanf("%u", &ip_address);
    
    /* Prompt for prefix length */
    printf("Enter prefix length: ");
    scanf("%d", &prefix_length);
    
    /* Calculate subnet mask */
    subnet_mask = calculate_subnet_mask(prefix_length);
    
    /* Print subnet mask */
    printf("Subnet mask: %u.%u.%u.%u\n",
        (subnet_mask >> (IP_OCTET_SHIFT * 3)) & IP_MASK,
        (subnet_mask >> (IP_OCTET_SHIFT * 2)) & IP_MASK,
        (subnet_mask >> (IP_OCTET_SHIFT * 1)) & IP_MASK,
        (subnet_mask >> (IP_OCTET_SHIFT * 0)) & IP_MASK);
    
    /* Calculate and print network address */
    printf("Network address: %u.%u.%u.%u\n",
        (calculate_network_address(ip_address, subnet_mask) >> (IP_OCTET_SHIFT * 3)) & IP_MASK,
        (calculate_network_address(ip_address, subnet_mask) >> (IP_OCTET_SHIFT * 2)) & IP_MASK,
        (calculate_network_address(ip_address, subnet_mask) >> (IP_OCTET_SHIFT * 1)) & IP_MASK,
        (calculate_network_address(ip_address, subnet_mask) >> (IP_OCTET_SHIFT * 0)) & IP_MASK);
    
    /* Calculate and print broadcast address */
    printf("Broadcast address: %u.%u.%u.%u\n",
        (calculate_broadcast_address(ip_address, subnet_mask) >> (IP_OCTET_SHIFT * 3)) & IP_MASK,
        (calculate_broadcast_address(ip_address, subnet_mask) >> (IP_OCTET_SHIFT * 2)) & IP_MASK,
        (calculate_broadcast_address(ip_address, subnet_mask) >> (IP_OCTET_SHIFT * 1)) & IP_MASK,
        (calculate_broadcast_address(ip_address, subnet_mask) >> (IP_OCTET_SHIFT * 0)) & IP_MASK);
    
    /* Calculate and print number of hosts */
    printf("Number of hosts: %u\n", calculate_host_count(subnet_mask));
    
    return 0;
}