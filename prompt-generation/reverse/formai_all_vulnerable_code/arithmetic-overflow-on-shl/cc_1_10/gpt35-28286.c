//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sanitize_input(char* input_str); // Function to sanitize IP address input
int get_mask_bits(int subnet_pos); // Function to get number of mask bits based on subnet position

int main()
{
    int subnet_pos;
    char ip_addr[16];
    char subnet_mask[16];
    char subnet_ip[16];
    char wildcard_mask[16];

    printf("Enter an IP address: ");
    fgets(ip_addr, 16, stdin);
    sanitize_input(ip_addr);

    printf("Enter the subnet position (1-32): ");
    scanf("%d", &subnet_pos);
    while (subnet_pos < 1 || subnet_pos > 32) {
        printf("Invalid subnet position! Enter again (1-32): ");
        scanf("%d", &subnet_pos);
    }

    int mask_bits = get_mask_bits(subnet_pos);
    sprintf(subnet_mask, "%d.%d.%d.%d", 255 << (24 - mask_bits) & 255, 255 << (16 - mask_bits) & 255, 255 << (8 - mask_bits) & 255, 255 >> (mask_bits - 8));
    sprintf(wildcard_mask, "%d.%d.%d.%d", ~(255 << (24 - mask_bits) & 255), ~(255 << (16 - mask_bits) & 255), ~(255 << (8 - mask_bits) & 255), 255 << (mask_bits - 8) & 255);
    sprintf(subnet_ip, "%d.%d.%d.%d", atoi(strtok(ip_addr, ".")) & atoi(strtok(NULL, ".")) & atoi(strtok(NULL, ".")) & atoi(strtok(NULL, ".")), (atoi(strtok(ip_addr, ".")) & atoi(strtok(NULL, ".")) & atoi(strtok(NULL, ".")) & atoi(strtok(NULL, "."))) | (1 << (32 - subnet_pos)) - 1);

    printf("\nResults:\n");
    printf("Subnet Mask: %s\n", subnet_mask);
    printf("Wildcard Mask: %s\n", wildcard_mask);
    printf("Subnet IP Address: %s\n\n", subnet_ip);
    return 0;
}

void sanitize_input(char* input_str) {
    int len = strlen(input_str) - 1;
    if (input_str[len] == '\n') {
        input_str[len] = '\0';
    }
}

int get_mask_bits(int subnet_pos) {
    int mask_bits = 0, i;
    for (i = 0; i < subnet_pos; i++) {
        mask_bits |= 1 << (31 - i);
    }
    return mask_bits;
}