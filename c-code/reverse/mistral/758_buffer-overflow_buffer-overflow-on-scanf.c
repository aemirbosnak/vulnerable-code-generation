#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

void hexToDec(char hex[]) {
    int decimal = 0, i = 0, power = 1;

    for (; hex[i] != '\0'; i++) {
        if (!isxdigit(hex[i])) {
            printf("Invalid input. Please enter a valid hexadecimal number.\n");
            return;
        }

        decimal += (isdigit(hex[i]) ? (hex[i] - '0') : (hex[i] - 'A' + 10)) * power;
        power *= 16;
    }

    printf("Decimal: %d\n", decimal);
}

void decToHex(int decimal) {
    char hex[32];
    int i = 0, remainder;

    for (; decimal != 0; decimal /= 16, i++) {
        remainder = decimal % 16;
        hex[i] = remainder < 10 ? remainder + '0' : remainder + 'A' - 10;
    }

    for (--i; i >= 0; i--) {
        printf("%c", hex[i]);
    }
    printf("\n");
}

int main() {
    char input[MAX_INPUT_LENGTH];
    int choice, decimal;

    printf("Hexadecimal to Decimal or Decimal to Hexadecimal? (1/2)\n");
    scanf("%d", &choice);

    if (choice < 1 || choice > 2) {
        printf("Invalid input. Please enter 1 or 2.\n");
        return 1;
    }

    printf("Enter the number: ");
    scanf("%s", input);

    if (choice == 1) {
        hexToDec(input);
    } else {
        decimal = atoi(input);
        decToHex(decimal);
    }

    return 0;
}
