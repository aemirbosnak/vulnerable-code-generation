//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 32

// Function to convert decimal to binary
void decimalToBinary(int decimal, char *binary) {
    int index = 0;

    // Handle the case of decimal 0 explicitly
    if (decimal == 0) {
        binary[index++] = '0';
        binary[index] = '\0';
        return;
    }

    while (decimal > 0) {
        // Store the remainder in reverse order
        binary[index++] = (decimal % 2) + '0';
        decimal /= 2;
    }
    binary[index] = '\0';

    // Reverse the binary string
    for (int i = 0; i < index / 2; i++) {
        char temp = binary[i];
        binary[i] = binary[index - i - 1];
        binary[index - i - 1] = temp;
    }
}

// Function to convert binary string to decimal
int binaryToDecimal(const char *binary) {
    int decimal = 0;
    int base = 1; // Represents 2^0

    for (int i = strlen(binary) - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += base;
        }
        base *= 2; // Move to the next bit's value
    }

    return decimal;
}

// Function to display the menu
void displayMenu() {
    printf("Binary Converter\n");
    printf("=================\n");
    printf("1. Convert Decimal to Binary\n");
    printf("2. Convert Binary to Decimal\n");
    printf("3. Exit\n");
    printf("Choose an option (1-3): ");
}

// Main function
int main() {
    int choice;
    char binary[MAX_INPUT_SIZE];
    int decimal;
    
    do {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &decimal);
                if (decimal < 0) {
                    printf("Please enter a non-negative integer.\n");
                } else {
                    decimalToBinary(decimal, binary);
                    printf("Binary representation: %s\n\n", binary);
                }
                break;

            case 2:
                printf("Enter a binary number: ");
                scanf("%s", binary);
                // Validate binary input
                for (int i = 0; i < strlen(binary); i++) {
                    if (binary[i] != '0' && binary[i] != '1') {
                        printf("Invalid binary input. Please enter a valid binary number.\n\n");
                        goto end_of_case;
                    }
                }
                decimal = binaryToDecimal(binary);
                printf("Decimal representation: %d\n\n", decimal);

                end_of_case:
                break;

            case 3:
                printf("Exiting the program. Thank you!\n");
                break;

            default:
                printf("Invalid choice. Please choose a valid option.\n\n");
                break;
        }
    } while (choice != 3);

    return 0;
}