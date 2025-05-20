//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

void convertToBinary(int decimal);
void clearInputBuffer();

int main() {
    int decimalNumber;
    char choice;

    printf("Welcome to the Decimal to Binary Converter!\n");
    
    do {
        printf("Please enter a decimal number: ");
        while (scanf("%d", &decimalNumber) != 1) {
            printf("Invalid input. Please enter a valid decimal number: ");
            clearInputBuffer();
        }
        
        convertToBinary(decimalNumber);

        printf("Do you want to convert another number? (y/n): ");
        clearInputBuffer();
        choice = getchar();

    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the converter. Goodbye!\n");
    return 0;
}

void convertToBinary(int decimal) {
    if (decimal < 0) {
        printf("The number should be non-negative.\n");
        return;
    }

    int binary[32]; // Array to hold the binary digits
    int index = 0;

    if (decimal == 0) {
        printf("Binary representation of %d is: 0\n", decimal);
        return;
    }

    while (decimal > 0) {
        binary[index] = decimal % 2; // Store remainder
        decimal = decimal / 2; // Update decimal
        index++;
    }

    printf("Binary representation: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}