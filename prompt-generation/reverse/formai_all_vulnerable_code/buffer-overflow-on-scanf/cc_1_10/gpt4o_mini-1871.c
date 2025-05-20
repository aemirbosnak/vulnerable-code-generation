//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

// Function to convert a decimal number to binary and store it in a string
void decimalToBinary(int n, char* binary) {
    int index = 0;
    
    // Handle the special case when the number is 0
    if (n == 0) {
        binary[index++] = '0';
    }
    
    // Convert decimal to binary
    while (n > 0) {
        binary[index++] = (n % 2) ? '1' : '0';
        n /= 2;
    }
    
    // Null terminate the string
    binary[index] = '\0';

    // Reverse the string since the binary digits are generated in reverse order
    for (int i = 0; i < index / 2; i++) {
        char temp = binary[i];
        binary[i] = binary[index - i - 1];
        binary[index - i - 1] = temp;
    }
}

// Function to prompt for user input
int getUserInput() {
    int number;
    printf("Enter a non-negative decimal number to convert to binary: ");
    if (scanf("%d", &number) != 1 || number < 0) {
        printf("Invalid input! Please enter a non-negative integer.\n");
        exit(EXIT_FAILURE);
    }
    return number;
}

// Main function to orchestrate the binary conversion
int main() {
    // Step 1: Collect user input
    int decimalNumber = getUserInput();
    
    // Step 2: Prepare a dynamic string for binary representation
    char* binaryRepresentation = malloc(32 * sizeof(char)); // Enough for a 32-bit integer
    if (binaryRepresentation == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return EXIT_FAILURE;
    }
    
    // Step 3: Convert decimal to binary
    decimalToBinary(decimalNumber, binaryRepresentation);
    
    // Step 4: Display the results
    printf("The binary representation of %d is: %s\n", decimalNumber, binaryRepresentation);
    
    // Tidy up and free allocated memory
    free(binaryRepresentation);
    
    return EXIT_SUCCESS;
}