//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

void displayBinary(int number);
void convertAndDisplay(int decimal);
int getValidInput();

int main() {
    int choice;
    int decimalNumber;

    printf("Welcome to the Decimal to Binary Converter!\n");
    printf("===========================================\n");
    
    do {
        printf("\nEnter a non-negative decimal number (or -1 to exit): ");
        decimalNumber = getValidInput();

        if (decimalNumber < 0) {
            break;
        }
        
        convertAndDisplay(decimalNumber);

        printf("Do you want to convert another number? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);

    } while (choice == 1);
    
    printf("Thank you for using the Decimal to Binary Converter! Goodbye!\n");
    
    return 0;
}

void convertAndDisplay(int decimal) {
    printf("The binary representation of %d is: ", decimal);
    displayBinary(decimal);
    printf("\n");
}

void displayBinary(int number) {
    int binary[32]; // Size enough to hold the binary representation of an integer
    int index = 0;
    
    // Handle the special case of 0
    if (number == 0) {
        printf("0");
        return;
    }
    
    // Generate binary representation
    while (number > 0) {
        binary[index] = number % 2; // Store remainder in binary array
        number = number / 2; // Divide the number by 2
        index++;
    }
    
    // Print binary representation in reverse order
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
}

int getValidInput() {
    int input;
    
    while (1) {
        if (scanf("%d", &input) != 1) {
            printf("Invalid input. Please enter a non-negative integer.\n");
            while (getchar() != '\n'); // Clear the input buffer
        } else if (input < -1) {
            printf("Negative numbers are not accepted, please try again.\n");
        } else {
            return input;
        }
    }
}