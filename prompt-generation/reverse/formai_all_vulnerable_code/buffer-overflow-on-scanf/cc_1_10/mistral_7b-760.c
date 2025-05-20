//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: careful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void binary_to_decimal(char *binary) {
    int decimal = 0;
    int weight = 1;

    // Iterate through each digit in the binary number
    for (int i = strlen(binary) - 1; i >= 0; i--) {
        // Check if the current digit is a '0' or '1'
        if (binary[i] == '0') {
            decimal += weight;
        }

        // Update the weight for the next digit
        weight *= 2;
    }

    printf("Decimal: %d\n", decimal);
}

void binary_to_hexadecimal(char *binary) {
    int decimal = 0;

    // Convert binary to decimal first
    binary_to_decimal(binary);

    // Convert decimal to hexadecimal
    int digits[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    char hex[3];

    // Iterate through each nibble in the decimal number
    for (int i = 0; decimal > 0; i++) {
        // Find the corresponding hexadecimal digit for the current nibble
        int digit = decimal % 16;

        // Convert the digit to a character and append it to the hexadecimal string
        if (digit < 10) {
            hex[i] = digits[digit] + '0';
        } else {
            hex[i] = digits[digit] + 55;
        }

        // Update the decimal number for the next nibble
        decimal /= 16;
    }

    // Reverse the hexadecimal string and print it out
    for (int i = 2; i >= 0; i--) {
        printf("%c", hex[i]);
    }
    printf("\n");
}

int main() {
    char binary[10];

    printf("Enter a binary number: ");
    scanf("%s", binary);

    // Convert binary to decimal and hexadecimal
    binary_to_hexadecimal(binary);

    return 0;
}