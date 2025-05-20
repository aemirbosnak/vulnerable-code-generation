//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to binary
void decimalToBinary(int n, char* binaryRepresentation) {
    int index = 0;
    
    // Edge case for 0
    if (n == 0) {
        binaryRepresentation[index++] = '0';
        binaryRepresentation[index] = '\0';
        return;
    }

    while (n > 0) {
        // Store the binary digit
        binaryRepresentation[index++] = (n % 2) + '0';
        n /= 2;
    }
    
    // Reverse the string to get the correct binary representation
    binaryRepresentation[index] = '\0';
    for (int i = 0; i < index / 2; i++) {
        char temp = binaryRepresentation[i];
        binaryRepresentation[i] = binaryRepresentation[index - i - 1];
        binaryRepresentation[index - i - 1] = temp;
    }
}

// Function to prompt user for input until a valid integer is entered
int getUserInput() {
    int num;
    char buffer[256];
    
    while (1) {
        printf("Please enter a non-negative integer (or 'exit' to quit): ");
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            // Check for the exit command
            if (strncmp(buffer, "exit", 4) == 0) {
                exit(0);
            }
            
            // Attempt to convert string to integer
            if (sscanf(buffer, "%d", &num) == 1 && num >= 0) {
                return num;
            } else {
                printf("Invalid input. Please try again.\n");
            }
        }
    }
}

// Main function
int main() {
    printf("Welcome to the Decimal to Binary Converter!\n");
    int num;

    while (1) {
        num = getUserInput();

        // Allocate enough space for the binary representation
        char* binaryRepresentation = (char*)malloc(32 * sizeof(char));
        if (binaryRepresentation == NULL) {
            fprintf(stderr, "Memory allocation failed!\n");
            exit(1);
        }

        // Convert decimal to binary
        decimalToBinary(num, binaryRepresentation);
        
        // Display the result
        printf("Decimal: %d => Binary: %s\n", num, binaryRepresentation);
        
        // Free the allocated memory
        free(binaryRepresentation);
    }

    return 0;
}