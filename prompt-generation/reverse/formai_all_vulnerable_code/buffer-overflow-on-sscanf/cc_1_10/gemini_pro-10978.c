//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef unsigned int uint32_t;
typedef unsigned char uint8_t;

typedef struct _subnet_calc_result {
    uint32_t network_address;
    uint32_t broadcast_address;
    uint32_t subnet_mask;
    uint32_t host_min;
    uint32_t host_max;
    uint32_t total_hosts;
    uint8_t prefix_length;
    char network_address_str[16];
    char broadcast_address_str[16];
    char subnet_mask_str[16];
    char host_min_str[16];
    char host_max_str[16];
} subnet_calc_result;

bool parse_ip_address(const char *ip_address, uint32_t *ip_address_num)
{
    uint8_t octets[4];
    int num_octets = sscanf(ip_address, "%hhu.%hhu.%hhu.%hhu", &octets[0], &octets[1], &octets[2], &octets[3]);
    if (num_octets != 4)
        return false;

    for (int i = 0; i < 4; i++)
        if (octets[i] > 255)
            return false;

    *ip_address_num = (octets[0] << 24) | (octets[1] << 16) | (octets[2] << 8) | octets[3];
    return true;
}

bool calculate_subnet(uint32_t ip_address, uint8_t prefix_length, subnet_calc_result *result)
{
    if (prefix_length > 32)
        return false;

    uint32_t subnet_mask = 0xffffffff << (32 - prefix_length);
    result->network_address = ip_address & subnet_mask;
    result->broadcast_address = result->network_address | ~subnet_mask;
    result->subnet_mask = subnet_mask;
    result->host_min = result->network_address + 1;
    result->host_max = result->broadcast_address - 1;
    result->total_hosts = (1 << (32 - prefix_length)) - 2;
    result->prefix_length = prefix_length;

    return true;
}

void print_subnet_result(subnet_calc_result *result)
{
    sprintf(result->network_address_str, "%u.%u.%u.%u",
            (result->network_address >> 24) & 0xff,
            (result->network_address >> 16) & 0xff,
            (result->network_address >> 8) & 0xff,
            result->network_address & 0xff);
    sprintf(result->broadcast_address_str, "%u.%u.%u.%u",
            (result->broadcast_address >> 24) & 0xff,
            (result->broadcast_address >> 16) & 0xff,
            (result->broadcast_address >> 8) & 0xff,
            result->broadcast_address & 0xff);
    sprintf(result->subnet_mask_str, "%u.%u.%u.%u",
            (result->subnet_mask >> 24) & 0xff,
            (result->subnet_mask >> 16) & 0xff,
            (result->subnet_mask >> 8) & 0xff,
            result->subnet_mask & 0xff);
    sprintf(result->host_min_str, "%u.%u.%u.%u",
            (result->host_min >> 24) & 0xff,
            (result->host_min >> 16) & 0xff,
            (result->host_min >> 8) & 0xff,
            result->host_min & 0xff);
    sprintf(result->host_max_str, "%u.%u.%u.%u",
            (result->host_max >> 24) & 0xff,
            (result->host_max >> 16) & 0xff,
            (result->host_max >> 8) & 0xff,
            result->host_max & 0xff);

    printf("Network address: %s\n", result->network_address_str);
    printf("Broadcast address: %s\n", result->broadcast_address_str);
    printf("Subnet mask: %s\n", result->subnet_mask_str);
    printf("Host min: %s\n", result->host_min_str);
    printf("Host max: %s\n", result->host_max_str);
    printf("Total hosts: %u\n", result->total_hosts);
    printf("Prefix length: %u\n", result->prefix_length);
}

int main()
{
    char ip_address[16];
    uint32_t ip_address_num;
    uint8_t prefix_length;

    printf("Enter the IP address: ");
    scanf("%s", ip_address);

    printf("Enter the prefix length: ");
    scanf("%hhu", &prefix_length);

    if (!parse_ip_address(ip_address, &ip_address_num))
    {
        printf("Invalid IP address\n");
        return 1;
    }

    subnet_calc_result result;
    if (!calculate_subnet(ip_address_num, prefix_length, &result))
    {
        printf("Invalid prefix length\n");
        return 1;
    }

    print_subnet_result(&result);

    return 0;
}