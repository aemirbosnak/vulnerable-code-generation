//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Galactic Constants
#define MAX_BITS 32
#define MAX_BINARY_STRING 33   // 32 bits + 1 for null-terminator

// Function Prototypes
void decimalToBinary(int decimal, char *binary);
void printBinary(char *binary);
void interactiveConversion();

int main() {
    int choice;

    // Welcome to the Galactic Binary Converter
    printf("Welcome to the Galactic Binary Converter!\n");
    printf("Experience the power of conversion in the digital cosmos.\n");

    do {
        printf("\nChoose your action:\n");
        printf("1. Convert Decimal to Binary\n");
        printf("2. Interactive Conversion Mode\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                int decimal;
                char binary[MAX_BINARY_STRING];

                printf("Enter a decimal number (0 to %d): ", (1 << MAX_BITS) - 1);
                scanf("%d", &decimal);

                if(decimal < 0 || decimal >= (1 << MAX_BITS)) {
                    printf("Invalid input! Please enter a number within valid bounds.\n");
                } else {
                    decimalToBinary(decimal, binary);
                    printf("Decimal: %d\n", decimal);
                    printBinary(binary);
                }
                break;
            }
            case 2:
                interactiveConversion();
                break;
            case 3:
                printf("Initiating departure... Thank you for using the Galactic Binary Converter! Safe travels!\n");
                break;
            default:
                printf("Unknown option! Please select again.\n");
        }
    } while(choice != 3);

    return 0;
}

// Convert Decimal to Binary
void decimalToBinary(int decimal, char *binary) {
    int index = MAX_BITS - 1;
    binary[MAX_BITS] = '\0'; // Null-terminate the string

    while(decimal > 0) {
        binary[index--] = (decimal % 2) + '0'; // Convert to char '0' or '1'
        decimal /= 2;
    }

    while(index >= 0) {
        binary[index--] = '0'; // Fill remaining bits with '0'
    }
}

// Print the binary representation
void printBinary(char *binary) {
    printf("Binary Representation: ");
    for (int i = 0; i < MAX_BITS; i++) {
        printf("%c", binary[i]);
        if ((i + 1) % 4 == 0 && i != MAX_BITS - 1) {
            printf(" "); // Add space every 4 bits for clarity
        }
    }
    printf("\n");
}

// Interactive conversion for multiple inputs
void interactiveConversion() {
    int decimal;
    char binary[MAX_BINARY_STRING];

    printf("Entering interactive conversion mode...\n");
    printf("Type your decimal numbers and I will convert them to binary.\n");
    printf("Type '-1' to exit this mode.\n");

    while(1) {
        printf("Enter decimal number: ");
        scanf("%d", &decimal);
        
        if (decimal == -1) {
            printf("Exiting interactive mode. Initiating return to main menu...\n");
            break;
        }
        
        if(decimal < 0 || decimal >= (1 << MAX_BITS)) {
            printf("Invalid input! Please enter a number within valid bounds (0 to %d).\n", (1 << MAX_BITS) - 1);
        } else {
            decimalToBinary(decimal, binary);
            printf("Decimal: %d\n", decimal);
            printBinary(binary);
            printf("\n");
        }
    }
}