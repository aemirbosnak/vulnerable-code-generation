//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_HEX_LENGTH 1000 // Maximum length of a hexadecimal number
#define MAX_DEC_LENGTH 500 // Maximum length of a decimal number

int main() {
    char hex_str[MAX_HEX_LENGTH]; // String to hold hexadecimal input
    char dec_str[MAX_DEC_LENGTH]; // String to hold decimal output
    int decimal; // Variable to hold decimal value
    int i, j, length; // Loop variables
    int valid_hex = 1; // Flag to check if input is a valid hexadecimal number
    
    printf("Enter a hexadecimal number: ");
    fgets(hex_str, MAX_HEX_LENGTH, stdin); // Get input from user
    
    // Check if input is a valid hexadecimal number
    length = strlen(hex_str);
    for (i = 0; i < length; i++) {
        if (!isxdigit(hex_str[i])) { // If the character is not a hexadecimal digit
            printf("Invalid hexadecimal number\n");
            valid_hex = 0;
            break;
        }
    }
    
    if (valid_hex) {
        // Convert hexadecimal to decimal
        decimal = 0;
        for (i = 0; i < length; i++) {
            if (isdigit(hex_str[i])) { // If the character is a digit
                decimal = decimal * 16 + hex_str[i] - '0'; // Convert to decimal
            } else { // If the character is a letter
                decimal = decimal * 16 + hex_str[i] - 'A' + 10; // Convert to decimal
            }
        }
        
        // Convert decimal to hexadecimal
        length = sprintf(dec_str, "%d", decimal); // Get length of decimal number
        i = length - 1;
        while (i >= 0) {
            j = (int) (decimal % 16); // Get remainder when dividing by 16
            if (j < 10) {
                dec_str[i--] = j + '0'; // Convert to decimal digit
            } else {
                dec_str[i--] = j + 'A' - 10; // Convert to hexadecimal letter
            }
            decimal /= 16; // Divide by 16
        }
        
        // Print output
        printf("Decimal equivalent: %s\n", dec_str);
    }
    
    return 0;
}