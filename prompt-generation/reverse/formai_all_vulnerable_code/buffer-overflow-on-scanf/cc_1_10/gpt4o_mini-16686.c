//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to binary
void decimalToBinary(int n) {
    if (n == 0) {
        printf("0");
        return;
    }

    // Array to store binary number
    int binary[32];
    int index = 0;

    // Calculate binary representation
    while (n > 0) {
        binary[index] = n % 2;
        n = n / 2;
        index++;
    }

    // Print binary number in reverse order
    printf("Binary: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");
}

// Function to get user input and validate it
int getUserInput() {
    int num;
    char buffer[20];

    while (1) {
        printf("Enter a decimal number (or -1 to exit): ");
        fgets(buffer, sizeof(buffer), stdin); // safer than gets
        num = atoi(buffer); // Convert string to integer

        if (num == -1) {
            return -1; // Exit command
        } else if (num < 0) {
            printf("Please enter a positive number.\n");
        } else {
            return num; // Valid input
        }
    }
}

// Function to display menu
void displayMenu() {
    printf("Decimal to Binary Converter Program\n");
    printf("-----------------------------------\n");
    printf("1. Convert decimal to binary\n");
    printf("2. Exit\n");
}

// Main function
int main() {
    int choice;
    
    while (1) {
        displayMenu();
        
        //Get user input for menu choice
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character left by scanf

        if (choice == 1) {
            int decimalNumber = getUserInput();
            if (decimalNumber == -1) {
                printf("Exiting the program. Goodbye!\n");
                break; // Exit the program
            }
            decimalToBinary(decimalNumber);
        } else if (choice == 2) {
            printf("Exiting the program. Goodbye!\n");
            break; // Exit the program
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}