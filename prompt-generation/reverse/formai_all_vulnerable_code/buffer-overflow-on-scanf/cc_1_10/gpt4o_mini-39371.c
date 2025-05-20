//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void displayMenu();
void convertToHex(int decimal);
void convertFromHex(char hex[]);
void pauseExecution();

int main() {
    int choice;
    char hexInput[20];

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                {
                    int decimalNumber;
                    printf("Enter a decimal number to convert to hexadecimal: ");
                    scanf("%d", &decimalNumber);
                    convertToHex(decimalNumber);
                    break;
                }
            case 2:
                {
                    printf("Enter a hexadecimal number to convert to decimal: ");
                    scanf("%s", hexInput);
                    convertFromHex(hexInput);
                    break;
                }
            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option, try again.\n");
        }
        pauseExecution();
    }
    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("\n=== Hexadecimal Converter ===\n");
    printf("1. Convert Decimal to Hexadecimal\n");
    printf("2. Convert Hexadecimal to Decimal\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

// Function to convert decimal to hexadecimal
void convertToHex(int decimal) {
    if (decimal < 0) {
        printf("Invalid input! Please enter a non-negative integer.\n");
        return;
    }
    char hex[20];
    sprintf(hex, "%X", decimal);
    printf("Decimal %d in hexadecimal is: %s\n", decimal, hex);
}

// Function to convert hexadecimal to decimal
void convertFromHex(char hex[]) {
    int decimal;
    decimal = (int) strtol(hex, NULL, 16);
    if (decimal < 0) {
        printf("Invalid hexadecimal input!\n");
    } else {
        printf("Hexadecimal %s in decimal is: %d\n", hex, decimal);
    }
}

// Function to pause the execution until user presses enter
void pauseExecution() {
    printf("Press Enter to continue...");
    while (getchar() != '\n'); // Clear newline character from the buffer
    getchar(); // Wait for enter key
}