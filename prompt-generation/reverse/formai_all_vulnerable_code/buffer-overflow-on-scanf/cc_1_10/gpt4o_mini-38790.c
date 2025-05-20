//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decimalToBinary(int n);
void printBinaryDigits(int n);
void printMenu();
void flushInputBuffer();

int main() {
    char choice[3];
    int number;

    printf("Welcome to the Decimal to Binary Converter!\n");
    
    do {
        printMenu();
        printf("Enter a decimal number (or type 'exit' to quit): ");
        if (scanf("%d", &number) == 1) {
            printf("Decimal: %d => ", number);
            decimalToBinary(number);
            printf("\n");
        } else {
            flushInputBuffer();
            fgets(choice, sizeof(choice), stdin);
            if (strncmp(choice, "exit", 4) == 0) {
                break; // Exit loop if the user types "exit"
            } else {
                printf("Invalid input! Please enter a valid decimal number.\n");
            }
        }
        flushInputBuffer();
    } while (1);

    printf("Thank you for using the converter! Goodbye!\n");
    return 0;
}

void decimalToBinary(int n) {
    if (n == 0) {
        printf("0");
        return;
    }
    
    int binaryArray[32];
    int idx = 0;
    
    while (n > 0) {
        binaryArray[idx] = n % 2;
        n = n / 2;
        idx++;
    }
    
    // Print binary digits in reverse order
    for (int i = idx - 1; i >= 0; i--) {
        printf("%d", binaryArray[i]);
    }
}

void printMenu() {
    printf("\nMenu:\n");
    printf("1. Input a decimal number\n");
    printf("2. Type 'exit' to quit the program\n");
}

void flushInputBuffer() {
    // Clear the input buffer
    while (getchar() != '\n'); 
}