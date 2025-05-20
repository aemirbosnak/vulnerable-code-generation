//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void subnet_calculator(unsigned long long int ip_addr, int prefix_len);

int main()
{
    unsigned long long int ip_addr;
    int prefix_len;
    char buffer[20];

    printf("Enter the IP address in decimal form: ");
    scanf("%s", buffer);
    ip_addr = atoll(buffer);

    printf("Enter the prefix length: ");
    scanf("%d", &prefix_len);

    subnet_calculator(ip_addr, prefix_len);

    return 0;
}

void subnet_calculator(unsigned long long int ip_addr, int prefix_len)
{
    unsigned long long int subnet_mask = (1ull << prefix_len) - 1ull;
    subnet_mask <<= (32 - prefix_len);

    unsigned long long int network_id = ip_addr & subnet_mask;
    unsigned long long int broadcast_id = network_id | (~subnet_mask);

    printf("\nIP Address in decimal form: %llu\n", ip_addr);
    printf("IP Address in binary form: ");
    for(int i = 31; i >= 0; i--)
    {
        printf("%llu", ((ip_addr >> i) & 1ull));
        if(i % 8 == 0)
            printf(" ");
    }

    printf("\nSubnet Mask in decimal form: %llu\n", subnet_mask);
    printf("Subnet Mask in binary form: ");
    for(int i = 31; i >= 0; i--)
    {
        printf("%llu", ((subnet_mask >> i) & 1ull));
        if(i % 8 == 0)
            printf(" ");
    }

    printf("\nNetwork ID in decimal form: %llu\n", network_id);
    printf("Network ID in binary form: ");
    for(int i = 31; i >= 0; i--)
    {
        printf("%llu", ((network_id >> i) & 1ull));
        if(i % 8 == 0)
            printf(" ");
    }

    printf("\nBroadcast ID in decimal form: %llu\n", broadcast_id);
    printf("Broadcast ID in binary form: ");
    for(int i = 31; i >= 0; i--)
    {
        printf("%llu", ((broadcast_id >> i) & 1ull));
        if(i % 8 == 0)
            printf(" ");
    }
    printf("\n");
}