//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Function to check if the entered IP address is valid
int checkIP(char *ip) {
    char *token;
    int count = 0;

    token = strtok(ip, ".");

    while (token != NULL) {
        count++;
        int num = atoi(token);

        if (num < 0 || num > 255) {
            printf("Invalid IP Address\n");
            return 0;
        }

        token = strtok(NULL, ".");
    }

    if (count != 4) {
        printf("Invalid IP Address\n");
        return 0;
    }

    return 1;
}

//Function to calculate the subnet mask
void calculateSubnetMask(int subnet_mask, int *subnet) {
    int binary[32];
    int i, j;

    for (i = 0; i < 32; i++) {
        if (i < subnet_mask) {
            binary[i] = 1;
        }
        else {
            binary[i] = 0;
        }
    }

    for (i = 0, j = 7; i < 32; i++) {
        if (i % 8 == 0 && i != 0) {
            j += 8;
        }
        subnet[j - i] += binary[i] * pow(2, (i % 8));
    }
}

int main() {
    char ip_address[16];
    int subnet_mask;
    int subnet[4] = {0, 0, 0, 0};
    int i;

    printf("Enter the IP Address (xxx.xxx.xxx.xxx): ");
    scanf("%s", ip_address);

    if (checkIP(ip_address) == 0) {
        return 0;
    }

    printf("Enter the Subnet Mask (0 to 32): ");
    scanf("%d", &subnet_mask);

    printf("\n");

    calculateSubnetMask(subnet_mask, subnet);

    printf("Subnet Mask: %d.%d.%d.%d\n", subnet[0], subnet[1], subnet[2], subnet[3]);

    return 0;
}