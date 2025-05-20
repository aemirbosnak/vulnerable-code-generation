//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_HEX_LENGTH 32
#define MAX_BIN_LENGTH (MAX_HEX_LENGTH * 2)
#define MAX_INPUT_LENGTH 100

int main() {
    char hex[MAX_HEX_LENGTH];
    char bin[MAX_BIN_LENGTH];
    char input[MAX_INPUT_LENGTH];
    int i;
    int j;
    int num_chars;
    int input_len;
    int is_valid_hex;
    int is_valid_bin;

    // Prompt user for input
    printf("Enter a hexadecimal number: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    input_len = strlen(input);

    // Remove newline character from input
    input[input_len - 1] = '\0';

    // Check if input is valid hexadecimal
    is_valid_hex = true;
    for (i = 0; i < input_len; i++) {
        if (!isxdigit(input[i])) {
            is_valid_hex = false;
            break;
        }
    }

    // Convert input to hexadecimal
    num_chars = strspn(input, "0123456789abcdefABCDEF");
    if (num_chars!= input_len) {
        printf("Invalid hexadecimal number.\n");
        return 1;
    }
    strncpy(hex, input, num_chars);
    hex[num_chars] = '\0';

    // Convert hexadecimal to binary
    is_valid_bin = true;
    for (i = 0; i < strlen(hex); i++) {
        if (!isxdigit(hex[i])) {
            is_valid_bin = false;
            break;
        }
    }
    if (is_valid_bin) {
        for (i = 0, j = 0; i < strlen(hex); i += 2) {
            char str[3] = { hex[i], hex[i + 1], '\0' };
            int num = strtol(str, NULL, 16);
            sprintf(&bin[j], "%02X", num);
            j += 2;
        }
    } else {
        printf("Invalid hexadecimal number.\n");
        return 1;
    }

    // Print the binary representation
    printf("Binary representation: %s\n", bin);

    return 0;
}