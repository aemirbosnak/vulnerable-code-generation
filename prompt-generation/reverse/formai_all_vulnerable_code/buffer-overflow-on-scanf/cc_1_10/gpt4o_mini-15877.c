//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

void printBinary(int number) {
    if (number == 0) {
        printf("Binary: 0\n");
        return;
    }

    int binary[32]; // Array to hold binary digits
    int index = 0;

    while (number > 0) {
        binary[index] = number % 2; // Store the remainder
        number /= 2;
        index++;
    }

    // Print binary number in reverse order
    printf("Binary: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");
}

int getValidInput() {
    int number;
    char term;

    while (1) {
        printf("Enter a decimal number (or type 'q' to quit): ");
        if (scanf("%d%c", &number, &term) != 2 || term != '\n') {
            printf("Invalid input. Please enter a valid decimal number.\n");
            while (getchar() != '\n'); // clear the input buffer
        } else {
            while (getchar() != '\n'); // clear the input buffer
            return number;
        }
    }
}

void displayMenu() {
    printf("\nDecimal to Binary Converter\n");
    printf("===========================\n");
    printf("1. Convert a Decimal Number\n");
    printf("2. Exit\n");
    printf("===========================\n");
}

int main() {
    int choice;
    int number;

    while (1) {
        displayMenu();
        printf("Select an option: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice. Please enter a number between 1 and 2.\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                number = getValidInput();
                printf("You entered: %d\n", number);
                printBinary(number);
                break;
            case 2:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please select either 1 or 2.\n");
        }
    }
    
    return 0;
}