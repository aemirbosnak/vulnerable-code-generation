//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to convert IP address to binary format
void ip_to_binary(char *ip, char *binary)
{
    int i = 0;
    char *token;
    token = strtok(ip, ".");
    
    while(token != NULL)
    {
        int num = atoi(token);
        int k = 0;
        
        for(int j=7; j>=0; j--)
        {
            if(num >= (1 << j))
            {
                binary[i + k] = '1';
                num -= (1 << j);
            }
            else
            {
                binary[i + k] = '0';
            }
            
            k++;
        }
        i += 8;
        token = strtok(NULL, ".");
    }
    binary[i] = '\0';
}

int main()
{
    char ip[16];
    printf("Enter IP Address (xxx.xxx.xxx.xxx): ");
    fgets(ip, 16, stdin);
    ip[strcspn(ip, "\n")] = 0; // remove newline character from input
    
    int mask;
    printf("Enter Subnet Mask (0-32): ");
    scanf("%d", &mask);
    
    char binary_ip[33];
    ip_to_binary(ip, binary_ip);
    
    char binary_mask[33];
    for(int i=0; i<mask; i++)
    {
        binary_mask[i] = '1';
    }
    for(int i=mask; i<32; i++)
    {
        binary_mask[i] = '0';
    }
    binary_mask[32] = '\0';
    
    char network[33];
    for(int i=0; i<32; i++)
    {
        if(binary_ip[i] == binary_mask[i])
        {
            network[i] = binary_ip[i];
        }
        else
        {
            network[i] = '0';
        }
    }
    network[32] = '\0';
    
    char broadcast[33];
    for(int i=0; i<32; i++)
    {
        if(binary_mask[i] == '1')
        {
            broadcast[i] = network[i];
        }
        else
        {
            broadcast[i] = '1';
        }
    }
    broadcast[32] = '\0';
    
    char first_host[33];
    strcpy(first_host, network);
    first_host[31] = '1';
    
    char last_host[33];
    strcpy(last_host, broadcast);
    last_host[31] = '0';
    
    char cidr_notation[18];
    sprintf(cidr_notation, "%s/%d", ip, mask);
    
    printf("\n");
    printf("IP Address: %s\n", ip);
    printf("Subnet Mask: %d\n", mask);
    printf("CIDR Notation: %s\n", cidr_notation);
    printf("\n");
    printf("Network Address: %s\n", network);
    printf("Broadcast Address: %s\n", broadcast);
    printf("\n");
    printf("First Host Address: ");
    for(int i=0; i<32; i+=8)
    {
        int num = 0;
        for(int j=0; j<8; j++)
        {
            if(first_host[i+j] == '1')
            {
                num += (1 << (7-j));
            }
        }
        printf("%d", num);
        if(i < 24)
        {
            printf(".");
        }
    }
    printf("\n");
    printf("Last Host Address: ");
    for(int i=0; i<32; i+=8)
    {
        int num = 0;
        for(int j=0; j<8; j++)
        {
            if(last_host[i+j] == '1')
            {
                num += (1 << (7-j));
            }
        }
        printf("%d", num);
        if(i < 24)
        {
            printf(".");
        }
    }
    printf("\n");

    return 0;
}