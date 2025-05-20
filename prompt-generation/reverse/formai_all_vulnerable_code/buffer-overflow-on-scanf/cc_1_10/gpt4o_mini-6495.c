//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertToBinary(int number, char *binaryRepresentation) {
    for (int i = 31; i >= 0; i--) {
        binaryRepresentation[i] = (number % 2) ? '1' : '0';
        number /= 2;
    }
    binaryRepresentation[32] = '\0'; // Null-terminate the string
}

void displayBinary(const char *binaryRepresentation) {
    printf("Binary representation: ");
    for (int i = 0; i < 32; i++) {
        if (i % 4 == 0 && i != 0) {
            printf(" "); // Print space every 4 bits for better readability
        }
        printf("%c", binaryRepresentation[i]);
    }
    printf("\n");
}

void menu() {
    printf("Welcome to the Binary Converter!\n");
    printf("1. Convert an integer to binary\n");
    printf("2. Convert a binary string to integer\n");
    printf("3. Exit\n");
}

int convertBinaryToDecimal(const char *binaryString) {
    int decimalValue = 0;
    for (int i = 0; i < 32; i++) {
        if (binaryString[i] == '1') {
            decimalValue += (1 << (31 - i));
        }
    }
    return decimalValue;
}

int main() {
    int choice;
    int number;
    char binaryRepresentation[33];
    char binaryInput[33];

    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter an integer: ");
                scanf("%d", &number);
                convertToBinary(number, binaryRepresentation);
                displayBinary(binaryRepresentation);
                break;
            case 2:
                printf("Enter a 32-bit binary string: ");
                scanf("%s", binaryInput);
                if (strlen(binaryInput) != 32) {
                    printf("Invalid binary string! Please enter exactly 32 bits.\n");
                    break;
                }
                int result = convertBinaryToDecimal(binaryInput);
                printf("Decimal value: %d\n", result);
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    } while (choice != 3);

    return 0;
}