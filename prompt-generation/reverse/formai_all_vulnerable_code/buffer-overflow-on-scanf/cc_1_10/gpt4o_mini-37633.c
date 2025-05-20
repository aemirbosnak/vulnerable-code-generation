//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

void displayShockCause() {
    const char *causes[] = {
        "You forgot to check your variables!",
        "You left a semicolon there, didn't you?",
        "You just used the wrong logic - again!",
        "Your pointer might be NULL... oh no!",
        "You didn't return anything from your function!",
        "You mixed up your data types!",
        "Infinite recursion? What have you done?!",
        "Logic error! This can't be happening!",
        "You declared a variable but forgot to use it!",
        "The stack is overflowing! It's a disaster!"
    };
    int index = rand() % 10; // Choose a random index
    printf("%s\n", causes[index]);
}

int factorial(int n) {
    if (n < 0) {
        printf("ERROR: Negative number! ");
        displayShockCause();
        return -1; // Handling negative input.
    }
    if (n == 0) {
        return 1; 
    }
    return n * factorial(n - 1);
}

int fibonacci(int n) {
    if (n < 0) {
        printf("ERROR: Negative index in Fibonacci! ");
        displayShockCause();
        return -1; // Handling negative index.
    }
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1; 
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void printMenu() {
    printf("Welcome to the Shocked Recursive Calculator\n");
    printf("1. Calculate Factorial\n");
    printf("2. Get Fibonacci Number\n");
    printf("3. Exit\n");
    printf("Please select an option: ");
}

void handleUserSelection(int choice) {
    int number;
    switch (choice) {
        case 1:
            printf("Enter a non-negative integer for factorial: ");
            scanf("%d", &number);
            printf("Factorial of %d is: %d\n", number, factorial(number));
            break;
        case 2:
            printf("Enter a non-negative integer for Fibonacci: ");
            scanf("%d", &number);
            printf("Fibonacci number at index %d is: %d\n", number, fibonacci(number));
            break;
        case 3:
            printf("Exiting the program. Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice! ");
            displayShockCause();
    }
}

int main() {
    int choice;
    
    // Seed for random number generation.
    srand(time(NULL));

    while (1) {
        printMenu();
        scanf("%d", &choice);
        handleUserSelection(choice);
    }
    
    return 0; // Just in case, though we should never reach here.
}