//MISTRAL-7B DATASET v1.0 Category: Subnet Calculator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_IP_ADDRESS_LENGTH 16
#define BINARY_LENGTH 32

void binary_string_from_decimal(unsigned char ip[4], unsigned char binary[BINARY_LENGTH]) {
    int i;
    for (i = 0; i < 4; i++) {
        int num = ip[i];
        int j;
        for (j = 0; j < 8; j++) {
            binary[BINARY_LENGTH - i - 1 - j / 8 - ((j % 8) > 0 ? 1 : 0)] = (num >> j) & 1;
        }
    }
}

void print_binary(unsigned char binary[BINARY_LENGTH]) {
    int i;
    for (i = 0; i < BINARY_LENGTH; i++) {
        printf("%c", (binary[i] > 0 ? '1' : '0'));
        if ((i + 1) % 8 == 0 || i == BINARY_LENGTH - 1)
            printf(" ");
    }
    printf("|");
}

void process_input() {
    char ip_str[MAX_IP_ADDRESS_LENGTH], mask_str[MAX_IP_ADDRESS_LENGTH];
    unsigned char ip[4], mask[4];
    unsigned char binary_ip[BINARY_LENGTH], binary_mask[BINARY_LENGTH];
    int i, j;

    printf("Enter IP address (e.g., 192.168.1.1): ");
    scanf("%s", ip_str);

    sscanf(ip_str, "%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);

    printf("Enter subnet mask (e.g., 255.255.255.0): ");
    scanf("%s", mask_str);

    sscanf(mask_str, "%d.%d.%d.%d", &mask[0], &mask[1], &mask[2], &mask[3]);

    binary_string_from_decimal(ip, binary_ip);
    binary_string_from_decimal(mask, binary_mask);

    printf("\nIP address binary representation:\n");
    print_binary(binary_ip);
    printf("\n");

    printf("Subnet mask binary representation:\n");
    print_binary(binary_mask);
    printf("\n");

    // Calculate subnet address
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 8; j++) {
            if (binary_mask[BINARY_LENGTH - i - 1 - j / 8 - ((j % 8) > 0 ? 1 : 0)] == 1) {
                ip[i] |= (binary_ip[BINARY_LENGTH - i - 1 - j / 8] << j);
                break;
            }
        }
    }

    printf("Subnet address binary representation:\n");
    print_binary(binary_ip);
    printf("\n");

    // Calculate broadcast address
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 8; j++) {
            if (binary_mask[BINARY_LENGTH - i - 1 - j / 8 - ((j % 8) > 0 ? 1 : 0)] == 1) {
                ip[i] |= ~(binary_ip[BINARY_LENGTH - i - 1 - j / 8] << j);
                break;
            }
        }
    }

    printf("Broadcast address binary representation:\n");
    print_binary(binary_ip);
    printf("\n");
}

int main() {
    process_input();
    return 0;
}