//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal to hexadecimal
void decimalToHexadecimal(int decimal, char *hexadecimal) {
    int index = 0;
    while (decimal != 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hexadecimal[index++] = 48 + remainder; // ASCII for '0' is 48
        } else {
            hexadecimal[index++] = 55 + remainder; // ASCII for 'A' is 65
        }
        decimal /= 16;
    }
    hexadecimal[index] = '\0';

    // Reverse the string as we've built it backwards
    for (int i = 0; i < index / 2; i++) {
        char temp = hexadecimal[i];
        hexadecimal[i] = hexadecimal[index - 1 - i];
        hexadecimal[index - 1 - i] = temp;
    }
}

// Function to get user input
int getUserInput() {
    int number;
    printf("Enter a decimal number (greater than or equal to 0): ");
    
    while (1) {
        scanf("%d", &number);
        if (number >= 0) {
            break;
        }
        printf("Please enter a valid non-negative integer: ");
    }
    
    return number;
}

// Function to print the results
void printResults(int decimal, const char *hexadecimal) {
    printf("Decimal: %d\n", decimal);
    printf("Hexadecimal: %s\n", hexadecimal);
}

// Main function
int main() {
    int number;
    char hexadecimal[20]; // Buffer for hexadecimal representation
    
    printf("Welcome to the Decimal to Hexadecimal Converter!\n");
    // Loop to continually accept input until the user decides to quit
    while (1) {
        number = getUserInput(); // Get user input
        
        decimalToHexadecimal(number, hexadecimal); // Convert to hexadecimal
        printResults(number, hexadecimal); // Print the results
        
        // Ask if user wants to continue
        printf("Do you want to convert another number? (y/n): ");
        char choice;
        while (1) {
            scanf(" %c", &choice);
            if (choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N') {
                break;
            }
            printf("Invalid input. Please enter 'y' or 'n': ");
        }
        
        if (choice == 'n' || choice == 'N') {
            printf("Thank you for using the converter! Goodbye!\n");
            break; // Exit the loop
        }
    }
    
    return 0;
}