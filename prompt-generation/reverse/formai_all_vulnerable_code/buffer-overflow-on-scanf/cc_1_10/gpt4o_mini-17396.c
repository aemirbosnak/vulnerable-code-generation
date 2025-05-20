//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: relaxed
#include <stdio.h>

// Function to convert decimal to hexadecimal
void decimalToHexadecimal(int decimal) {
    char hex[20]; // Array to hold hexadecimal representation
    int i = 0;

    // Convert decimal to hexadecimal
    while (decimal != 0) {
        int rem = decimal % 16;

        // Check remainder and append proper value
        if (rem < 10) {
            hex[i] = rem + '0'; // Convert to character '0' to '9'
        } else {
            hex[i] = rem - 10 + 'A'; // Convert to character 'A' to 'F'
        }
        decimal /= 16;
        i++;
    }

    // Reverse the hex array
    printf("Hexadecimal value: ");
    for (int j = i - 1; j >= 0; j--) {
        putchar(hex[j]);
    }
    putchar('\n');
}

// Main function to execute the program
int main() {
    int decimalNumber;

    printf("Welcome to the Decimal to Hexadecimal Converter!\n");
    printf("Please enter a decimal number (non-negative integer): ");
  
    while (1) { // Loop until a valid input is received
        if (scanf("%d", &decimalNumber) != 1 || decimalNumber < 0) {
            // Clear the input buffer if the input is invalid
            while (getchar() != '\n'); 
            printf("Oops! That’s not a valid non-negative integer. Try again: ");
        } else {
            break; // Exit the loop if valid input is received
        }
    }

    // Function call to convert and display
    decimalToHexadecimal(decimalNumber);

    printf("Thank you for using the converter! Have a lovely day!\n");

    return 0;
}