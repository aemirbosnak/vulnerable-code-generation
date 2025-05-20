//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_HEX_LENGTH 1000

// Function to convert a decimal number to hexadecimal
void dec_to_hex(int decimal, char* hex) {
    char buffer[MAX_HEX_LENGTH];
    int i = 0;
    int j = 0;
    int temp = decimal;

    // Convert decimal to hexadecimal
    while (temp!= 0) {
        int remainder = temp % 16;
        if (remainder < 10) {
            buffer[i] = remainder + '0';
        } else {
            buffer[i] = remainder + 'A' - 10;
        }
        temp /= 16;
        i++;
    }

    // Reverse the hexadecimal string
    for (i = strlen(buffer) - 1, j = 0; i >= 0; i--, j++) {
        hex[j] = buffer[i];
    }
}

// Function to convert a hexadecimal string to decimal
int hex_to_dec(char* hex) {
    int decimal = 0;
    int i = 0;
    int j = strlen(hex) - 1;

    // Convert hexadecimal to decimal
    while (i <= j) {
        if (isdigit(hex[i])) {
            decimal = decimal * 16 + hex[i] - '0';
        } else {
            decimal = decimal * 16 + hex[i] - 'A' + 10;
        }
        i++;
    }

    return decimal;
}

int main() {
    char input[MAX_HEX_LENGTH];
    int decimal;
    int choice;

    printf("Enter a hexadecimal number: ");
    scanf("%s", input);

    // Convert hexadecimal to decimal
    decimal = hex_to_dec(input);

    // Convert decimal to hexadecimal
    char hex[MAX_HEX_LENGTH];
    dec_to_hex(decimal, hex);

    printf("The decimal equivalent of %s is %d.\n", input, decimal);
    printf("The hexadecimal equivalent of %d is %s.\n", decimal, hex);

    printf("Enter 1 to convert another number, or 0 to exit: ");
    scanf("%d", &choice);

    while (choice == 1) {
        printf("Enter a hexadecimal number: ");
        scanf("%s", input);

        // Convert hexadecimal to decimal
        decimal = hex_to_dec(input);

        // Convert decimal to hexadecimal
        dec_to_hex(decimal, hex);

        printf("The decimal equivalent of %s is %d.\n", input, decimal);
        printf("The hexadecimal equivalent of %d is %s.\n", decimal, hex);

        printf("Enter 1 to convert another number, or 0 to exit: ");
        scanf("%d", &choice);
    }

    return 0;
}