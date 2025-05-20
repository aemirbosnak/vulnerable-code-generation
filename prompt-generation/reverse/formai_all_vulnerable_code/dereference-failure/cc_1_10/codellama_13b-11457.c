//Code Llama-13B DATASET v1.0 Category: Hexadecimal Converter ; Style: modular
///
/// Hexadecimal Converter
///
/// This program converts hexadecimal numbers to decimal and vice versa.
///

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///
/// Function Declarations
///

void hex_to_dec(char* hex_str);
void dec_to_hex(int dec_num);

///
/// Main Function
///

int main() {
    // Prompt the user to enter a hexadecimal number
    printf("Enter a hexadecimal number: ");
    char hex_str[100];
    fgets(hex_str, 100, stdin);

    // Convert the hexadecimal number to decimal
    hex_to_dec(hex_str);

    // Prompt the user to enter a decimal number
    printf("Enter a decimal number: ");
    int dec_num;
    scanf("%d", &dec_num);

    // Convert the decimal number to hexadecimal
    dec_to_hex(dec_num);

    return 0;
}

///
/// Function Definitions
///

void hex_to_dec(char* hex_str) {
    // Remove the newline character at the end of the string
    hex_str[strlen(hex_str) - 1] = '\0';

    // Convert the hexadecimal number to decimal
    int dec_num = strtol(hex_str, NULL, 16);

    // Print the decimal number
    printf("The decimal equivalent of %s is %d\n", hex_str, dec_num);
}

void dec_to_hex(int dec_num) {
    // Convert the decimal number to hexadecimal
    char hex_str[100];
    sprintf(hex_str, "%x", dec_num);

    // Print the hexadecimal number
    printf("The hexadecimal equivalent of %d is %s\n", dec_num, hex_str);
}