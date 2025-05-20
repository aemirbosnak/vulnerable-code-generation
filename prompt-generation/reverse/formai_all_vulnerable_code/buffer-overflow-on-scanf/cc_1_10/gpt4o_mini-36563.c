//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void decToBinary(int n);
void decToBinaryHelper(int n, char *binary, int index);
void printBinaryRepresentation(char *binary);

// Entry point of the program, where the puzzling journey begins
int main() {
    int number; // The number to convert into binary
    char *binaryRepresentation; // Storage for the binary representation
    printf("Welcome to the Overworld of Decimal to Binary Conversion!\n");
    printf("Tell me, brave traveler, which decimal number do you wish to transform?\n");
    
    // Fetching user input
    while (scanf("%d", &number) != 1 || number < 0) {
        printf("Alas! Please enter a valid non-negative integer: ");
        while(getchar() != '\n'); // Clear input buffer
    }

    // Allocate memory for binary representation
    binaryRepresentation = (char *)malloc(32 * sizeof(char)); // Assuming a 32-bit integer
    if (binaryRepresentation == NULL) {
        fprintf(stderr, "Memory allocation failed. The quest ends here.\n");
        return 1;
    }

    // Begin the transformation
    printf("Transforming the number %d into its mystical binary form...\n", number);
    decToBinary(number); // Call the binary conversion function

    // Proceed to reveal the result
    printf("Behold the binary representation of %d:\n", number);
    decToBinaryHelper(number, binaryRepresentation, 0);
    printBinaryRepresentation(binaryRepresentation);
    
    // Clean up memory
    free(binaryRepresentation);
    printf("May your adventures in the realm of numbers be fruitful and enlightening!\n");

    return 0;
}

// Function to convert decimal to binary using recursive helper
void decToBinary(int n) {
    if (n == 0) {
        return; // Base case, nothing to convert
    }
    decToBinary(n / 2); // Recursively divide the number by 2
    printf("%d", n % 2); // Print the remainder (binary digit)
}

// Helper function for recursive conversion
void decToBinaryHelper(int n, char *binary, int index) {
    if (n > 0) {
        binary[index] = (n % 2) + '0'; // Capture binary digit
        decToBinaryHelper(n / 2, binary, index + 1); // Move to next digit
    }
}

// Function to print the binary representation stored in the char array
void printBinaryRepresentation(char *binary) {
    // Logic to print the binary in reverse
    int length = 0;
    while (binary[length] != '\0') {
        length++; // Determine the length of binary representation
    }

    // Print in reverse order to get the correct binary representation
    printf("Binary (from most significant to least): ");
    for (int i = length - 1; i >= 0; i--) {
        putchar(binary[i]); // Print each binary digit
    }
    
    putchar('\n'); // New line after the binary output
}