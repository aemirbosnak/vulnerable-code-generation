//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void binary_to_decimal(char* binary) {
    int decimal = 0;
    int power = 0;
    int length = strlen(binary);

    for (int i = length - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += pow(2, power);
        }
        power++;
    }

    printf("Decimal value: %d\n", decimal);
}

void decimal_to_binary(int decimal) {
    char binary[33];
    int remainder, quotient = decimal;
    int index = 0;

    while (quotient > 0) {
        remainder = quotient % 2;
        binary[index++] = remainder + '0';
        quotient /= 2;
    }

    binary[index] = '\0';
    printf("Binary value: %s\n", binary);
}

int main() {
    char choice;
    int decimal;

    do {
        printf("Enter your choice:\n");
        printf("1. Convert binary to decimal\n");
        printf("2. Convert decimal to binary\n");
        printf("3. Exit\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter a binary number: ");
                scanf("%s", &choice);
                binary_to_decimal(choice);
                break;
            case '2':
                printf("Enter a decimal number: ");
                scanf("%d", &decimal);
                decimal_to_binary(decimal);
                break;
            case '3':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= '3');

    return 0;
}