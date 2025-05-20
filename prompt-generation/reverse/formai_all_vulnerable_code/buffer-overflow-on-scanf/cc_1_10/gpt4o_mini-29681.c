//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: protected
#include <stdio.h>
#include <stdlib.h>

void printPyramid(int height);
void printMenu();
int getUserInput();
void clearBuffer();

int main() {
    int height;
    char choice;

    do {
        printMenu();
        height = getUserInput();

        if (height > 0) {
            printPyramid(height);
        } else {
            printf("Please enter a positive integer for the height.\n");
        }

        printf("Do you want to print another pyramid? (y/n): ");
        scanf(" %c", &choice);
        clearBuffer(); // Clear any remaining characters in the input buffer

    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the pyramid pattern printer!\n");
    return 0;
}

void printPyramid(int height) {
    for (int i = 1; i <= height; i++) {
        // Print leading spaces
        for (int j = height; j > i; j--) {
            printf(" ");
        }
        // Print asterisks
        for (int k = 1; k <= (2 * i - 1); k++) {
            printf("*");
        }
        printf("\n");
    }
}

void printMenu() {
    printf("\n--- Pyramid Pattern Printer ---\n");
    printf("Enter the height of the pyramid:\n");
    printf("Choices:\n");
    printf("1. 1\n");
    printf("2. 2\n");
    printf("3. 3\n");
    printf("4. 4\n");
    printf("5. 5\n");
    printf("6. Custom Height\n");
    printf("Select from the above options (1-6): ");
}

int getUserInput() {
    int input;
    int option;
    scanf("%d", &option);
    clearBuffer(); // Clear any remaining characters in the input buffer

    switch (option) {
        case 1: input = 1; break;
        case 2: input = 2; break;
        case 3: input = 3; break;
        case 4: input = 4; break;
        case 5: input = 5; break;
        case 6: 
            printf("Enter custom height: ");
            scanf("%d", &input);
            break;
        default:
            printf("Invalid selection. Please select a valid option.\n");
            input = -1; // Indicate an invalid selection
    }

    return input;
}

void clearBuffer() {
    while (getchar() != '\n'); // Clear the input buffer
}