//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold decimal value and its binary representation
typedef struct {
    int decimal;
    char binary[32];
} DecimalToBinary;

// Function prototypes
void convertToBinary(DecimalToBinary *dtb);
void displayBinary(const DecimalToBinary *dtb);
void getInput(DecimalToBinary *dtb);
void displayMenu();
void clearBuffer();

int main() {
    DecimalToBinary dtb; // Instance of DecimalToBinary struct
    int choice;

    do {
        displayMenu();
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        clearBuffer(); // Clear input buffer after reading integer choice
        
        switch (choice) {
            case 1:
                getInput(&dtb); // Get user input
                convertToBinary(&dtb); // Convert to binary
                displayBinary(&dtb); // Display result
                break;
            case 2:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 2);

    return 0;
}

// Function to convert decimal to binary
void convertToBinary(DecimalToBinary *dtb) {
    int num = dtb->decimal; // Get the decimal number
    int index = 0; // Index for binary string

    if (num == 0) { // Special case for 0
        strcpy(dtb->binary, "0");
        return;
    }

    while (num > 0) {
        dtb->binary[index++] = (num % 2) + '0'; // Store binary digit
        num /= 2; // Divide by 2
    }
    dtb->binary[index] = '\0'; // Null-terminate the string

    // Reverse the binary string
    for (int i = 0; i < index / 2; i++) {
        char temp = dtb->binary[i];
        dtb->binary[i] = dtb->binary[index - i - 1];
        dtb->binary[index - i - 1] = temp;
    }
}

// Function to display binary result
void displayBinary(const DecimalToBinary *dtb) {
    printf("Decimal: %d --> Binary: %s\n", dtb->decimal, dtb->binary);
}

// Function to get user input with validation
void getInput(DecimalToBinary *dtb) {
    char input[32];
    int isValid = 0;

    while (!isValid) {
        printf("Enter a decimal number (0-2147483647): ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0; // Strip newline

        dtb->decimal = atoi(input); // Convert string to integer

        if (dtb->decimal >= 0 && dtb->decimal <= 2147483647) {
            isValid = 1; // Valid input
        } else {
            printf("Invalid input. Please enter a valid positive integer.\n");
        }
    }
}

// Function to display menu options
void displayMenu() {
    printf("\n==== Decimal to Binary Converter ====\n");
    printf("1. Convert Decimal to Binary\n");
    printf("2. Exit\n");
}

// Function to clear the input buffer
void clearBuffer() {
    while (getchar() != '\n'); // Discard invalid input
}