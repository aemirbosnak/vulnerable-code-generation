//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

int main() {
    char input[MAX_SIZE];
    int length;
    int decimal;
    int binary[MAX_SIZE];
    int i;
    int j;
    int k;
    int base;
    int isNegative;

    // Get user input
    printf("Enter a decimal number: ");
    fgets(input, MAX_SIZE, stdin);
    length = strlen(input);

    // Check for leading plus sign
    if (input[0] == '+') {
        isNegative = 0;
        i = 1;
    } else if (input[0] == '-') {
        isNegative = 1;
        i = 1;
    } else {
        isNegative = 0;
        i = 0;
    }

    // Check for leading zeros
    while (i < length && input[i] == '0') {
        i++;
    }

    // Convert decimal to binary
    decimal = 0;
    j = 0;
    base = 1;
    while (i < length) {
        if (isdigit(input[i])) {
            decimal += (input[i] - '0') * base;
            base *= 10;
        } else {
            printf("Invalid input. Please enter a decimal number.\n");
            return 1;
        }
        i++;
    }

    // Add leading zeros if necessary
    if (isNegative) {
        binary[j++] = '-';
    }
    while (j < 8) {
        binary[j++] = '0';
    }

    // Reverse binary string
    for (k = 0; k < j / 2; k++) {
        char temp = binary[k];
        binary[k] = binary[j - 1 - k];
        binary[j - 1 - k] = temp;
    }

    // Print binary string
    printf("Binary: ");
    for (k = 0; k < j; k++) {
        printf("%c", binary[k]);
    }
    printf("\n");

    return 0;
}