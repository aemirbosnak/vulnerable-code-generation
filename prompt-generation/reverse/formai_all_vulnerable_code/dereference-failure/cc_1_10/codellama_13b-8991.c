//Code Llama-13B DATASET v1.0 Category: Binary Converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BINARY_BASE 2
#define HEXADECIMAL_BASE 16
#define OCTAL_BASE 8

void binary_to_hexadecimal(char *binary_str, char *hexadecimal_str) {
    int i, j, k, binary_len, hexadecimal_len;
    char hex_map[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    binary_len = strlen(binary_str);
    hexadecimal_len = (binary_len * HEXADECIMAL_BASE) / BINARY_BASE;
    hexadecimal_str = malloc(hexadecimal_len + 1);

    for (i = 0, j = 0, k = 0; i < binary_len; i += BINARY_BASE, j += HEXADECIMAL_BASE, k++) {
        int binary_value = 0;
        for (int x = 0; x < BINARY_BASE; x++) {
            binary_value += (binary_str[i + x] - '0') * pow(2, x);
        }
        hexadecimal_str[k] = hex_map[binary_value];
    }
    hexadecimal_str[hexadecimal_len] = '\0';
}

void hexadecimal_to_binary(char *hexadecimal_str, char *binary_str) {
    int i, j, k, hexadecimal_len, binary_len;
    char hex_map[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    hexadecimal_len = strlen(hexadecimal_str);
    binary_len = (hexadecimal_len * BINARY_BASE) / HEXADECIMAL_BASE;
    binary_str = malloc(binary_len + 1);

    for (i = 0, j = 0, k = 0; i < hexadecimal_len; i += HEXADECIMAL_BASE, j += BINARY_BASE, k++) {
        int hexadecimal_value = 0;
        for (int x = 0; x < HEXADECIMAL_BASE; x++) {
            hexadecimal_value += (hexadecimal_str[i + x] - '0') * pow(16, x);
        }
        binary_str[k] = hex_map[hexadecimal_value];
    }
    binary_str[binary_len] = '\0';
}

void octal_to_binary(char *octal_str, char *binary_str) {
    int i, j, k, octal_len, binary_len;
    char octal_map[8] = {'0', '1', '2', '3', '4', '5', '6', '7'};

    octal_len = strlen(octal_str);
    binary_len = (octal_len * BINARY_BASE) / OCTAL_BASE;
    binary_str = malloc(binary_len + 1);

    for (i = 0, j = 0, k = 0; i < octal_len; i += OCTAL_BASE, j += BINARY_BASE, k++) {
        int octal_value = 0;
        for (int x = 0; x < OCTAL_BASE; x++) {
            octal_value += (octal_str[i + x] - '0') * pow(8, x);
        }
        binary_str[k] = octal_map[octal_value];
    }
    binary_str[binary_len] = '\0';
}

int main() {
    char binary_str[33];
    char hexadecimal_str[65];
    char octal_str[21];

    printf("Enter a binary number: ");
    fgets(binary_str, 32, stdin);
    binary_to_hexadecimal(binary_str, hexadecimal_str);
    printf("Binary to Hexadecimal: %s\n", hexadecimal_str);
    hexadecimal_to_binary(hexadecimal_str, binary_str);
    printf("Hexadecimal to Binary: %s\n", binary_str);

    printf("Enter an octal number: ");
    fgets(octal_str, 20, stdin);
    octal_to_binary(octal_str, binary_str);
    printf("Octal to Binary: %s\n", binary_str);

    return 0;
}