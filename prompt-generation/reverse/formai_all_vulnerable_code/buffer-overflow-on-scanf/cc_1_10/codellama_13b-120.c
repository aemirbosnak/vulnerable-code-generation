//Code Llama-13B DATASET v1.0 Category: Subnet Calculator ; Style: curious
// Subnet Calculator
#include <stdio.h>
#include <string.h>

int main() {
    char ip[16], mask[16], subnet[16];
    int ip_bin[32], mask_bin[32], subnet_bin[32];
    int i, j, k;

    printf("Enter the IP address: ");
    scanf("%s", ip);

    printf("Enter the subnet mask: ");
    scanf("%s", mask);

    // Convert IP address to binary
    for (i = 0, j = 0; i < strlen(ip); i++) {
        if (ip[i] == '.') {
            ip_bin[j++] = atoi(ip + i + 1);
            ip[i] = 0;
        }
    }
    ip_bin[j] = atoi(ip);

    // Convert subnet mask to binary
    for (i = 0, j = 0; i < strlen(mask); i++) {
        if (mask[i] == '.') {
            mask_bin[j++] = atoi(mask + i + 1);
            mask[i] = 0;
        }
    }
    mask_bin[j] = atoi(mask);

    // Calculate the subnet
    for (i = 0; i < 32; i++) {
        subnet_bin[i] = ip_bin[i] & mask_bin[i];
    }

    // Convert subnet to dotted decimal
    for (i = 0, j = 0, k = 0; i < 32; i++) {
        if (i % 8 == 0 && i != 0) {
            subnet[k++] = '.';
        }
        subnet[k++] = subnet_bin[i] + '0';
    }
    subnet[k] = 0;

    printf("Subnet: %s\n", subnet);

    return 0;
}