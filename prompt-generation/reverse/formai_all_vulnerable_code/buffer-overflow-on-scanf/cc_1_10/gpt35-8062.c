//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// A function to calculate the subnet mask
// based on the prefix length
void subnetMaskCalc(int prefix, int mask[])
{
    int i, j;
    for(i = 0; i < 4; i++)
    {
        mask[i] = 0;
        for(j = 0; j < 8 && prefix > 0; j++, prefix--)
        {
            mask[i] |= (1 << (7 - j));
        }
    }
}

// A function to convert an IP address
// in string form to an integer form
void ipToInt(char* ip, int intIP[])
{
    int i = 0;
    char* token = strtok(ip, ".");
    while(token != NULL)
    {
        intIP[i++] = atoi(token);
        token = strtok(NULL, ".");
    }
}

// A function to calculate the network ID
// based on the IP address and subnet mask
void networkIDCalc(int intIP[], int mask[], int netID[])
{
    int i;
    for(i = 0; i < 4; i++)
    {
        netID[i] = intIP[i] & mask[i];
    }
}

int main()
{
    char ip[16];
    int prefix, mask[4], intIP[4], netID[4];

    printf("Enter IP address in dotted decimal form(xxx.xxx.xxx.xxx): ");
    scanf("%s", ip);

    printf("Enter prefix length: ");
    scanf("%d", &prefix);

    subnetMaskCalc(prefix, mask);
    ipToInt(ip, intIP);
    networkIDCalc(intIP, mask, netID);

    printf("\nSubnet mask: %d.%d.%d.%d", mask[0], mask[1], mask[2], mask[3]);
    printf("\nNetwork ID: %d.%d.%d.%d", netID[0], netID[1], netID[2], netID[3]);

    return 0;
}