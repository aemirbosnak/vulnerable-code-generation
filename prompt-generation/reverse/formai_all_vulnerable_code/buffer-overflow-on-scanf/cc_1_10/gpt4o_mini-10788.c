//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to binary recursively
void decimalToBinary(int decimal) {
    if (decimal > 1) {
        // Recursive call for the next higher bit
        decimalToBinary(decimal / 2);
    }
    // Print the remainder (0 or 1)
    printf("%d", decimal % 2);
}

// Function to print a welcome message about binary numbers
void welcomeMessage() {
    printf("***********************************\n");
    printf("* Welcome to the Binary Converter!*\n");
    printf("***********************************\n");
    printf("This program will convert decimal numbers to binary.\n");
}

// Function to handle user input and conversion
void convertNumbers() {
    int decimal;
    printf("Enter a non-negative decimal number (or -1 to exit): ");
    
    while (1) {
        scanf("%d", &decimal);
        
        // Exit condition
        if (decimal == -1) {
            printf("Thank you for using the Binary Converter. Goodbye!\n");
            break;
        }
        
        // Input validation
        if (decimal < 0) {
            printf("Please enter a non-negative value.\n");
            continue;
        }
        
        printf("Decimal: %d in binary is: ", decimal);
        decimalToBinary(decimal);
        printf("\n");
    }
}

// Main function to orchestrate the binary conversion journey
int main() {
    welcomeMessage();
    convertNumbers();
    return 0;
}