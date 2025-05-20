//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to binary
void decimalToBinary(int n) {
    // Array to store binary number
    int binary[32];
    int i = 0;

    // Convert decimal to binary
    while (n > 0) {
        binary[i] = n % 2;
        n = n / 2;
        i++;
    }

    // Print binary number in reverse order
    printf("Binary: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    printf("\n");
}

// Function to print binary representation of a floating point number
void floatToBinary(float num) {
    unsigned int *p = (unsigned int *) &num;
    printf("Binary (Float): ");
    for (int i = 31; i >= 0; i--) {
        printf("%d", (*p >> i) & 1);
    }
    printf("\n");
}

// Function to handle user input and validation
int getInput() {
    int number;
    char buffer[100];

    while (1) {
        printf("Enter a decimal number (integer or floating-point) to convert to binary (or 'q' to quit): ");
        
        // Taking input and handling quit command
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (buffer[0] == 'q') {
                return -1; // signal to quit the program
            }
            // Try to parse input as integer
            if (sscanf(buffer, "%d", &number) == 1) {
                return number;
            } else {
                // Check if input is a valid float
                float floatNum;
                if (sscanf(buffer, "%f", &floatNum) == 1) {
                    int intPart = (int)floatNum;
                    printf("Integer Part: ");
                    decimalToBinary(intPart);

                    printf("Decimal Part: "); 
                    floatToBinary(floatNum);
                    continue; // Prompt for another input
                } 
            }
        }
        
        printf("Invalid input! Please enter a valid integer or floating-point number.\n");
    }
}

// Main function
int main() {
    printf("Welcome to the Decimal to Binary Converter!\n");
    printf("This tool converts both integers and floating-point numbers to binary representation.\n");

    while (1) {
        int num = getInput();
        if (num == -1) {
            printf("Exiting the converter. Goodbye!\n");
            break; // Exit condition
        }
        decimalToBinary(num);
    }

    return 0;
}