//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decimalToBinary(int n, char *binaryStr) {
    if (n == 0) {
        strcpy(binaryStr, "0");
        return;
    }
    
    int index = 0;
    while (n > 0) {
        binaryStr[index++] = (n % 2) + '0';
        n /= 2;
    }
    binaryStr[index] = '\0';

    // Reverse the string to get the correct binary representation
    for (int i = 0; i < index / 2; i++) {
        char temp = binaryStr[i];
        binaryStr[i] = binaryStr[index - i - 1];
        binaryStr[index - i - 1] = temp;
    }
}

void binaryToDecimal(const char *binaryStr, int *decimal) {
    *decimal = 0;
    int len = strlen(binaryStr);
    for (int i = 0; i < len; i++) {
        if (binaryStr[len - 1 - i] == '1') {
            *decimal += (1 << i);
        }
    }
}

int main() {
    char option;
    int number;
    char binaryStr[65]; // Assuming 64 bit integers
    int decimalResult = 0;

    printf("Binary Converter\n");
    printf("===================\n");
    printf("Choose an option:\n");
    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");
    printf("Enter your choice (1/2): ");
    scanf(" %c", &option);

    switch (option) {
        case '1':
            printf("Enter a decimal number: ");
            if (scanf("%d", &number) != 1 || number < 0) {
                fprintf(stderr, "Error: Please enter a valid non-negative integer.\n");
                return EXIT_FAILURE;
            }
            decimalToBinary(number, binaryStr);
            printf("The binary representation of %d is: %s\n", number, binaryStr);
            break;

        case '2':
            printf("Enter a binary number: ");
            scanf("%s", binaryStr);

            // Validate binary input
            for (int i = 0; binaryStr[i] != '\0'; i++) {
                if (binaryStr[i] != '0' && binaryStr[i] != '1') {
                    fprintf(stderr, "Error: Invalid binary number.\n");
                    return EXIT_FAILURE;
                }
            }

            binaryToDecimal(binaryStr, &decimalResult);
            printf("The decimal representation of %s is: %d\n", binaryStr, decimalResult);
            break;

        default:
            fprintf(stderr, "Error: Invalid option selected. Please choose 1 or 2.\n");
            return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}