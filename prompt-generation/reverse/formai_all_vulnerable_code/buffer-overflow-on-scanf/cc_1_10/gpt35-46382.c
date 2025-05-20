//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_DIGITS 100

void convert_decimal_to_hexadecimal(int decimal_number);
void convert_hexadecimal_to_decimal(char* hexadecimal_number);

int main() {
    int choice;
    printf("1. Convert a decimal number to hexadecimal\n");
    printf("2. Convert a hexadecimal number to decimal\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        int decimal_number;
        printf("Enter a decimal number: ");
        scanf("%d", &decimal_number);
        printf("The hexadecimal equivalent of %d is: ", decimal_number);
        convert_decimal_to_hexadecimal(decimal_number);
    } else if (choice == 2) {
        char hexadecimal_number[MAX_DIGITS];
        printf("Enter a hexadecimal number: ");
        scanf("%s", hexadecimal_number);
        convert_hexadecimal_to_decimal(hexadecimal_number);
    } else {
        printf("Invalid choice. Please enter either 1 or 2.");
    }

    return 0;
}

void convert_decimal_to_hexadecimal(int decimal_number) {
    char hexadecimal_number[MAX_DIGITS];
    int remainder;
    int i = 0;
    while (decimal_number != 0) {
        remainder = decimal_number % 16;
        if (remainder < 10) {
            hexadecimal_number[i] = remainder + '0';
        } else {
            hexadecimal_number[i] = remainder + 55;
        }
        i++;
        decimal_number /= 16;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexadecimal_number[j]);
    }
}

void convert_hexadecimal_to_decimal(char* hexadecimal_number) {
    int decimal_number = 0;
    int length = strlen(hexadecimal_number);
    for (int i = 0; i < length; i++) {
        if (isalpha(hexadecimal_number[i])) {
            decimal_number = decimal_number * 16 + (toupper(hexadecimal_number[i]) - 55);
        } else {
            decimal_number = decimal_number * 16 + (hexadecimal_number[i] - '0');
        }
    }
    printf("The decimal equivalent of %s is: %d", hexadecimal_number, decimal_number);
}