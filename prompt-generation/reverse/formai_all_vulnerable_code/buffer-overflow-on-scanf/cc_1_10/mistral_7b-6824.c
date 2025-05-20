//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BINARY_SIZE 32

void binary_to_decimal(char binary[]) {
    int decimal = 0;
    int power = 0;

    for (int i = strlen(binary) - 1; i >= 0; i--) {
        if (binary[i] == '1')
            decimal += pow(2, power);

        power++;
    }

    printf("The decimal equivalent of the binary number is: %d\n", decimal);
}

void print_binary(int decimal) {
    char binary[MAX_BINARY_SIZE];
    int index = 0;

    while (decimal > 0) {
        binary[index++] = (decimal % 2) + '0';
        decimal /= 2;
    }

    for (int i = index; i < MAX_BINARY_SIZE; i++)
        binary[i] = '0';

    printf("The binary equivalent of the decimal number is: %s\n", binary);
}

int main() {
    char choice, binary[MAX_BINARY_SIZE];
    int decimal;

    do {
        printf("\nBinary to Decimal Converter\n");
        printf("---------------------------\n");
        printf("1. Convert Binary to Decimal\n");
        printf("2. Convert Decimal to Binary\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Enter the binary number: ");
                scanf("%s", binary);
                binary_to_decimal(binary);
                break;
            case '2':
                printf("Enter the decimal number: ");
                scanf("%d", &decimal);
                print_binary(decimal);
                break;
            case '3':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != '3');

    return 0;
}