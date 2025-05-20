//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal to hexadecimal
void decimalToHexadecimal(int decimal, char hexadecimal[]) {
    int i = 0;
    char hex[] = "0123456789ABCDEF";

    // Iterate until the decimal number becomes 0
    while (decimal!= 0) {
        // Get the remainder when divided by 16
        int remainder = decimal % 16;

        // If remainder is less than 10, append it to the hexadecimal string
        if (remainder < 10) {
            hexadecimal[i] = remainder + '0';
        }
        // If remainder is greater than or equal to 10, append the corresponding hexadecimal character
        else {
            hexadecimal[i] = hex[remainder];
        }

        // Move to the next position in the hexadecimal string
        i++;

        // Divide decimal by 16 and update its value
        decimal /= 16;
    }

    // Reverse the hexadecimal string
    for (int j = 0; j < strlen(hexadecimal) / 2; j++) {
        char temp = hexadecimal[j];
        hexadecimal[j] = hexadecimal[strlen(hexadecimal) - j - 1];
        hexadecimal[strlen(hexadecimal) - j - 1] = temp;
    }

    // Append null terminator
    hexadecimal[strlen(hexadecimal)] = '\0';
}

int main() {
    int decimal;
    char hexadecimal[100];

    // Get decimal input from user
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    // Convert decimal to hexadecimal
    decimalToHexadecimal(decimal, hexadecimal);

    // Print the hexadecimal representation
    printf("Hexadecimal representation: %s\n", hexadecimal);

    return 0;
}