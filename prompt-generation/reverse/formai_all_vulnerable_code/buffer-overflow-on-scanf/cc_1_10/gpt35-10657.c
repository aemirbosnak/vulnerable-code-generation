//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: paranoid
//Paranoid-style C Subnet Calculator

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_IP_LEN 16
#define MAX_CIDR_LEN 3
#define MAX_SUBNETS 256

const char IP_DELIMITER[] = ".";
const char CIDR_DELIMITER[] = "/";

bool is_valid_ip_addr(char*);
bool is_valid_cidr_notation(char*);
int count_subnet_bits(char*);
void get_base_ip(char*, char*, int);
void get_broadcast_ip(char*, char*, int);
void get_subnet_addr(char*, char*, int, int);

int main()
{
    char ip_addr[MAX_IP_LEN];
    printf("Enter IP address: ");
    scanf("%s", ip_addr);

    if(!is_valid_ip_addr(ip_addr))
    {
        printf("Invalid IP address format\n");
        return EXIT_FAILURE;
    }

    char cidr_notation[MAX_CIDR_LEN];
    printf("Enter CIDR notation: ");
    scanf("%s", cidr_notation);

    if(!is_valid_cidr_notation(cidr_notation))
    {
        printf("Invalid CIDR notation format\n");
        return EXIT_FAILURE;
    }

    int subnet_bits = count_subnet_bits(cidr_notation);
    printf("Number of subnet bits: %d\n", subnet_bits);

    char base_ip[MAX_IP_LEN], broadcast_ip[MAX_IP_LEN];
    get_base_ip(ip_addr, base_ip, subnet_bits);
    get_broadcast_ip(ip_addr, broadcast_ip, subnet_bits);

    printf("Base IP address: %s\n", base_ip);
    printf("Broadcast IP address: %s\n", broadcast_ip);

    int num_subnets = (1 << subnet_bits); //Same as 2^subnet_bits
    printf("Number of subnets: %d\n", num_subnets);

    char subnet_addr[MAX_SUBNETS][MAX_IP_LEN];
    for(int i=0; i<num_subnets; i++)
    {
        get_subnet_addr(ip_addr, subnet_addr[i], subnet_bits, i);
        printf("Subnet %d address: %s\n", i+1, subnet_addr[i]);
    }

    return EXIT_SUCCESS;
}

bool is_valid_ip_addr(char* ip_addr)
{
    int len = strlen(ip_addr);
    if(len < 7 || len > 15)
        return false;

    char* token = strtok(ip_addr, IP_DELIMITER);
    int num_tokens = 0;

    while(token != NULL)
    {
        if(num_tokens++ > 4)
            return false;

        for(int i=0; i<strlen(token); i++)
            if(!isdigit(token[i]))
                return false;

        int num = atoi(token);
        if(num < 0 || num > 255)
            return false;

        token = strtok(NULL, IP_DELIMITER);
    }

    return (num_tokens == 4);
}

bool is_valid_cidr_notation(char* cidr_notation)
{
    int len = strlen(cidr_notation);
    if(len < 2 || len > 3)
        return false;

    char* token = strtok(cidr_notation, CIDR_DELIMITER);
    int num_tokens = 0;

    while(token != NULL)
    {
        if(num_tokens++ > 1)
            return false;

        for(int i=0; i<strlen(token); i++)
            if(!isdigit(token[i]))
                return false;

        int num = atoi(token);
        if(num < 0 || num > ((num_tokens == 1) ? 32 : 256))
            return false;

        token = strtok(NULL, CIDR_DELIMITER);
    }

    return (num_tokens == 2);
}

int count_subnet_bits(char* cidr_notation)
{
    int subnet_bits = 0;
    char* token = strtok(cidr_notation, CIDR_DELIMITER);

    while(token != NULL)
    {
        if(strchr(cidr_notation, '/') != NULL)
            subnet_bits = atoi(token);
        else
            subnet_bits = 8 * sizeof(char*) - atoi(token);

        token = strtok(NULL, CIDR_DELIMITER);
    }

    return subnet_bits;
}

void get_base_ip(char* ip_addr, char* base_ip, int subnet_bits)
{
    int last_octet = 0;
    int num_bits = 8 - (subnet_bits % 8);
    int subnet_shift = subnet_bits % 8 == 0 ? 8 : subnet_bits % 8;

    char* token = strtok(ip_addr, IP_DELIMITER);
    int num_tokens = 0;

    while(token != NULL)
    {
        if(num_tokens++ > 4)
            break;

        if(num_tokens == 4)
        {
            last_octet = atoi(token) >> subnet_shift << subnet_shift;
        }
        else if(num_tokens == 3)
        {
            int octet_val = atoi(token);
            if(subnet_bits >= 24)
            {
                octet_val = 0;
            }
            else if(subnet_bits >= 16)
            {
                octet_val = last_octet;
            }
            else if(subnet_bits >= 8)
            {
                octet_val = last_octet | ((atoi(token) >> num_bits) << num_bits);
            }

            sprintf(base_ip, "%s%d", base_ip, octet_val);
        }
        else
        {
            sprintf(base_ip, "%s%s", base_ip, token);
        }

        if(num_tokens < 4)
            sprintf(base_ip, "%s.", base_ip);

        token = strtok(NULL, IP_DELIMITER);
    }
}

void get_broadcast_ip(char* ip_addr, char* broadcast_ip, int subnet_bits)
{
    int last_octet = 0;
    int num_bits = 8 - (subnet_bits % 8);
    int subnet_shift = subnet_bits % 8 == 0 ? 8 : subnet_bits % 8;
    int last_octet_mask = (1 << subnet_shift) - 1;
    int last_octet_broadcast = last_octet_mask | last_octet;

    char* token = strtok(ip_addr, IP_DELIMITER);
    int num_tokens = 0;

    while(token != NULL)
    {
        if(num_tokens++ > 4)
            break;

        if(num_tokens == 4)
        {
            last_octet = last_octet_broadcast;
        }
        else if(num_tokens == 3)
        {
            int octet_val = atoi(token);
            if(subnet_bits >= 24)
            {
                octet_val = 255;
            }
            else if(subnet_bits >= 16)
            {
                octet_val = last_octet_broadcast;
            }
            else if(subnet_bits >= 8)
            {
                octet_val = last_octet | (atoi(token) & ~last_octet_mask);
            }

            sprintf(broadcast_ip, "%s%d", broadcast_ip, octet_val);
        }
        else
        {
            sprintf(broadcast_ip, "%s%s", broadcast_ip, token);
        }

        if(num_tokens < 4)
            sprintf(broadcast_ip, "%s.", broadcast_ip);

        token = strtok(NULL, IP_DELIMITER);
    }
}

void get_subnet_addr(char* ip_addr, char* subnet_addr, int subnet_bits, int subnet_num)
{
    int last_octet = 0;
    int num_bits = 8 - (subnet_bits % 8);
    int subnet_shift = subnet_bits % 8 == 0 ? 8 : subnet_bits % 8;
    int subnet_mask = (1 << subnet_shift) - 1;

    char* token = strtok(ip_addr, IP_DELIMITER);
    int num_tokens = 0;

    while(token != NULL)
    {
        if(num_tokens++ > 4)
            break;

        if(num_tokens == 4)
        {
            last_octet = (subnet_num & subnet_mask) | (atoi(token) >> subnet_shift << subnet_shift);
        }
        else if(num_tokens == 3)
        {
            int octet_val = atoi(token);
            if(subnet_bits >= 24)
            {
                octet_val = last_octet;
            }
            else if(subnet_bits >= 16)
            {
                octet_val = 0;
            }
            else if(subnet_bits >= 8)
            {
                octet_val = (last_octet << num_bits) | (atoi(token) >> num_bits);
            }

            sprintf(subnet_addr, "%s%d", subnet_addr, octet_val);
        }
        else
        {
            sprintf(subnet_addr, "%s%s", subnet_addr, token);
        }

        if(num_tokens < 4)
            sprintf(subnet_addr, "%s.", subnet_addr);

        token = strtok(NULL, IP_DELIMITER);
    }
}