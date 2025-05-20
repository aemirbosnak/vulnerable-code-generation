//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function to convert hexadecimal to decimal
int hexToDec(char hex[]) {
    int len = strlen(hex);
    int base = 1;
    int dec = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            dec += (hex[i] - 48) * base;
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F') {
            dec += (hex[i] - 55) * base;
        }
        base *= 16;
    }
    return dec;
}

// function to convert decimal to hexadecimal
void decToHex(int dec) {
    int remainder, quotient;
    char hex[100];
    int i = 0;
    quotient = dec;
    while (quotient != 0) {
        remainder = quotient % 16;
        if (remainder < 10) {
            hex[i++] = 48 + remainder;
        }
        else {
            hex[i++] = 55 + remainder;
        }
        quotient = quotient / 16;
    }
    printf("The hexadecimal number is: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);
    }
}

int main() {
    int choice;
    double number;
    char hex[100];
    int dec;
    printf("Welcome to the C Hexadecimal Converter!\n\n");
    printf("Please choose an option:\n\n");
    printf("1. Convert decimal to hexadecimal\n");
    printf("2. Convert hexadecimal to decimal\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
        printf("\nEnter a decimal number: ");
        scanf("%lf", &number);
        decToHex((int)number);
        break;
    case 2:
        printf("\nEnter a hexadecimal number: ");
        scanf("%s", hex);
        dec = hexToDec(hex);
        printf("The decimal number is: %d", dec);
        break;
    default:
        printf("\nInvalid choice!");
        break;
    }
    printf("\n\nThank you for using the C Hexadecimal Converter!");
    return 0;
}