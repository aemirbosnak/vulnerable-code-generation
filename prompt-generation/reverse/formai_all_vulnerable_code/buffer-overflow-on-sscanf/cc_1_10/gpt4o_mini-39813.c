//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: Dennis Ritchie
#include <stdio.h>

void decimalToBinary(int n);
void printBinary(int n);
int isValidInput(char *input);

int main() {
    int number;
    char input[50];
    
    printf("Welcome to the Decimal to Binary Converter!\n");
    printf("===========================================\n");

    while (1) {
        printf("Enter a decimal number (or type 'exit' to quit): ");
        fgets(input, sizeof(input), stdin);
        
        if (input[0] == 'e' && input[1] == 'x' && input[2] == 'i' && input[3] == 't') {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        if (isValidInput(input)) {
            sscanf(input, "%d", &number);
            printf("Binary representation of %d is: ", number);
            decimalToBinary(number);
            printf("\n\n");
        } else {
            printf("Invalid input. Please enter a valid decimal number.\n\n");
        }
    }

    return 0;
}

void decimalToBinary(int n) {
    if (n < 0) {
        printf("Invalid input: negative numbers are not supported in this converter.\n");
        return;
    }

    printBinary(n);
}

void printBinary(int n) {
    if (n > 1) {
        printBinary(n >> 1);
    }

    printf("%d", n & 1);
}

int isValidInput(char *input) {
    int i = 0;

    // Handle leading whitespace
    while (input[i] == ' ') {
        i++;
    }

    // Check for exit command first
    if (input[i] == 'e') {
        return 1; // It's 'exit'
    }

    // Process characters to check for digits
    for (; input[i] != '\0'; i++) {
        if (input[i] == '\n') break; // Skip newline character
        if (input[i] < '0' || input[i] > '9') {
            return 0; // Not a valid integer
        }
    }

    // If it reaches here, it's valid
    return 1;
}