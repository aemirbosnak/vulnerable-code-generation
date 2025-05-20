//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

void decimalToHexadecimal(int decimal) {
    char hexadecimal[20];  // Array to store hexadecimal number
    int index = 0;        // Index for hexadecimal array

    // If the number is 0, immediately return "0"
    if (decimal == 0) {
        printf("Hexadecimal: 0\n");
        return;
    }

    // Converting decimal to hexadecimal
    while (decimal > 0) {
        int remainder = decimal % 16;

        // Convert remainder to appropriate hexadecimal digit
        if (remainder < 10) {
            hexadecimal[index++] = 48 + remainder;  // 48 is ASCII for '0'
        } else {
            hexadecimal[index++] = 87 + remainder;  // 87 is ASCII for 'a' (10 to 'a', 11 to 'b', etc.)
        }
        decimal = decimal / 16;
    }

    printf("Hexadecimal: ");
    
    // Printing hexadecimal number in reverse
    for (int j = index - 1; j >= 0; j--) {
        putchar(hexadecimal[j]);
    }
    printf("\n");
}

void getDecimalInput() {
    int decimal;
    
    printf("Welcome to the Decimal to Hexadecimal Converter!\n");
    printf("Enter a decimal number (non-negative integers only): ");
    
    // Take user input
    if (scanf("%d", &decimal) != 1 || decimal < 0) {
        printf("Invalid input! Please enter a non-negative integer.\n");
        return;  // Exit if input is invalid
    }
    
    // Call function to convert to hexadecimal
    decimalToHexadecimal(decimal);
}

int main() {
    char choice;
    
    do {
        getDecimalInput();  // Get decimal input from the user
        
        printf("Do you want to convert another number? (y/n): ");
        scanf(" %c", &choice);  // Read user's choice
        
        // Handle invalid input for choice
        while (choice != 'y' && choice != 'n') {
            printf("Invalid choice! Please enter 'y' to continue or 'n' to exit: ");
            scanf(" %c", &choice);
        }
        
    } while (choice == 'y');  // Repeat if user wants another conversion

    printf("Thank you for using the Decimal to Hexadecimal Converter! Have a great day!\n");
    return 0;  // End of program
}