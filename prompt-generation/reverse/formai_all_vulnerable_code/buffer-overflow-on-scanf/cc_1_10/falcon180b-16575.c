//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to remove leading zeros from a string
void remove_leading_zeros(char* str) {
    int i = 0;
    while (str[i] == '0' && str[i]!= '\0') {
        str[i] = str[i + 1];
        i++;
    }
}

// Function to convert decimal to hexadecimal
void decimal_to_hexadecimal(int decimal, char* hexadecimal) {
    int i = 0;
    int remainder;

    // Handle negative numbers
    if (decimal < 0) {
        hexadecimal[i++] = '-';
        decimal = -decimal;
    }

    // Convert decimal to hexadecimal
    while (decimal!= 0) {
        remainder = decimal % 16;
        if (remainder < 10) {
            hexadecimal[i++] = remainder + 48;
        } else {
            hexadecimal[i++] = remainder + 55;
        }
        decimal /= 16;
    }

    // Reverse the hexadecimal string
    for (int j = 0; j < i / 2; j++) {
        char temp = hexadecimal[j];
        hexadecimal[j] = hexadecimal[i - j - 1];
        hexadecimal[i - j - 1] = temp;
    }

    // Add leading zeros if necessary
    remove_leading_zeros(hexadecimal);
}

int main() {
    char input[100];
    char output[100];

    // Get user input
    printf("Enter a decimal number: ");
    scanf("%s", input);

    // Convert decimal to hexadecimal
    decimal_to_hexadecimal(atoi(input), output);

    // Print the result
    printf("Hexadecimal: %s\n", output);

    return 0;
}