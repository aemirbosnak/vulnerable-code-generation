//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BINARY_SIZE 100
#define MAX_HEX_SIZE 33

void convert_binary_to_hex(char *binary, char *hex) {
    int i, j;
    char binary_digit;
    hex[0] = '$';
    for (i = 0; binary[i] != '\0'; i++) {
        binary_digit = binary[i];
        hex[i + 1] = '0' + (binary_digit & 0x01);
        if ((i + 1) % 2 == 0) {
            hex[i + 1] = (hex[i + 1] << 4) | (binary_digit >> 3);
        }
    }
    hex[i + 2] = '\0';
}

void convert_hex_to_binary(char *hex, char *binary) {
    int i, j, k, n;
    char hex_digit, binary_digit;

    for (i = strlen(hex) - 1, j = 0; i >= 0; i--) {
        hex_digit = hex[i];
        if ((hex_digit >= '0' && hex_digit <= '9')) {
            binary_digit = hex_digit;
        } else if ((hex_digit >= 'A' && hex_digit <= 'F')) {
            binary_digit = hex_digit - 'A' + 10;
        }

        for (k = 0; k < 4; k++, j++) {
            binary[j] = binary_digit % 2 + '0';
            binary_digit /= 2;
        }
    }

    binary[j] = '\0';
    for (n = strlen(binary) - 1; n >= 0; n--) {
        if (binary[n] != '0') {
            break;
        }
    }

    memmove(binary, binary + n + 1, strlen(binary) - n);
    binary[strlen(binary) - n] = '\0';
}

int main(int argc, char *argv[]) {
    int choice;
    char binary[MAX_BINARY_SIZE], hex[MAX_HEX_SIZE];

    printf("Binary to Hex Converter v1.0\n");
    printf("1. Convert binary to hexadecimal\n");
    printf("2. Convert hexadecimal to binary\n");
    printf("3. Exit\n");

    while (1) {
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter binary number: ");
                scanf("%s", binary);
                convert_binary_to_hex(binary, hex);
                printf("Hexadecimal: %s\n", hex);
                break;

            case 2:
                printf("Enter hexadecimal number: ");
                scanf("%s", hex);
                convert_hex_to_binary(hex, binary);
                printf("Binary: %s\n", binary);
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }

    return 0;
}