//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_INPUT_SIZE 1000
#define MAX_OUTPUT_SIZE 1000

bool is_valid_hex_digit(char c) {
    if (isdigit(c)) {
        return true;
    }
    if (c >= 'A' && c <= 'F') {
        return true;
    }
    if (c >= 'a' && c <= 'f') {
        return true;
    }
    return false;
}

int hex_to_dec(char hex) {
    if (isdigit(hex)) {
        return hex - '0';
    }
    if (hex >= 'A' && hex <= 'F') {
        return hex - 'A' + 10;
    }
    if (hex >= 'a' && hex <= 'f') {
        return hex - 'a' + 10;
    }
    return 0;
}

void dec_to_hex(int dec, char *hex) {
    char temp[10];
    sprintf(temp, "%X", dec);
    strcpy(hex, temp);
}

int main() {
    char input[MAX_INPUT_SIZE];
    char output[MAX_OUTPUT_SIZE];
    int i, j;

    printf("Enter a hexadecimal number: ");
    scanf("%s", input);

    if (strlen(input) > MAX_INPUT_SIZE) {
        printf("Error: Input too long. Please enter a number with at most %d characters.\n", MAX_INPUT_SIZE - 1);
        return 1;
    }

    for (i = 0; i < strlen(input); i++) {
        if (!is_valid_hex_digit(input[i])) {
            printf("Error: Input contains invalid characters. Please enter a valid hexadecimal number.\n");
            return 1;
        }
    }

    for (i = 0, j = strlen(input) - 1; i < j; i++, j--) {
        output[i] = input[j];
    }
    output[i] = '\0';

    printf("Decimal equivalent: ");
    for (i = 0; i < strlen(output); i++) {
        dec_to_hex(hex_to_dec(output[i]), output);
        printf("%s", output);
    }
    printf("\n");

    return 0;
}