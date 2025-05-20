//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

void printBinary(int n) {
    if (n == 0) {
        printf("0");
        return;
    }
    int binary[32]; // To store binary representation
    int index = 0;

    while (n > 0) {
        binary[index++] = n % 2; // Save the remainder
        n = n / 2;
    }

    // Print in reverse order
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");
}

void displayMenu() {
    printf("Welcome to the Binary Converter!\n");
    printf("1. Convert decimal to binary\n");
    printf("2. Exit\n");
}

int main() {
    int choice;
    int number;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &number);
                printf("The binary representation of %d is: ", number);
                printBinary(number);
                break;
            case 2:
                printf("Exiting... Thank you for using the Binary Converter!\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    } while (choice != 2);
    
    return 0;
}