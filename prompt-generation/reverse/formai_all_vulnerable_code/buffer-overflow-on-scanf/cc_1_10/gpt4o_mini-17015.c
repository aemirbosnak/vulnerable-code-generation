//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 50

void decimalToBinary(int n) {
    if (n == 0) {
        printf("Binary: 0\n");
        return;
    }

    char binary[32];
    int index = 0;

    while (n > 0) {
        binary[index++] = (n % 2) + '0'; // Store the remainder in binary format
        n /= 2;
    }
    binary[index] = '\0'; // Null-terminate the string

    // Print the binary string in reverse order
    printf("Binary: ");
    for (int i = index - 1; i >= 0; i--) {
        putchar(binary[i]);
    }
    putchar('\n');
}

void binaryToDecimal(const char* binary) {
    int decimal = 0;
    int base = 1; // Initialize base value to 1
    int length = strlen(binary);

    for (int i = length - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += base;
        }
        base *= 2; // Move to the next base
    }

    printf("Decimal: %d\n", decimal);
}

void displayMenu() {
    printf("Welcome to the Binary Converter!\n");
    printf("Please choose an option:\n");
    printf("1. Convert Decimal to Binary\n");
    printf("2. Convert Binary to Decimal\n");
    printf("3. Exit\n");
}

int main() {
    int choice;
    char binaryInput[MAX_INPUT_LENGTH];

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                int decimalInput;
                printf("Enter a decimal number: ");
                scanf("%d", &decimalInput);
                decimalToBinary(decimalInput);
                break;
            }
            
            case 2: {
                printf("Enter a binary number: ");
                scanf("%s", binaryInput);

                // Validate binary input
                int valid = 1;
                for (int i = 0; i < strlen(binaryInput); i++) {
                    if (binaryInput[i] != '0' && binaryInput[i] != '1') {
                        valid = 0;
                        break;
                    }
                }
                
                if (valid) {
                    binaryToDecimal(binaryInput);
                } else {
                    printf("Invalid binary number! Please use only 0s and 1s.\n");
                }
                break;
            }

            case 3:
                printf("Thank you for using the Binary Converter. Goodbye!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice! Please select an option from the menu.\n");
                break;
        }

        printf("\n");
    }

    return 0;
}