//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_NUM_LENGTH 32

/**
 * Converts a binary string to an integer.
 * @param binary The binary string to convert.
 * @param length The length of the binary string.
 * @return The integer representation of the binary string.
 */
int binary_to_int(char *binary, int length) {
    int num = 0;
    for (int i = 0; i < length; i++) {
        if (binary[i] == '1') {
            num += pow(2, length - 1 - i);
        }
    }
    return num;
}

/**
 * Converts an integer to a binary string.
 * @param num The integer to convert.
 * @param length The length of the binary string.
 * @return The binary string representation of the integer.
 */
char *int_to_binary(int num, int length) {
    char *binary = malloc(length + 1);
    int i = 0;
    while (num > 0) {
        if (num % 2 == 1) {
            binary[i++] = '1';
        }
        num /= 2;
    }
    binary[i] = '\0';
    return binary;
}

/**
 * Converts a binary string to a hexadecimal string.
 * @param binary The binary string to convert.
 * @param length The length of the binary string.
 * @return The hexadecimal string representation of the binary string.
 */
char *binary_to_hex(char *binary, int length) {
    char *hex = malloc((length * 2) + 1);
    for (int i = 0; i < length; i++) {
        int num = binary[i] - '0';
        sprintf(&hex[i * 2], "%02x", num);
    }
    hex[length * 2] = '\0';
    return hex;
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <binary_number>\n", argv[0]);
        return 1;
    }

    char *binary = argv[1];
    int length = strlen(binary);

    if (length > MAX_NUM_LENGTH) {
        printf("Error: Binary number is too long.\n");
        return 1;
    }

    int num = binary_to_int(binary, length);
    char *hex = binary_to_hex(binary, length);

    printf("Binary: %s\n", binary);
    printf("Integer: %d\n", num);
    printf("Hexadecimal: %s\n", hex);

    free(hex);
    return 0;
}