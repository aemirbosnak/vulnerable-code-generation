//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: puzzling
#include <stdio.h>

// Function prototypes
void displayInstructions();
int calculateFactorial(int num);
int fibonacci(int n);
void reverseString(char str[], int index);
void printPyramid(int n);

// Main function
int main() {
    int choice, num;
    char str[100];

    displayInstructions();

    // Getting user choice
    printf("Enter your choice (1-5): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter a number to calculate its factorial: ");
            scanf("%d", &num);
            printf("Factorial of %d is %d\n", num, calculateFactorial(num));
            break;

        case 2:
            printf("Enter a position in Fibonacci sequence: ");
            scanf("%d", &num);
            printf("Fibonacci number at position %d is %d\n", num, fibonacci(num));
            break;

        case 3:
            printf("Enter a string to reverse: ");
            scanf("%s", str);
            printf("Reversed string: ");
            reverseString(str, 0);
            printf("\n");
            break;

        case 4:
            printf("Enter the height of the pyramid: ");
            scanf("%d", &num);
            printPyramid(num);
            break;

        default:
            printf("Invalid choice! Please restart the program and try again.\n");
            break;
    }
    return 0;
}

// Recursive function to calculate factorial
int calculateFactorial(int num) {
    return (num <= 1) ? 1 : num * calculateFactorial(num - 1);
}

// Recursive function to calculate Fibonacci number
int fibonacci(int n) {
    return (n <= 1) ? n : fibonacci(n - 1) + fibonacci(n - 2);
}

// Recursive function to reverse a string
void reverseString(char str[], int index) {
    if (str[index] != '\0') {
        reverseString(str, index + 1);
        putchar(str[index]);
    }
}

// Recursive function to print a pyramid pattern
void printPyramid(int n) {
    if (n <= 0) {
        return;
    }
    printPyramid(n - 1);
    for (int i = 0; i < n; i++) {
        putchar('*');
    }
    putchar('\n');
}

// Function to display instructions
void displayInstructions() {
    printf("Welcome to the Puzzling Program!\n");
    printf("Choose one of the following options:\n");
    printf("1. Calculate Factorial of a Number\n");
    printf("2. Get Fibonacci Number at a Position\n");
    printf("3. Reverse a String\n");
    printf("4. Print a Pyramid Pattern\n");
    printf("5. Exit\n");
}