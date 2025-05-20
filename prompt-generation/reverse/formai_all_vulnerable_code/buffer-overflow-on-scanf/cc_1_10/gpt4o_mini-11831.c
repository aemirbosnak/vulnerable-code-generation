//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function Prototypes
void decToBinary(int n);
void binaryToDec(char* binaryStr);
void displayMenu();
void handleUserChoice(int choice);

int main() {
    int userChoice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        if (scanf("%d", &userChoice) != 1) {
            printf("Invalid input. Please enter a valid choice.\n");
            // Clear the input buffer
            while (getchar() != '\n');
            continue;
        }
        getchar(); // consume newline character

        if (userChoice == 0) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        handleUserChoice(userChoice);
    }

    return 0;
}

// Function to convert decimal to binary
void decToBinary(int n) {
    if (n == 0) {
        printf("Binary: 0\n");
        return;
    }

    char binary[33]; // 32 bits + null terminator
    int index = 0;

    while (n > 0) {
        binary[index] = (n % 2) ? '1' : '0';
        n /= 2;
        index++;
    }

    // Reverse the binary string
    printf("Binary: ");
    for (int i = index - 1; i >= 0; i--) {
        putchar(binary[i]);
    }
    putchar('\n');
}

// Function to convert binary to decimal
void binaryToDec(char* binaryStr) {
    int decimalValue = 0;
    int len = strlen(binaryStr);

    for (int i = 0; i < len; i++) {
        if (binaryStr[len - i - 1] == '1') {
            decimalValue += pow(2, i);
        }
    }
    
    printf("Decimal: %d\n", decimalValue);
}

// Function to display the menu
void displayMenu() {
    printf("\nWelcome to the Binary Converter!\n");
    printf("1. Convert Decimal to Binary\n");
    printf("2. Convert Binary to Decimal\n");
    printf("0. Exit\n");
}

// Function to handle user choice
void handleUserChoice(int choice) {
    switch (choice) {
        case 1: {
            int decimalNum;
            printf("Enter a decimal number: ");
            if (scanf("%d", &decimalNum) != 1) {
                printf("Invalid input. Please enter a valid decimal number.\n");
                // Clear the input buffer
                while (getchar() != '\n');
                return;
            }
            decToBinary(decimalNum);
            break;
        }
        case 2: {
            char binaryStr[33];
            printf("Enter a binary number: ");
            fgets(binaryStr, sizeof(binaryStr), stdin);
            binaryStr[strcspn(binaryStr, "\n")] = 0; // remove the newline character
            binaryToDec(binaryStr);
            break;
        }
        default:
            printf("Invalid choice. Please try again.\n");
    }
}