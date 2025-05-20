#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int subnet_calc(char *ip_addr, char *subnet_mask)
{
    char subnet_mask_bin[128];
    int subnet_mask_len = 0;
    int subnet_mask_bits = 0;
    int i = 0;

    // Calculate subnet mask binary string length
    subnet_mask_len = snprintf(subnet_mask_bin, 128, "%s", subnet_mask);
    subnet_mask_len++;

    // Convert subnet mask to binary
    for (i = 0; i < subnet_mask_len; i++)
    {
        if (subnet_mask_bin[i] == '/')
            break;
        subnet_mask_bits++;
    }

    // Return number of subnet mask bits
    return subnet_mask_bits;
}

int main()
{
    char ip_addr[16] = "192.168.1.1";
    char subnet_mask[32] = "255.255.255.0";

    int subnet_mask_bits = subnet_calc(ip_addr, subnet_mask);

    printf("Number of subnet mask bits: %d\n", subnet_mask_bits);

    return 0;
}
