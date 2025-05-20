//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BITS 32

// Function Prototype
void convertToBinary(unsigned int num, char *binaryStr);
void printBinaryTable(int num);
void takeUserInput();

// Main function
int main() {
    printf("Welcome to the Binary Converter Program!\n");
    printf("You can convert a decimal number to binary and see a table of binary values.\n\n");

    // Take input from the user
    takeUserInput();

    return 0;
}

// Function to convert decimal to binary
void convertToBinary(unsigned int num, char *binaryStr) {
    for (int i = MAX_BITS - 1; i >= 0; i--) {
        binaryStr[i] = (num & 1) ? '1' : '0';
        num >>= 1;
    }
    binaryStr[MAX_BITS] = '\0'; // Null-terminate the string
}

// Function to print a binary table for numbers from 0 to a specified number
void printBinaryTable(int num) {
    printf("\nDecimal\t|  Binary\n");
    printf("-----------------------\n");
    for (int i = 0; i <= num; i++) {
        char binaryStr[MAX_BITS + 1]; // +1 for the null terminator
        convertToBinary(i, binaryStr);
        printf("%d\t|  %s\n", i, binaryStr);
    }
}

// Function to take user input and handle it
void takeUserInput() {
    int choice;
    unsigned int number;

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Convert a single number to binary\n");
        printf("2. Display a binary table from 0 to n\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        
        // Ensuring valid input
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number between 1 and 3.\n");
            while (getchar() != '\n'); // clear invalid input
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                if (scanf("%u", &number) == 1) {
                    char binaryStr[MAX_BITS + 1];
                    convertToBinary(number, binaryStr);
                    printf("Decimal: %u => Binary: %s\n", number, binaryStr);
                } else {
                    printf("Invalid input! Please enter a valid decimal number.\n");
                    while (getchar() != '\n'); // clear invalid input
                }
                break;

            case 2:
                printf("Enter the maximum number to display in the table: ");
                if (scanf("%u", &number) == 1) {
                    printBinaryTable(number);
                } else {
                    printf("Invalid input! Please enter a valid decimal number.\n");
                    while (getchar() != '\n'); // clear invalid input
                }
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice! Please choose between 1 and 3.\n");
                break;
        }
    }
}