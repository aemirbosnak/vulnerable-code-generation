//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

void decimalToBinary(int num);
void printBinary(int n);
void displayMenu();
int getChoice();
int getInteger();

int main() {
    int choice, number;

    while (1) {
        displayMenu();
        choice = getChoice();

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                number = getInteger();
                printf("Binary representation of %d is: ", number);
                decimalToBinary(number);
                printf("\n");
                break;
            case 2:
                printf("Exiting the program.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n--- Decimal to Binary Converter ---\n");
    printf("1. Convert Decimal to Binary\n");
    printf("2. Exit\n");
    printf("Choose an option: ");
}

int getChoice() {
    int choice;
    if (scanf("%d", &choice) != 1) {
        while (getchar() != '\n'); // Clear invalid input
        return 0; // Invalid choice
    }
    return choice;
}

int getInteger() {
    int number;
    while (1) {
        if (scanf("%d", &number) == 1) {
            if (number >= 0) {
                break; // Valid input
            } else {
                printf("Please enter a non-negative integer: ");
            }
        } else {
            while (getchar() != '\n'); // Clear invalid input
            printf("Invalid input. Please enter a non-negative integer: ");
        }
    }
    return number;
}

void decimalToBinary(int num) {
    if (num == 0) {
        printf("0");
        return;
    }

    printBinary(num);
}

void printBinary(int n) {
    if (n > 1)
        printBinary(n / 2);

    printf("%d", n % 2);
}