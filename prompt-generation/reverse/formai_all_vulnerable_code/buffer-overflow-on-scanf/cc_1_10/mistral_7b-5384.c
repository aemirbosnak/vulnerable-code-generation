//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BINARY_LENGTH 32
#define MAX_DECIMAL_LENGTH 11

void binary_to_decimal(char binary[MAX_BINARY_LENGTH]) {
    int decimal = 0;
    int power = 0;

    for (int i = strlen(binary) - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += pow(2, power);
        }
        power++;
    }

    printf("Decimal equivalent: %d\n", decimal);
}

void decimal_to_binary(int decimal) {
    char binary[MAX_BINARY_LENGTH];
    int index = 0;
    int decimalCopy = decimal;

    while (decimalCopy > 0) {
        binary[index++] = decimal % 2 + '0';
        decimal /= 2;
    }

    for (int i = index; i < MAX_BINARY_LENGTH; i++) {
        binary[i] = '0';
    }

    printf("Binary equivalent: %s\n", binary);
}

int main() {
    int choice, decimal;
    char binary[MAX_BINARY_LENGTH];

    do {
        printf("\n1. Decimal to Binary\n");
        printf("2. Binary to Decimal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter decimal number: ");
                scanf("%d", &decimal);
                decimal_to_binary(decimal);
                break;
            case 2:
                printf("Enter binary number: ");
                scanf("%s", binary);
                binary_to_decimal(binary);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}