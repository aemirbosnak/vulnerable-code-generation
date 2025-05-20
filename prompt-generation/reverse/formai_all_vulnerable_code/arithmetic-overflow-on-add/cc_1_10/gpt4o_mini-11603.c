//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void displayMenu();
int getInput();
int factorial(int n);
int isPrime(int n);
void performOperations(int choice);

int main() {
    int choice;

    do {
        displayMenu();
        choice = getInput();

        if (choice != 5) {
            performOperations(choice);
        }
    } while (choice != 5);

    printf("Exiting the program. Goodbye!\n");
    return 0;
}

void displayMenu() {
    printf("\n********** Math Operations Menu **********\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Factorial\n");
    printf("4. Prime Check\n");
    printf("5. Exit\n");
    printf("*******************************************\n");
    printf("Please choose an option (1-5): ");
}

int getInput() {
    int choice;
    char term;

    while (scanf("%d%c", &choice, &term) != 2 || term != '\n' || choice < 1 || choice > 5) {
        printf("Invalid input. Please enter a number between 1 and 5: ");
        while (getchar() != '\n'); // Clear input buffer
    }
    
    return choice;
}

void performOperations(int choice) {
    int num1, num2;

    switch (choice) {
        case 1: // Addition
            printf("Enter two numbers to add (separated by space): ");
            scanf("%d %d", &num1, &num2);
            printf("Result: %d + %d = %d\n", num1, num2, num1 + num2);
            break;
        case 2: // Subtraction
            printf("Enter two numbers to subtract (separated by space): ");
            scanf("%d %d", &num1, &num2);
            printf("Result: %d - %d = %d\n", num1, num2, num1 - num2);
            break;
        case 3: // Factorial
            printf("Enter a non-negative integer for the factorial: ");
            scanf("%d", &num1);
            if (num1 < 0) {
                printf("Factorial is not defined for negative numbers.\n");
            } else {
                printf("Factorial of %d is %d\n", num1, factorial(num1));
            }
            break;
        case 4: // Prime Check
            printf("Enter a number to check if it's prime: ");
            scanf("%d", &num1);
            if (isPrime(num1)) {
                printf("%d is a prime number.\n", num1);
            } else {
                printf("%d is not a prime number.\n", num1);
            }
            break;
        default:
            printf("This should not have happened!\n");
            break;
    }
}

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

int isPrime(int n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}