//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_ADDR_LEN 15
#define MAX_SUBNET_MASK_LEN 2
#define MAX_BINARY_MASK 32

void read_ip_addr(unsigned char *ip_addr_parts)
{
    int a, b, c, d;
    scanf("%d.%d.%d.%d", &a, &b, &c, &d);
    ip_addr_parts[0] = (unsigned char)a;
    ip_addr_parts[1] = (unsigned char)b;
    ip_addr_parts[2] = (unsigned char)c;
    ip_addr_parts[3] = (unsigned char)d;
}

void read_subnet(unsigned char *subnet_parts)
{
    int subnet;
    scanf("%d", &subnet);
    memset(subnet_parts, 0xff, 4);
    if (subnet < 32) {
        memset(subnet_parts + subnet / 8, 0, 4 - subnet / 8);
        subnet_parts[subnet / 8] = 0xff << (subnet % 8);
    }
}

void print_ip_addr(unsigned char *ip_addr_parts)
{
    printf("%d.%d.%d.%d", ip_addr_parts[0], ip_addr_parts[1], ip_addr_parts[2], ip_addr_parts[3]);
}

void print_binary_mask(unsigned char *subnet_parts)
{
    unsigned char binary_mask[MAX_BINARY_MASK + 1];
    memset(binary_mask, 0, MAX_BINARY_MASK + 1);
    for (int i = 0; i < MAX_BINARY_MASK; ++i) {
        binary_mask[i] = (subnet_parts[i / 8] & (1 << (7 - i % 8))) ? '1' : '0';
    }
    printf("%s", binary_mask);
}

int main()
{
    unsigned char ip_addr_parts[4], subnet_parts[4];
    read_ip_addr(ip_addr_parts);
    read_subnet(subnet_parts);
    
    printf("IP Address:\t");
    print_ip_addr(ip_addr_parts);
    printf("\n");
    
    printf("Subnet Mask:\t");
    print_ip_addr(subnet_parts);
    printf(" (");
    print_binary_mask(subnet_parts);
    printf(")\n");
    
    int num_hosts = 1;
    for (int i = 0; i < MAX_BINARY_MASK; ++i) {
        if (subnet_parts[i / 8] & (1 << (7 - i % 8))) {
            continue;
        }
        int hosts = 1 << (MAX_BINARY_MASK - i - 1);
        num_hosts += hosts;
    }
    
    printf("Net Address:\t");
    unsigned char net_addr_parts[4];
    for (int i = 0; i < 4; ++i) {
        net_addr_parts[i] = ip_addr_parts[i] & subnet_parts[i];
        printf("%d", net_addr_parts[i]);
        if (i < 3) {
            printf(".");
        }
    }
    printf("\n");
    
    printf("Broadcast Address: ");
    unsigned char broadcast_addr_parts[4];
    for (int i = 0; i < 4; ++i) {
        broadcast_addr_parts[i] = ip_addr_parts[i] | ~subnet_parts[i];
        printf("%d", broadcast_addr_parts[i]);
        if (i < 3) {
            printf(".");
        }
    }
    printf("\n");
    
    printf("# of Hosts:\t%d\n", num_hosts);
    
    return 0;
}