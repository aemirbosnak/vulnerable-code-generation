//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert an integer to binary
void convertToBinary(int num, char *binary) {
    int index = 0;
    
    // Handle the case for zero explicitly
    if (num == 0) {
        strcpy(binary, "0");
        return;
    }

    // Clear the binary string
    memset(binary, 0, 33);
    
    // Convert the number to binary
    while (num > 0) {
        binary[index++] = (num % 2) + '0';  // Get the last bit and convert to character
        num /= 2;                             // Right shift the number
    }
    binary[index] = '\0'; // Null-terminate the string
    
    // Reverse the binary string to get the correct order
    for (int i = 0; i < index / 2; i++) {
        char temp = binary[i];
        binary[i] = binary[index - i - 1];
        binary[index - i - 1] = temp;
    }
}

// Function to prompt the user and perform number conversion
void userInputHandler() {
    char input[10];
    int number;
    char binary[33]; // Buffer for binary representation (up to 32 bits + null terminator)

    printf("Welcome to the Binary Converter!\n");
    while (1) {
        printf("\nEnter a non-negative integer (or 'exit' to quit): ");
        fgets(input, sizeof(input), stdin);

        // Handle exit condition
        if (strncmp(input, "exit", 4) == 0) {
            printf("Exiting the Binary Converter. Goodbye!\n");
            break;
        }

        // Validate the input
        if (sscanf(input, "%d", &number) != 1 || number < 0) {
            printf("Invalid input. Please enter a valid non-negative integer.\n");
            continue;
        }

        // Convert number to binary
        convertToBinary(number, binary);
        printf("The binary representation of %d is: %s\n", number, binary);
    }
}

int main() {
    // Call the input handler to start the program
    userInputHandler();
    return 0;
}