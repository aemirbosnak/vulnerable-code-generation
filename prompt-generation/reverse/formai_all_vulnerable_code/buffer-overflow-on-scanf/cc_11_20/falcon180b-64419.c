//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char *name;
    int value;
} BinaryDigit;

BinaryDigit binaryDigits[] = {
    {"One", 1},
    {"Two", 2},
    {"Three", 3},
    {"Four", 4},
    {"Five", 5},
    {"Six", 6},
    {"Seven", 7},
    {"Eight", 8},
    {"Nine", 9},
    {"Zero", 0}
};

int main() {

    int decimalNumber = 0;
    char binaryNumber[100];
    int i, j, k;
    bool isDecimal = true;

    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    if (decimalNumber < 0) {
        printf("Invalid input: Decimal number must be non-negative.\n");
        return 1;
    }

    for (i = 0; i < 10; i++) {
        if (decimalNumber % 10 == i) {
            strcat(binaryNumber, "One");
            decimalNumber /= 10;
        } else if (decimalNumber % 10 == 2 * i + 1) {
            strcat(binaryNumber, "Two");
            decimalNumber /= 10;
        } else if (decimalNumber % 10 == 2 * i + 2) {
            strcat(binaryNumber, "Three");
            decimalNumber /= 10;
        } else if (decimalNumber % 10 == 2 * i + 3) {
            strcat(binaryNumber, "Four");
            decimalNumber /= 10;
        } else if (decimalNumber % 10 == 2 * i + 4) {
            strcat(binaryNumber, "Five");
            decimalNumber /= 10;
        } else if (decimalNumber % 10 == 2 * i + 5) {
            strcat(binaryNumber, "Six");
            decimalNumber /= 10;
        } else if (decimalNumber % 10 == 2 * i + 6) {
            strcat(binaryNumber, "Seven");
            decimalNumber /= 10;
        } else if (decimalNumber % 10 == 2 * i + 7) {
            strcat(binaryNumber, "Eight");
            decimalNumber /= 10;
        } else if (decimalNumber % 10 == 2 * i + 8) {
            strcat(binaryNumber, "Nine");
            decimalNumber /= 10;
        } else if (decimalNumber % 10 == 2 * i + 9) {
            strcat(binaryNumber, "Zero");
            decimalNumber /= 10;
        }
    }

    printf("Binary number: %s\n", binaryNumber);

    return 0;
}