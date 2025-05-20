//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256

// Function to convert a decimal number to binary
void decimalToBinary(int n, char* binary) {
    if (n == 0) {
        strcpy(binary, "0");
        return;
    }
    
    int index = 0;
    while (n > 0) {
        binary[index++] = (n % 2) + '0'; // Convert to character
        n /= 2;
    }
    
    binary[index] = '\0'; // Null-terminate the string

    // Reverse the string as we populated it backwards
    for (int i = 0; i < index / 2; ++i) {
        char temp = binary[i];
        binary[i] = binary[index - i - 1];
        binary[index - i - 1] = temp;
    }
}

// Function to display a message to survivors
void displayMessage() {
    printf("In this desolate wasteland, technology flickers like a dying star.\n");
    printf("You hold the key to survival: the power of understanding binary.\n");
    printf("Transform your numbers, let the code unite man and machine once more.\n");
    printf("Enter a decimal number to reveal its binary essence...\n");
}

int main() {
    int decimalNumber;
    char binary[MAX_SIZE];
    
    displayMessage();

    // Ask for user input
    printf("Enter a decimal number (0 to exit): ");
    while (1) {
        scanf("%d", &decimalNumber);

        // Break the loop if the user enters 0
        if (decimalNumber == 0) {
            printf("You chose to leave the world of numbers. Safe travels, wanderer.\n");
            break;
        }

        // Validate the input
        if (decimalNumber < 0) {
            printf("In this world, the shadows of negativity reign. Enter a positive number!\n");
        } else {
            // Convert to binary
            decimalToBinary(decimalNumber, binary);
            printf("The binary form of %d is: %s\n", decimalNumber, binary);
        }

        // Prompt for the next number
        printf("Enter another decimal number (0 to exit): ");
    }

    return 0;
}