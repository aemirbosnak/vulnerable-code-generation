//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

void convertToHex(int decimal);
void displayMenu();
void getInput(int *number);
void clearBuffer();

int main() {
    int choice;
    int decimalNumber;

    do {
        displayMenu();
        getInput(&choice);

        switch(choice) {
            case 1:
                getInput(&decimalNumber);
                convertToHex(decimalNumber);
                break;
            case 2:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please select again.\n");
        }
    } while (choice != 2);

    return 0;
}

void displayMenu() {
    printf("\n--- Decimal to Hexadecimal Converter ---\n");
    printf("1. Convert Decimal to Hexadecimal\n");
    printf("2. Exit\n");
    printf("Please enter your choice: ");
}

void getInput(int *number) {
    while (1) {
        if (scanf("%d", number) != 1) {
            printf("Invalid input. Please enter a valid integer.\n");
            clearBuffer(); // Clear invalid input
        } else {
            break;
        }
    }
    clearBuffer(); // Clear the newline character from buffer
}

void convertToHex(int decimal) {
    if (decimal < 0) {
        printf("Please enter a non-negative integer.\n");
        return;
    }
    
    printf("The hexadecimal representation of %d is: ", decimal);
    printf("0x%X\n", decimal); // Print in uppercase hexadecimal format
}

void clearBuffer() {
    while (getchar() != '\n'); // Clear input buffer
}