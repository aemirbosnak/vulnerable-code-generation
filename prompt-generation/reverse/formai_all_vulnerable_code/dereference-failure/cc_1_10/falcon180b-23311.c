//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void binary_to_decimal(char* binary) {
    int decimal = 0;
    int power = 0;
    int i = strlen(binary) - 1;

    while (binary[i]!= '\0') {
        if (binary[i] == '1') {
            decimal += pow(2, power);
        }
        power++;
        i--;
    }

    printf("Decimal equivalent: %d\n", decimal);
}

void decimal_to_binary(int decimal) {
    char binary[33];
    int i = 0;

    while (decimal > 0) {
        int remainder = decimal % 2;
        binary[i] = remainder + '0';
        decimal /= 2;
        i++;
    }

    binary[i] = '\0';
    printf("Binary equivalent: %s\n", binary);
}

int main() {
    char* input;
    int choice;

    printf("Enter a binary number: ");
    scanf("%s", input);
    binary_to_decimal(input);

    printf("Enter a decimal number: ");
    scanf("%d", &choice);
    decimal_to_binary(choice);

    return 0;
}