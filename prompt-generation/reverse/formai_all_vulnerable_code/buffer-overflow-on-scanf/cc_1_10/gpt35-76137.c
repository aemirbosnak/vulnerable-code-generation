//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char subnet[4]; /* Declare an array to hold the subnet octets */
unsigned char subnet_mask; /* Declare a variable to hold the subnet mask */

/* Function prototype */
void CalculateSubnet(unsigned char *ip_address, unsigned char subnet_mask);

int main(void) 
{
    unsigned char ip_address[16]; /* Declare a string to hold the IP address */
    
    /* Get user input for IP address and subnet mask */
    printf("Enter IP address (format: XXX.XXX.XXX.XXX): ");
    fgets(ip_address, 16, stdin);
    printf("Enter subnet mask (format: X): ");
    scanf("%hhu", &subnet_mask);
    
    /* Call function to calculate subnet */
    CalculateSubnet(ip_address, subnet_mask);
    
    /* Display the calculated subnet */
    printf("Calculated subnet: %d.%d.%d.%d/%hhu\n", subnet[0], subnet[1], subnet[2], subnet[3], subnet_mask);
    
    return 0;
}

void CalculateSubnet(unsigned char *ip_address, unsigned char subnet_mask) 
{
    unsigned char octet_count = 0;
    unsigned char octet_position = 0;
    unsigned char temp_num = 0;
    unsigned char temp_mask = 0;
    
    /* Split the IP address octets */
    while (*ip_address) 
    {
        if (*ip_address == '.') 
        {
            subnet[octet_count++] = temp_num;
            temp_num = 0;
            octet_position = 0;
        }
        else 
        {
            temp_num = (temp_num * 10) + (*ip_address - '0');
            octet_position++;
        }
        ip_address++;
    }
    subnet[octet_count] = temp_num;
    
    /* Calculate the subnet */
    for (unsigned char i = 0; i < subnet_mask; i++) 
    {
        if (i > 0 && i % 8 == 0) 
        {
            temp_mask = temp_mask << 1;
            subnet[octet_count - (i / 8) - 1] |= temp_mask;
            
            temp_mask = 0;
        }
        temp_mask = (temp_mask << 1) | 0x01;
    }
    if (temp_mask) 
    {
        subnet[octet_count - ((subnet_mask - 1) / 8) - 1] |= temp_mask;
    }
}