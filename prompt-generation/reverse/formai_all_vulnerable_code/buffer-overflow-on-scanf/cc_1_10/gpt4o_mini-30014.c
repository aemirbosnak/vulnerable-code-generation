//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void convertToBinary(int number);
void displayMenu();
int getInput();

int main() {
    int choice = 0;

    // A whimsical welcome to the user
    printf("Welcome, Esteemed User, to the Decimal to Binary Converter!\n");
    printf("Let us embark on a journey through the realms of numbers.\n\n");

    while (choice != 3) {
        displayMenu();
        choice = getInput();

        switch (choice) {
            case 1: {
                int number;
                printf("Please enter a non-negative decimal number: ");
                number = getInput();

                if (number < 0) {
                    printf("The number must be non-negative. Please try again.\n");
                } else {
                    printf("The binary representation of %d is: ", number);
                    convertToBinary(number);
                    printf("\n");
                }
                break;
            }
            case 2: {
                printf("Thank you for using our converter. Farewell!\n");
                exit(0);
            }
            case 3: {
                printf("Exiting the program. Until next time!\n");
                break;
            }
            default: {
                printf("Invalid choice. Please select again!\n");
                break;
            }
        }
    }
    return 0;
}

void convertToBinary(int number) {
    // An array to hold the binary representation
    int binary[32];
    int index = 0;

    // Convert decimal to binary
    while (number > 0) {
        binary[index] = number % 2;
        number = number / 2;
        index++;
    }

    // Displaying the binary representation in reverse order
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
}

void displayMenu() {
    printf("\nPlease select an option:\n");
    printf("1. Convert Decimal to Binary\n");
    printf("2. Quit\n");
    printf("3. Exit\n");
    printf("Your choice: ");
}

int getInput() {
    int input;
    // Reading user input and checking for valid integer
    while (scanf("%d", &input) != 1) {
        printf("Invalid input. Please enter an integer: ");
        while (getchar() != '\n'); // clear the input buffer
    }
    return input;
}