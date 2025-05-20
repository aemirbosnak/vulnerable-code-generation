//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct {
    char hex[9];
    char bin[33];
} converter;

int main() {
    converter c;
    char input[1000];
    int i, j, k;
    char hex_digits[] = "0123456789ABCDEF";
    bool valid_input = true;

    printf("Enter a hexadecimal number: ");
    fgets(input, 1000, stdin);

    // Check if input is valid hexadecimal
    for (i = 0; i < strlen(input); i++) {
        if (!isxdigit(input[i])) {
            printf("Invalid input. Please enter a valid hexadecimal number.\n");
            valid_input = false;
            break;
        }
    }

    if (valid_input) {
        // Convert hexadecimal to binary
        for (i = 0; i < strlen(input); i++) {
            if (isdigit(input[i])) {
                c.bin[i] = input[i] - '0';
            } else {
                c.bin[i] = toupper(input[i]) - 'A' + 10;
            }
        }

        // Convert binary to hexadecimal
        for (i = strlen(input) - 1, j = 0; i >= 0; i--, j++) {
            k = (int) (c.bin[i] & 0xF);
            c.hex[j] = hex_digits[k];
        }

        printf("Hexadecimal: %s\n", c.hex);
        printf("Binary:     %s\n", c.bin);
    }

    return 0;
}