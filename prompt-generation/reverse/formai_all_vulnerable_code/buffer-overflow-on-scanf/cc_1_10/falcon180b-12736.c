//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 100

typedef struct {
    char hex[MAX_LENGTH];
    int decimal;
} Hex;

void initialize_hex(Hex *hex) {
    hex->hex[0] = '\0';
    hex->decimal = 0;
}

bool is_hex_digit(char c) {
    if (isdigit(c)) {
        return true;
    } else if (c >= 'A' && c <= 'F') {
        return true;
    } else if (c >= 'a' && c <= 'f') {
        return true;
    } else {
        return false;
    }
}

void parse_hex(Hex *hex, char *string) {
    int i = 0;
    while (string[i]!= '\0' && i < MAX_LENGTH - 1) {
        if (is_hex_digit(string[i])) {
            hex->hex[i] = string[i];
            i++;
        } else {
            printf("Invalid hexadecimal string.\n");
            exit(1);
        }
    }
    hex->hex[i] = '\0';
    hex->decimal = strtol(hex->hex, NULL, 16);
}

void print_hex(Hex hex) {
    printf("Hexadecimal: %s\n", hex.hex);
    printf("Decimal: %d\n", hex.decimal);
}

int main() {
    Hex hex;
    initialize_hex(&hex);
    char input[MAX_LENGTH];
    printf("Enter a hexadecimal string: ");
    scanf("%s", input);
    parse_hex(&hex, input);
    print_hex(hex);
    return 0;
}