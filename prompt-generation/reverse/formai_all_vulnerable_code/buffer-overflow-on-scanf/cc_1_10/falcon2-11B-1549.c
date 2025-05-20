//Falcon2-11B DATASET v1.0 Category: Hexadecimal Converter ; Style: imaginative
#include <stdio.h>
#include <string.h>

// Function to convert decimal number to its hexadecimal representation
void decimalToHex(int decimal, char* hex) {
    // If decimal number is 0, return
    if (decimal == 0) {
        hex[0] = '0';
        hex[1] = '\0';
        return;
    }

    // If decimal number is negative, convert it to positive and return
    if (decimal < 0) {
        decimal = -decimal;
        decimalToHex(decimal, hex);
        decimal = -decimal;
        strcat(hex, " ");
        strcat(hex, "-");
    }

    // Get the remainder of the division of decimal by 16
    int remainder = decimal % 16;

    // Convert remainder to hexadecimal and append it to the result
    if (remainder < 10) {
        hex[0] = remainder + '0';
        hex[1] = '\0';
    } else {
        hex[0] = remainder + 'a' - 10;
        hex[1] = '\0';
    }

    // Get the quotient of the division of decimal by 16
    decimal /= 16;

    // Recursively convert decimal to hexadecimal
    decimalToHex(decimal, hex);
}

// Function to display the hexadecimal representation of a decimal number
void displayHex(int decimal) {
    // Convert decimal to hexadecimal
    char hex[10] = "";
    decimalToHex(decimal, hex);

    // Display the hexadecimal representation
    printf("%s\n", hex);
}

int main() {
    // Get the decimal number from the user
    int decimal;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    // Convert decimal to hexadecimal
    char hex[10] = "";
    decimalToHex(decimal, hex);

    // Display the hexadecimal representation
    printf("%s\n", hex);

    return 0;
}