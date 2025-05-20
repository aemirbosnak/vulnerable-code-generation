//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>

void printHexadecimal(int num) {
    // We will print the hexadecimal format using the standard printf.
    printf("Hexadecimal: %X\n", num);
}

void inputDecimalAndConvert() {
    int number;

    // Prompt user for a decimal number
    printf("Enter a decimal integer: ");
    
    // Check if the input is an integer
    while (scanf("%d", &number) != 1) {
        printf("Invalid input. Please enter a valid decimal integer: ");
        // Clear the input buffer
        while(getchar() != '\n');
    }

    // Convert to hexadecimal and print
    printHexadecimal(number);
}

void displayMenu() {
    printf("\n------- Hexadecimal Converter -------\n");
    printf("1. Convert Decimal to Hexadecimal\n");
    printf("2. Exit\n");
    printf("-------------------------------------\n");
}

int main() {
    int choice;

    do {
        displayMenu();

        // Get user choice
        printf("Choose an option (1-2): ");
        
        // Check if the input is an integer
        while (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 2: ");
            while(getchar() != '\n');
        }

        switch (choice) {
            case 1:
                inputDecimalAndConvert();
                break;

            case 2:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 2);

    return 0;
}