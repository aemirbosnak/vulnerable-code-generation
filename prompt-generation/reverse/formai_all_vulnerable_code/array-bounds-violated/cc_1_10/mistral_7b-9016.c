//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BINARY_LENGTH 64

void binary_to_hex(char *binary, char *hex) {
    int i;
    int binary_number[9];
    int j;
    char hex_digits[17] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    for (i = 0; i < 8; i++) {
        binary_number[i] = (binary[i] - '0');
        if (binary[i] > '9')
            binary_number[i] -= 8;
    }

    hex[0] = hex_digits[binary_number[0] >> 4];
    hex[1] = hex_digits[binary_number[0] & 0xF];

    for (i = 1; i < 8; i++) {
        hex[2 + i] = hex_digits[binary_number[i] >> 4];
        hex[3 + i] = hex_digits[binary_number[i] & 0xF];
    }

    hex[16] = '\0';
}

int main(int argc, char *argv[]) {
    int i;
    char binary[MAX_BINARY_LENGTH + 1];
    char hex[17];

    printf("Enter a binary number: ");
    fgets(binary, MAX_BINARY_LENGTH + 1, stdin);

    binary[strcspn(binary, "\n")] = '\0';

    if (strlen(binary) > MAX_BINARY_LENGTH) {
        printf("Error: Binary number is too long.\n");
        return 1;
    }

    binary_to_hex(binary, hex);

    printf("Binary number: %s\n", binary);
    printf("Hexadecimal number: %s\n", hex);

    return 0;
}