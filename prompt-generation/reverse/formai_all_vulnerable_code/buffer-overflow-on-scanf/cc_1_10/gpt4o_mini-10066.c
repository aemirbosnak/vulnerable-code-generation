//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

void decimalToBinary(int decimalNumber) {
    if (decimalNumber == 0) {
        printf("0");
        return;
    }

    int binary[32];
    int index = 0;

    while (decimalNumber > 0) {
        binary[index] = decimalNumber % 2;
        decimalNumber /= 2;
        index++;
    }

    printf("The binary representation is: ");
    for (int j = index - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    printf("\n");
}

int main() {
    int decimalNumber;
    char choice;

    printf("Welcome to the Decimal to Binary Converter!\n");
    printf("You can convert decimal numbers to binary.\n");

    do {
        printf("Please enter a decimal number (non-negative integer): ");
        
        // Read user input and check if it's a valid integer
        if (scanf("%d", &decimalNumber) != 1 || decimalNumber < 0) {
            printf("Invalid input! Please enter a non-negative integer.\n");
            // Clear the input buffer
            while(getchar() != '\n');
            continue; // Prompt again
        }

        decimalToBinary(decimalNumber);
        
        // Prompt user to continue or exit
        printf("Do you want to convert another number? (y/n): ");
        while(getchar() != '\n'); // Clear the input buffer
        choice = getchar();
        
        // Clear the input buffer again
        while(getchar() != '\n');

    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the Decimal to Binary Converter. Goodbye!\n");
    return 0;
}