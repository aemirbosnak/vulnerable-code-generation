//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert a hexadecimal string to an integer
int hex_to_int(char* hex) {
    int decimal = 0;
    int length = strlen(hex);
    for (int i = 0; i < length; i++) {
        char c = tolower(hex[i]);
        if (isdigit(c)) {
            decimal = decimal * 16 + (c - '0');
        } else if (isalpha(c)) {
            decimal = decimal * 16 + (c - 'a' + 10);
        } else {
            return -1;
        }
    }
    return decimal;
}

// Function to convert an integer to a hexadecimal string
void int_to_hex(int decimal, char* hex, int length) {
    if (decimal == 0) {
        strcpy(hex, "0");
        return;
    }
    char buffer[32];
    sprintf(buffer, "%x", decimal);
    strcpy(hex, buffer);
}

// Recursive function to convert a hexadecimal string to a binary string
void hex_to_binary(char* hex, char* binary) {
    int decimal = hex_to_int(hex);
    if (decimal == -1) {
        strcpy(binary, "Invalid hexadecimal string");
        return;
    }
    int length = strlen(hex);
    int binary_length = length * 4;
    char* buffer = malloc(binary_length + 1);
    int_to_hex(decimal, buffer, binary_length);
    strcpy(binary, buffer);
    free(buffer);
}

int main() {
    char hex[32];
    char binary[64];
    printf("Enter a hexadecimal string: ");
    scanf("%s", hex);
    hex_to_binary(hex, binary);
    printf("Binary representation: %s\n", binary);
    return 0;
}