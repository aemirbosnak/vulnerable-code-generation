//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hexToDecimal();
void decimalToHex();

int main() {
    int option;

    while(1) {
        printf("1. Convert hexadecimal to decimal\n");
        printf("2. Convert decimal to hexadecimal\n");
        printf("3. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch(option) {
            case 1: hexToDecimal();
                    break;

            case 2: decimalToHex();
                    break;

            case 3: exit(0);

            default: printf("Invalid option!\n");
        }
    }

    exit(0);
}

void hexToDecimal() {
    char hex[17];
    int decimal = 0, i, val, len;

    printf("Enter the hexadecimal number: ");
    scanf("%s", hex);

    len = strlen(hex);

    for(i = 0; hex[i] != '\0'; i++) {

        if(hex[i] >= '0' && hex[i] <= '9') {
            val = hex[i] - 48;
        }

        else if(hex[i] >= 'a' && hex[i] <= 'f') {
            val = hex[i] - 97 + 10;
        }

        else if(hex[i] >= 'A' && hex[i] <= 'F') {
            val = hex[i] - 65 + 10;
        }

        decimal += val * pow(16, len - 1);
        len--;
    }

    printf("The decimal value of %s is %d\n", hex, decimal);
}

void decimalToHex() {
    int decimal, quotient, remainder, i = 1, j;
    char hexadecimal[100];

    printf("Enter the decimal number: ");
    scanf("%d", &decimal);

    quotient = decimal;

    while(quotient != 0) {
        remainder = quotient % 16;

        if(remainder < 10) {
            hexadecimal[i++] = 48 + remainder;
        }

        else {
            hexadecimal[i++] = 55 + remainder;
        }

        quotient = quotient / 16;
    }

    printf("The hexadecimal value of %d is ", decimal);

    for(j = i - 1; j > 0; j--) {
        printf("%c", hexadecimal[j]);
    }

    printf("\n");
}