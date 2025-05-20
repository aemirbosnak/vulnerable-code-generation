//FormAI DATASET v1.0 Category: Error handling ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Function to add two numbers
int add(int a, int b) {
    return a + b;
}

// Function to subtract two numbers
int sub(int a, int b) {
    return a - b;
}

// Function to handle errors gracefully
void handle_error(char* message) {
    printf("Oops, something went wrong: %s\n", message);
    printf("Don't worry, we can handle this!\n");

    // Retry the operation or exit gracefully
    printf("Do you want to retry? (Y/N): ");
    char choice;
    scanf(" %c", &choice);

    // If user chooses to retry
    if (choice == 'Y' || choice == 'y') {
        printf("\nLet's give it another shot!\n\n");
    }
    // If user chooses to exit
    else if (choice == 'N' || choice == 'n') {
        printf("\nThanks for using our program. Have a nice day!\n");
        exit(0);
    }
    // If user enters invalid choice
    else {
        printf("\nOops, invalid choice! Exiting gracefully.\n");
        exit(0);
    }
}

// Main function
int main() {
    int a = 10;
    int b = 0;

    // Add two numbers and handle error if any
    int sum = 0;
    printf("Adding %d and %d...\n", a, b);
    if (b == 0) {
        handle_error("Cannot add two numbers if one is zero.");
    } else {
        sum = add(a, b);
        printf("Sum of %d and %d is %d\n", a, b, sum);
    }

    // Subtract two numbers and handle error if any
    int diff = 0;
    printf("\nSubtracting %d from %d...\n", b, a);
    if (a < b) {
        handle_error("Cannot subtract a larger number from a smaller number.");
    } else {
        diff = sub(a, b);
        printf("%d - %d is %d\n", a, b, diff);
    }

    return 0;
}