//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a decimal number to binary
void decimalToBinary(int n) {
    if (n == 0) {
        printf("0");
        return;
    }

    int binary[32];
    int index = 0;

    // Convert to binary
    while (n > 0) {
        binary[index] = n % 2;
        n = n / 2;
        index++;
    }

    // Print binary in reverse order
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
}

// Function to convert a binary number (as a string) to decimal
int binaryToDecimal(char *binaryStr) {
    int decimalValue = 0;
    int base = 1; // Represents 2^0

    // Reverse loop through the string
    for (int i = strlen(binaryStr) - 1; i >= 0; i--) {
        // Check if the character is '1'
        if (binaryStr[i] == '1') {
            decimalValue += base;
        }
        base *= 2; // Move to the next power of 2
    }

    return decimalValue;
}

// Function to display the menu
void displayMenu() {
    printf("\n*** Welcome to the Peaceful Binary Converter ***\n");
    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");
    printf("3. Exit\n");
    printf("Please choose an option (1-3): ");
}

// Function to handle the conversion process
void conversionProcess() {
    int choice;
    int decimalNumber;
    char binaryStr[33]; // To accommodate binary strings
    char *endptr;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &decimalNumber);
                printf("Binary representation: ");
                decimalToBinary(decimalNumber);
                printf("\n");
                break;

            case 2:
                printf("Enter a binary number: ");
                scanf("%s", binaryStr);
                // Check if input is valid binary
                if (strspn(binaryStr, "01") != strlen(binaryStr)) {
                    printf("Invalid binary number. Please use only '0' and '1'.\n");
                    break;
                }
                int decimalValue = binaryToDecimal(binaryStr);
                printf("Decimal representation: %d\n", decimalValue);
                break;

            case 3:
                printf("Thank you for using the Peaceful Binary Converter! Goodbye!\n");
                exit(0); // Exit the program

            default:
                printf("Invalid choice! Please select again.\n");
                break;
        }

        printf("Press Enter to continue...");
        while (getchar() != '\n'); // To ignore leftover input
        getchar(); // Wait for Enter press
        printf("\n");
    }
}

// Main function
int main() {
    conversionProcess();
    return 0;
}