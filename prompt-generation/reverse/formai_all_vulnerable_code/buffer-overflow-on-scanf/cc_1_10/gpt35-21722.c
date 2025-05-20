//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: thoughtful
/*
 * C Subnet Calculator Example Program
 * 
 * This program takes an IP address and subnet mask as inputs and calculates the network ID, broadcast ID, first usable IP, and last usable IP for the given subnet.
 *
 * Author: [Your Name]
 * Date: [Date]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_LENGTH 20

// Function to convert decimal IP address to binary
void decToBin(char *ip, char *binIp)
{
    int i, j, len, num, rem;
    char temp[MAX_IP_LENGTH];

    strcpy(temp, ip);

    len = strlen(temp);

    j = 0;

    for (i = 0; i < len; i++)
    {
        if (temp[i] == '.')
        {
            binIp[j++] = ' ';
        }
        else
        {
            num = temp[i] - '0';

            while (num > 0)
            {
                rem = num % 2;
                num = num / 2;

                binIp[j++] = rem + '0';
            }

            while (j % 8 != 0)
            {
                binIp[j++] = '0';
            }
        }
    }

    binIp[j] = '\0';
}

// Function to convert binary IP address to decimal
void binToDec(char *binIp, char *ip)
{
    int i, j, len, sum, pow;
    char temp[MAX_IP_LENGTH];

    strcpy(temp, binIp);

    len = strlen(temp);

    j = 0;

    for (i = 0; i < len; i++)
    {
        if (temp[i] == ' ')
        {
            ip[j++] = '.';
        }
        else
        {
            sum = 0;
            pow = 1;

            while (temp[i] == '0' || temp[i] == '1')
            {
                sum = sum + (temp[i] - '0') * pow;
                pow = pow * 2;
                i++;
            }

            i--;

            ip[j++] = sum + '0';
        }
    }

    ip[j] = '\0';
}

// Function to calculate network ID, broadcast ID, first and last usable IP addresses
void calculate(char *ip, char *mask, char *network, char *broadcast, char *first, char *last)
{
    char binIp[MAX_IP_LENGTH];
    char binMask[MAX_IP_LENGTH];
    char binNetwork[MAX_IP_LENGTH];
    char binBroadcast[MAX_IP_LENGTH];
    char binFirst[MAX_IP_LENGTH];
    char binLast[MAX_IP_LENGTH];
    char temp[MAX_IP_LENGTH];
    int i, j, len, num, rem, cidr, ones, zeros;

    // Convert IP address and mask to binary
    decToBin(ip, binIp);
    decToBin(mask, binMask);

    // Calculate CIDR notation
    cidr = 0;
    len = strlen(binMask);

    for (i = 0; i < len; i++)
    {
        if (binMask[i] == '1')
        {
            cidr++;
        }
    }

    // Calculate number of ones and zeros
    ones = cidr;
    zeros = 32 - cidr;

    // Calculate network ID
    strcpy(binNetwork, binIp);

    for (i = cidr; i < 32; i++)
    {
        binNetwork[i] = '0';
    }

    binNetwork[32] = '\0';

    // Calculate broadcast ID
    strcpy(binBroadcast, binIp);

    for (i = cidr; i < 32; i++)
    {
        binBroadcast[i] = '1';
    }

    binBroadcast[32] = '\0';

    // Calculate first usable IP
    strcpy(binFirst, binNetwork);

    for (i = 31; i >= cidr; i--)
    {
        if (binFirst[i] == '0')
        {
            binFirst[i] = '1';
            break;
        }
        else
        {
            binFirst[i] = '0';
        }
    }

    binFirst[32] = '\0';

    // Calculate last usable IP
    strcpy(binLast, binBroadcast);

    for (i = 31; i >= cidr; i--)
    {
        if (binLast[i] == '1')
        {
            binLast[i] = '0';
            break;
        }
        else
        {
            binLast[i] = '1';
        }
    }

    binLast[32] = '\0';

    // Convert binary back to decimal
    binToDec(binNetwork, network);
    binToDec(binBroadcast, broadcast);
    binToDec(binFirst, first);
    binToDec(binLast, last);
}

int main()
{
    char ip[MAX_IP_LENGTH];
    char mask[MAX_IP_LENGTH];
    char network[MAX_IP_LENGTH];
    char broadcast[MAX_IP_LENGTH];
    char first[MAX_IP_LENGTH];
    char last[MAX_IP_LENGTH];

    printf("Please enter an IP address and subnet mask (example: 192.168.1.1 255.255.255.0): ");
    scanf("%s %s", ip, mask);

    calculate(ip, mask, network, broadcast, first, last);

    printf("\nNetwork Address: %s", network);
    printf("\nBroadcast Address: %s", broadcast);
    printf("\nFirst Usable IP Address: %s", first);
    printf("\nLast Usable IP Address: %s\n", last);

    return 0;
}