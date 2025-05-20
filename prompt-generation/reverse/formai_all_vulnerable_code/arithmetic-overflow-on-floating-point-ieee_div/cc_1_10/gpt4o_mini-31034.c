//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: peaceful
#include <stdio.h>

void displayWelcomeMessage() {
    printf("Welcome to the Serene Arithmetic Garden!\n");
    printf("Here, you can explore the beauty of numbers and operations.\n");
    printf("Let's begin our journey through this peaceful garden...\n\n");
}

void displayMenu() {
    printf("Please choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit\n");
}

void addNumbers() {
    float a, b;
    printf("You are now in the Addition Zone.\n");
    printf("Enter two numbers to add: ");
    scanf("%f %f", &a, &b);
    printf("The serene sum of %.2f and %.2f is: %.2f\n\n", a, b, a + b);
}

void subtractNumbers() {
    float a, b;
    printf("You are now in the Subtraction Zone.\n");
    printf("Enter two numbers to subtract (first - second): ");
    scanf("%f %f", &a, &b);
    printf("The peaceful difference between %.2f and %.2f is: %.2f\n\n", a, b, a - b);
}

void multiplyNumbers() {
    float a, b;
    printf("You are now in the Multiplication Zone.\n");
    printf("Enter two numbers to multiply: ");
    scanf("%f %f", &a, &b);
    printf("The harmonious product of %.2f and %.2f is: %.2f\n\n", a, b, a * b);
}

void divideNumbers() {
    float a, b;
    printf("You are now in the Division Zone.\n");
    printf("Enter two numbers to divide (first / second): ");
    scanf("%f %f", &a, &b);
    if (b != 0) {
        printf("The gentle quotient of %.2f divided by %.2f is: %.2f\n\n", a, b, a / b);
    } else {
        printf("Oh no! Division by zero is not allowed in this peaceful garden.\n\n");
    }
}

int main() {
    int choice;
    displayWelcomeMessage();
    
    while (1) {
        displayMenu();
        printf("Enter your choice (1-5): ");
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
                printf("Thank you for visiting the Serene Arithmetic Garden. Goodbye! 🌼\n");
                return 0;
            default:
                printf("Invalid choice. Please choose a valid operation.\n\n");
                break;
        }
    }
    return 0;
}