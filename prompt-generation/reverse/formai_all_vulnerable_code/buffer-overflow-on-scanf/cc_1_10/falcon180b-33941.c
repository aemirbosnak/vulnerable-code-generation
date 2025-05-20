//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to convert hexadecimal to decimal
int hexToDecimal(char *hex) {
    int decimal = 0, base = 1;
    int len = strlen(hex);
    for (int i = len - 1; i >= 0; i--) {
        char c = hex[i];
        if (c >= '0' && c <= '9') {
            decimal += c - '0';
        } else if (c >= 'A' && c <= 'F') {
            decimal += c - 'A' + 10;
        } else if (c >= 'a' && c <= 'f') {
            decimal += c - 'a' + 10;
        } else {
            return -1; // invalid character
        }
        base *= 16;
    }
    return decimal;
}

// function to convert decimal to hexadecimal
void decimalToHex(int decimal, char *hex) {
    char hexDigits[] = "0123456789ABCDEF";
    int base = 16;
    int quotient, remainder;
    quotient = decimal / base;
    remainder = decimal % base;
    sprintf(hex, "%c", hexDigits[remainder]);
    if (quotient == 0) {
        return;
    } else {
        sprintf(hex + 2, "%c", hexDigits[quotient]);
        decimalToHex(quotient, hex + 1);
    }
}

int main() {
    char hex[100], decimal[100];
    int choice, decimalValue;

    // prompt user for choice
    printf("Enter 1 to convert hexadecimal to decimal\n");
    printf("Enter 2 to convert decimal to hexadecimal\n");
    scanf("%d", &choice);

    // get user input
    if (choice == 1) {
        printf("Enter a hexadecimal number: ");
        scanf("%s", hex);
        decimalValue = hexToDecimal(hex);
        if (decimalValue!= -1) {
            printf("Decimal equivalent: %d\n", decimalValue);
        }
    } else if (choice == 2) {
        printf("Enter a decimal number: ");
        scanf("%s", decimal);
        decimalToHex(atoi(decimal), hex);
        printf("Hexadecimal equivalent: %s\n", hex);
    } else {
        printf("Invalid choice\n");
    }

    return 0;
}