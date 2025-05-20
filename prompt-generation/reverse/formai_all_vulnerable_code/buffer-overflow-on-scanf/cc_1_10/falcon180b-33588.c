//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000

// Function to check if a character is a valid hexadecimal digit
int is_hex_digit(char c) {
    if (isdigit(c)) {
        return 1;
    } else if (c >= 'A' && c <= 'F') {
        return 1;
    } else if (c >= 'a' && c <= 'f') {
        return 1;
    } else {
        return 0;
    }
}

// Function to convert a hexadecimal string to binary
void hex_to_bin(char hex[], char bin[]) {
    int i, j;
    for (i = 0, j = 0; i < strlen(hex); i++) {
        if (is_hex_digit(hex[i])) {
            if (isdigit(hex[i])) {
                bin[j++] = hex[i];
            } else {
                bin[j++] = (hex[i] - 'A' + 10);
            }
        } else {
            printf("Invalid hexadecimal string.\n");
            exit(1);
        }
    }
    bin[j] = '\0';
}

// Function to convert a binary string to hexadecimal
void bin_to_hex(char bin[], char hex[]) {
    int i, j;
    for (i = 0, j = 0; i < strlen(bin); i++) {
        if (isdigit(bin[i])) {
            hex[j++] = bin[i];
        } else {
            hex[j++] = (bin[i] - 'A' + 10);
        }
    }
    hex[j] = '\0';
}

int main() {
    char hex[MAX_LINE_LENGTH], bin[MAX_LINE_LENGTH];
    printf("Enter a hexadecimal string: ");
    scanf("%s", hex);
    hex_to_bin(hex, bin);
    printf("Binary representation: %s\n", bin);
    bin_to_hex(bin, hex);
    printf("Hexadecimal representation: %s\n", hex);
    return 0;
}