//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decimalToBinary(int num, char *result) {
    int index = 0;
    if (num == 0) {
        result[index++] = '0';
    } else {
        while (num > 0) {
            result[index++] = (num % 2) + '0';
            num /= 2;
        }
    }
    result[index] = '\0';
    
    // Reverse the string to get the correct binary representation
    for (int i = 0; i < index / 2; i++) {
        char temp = result[i];
        result[i] = result[index - i - 1];
        result[index - i - 1] = temp;
    }
}

void binaryToDecimal(const char *binary, int *result) {
    *result = 0;
    int length = strlen(binary);
    for (int i = 0; i < length; i++) {
        if (binary[length - 1 - i] == '1') {
            *result += (1 << i);
        }
    }
}

void printMenu() {
    printf("\nMind-Bending Binary Converter\n");
    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");
    printf("3. Exit\n");
}

int main() {
    int choice;
    char input[65]; // Buffer for binary input (64 bits + null terminator)
    char binaryResult[65]; // Buffer for binary representation
    int decimalResult;

    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                int decimalNumber;
                scanf("%d", &decimalNumber);
                decimalToBinary(decimalNumber, binaryResult);
                printf("The binary representation of %d is %s\n", decimalNumber, binaryResult);
                break;

            case 2:
                printf("Enter a binary number: ");
                scanf("%s", input);
                
                // Validation: Check if the input is a valid binary number
                int isValid = 1;
                for (int i = 0; input[i] != '\0'; i++) {
                    if (input[i] != '0' && input[i] != '1') {
                        isValid = 0;
                        break;
                    }
                }
                
                if (!isValid) {
                    printf("Error: Invalid binary number!\n");
                } else {
                    binaryToDecimal(input, &decimalResult);
                    printf("The decimal representation of %s is %d\n", input, decimalResult);
                }
                break;

            case 3:
                printf("Exiting the Mind-Bending Binary Converter...\n");
                break;

            default:
                printf("Error: Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}