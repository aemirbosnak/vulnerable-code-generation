//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: brave
#include <stdio.h>

// Function declarations
void convertToBinary(int num);
void getInput();

int main() {
    printf("Welcome to the Brave Binary Converter!\n");
    printf("Ready to convert decimal numbers into binary? Let's start!\n");
    
    getInput(); // Start the input loop

    return 0;
}

// Function to convert number to binary and print it
void convertToBinary(int num) {
    if (num < 0) {
        printf("Negative numbers are not supported!\n");
        return;
    }
    
    // Create an array to store binary digits
    char binary[32];
    int index = 0;

    // Convert number to binary representation
    if (num == 0) {
        printf("Binary: 0\n");
        return;
    }

    while (num > 0) {
        binary[index++] = (num % 2) + '0'; // Store the binary digit
        num /= 2; // Divide the number by 2
    }

    // Print the binary representation in reverse
    printf("Binary: ");
    for (int i = index - 1; i >= 0; i--) {
        putchar(binary[i]);
    }
    putchar('\n'); // Newline after printing binary
}

// Function to get user input
void getInput() {
    int number;
    
    while (1) {
        printf("Please enter a decimal number (or -1 to quit): ");
        scanf("%d", &number);

        // Check for quit command
        if (number == -1) {
            printf("Exiting the Brave Binary Converter. Farewell!\n");
            break; // Exit the loop if user wants to quit
        }

        convertToBinary(number); // Convert the number to binary
    }
}