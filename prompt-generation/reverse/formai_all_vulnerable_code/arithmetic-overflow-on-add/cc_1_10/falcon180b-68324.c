//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_HEX_DIGITS 8
#define MAX_HEX_STRING_LENGTH (MAX_HEX_DIGITS * 2 + 1)

bool is_valid_hex_character(char c) {
    if (isdigit(c)) {
        return true;
    } else if (isupper(c)) {
        return (c >= 'A' && c <= 'F');
    } else if (islower(c)) {
        return (c >= 'a' && c <= 'f');
    } else {
        return false;
    }
}

int hex_to_decimal(char *hex_str) {
    int decimal_value = 0;
    int i = 0;
    while (i < strlen(hex_str)) {
        char c = hex_str[i];
        if (isdigit(c)) {
            decimal_value = (decimal_value * 16) + (c - '0');
        } else {
            decimal_value = (decimal_value * 16) + (c - 'A' + 10);
        }
        i++;
    }
    return decimal_value;
}

void decimal_to_hex(int decimal_value, char *hex_str) {
    sprintf(hex_str, "%X", decimal_value);
}

int main() {
    char hex_str[MAX_HEX_STRING_LENGTH];
    int decimal_value;

    printf("Enter a hexadecimal number: ");
    fgets(hex_str, MAX_HEX_STRING_LENGTH, stdin);
    hex_str[strcspn(hex_str, "\n")] = '\0';

    if (strlen(hex_str) == 0) {
        printf("Error: Empty input\n");
        return 1;
    }

    bool is_valid_hex = true;
    for (int i = 0; i < strlen(hex_str); i++) {
        if (!is_valid_hex_character(hex_str[i])) {
            is_valid_hex = false;
            break;
        }
    }

    if (!is_valid_hex) {
        printf("Error: Invalid hexadecimal number\n");
        return 1;
    }

    decimal_value = hex_to_decimal(hex_str);
    printf("Decimal equivalent: %d\n", decimal_value);

    return 0;
}