//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to hexadecimal recursively
void decimalToHexadecimal(int num) {
    if (num < 0) {
        printf("Error: Negative numbers are not supported.\n");
        return;
    }
    
    // Base case for zero
    if (num == 0) {
        printf("0");
        return;
    }

    // Recursive case
    if (num / 16 > 0) {
        decimalToHexadecimal(num / 16);
    }
    
    // Print the hexadecimal character corresponding to the remainder.
    int remainder = num % 16;
    if (remainder < 10) {
        printf("%d", remainder);  // Print numbers 0-9 directly
    } else {
        printf("%c", 'A' + (remainder - 10));  // Print A-F for 10-15
    }
}

// Function to get input from the user
int getInput() {
    int number;
    printf("Enter a non-negative integer to convert to hexadecimal: ");
    
    while (1) {
        if (scanf("%d", &number) != 1 || number < 0) {
            printf("Invalid input! Please enter a non-negative integer: ");
            while (getchar() != '\n'); // Clear input buffer
        } else {
            break; // Valid input
        }
    }

    return number;
}

// Main function
int main() {
    int number = getInput();
    
    printf("The hexadecimal representation of %d is: ", number);
    if (number == 0) { // Handle the special case for zero
        printf("0");
    } else {
        decimalToHexadecimal(number);
    }
    
    printf("\n"); // New line for better output formatting
    return 0;
}