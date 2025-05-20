//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: excited
#include <stdio.h>

// Function declarations
void addNumbers();
void subtractNumbers();
void multiplyNumbers();
void divideNumbers();
void moduloNumbers();
void displayMenu();

int main() {
    int choice;

    // Welcome message
    printf("Welcome to the Ultimate Arithmetic Arena!\n");
    printf("Here you can perform various arithmetic operations with ease!\n");

    // Menu loop
    do {
        displayMenu();
        printf("Enter your choice (1-6) or 0 to exit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addNumbers();
                break;
            case 2:
                subtractNumbers();
                break;
            case 3:
                multiplyNumbers();
                break;
            case 4:
                divideNumbers();
                break;
            case 5:
                moduloNumbers();
                break;
            case 0:
                printf("Exiting... Hope you had a blast! Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}

void displayMenu() {
    printf("\n----- Arithmetic Operations -----\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulo\n");
    printf("0. Exit\n");
}

void addNumbers() {
    int a, b;
    printf("Let's add some numbers!\n");
    printf("Enter the first number: ");
    scanf("%d", &a);
    printf("Enter the second number: ");
    scanf("%d", &b);
    printf("The result of %d + %d is: %d\n", a, b, a + b);
}

void subtractNumbers() {
    int a, b;
    printf("Time to subtract!\n");
    printf("Enter the first number: ");
    scanf("%d", &a);
    printf("Enter the second number: ");
    scanf("%d", &b);
    printf("The result of %d - %d is: %d\n", a, b, a - b);
}

void multiplyNumbers() {
    int a, b;
    printf("Welcome to multiplication mayhem!\n");
    printf("Enter the first number: ");
    scanf("%d", &a);
    printf("Enter the second number: ");
    scanf("%d", &b);
    printf("The result of %d * %d is: %d\n", a, b, a * b);
}

void divideNumbers() {
    int a, b;
    printf("Get ready to divide!\n");
    printf("Enter the numerator: ");
    scanf("%d", &a);
    printf("Enter the denominator: ");
    scanf("%d", &b);
    
    if (b == 0) {
        printf("Whoa! Division by zero is not allowed! Let's try that again.\n");
        return;
    }

    printf("The result of %d / %d is: %.2f\n", a, b, (float)a / b);
}

void moduloNumbers() {
    int a, b;
    printf("Modulo madness!\n");
    printf("Enter the first number: ");
    scanf("%d", &a);
    printf("Enter the second number: ");
    scanf("%d", &b);
    
    if (b == 0) {
        printf("Oops! Modulo by zero isn't possible! Please try different numbers.\n");
        return;
    }

    printf("The result of %d %% %d is: %d\n", a, b, a % b);
}