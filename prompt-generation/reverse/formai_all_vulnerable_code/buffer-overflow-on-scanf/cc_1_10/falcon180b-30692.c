//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to validate hexadecimal input
int is_hexadecimal(char *input) {
    int i = 0;
    while (input[i]!= '\0') {
        if (!isxdigit(input[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

// Function to convert decimal to hexadecimal
void decimal_to_hexadecimal(int decimal) {
    char hexadecimal[10];
    int i = 0;
    while (decimal!= 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hexadecimal[i++] = remainder + '0';
        } else {
            hexadecimal[i++] = remainder + 'A' - 10;
        }
        decimal /= 16;
    }
    printf("The hexadecimal representation is: %s\n", hexadecimal);
}

// Function to convert hexadecimal to decimal
int hexadecimal_to_decimal(char *hexadecimal) {
    int decimal = 0;
    int i = 0;
    while (hexadecimal[i]!= '\0') {
        if (isdigit(hexadecimal[i])) {
            decimal = decimal * 16 + hexadecimal[i] - '0';
        } else {
            decimal = decimal * 16 + hexadecimal[i] - 'A' + 10;
        }
        i++;
    }
    return decimal;
}

int main() {
    char input[100];
    int decimal;

    printf("Welcome to Sherlock Holmes' Hexadecimal Converter!\n");
    printf("Please enter a hexadecimal number: ");
    scanf("%s", input);

    if (is_hexadecimal(input)) {
        decimal = hexadecimal_to_decimal(input);
        printf("The decimal representation is: %d\n", decimal);
    } else {
        printf("Invalid input. Please enter a valid hexadecimal number.\n");
    }

    return 0;
}