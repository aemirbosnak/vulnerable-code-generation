//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: beginner-friendly
#include <stdio.h>

// Function to convert decimal to binary
void decimalToBinary(int n) {
    if (n == 0) {
        printf("0");
        return;
    }

    int binary[32]; // Array to store binary digits
    int index = 0; // Index for binary array

    while (n > 0) {
        binary[index] = n % 2; // Store remainder (0 or 1)
        n = n / 2; // Divide n by 2
        index++;
    }

    // Print the binary digits in reverse order
    printf("Binary: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");
}

// Function to get user input and handle conversion
void handleConversion() {
    int decimalNumber;
    
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);
    
    // Validate input
    if (decimalNumber < 0) {
        printf("Please enter a non-negative integer.\n");
        return; // Exit function on invalid input
    }

    decimalToBinary(decimalNumber); // Call conversion function
}

int main() {
    char choice;

    do {
        handleConversion(); // Handle the conversion

        // Ask the user if they want to convert another number
        printf("Do you want to convert another number? (y/n): ");
        scanf(" %c", &choice); // Space before %c to ignore any previous newline

    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the Decimal to Binary Converter!\n");
    return 0;
}