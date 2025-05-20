//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: innovative
#include <stdio.h>
#include <string.h>

/*
    This program converts a decimal number (base 10) to hexadecimal (base 16).
    The innovative approach here is to use bitwise operations to extract the hexadecimal digits.
*/

// Convert a decimal digit to its corresponding hexadecimal digit (0-9 to 0-9, 10-15 to A-F)
char to_hex_digit(int decimal_digit) {
    if (decimal_digit < 10) {
        return '0' + decimal_digit;
    } else {
        return 'A' + (decimal_digit - 10);
    }
}

int main() {
    // Read in the decimal number to be converted
    int decimal;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    // Convert the decimal number to hexadecimal digit-by-digit using bitwise operations
    char hexadecimal[16] = "";
    int i = 0;
    while (decimal > 0) {
        int digit = decimal & 0xF; // Extract the lowest 4 bits of the decimal number
        hexadecimal[i] = to_hex_digit(digit); // Convert the digit to hexadecimal and store it in the output string
        decimal >>= 4; // Shift the decimal number right by 4 bits (i.e. divide by 16)
        i++;
    }
    if (i == 0) { // Edge case for input 0
        hexadecimal[i] = '0';
        i++;
    }

    // Reverse the order of the hexadecimal digits to get the final output
    int n = strlen(hexadecimal);
    for (int j = 0; j < n / 2; j++) {
        char temp = hexadecimal[j];
        hexadecimal[j] = hexadecimal[n-j-1];
        hexadecimal[n-j-1] = temp;
    }

    // Print out the final hexadecimal number
    printf("Hexadecimal: %s\n", hexadecimal);

    return 0;
}