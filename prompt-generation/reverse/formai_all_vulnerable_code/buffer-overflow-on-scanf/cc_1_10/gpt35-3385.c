//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void binaryToDecimal(char *binary, int *decimal) {
    int i,j,power;
    int len = strlen(binary) - 1;
    for (i = 0; i <= len; i++) {
        decimal[i] = 0;
        power = 1;

        for (j = len; j >= 0; j--) {
            if (binary[j] == '1')
            decimal[i] += power;
            power *= 2;
        }
    }
}

void calculateSubnetMask(int num_hosts, char *subnet_mask) {
    int i, num_bits = 0;
    while (num_hosts > 0) {
        num_hosts /= 2;
        num_bits++;
    }

    int binary_subnet[32];
    for (i = 0; i < num_bits; i++) binary_subnet[i] = 1;
    for (; i < 32; i++) binary_subnet[i] = 0;

    int decimal_subnet[4];
    char binary[8];
    for (i = 0; i < 4; i++) {
        strncpy(binary, &subnet_mask[i*8], 8);
        binaryToDecimal(binary, &decimal_subnet[i]);
    }

    int result[32];
    for (i = 0; i < 32; i++)
    result[i] = binary_subnet[i] & decimal_subnet[i];

    for (i = 0; i < 4; i++) {
        sprintf(&subnet_mask[i*8], "%d", result[i]);
        if (i < 3) strcat(subnet_mask, ".");
    }
}

int main() {
    char ip_address[16];
    int num_hosts;

    printf("Enter IP address: ");
    scanf("%s", ip_address);

    printf("Enter number of hosts: ");
    scanf("%d", &num_hosts);

    int num_octets = 0;
    char *octet = strtok(ip_address, ".");
    while (octet != NULL && num_octets < 4) {
        num_octets++;
        int octet_val = atoi(octet);
        if (octet_val < 0 || octet_val > 255) {
            printf("Invalid IP address!\n");
            return 1;
        }

        octet = strtok(NULL, ".");
    }

    if (num_octets != 4) {
        printf("Invalid IP address!\n");
        return 1;
    }

    char subnet_mask[16] = "255.255.255.0";
    calculateSubnetMask(num_hosts, subnet_mask);
    printf("Subnet mask: %s\n", subnet_mask);

    return 0;
}