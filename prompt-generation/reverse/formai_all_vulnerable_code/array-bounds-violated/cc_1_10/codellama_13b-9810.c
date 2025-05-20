//Code Llama-13B DATASET v1.0 Category: Hexadecimal Converter ; Style: asynchronous
// Asynchronous Hexadecimal Converter
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure to store the hexadecimal values and their corresponding characters
struct hex_value {
    char character;
    int value;
};

// Array of all the hexadecimal values and their corresponding characters
struct hex_value hex_values[] = {
    { '0', 0 },
    { '1', 1 },
    { '2', 2 },
    { '3', 3 },
    { '4', 4 },
    { '5', 5 },
    { '6', 6 },
    { '7', 7 },
    { '8', 8 },
    { '9', 9 },
    { 'a', 10 },
    { 'b', 11 },
    { 'c', 12 },
    { 'd', 13 },
    { 'e', 14 },
    { 'f', 15 }
};

// Function to convert a hexadecimal string to its decimal equivalent
int hex_to_dec(char* hex_string) {
    int decimal = 0;
    int multiplier = 1;
    int length = strlen(hex_string);

    for (int i = 0; i < length; i++) {
        char c = hex_string[i];
        if (c >= '0' && c <= '9') {
            decimal += (c - '0') * multiplier;
        } else if (c >= 'a' && c <= 'f') {
            decimal += (c - 'a' + 10) * multiplier;
        }
        multiplier *= 16;
    }

    return decimal;
}

// Function to convert a decimal number to its hexadecimal equivalent
char* dec_to_hex(int decimal) {
    char hex_string[9];
    int index = 8;

    do {
        hex_string[index--] = hex_values[decimal % 16].character;
        decimal /= 16;
    } while (decimal > 0);

    hex_string[9] = '\0';

    return hex_string;
}

// Function to handle the user input and call the appropriate conversion function
void handle_input(char* input) {
    if (input[0] == 'h') {
        printf("Decimal equivalent of %s is %d\n", input + 2, hex_to_dec(input + 2));
    } else if (input[0] == 'd') {
        printf("Hexadecimal equivalent of %s is %s\n", input + 2, dec_to_hex(atoi(input + 2)));
    } else {
        printf("Invalid input\n");
    }
}

// Main function
int main() {
    char input[100];

    while (1) {
        printf("Enter a hexadecimal or decimal number with h or d as the first character: ");
        fgets(input, 100, stdin);
        handle_input(input);
    }

    return 0;
}