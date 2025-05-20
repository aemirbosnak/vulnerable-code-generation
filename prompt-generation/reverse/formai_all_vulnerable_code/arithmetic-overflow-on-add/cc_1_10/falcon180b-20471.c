//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void convert_binary(int decimal);
void convert_octal(int decimal);
void convert_hexadecimal(int decimal);

int main() {
    int decimal, choice;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    printf("Enter the conversion type:\n");
    printf("1. Binary\n");
    printf("2. Octal\n");
    printf("3. Hexadecimal\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            convert_binary(decimal);
            break;
        case 2:
            convert_octal(decimal);
            break;
        case 3:
            convert_hexadecimal(decimal);
            break;
        default:
            printf("Invalid choice.\n");
            return 0;
    }

    return 0;
}

// Function to convert decimal to binary
void convert_binary(int decimal) {
    char binary[33]; // Maximum 32 bits + null terminator
    int i, j;

    i = 0;
    do {
        binary[i] = (decimal % 2) + '0';
        decimal /= 2;
        i++;
    } while (decimal!= 0);

    for (j = i - 1; j >= 0; j--)
        printf("%c", binary[j]);
}

// Function to convert decimal to octal
void convert_octal(int decimal) {
    char octal[11]; // Maximum 8 digits + null terminator
    int i, j;

    i = 0;
    do {
        octal[i] = (decimal % 8) + '0';
        decimal /= 8;
        i++;
    } while (decimal!= 0);

    for (j = i - 1; j >= 0; j--)
        printf("%c", octal[j]);
}

// Function to convert decimal to hexadecimal
void convert_hexadecimal(int decimal) {
    char hexadecimal[9]; // Maximum 8 digits + null terminator
    int i, j;

    i = 0;
    do {
        if (decimal < 10)
            hexadecimal[i] = (decimal + '0');
        else
            hexadecimal[i] = (decimal - 10 + 'A');
        decimal /= 16;
        i++;
    } while (decimal!= 0);

    for (j = i - 1; j >= 0; j--)
        printf("%c", hexadecimal[j]);
}