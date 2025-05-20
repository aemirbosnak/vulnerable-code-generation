//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_BITS 32

// Function to convert a decimal number to binary
void decimalToBinary(int num, char *binary) {
    for (int i = MAX_BITS - 1; i >= 0; i--) {
        binary[i] = (num & 1) ? '1' : '0'; // Check if the least significant bit is a 1 or a 0
        num >>= 1; // Shift right to process the next bit
    }
    binary[MAX_BITS] = '\0'; // Null-terminate the string
}

// Function to display binary representation
void displayBinary(char *binary) {
    // Print in groups of 4 for better readability
    for (int i = 0; i < MAX_BITS; i++) {
        printf("%c", binary[i]);
        if ((i + 1) % 4 == 0 && i + 1 < MAX_BITS) {
            printf(" "); // Add space for groups of 4
        }
    }
    printf("\n");
}

// Main function to handle user input and output
int main() {
    int number, count;
    char binary[MAX_BITS + 1];
    
    printf("Binary Converter Program\n");
    printf("==========================\n");
    
    do {
        printf("Enter the number of integers you wish to convert (1 to 5): ");
        scanf("%d", &count);
        if (count < 1 || count > 5) {
            printf("Invalid input. Please enter a number between 1 and 5.\n");
        }
    } while (count < 1 || count > 5);
    
    for (int i = 0; i < count; i++) {
        // Prompt user for decimal number
        printf("Enter decimal number %d: ", i + 1);
        while (scanf("%d", &number) != 1) {
            printf("Invalid input. Please enter a valid integer: ");
            while(getchar() != '\n'); // Clear invalid input
        }
        
        // Convert and display binary representation
        decimalToBinary(number, binary);
        printf("Decimal: %d | Binary: ", number);
        displayBinary(binary);
        printf("\n");
    }
    
    return 0;
}