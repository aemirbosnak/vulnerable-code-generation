//FormAI DATASET v1.0 Category: Binary Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_BINARY_LENGTH 8

void binaryToDecimal(char binary[], int length) {
    int decimal = 0;
    int index = 0;
    for (int i = length - 1; i >= 0; i--) {
        decimal += (binary[i] - '0') * (1 << index);
        index++;
    }
    printf("Decimal: %d\n", decimal);
}

void decimalToBinary(int decimal) {
    char binary[MAX_BINARY_LENGTH];
    int index = 0;
    while (decimal > 0) {
        binary[index] = (decimal % 2) + '0';
        decimal /= 2;
        index++;
    }
    printf("Binary: ");
    while (index < MAX_BINARY_LENGTH) {
        printf("0");
        index++;
    }
    for (int i = MAX_BINARY_LENGTH - 1; i >= 0; i--) {
        printf("%c", binary[i]);
    }
    printf("\n");
}

int main() {
    int choice = 0;
    int decimal = 0;
    char binary[MAX_BINARY_LENGTH];

    printf("Enter 1 to convert binary to decimal\n");
    printf("Enter 2 to convert decimal to binary\n");
    printf("Enter 3 to exit\n");

    while (choice != 3) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter binary number: ");
                scanf("%s", binary);
                binaryToDecimal(binary, MAX_BINARY_LENGTH);
                break;
            case 2:
                printf("Enter decimal number: ");
                scanf("%d", &decimal);
                decimalToBinary(decimal);
                break;
            case 3:
                break;
            default:
                printf("Invalid choice! Try again.\n");
                break;
        }
    }
    return 0;
}