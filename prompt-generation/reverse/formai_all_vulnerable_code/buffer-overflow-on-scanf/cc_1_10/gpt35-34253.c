//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: curious
#include <stdio.h>

// function to convert decimal to binary
void decimal_to_binary(int decimal, int *binary)
{
    int i = 0;
    
    // loop until decimal is greater than 0
    while(decimal > 0)
    {
        binary[i++] = decimal % 2; // get the remainder
        decimal = decimal / 2; // divide decimal by 2
    }
    
    // add zeros to remaining bits
    while(i < 8)
    {
        binary[i++] = 0;
    }
}

// function to calculate subnet mask
void calculate_subnet_mask(int prefix_length, int *subnet_mask)
{
    int i = 0;
    int remaining_bits = prefix_length;
    
    // loop for each byte in subnet mask
    while(remaining_bits > 0)
    {
        if(remaining_bits >= 8)
        {
            subnet_mask[i++] = 255;
            remaining_bits -= 8;
        }
        else
        {
            int binary[8] = {0};
            decimal_to_binary(255 << (8 - remaining_bits), binary);
            subnet_mask[i++] = binary_to_decimal(binary);
            remaining_bits = 0;
        }
    }
}

// function to convert binary to decimal
int binary_to_decimal(int *binary)
{
    int decimal = 0;
    int power = 128;
    
    // loop until all bits are converted
    for(int i = 0; i < 8; i++)
    {
        decimal += binary[i] * power;
        power /= 2;
    }
    
    return decimal;
}

int main()
{
    // get user input
    int ip_address[4] = {0};
    int prefix_length = 0;
    printf("Enter IP Address (Example: 192.168.0.1): ");
    scanf("%d.%d.%d.%d", &ip_address[0], &ip_address[1], &ip_address[2], &ip_address[3]);
    printf("Enter Prefix Length (Example: 24): ");
    scanf("%d", &prefix_length);
    
    // calculate subnet mask
    int subnet_mask[4] = {0};
    calculate_subnet_mask(prefix_length, subnet_mask);
    
    // print subnet mask
    printf("\nIPv4 Subnet Mask: %d.%d.%d.%d\n", subnet_mask[0], subnet_mask[1], subnet_mask[2], subnet_mask[3]);
    
    return 0;
}