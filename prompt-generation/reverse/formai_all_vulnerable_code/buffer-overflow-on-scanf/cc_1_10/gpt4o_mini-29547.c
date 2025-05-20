//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal to binary
void decimalToBinary(int n) {
    // Surprise! We’re allocating memory dynamically!
    int *binary = malloc(32 * sizeof(int));
    if (binary == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }

    int index = 0;
    while (n > 0) {
        binary[index] = n % 2;  // Store remainder in binary array
        n = n / 2;               // Divide number by 2
        index++;
    }

    // Surprise! The binary values are reversed in the array!
    printf("Binary representation (reversed): ");
    for (int j = index - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    printf("\n");

    // Free the allocated memory
    free(binary);
}

// Function to print menu options
void printMenu() {
    printf("Welcome to the Decimal to Binary Converter!\n");
    printf("Please choose an option:\n");
    printf("1. Convert a number\n");
    printf("2. Exit the program\n");
}

// Function that contains the main loop
void runConverter() {
    int choice;
    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int number;
            printf("Please enter a non-negative decimal number: ");
            scanf("%d", &number);

            // Surprise! We check for negative inputs!
            if (number < 0) {
                printf("Whoa! Negative numbers are not allowed!\n");
            } else {
                decimalToBinary(number);
            }
        } else if (choice != 2) {
            printf("Hmm, that's not a valid choice. Try again!\n");
        }
    } while (choice != 2);

    printf("Exiting the converter. Have a great day!\n");
}

// Main function to drive the program
int main() {
    // A surprise message to start the program!
    printf("Surprise! You've just opened a binary portal!\n");
    runConverter();
    return 0;
}