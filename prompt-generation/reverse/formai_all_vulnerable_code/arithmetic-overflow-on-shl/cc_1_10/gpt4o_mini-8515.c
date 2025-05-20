//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
void printBinary(int num);
int isValidInput(const char *input);
void convertToBinary(int num, char *binary);
void userInteraction();

int main() {
    userInteraction();
    return 0;
}

//Function to print the binary representation of an integer
void printBinary(int num) {
    char binary[33]; // 32 bits + 1 for null-terminator
    convertToBinary(num, binary);
    printf("Binary representation of %d is: %s\n", num, binary);
}

// Check if the input string is a valid integer
int isValidInput(const char *input) {
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] < '0' || input[i] > '9') {
            return 0; // Not a valid input
        }
    }
    return 1; // Valid input
}

// Function to convert integer to binary string
void convertToBinary(int num, char *binary) {
    int index = 0;
    for (int i = 31; i >= 0; i--) {
        binary[index++] = (num & (1 << i)) ? '1' : '0';
    }
    binary[index] = '\0'; // Null-terminate the string
}

// User interaction function for input and output handling
void userInteraction() {
    char input[20];
    int number;
    
    printf("Welcome to the Binary Converter Program!\n");
    printf("Please enter a non-negative integer (up to 2147483647): \n");

    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0; // Remove newline character from input
        
        if (isValidInput(input)) {
            number = atoi(input);
            if (number < 0) {
                printf("Negative numbers are not allowed. Please try again.\n");
                continue;
            }
            printBinary(number);
            break; // Exit the loop after successful conversion
        } else {
            printf("Invalid input. Please enter a valid non-negative integer.\n");
        }
    }

    // Asking user for another conversion
    char choice;
    printf("Do you want to convert another number? (y/n): ");
    while (1) {
        choice = getchar();
        getchar(); // to consume newline character
        if (choice == 'y' || choice == 'Y') {
            userInteraction(); // Recursively call for another round
            break;
        } else if (choice == 'n' || choice == 'N') {
            printf("Thank you for using the Binary Converter Program. Goodbye!\n");
            break;
        } else {
            printf("Please answer 'y' or 'n': ");
        }
    }
}