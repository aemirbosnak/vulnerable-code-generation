//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_SIZE 16
#define BINARY_DIGITS 2
#define HEX_DIGITS 4

void print_binary(int num) {
    char binary[MAX_NUM_SIZE];
    int i;

    for (i = 0; i < MAX_NUM_SIZE; i++) {
        binary[i] = '0';
    }
    binary[MAX_NUM_SIZE - 1] = '\0';

    int j = 0;
    while (num > 0) {
        binary[j++] = (num & 1) + '0';
        num >>= 1;
    }

    printf("Binary: %s\n", binary);
}

void print_hex(int num) {
    char hex[MAX_NUM_SIZE];
    int i;

    for (i = 0; i < MAX_NUM_SIZE; i++) {
        hex[i] = '0';
    }
    hex[MAX_NUM_SIZE - 1] = '\0';

    int j = 0;
    while (num > 0) {
        hex[j++] = (num & 0xF) + '0';
        num >>= 4;
    }

    printf("Hexadecimal: %s\n", hex);
}

int main() {
    int num, choice;

    printf("Enter a decimal number: ");
    scanf("%d", &num);

    printf("1. Convert to binary\n");
    printf("2. Convert to hexadecimal\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            print_binary(num);
            break;
        case 2:
            print_hex(num);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}