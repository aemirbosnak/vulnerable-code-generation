//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

void printBinary(int num) {
    if (num > 1) {
        printBinary(num >> 1);
    }
    printf("%d", num & 1);
}

void convertToBinary() {
    int decimal;
    printf("Enter a decimal number to convert to binary: ");
    if (scanf("%d", &decimal) != 1) {
        printf("Invalid input. Please enter a valid integer.\n");
        return;
    }
    printf("Binary representation of %d is: ", decimal);
    printBinary(decimal);
    printf("\n");
}

void printMenu() {
    printf("\n----- Binary Converter -----\n");
    printf("1. Convert Decimal to Binary\n");
    printf("2. Exit\n");
    printf("---------------------------\n");
}

int main() {
    int choice;

    do {
        printMenu();
        printf("Choose an option: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a valid integer.\n");
            while(getchar() != '\n'); // Clear the input buffer
            continue;
        }
        
        switch (choice) {
            case 1:
                convertToBinary();
                break;
            case 2:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 2);

    return 0;
}