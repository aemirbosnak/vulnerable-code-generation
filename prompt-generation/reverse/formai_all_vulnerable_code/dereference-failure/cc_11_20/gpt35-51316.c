//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    printf("Welcome to the Puzzling Subnet Calculator!\n\n");

    char ip_address[20], cidr[4];
    int octets[4], subnet_mask, hosts, i, j;

    printf("Enter the IP address: ");
    scanf("%s", ip_address);

    printf("Enter the CIDR notation: ");
    scanf("%s", cidr);

    char *octet = strtok(ip_address, ".");
    for (i = 0; i < 4; i++)
    {
        octets[i] = atoi(octet);
        octet = strtok(NULL, ".");
    }

    printf("\n");

    subnet_mask = 0;
    for (i = 0; i < atoi(cidr); i++)
    {
        if (i % 8 == 0)
            subnet_mask += 256;

        subnet_mask /= 2;
    }

    printf("The subnet mask is: %d.%d.%d.%d\n\n", (subnet_mask / 256) % 256, subnet_mask / (256*256), subnet_mask / 256, subnet_mask % 256);

    hosts = pow(2, 32 - atoi(cidr)) - 2;
    printf("The number of hosts in the subnet is: %d\n\n", hosts);

    printf("The IP address range for the subnet is:\n");
    for (i = 0; i < 4; i++)
    {
        if (i == 3)
            printf("%d - %d\n\n", octets[i], octets[i] + hosts + 1);
        else
            printf("%d.", octets[i]);
    }

    char binary_subnet_mask[33];
    for (i = 0; i < 32; i++)
    {
        if (i < atoi(cidr))
            binary_subnet_mask[i] = '1';
        else
            binary_subnet_mask[i] = '0';
    }
    binary_subnet_mask[32] = '\0';

    printf("The binary subnet mask is: %s\n\n", binary_subnet_mask);

    char subnet_octets[4][9], binary_ip_address[33];
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 8; j++)
        {
            subnet_octets[i][j] = binary_subnet_mask[j + (i * 8)];
        }
        subnet_octets[i][8] = '\0';
    }

    printf("The binary representation of the IP address is: ");
    for (i = 0; i < 4; i++)
    {
        sprintf(binary_ip_address, "%s%s", binary_ip_address, subnet_octets[i]);
    }

    for (i = 0; i < 32; i += 8)
    {
        printf("%d.", strtol(binary_ip_address + i, NULL, 2));
    }
    printf("\n\n");

    printf("Thank you for using the Puzzling Subnet Calculator!\n");

    return 0;
}