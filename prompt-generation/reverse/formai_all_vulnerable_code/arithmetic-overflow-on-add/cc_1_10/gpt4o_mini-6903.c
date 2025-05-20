//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: grateful
#include <stdio.h>

// Function to display a friendly welcome message
void welcomeMessage() {
    printf("Welcome to the Grateful Arithmetic Program!\n");
    printf("Here, we will perform some basic arithmetic operations with a positive attitude!\n\n");
}

// Function to add two numbers with gratitude
void addNumbers() {
    int num1, num2, sum;
    printf("Enter two numbers to add: ");
    scanf("%d %d", &num1, &num2);
    
    sum = num1 + num2;
    printf("Thank you for your numbers! The sum of %d and %d is: %d\n\n", num1, num2, sum);
}

// Function to subtract two numbers with appreciation
void subtractNumbers() {
    int num1, num2, difference;
    printf("Enter two numbers to subtract (first - second): ");
    scanf("%d %d", &num1, &num2);
    
    difference = num1 - num2;
    printf("Grateful for your input! The difference of %d and %d is: %d\n\n", num1, num2, difference);
}

// Function to multiply two numbers with thankfulness
void multiplyNumbers() {
    int num1, num2, product;
    printf("Enter two numbers to multiply: ");
    scanf("%d %d", &num1, &num2);
    
    product = num1 * num2;
    printf("Thank you for sharing your numbers! The product of %d and %d is: %d\n\n", num1, num2, product);
}

// Function to divide two numbers with kind respect
void divideNumbers() {
    double num1, num2, quotient;
    printf("Enter two numbers to divide (first / second): ");
    scanf("%lf %lf", &num1, &num2);
    
    if (num2 != 0) {
        quotient = num1 / num2;
        printf("Thank you for your numbers! The quotient of %.2lf and %.2lf is: %.2lf\n\n", num1, num2, quotient);
    } else {
        printf("We are grateful but cannot divide by zero! Please provide a non-zero divisor.\n\n");
    }
}

// Function to perform modulus operation with gratitude
void modulusNumbers() {
    int num1, num2, modulus;
    printf("Enter two integers to find the modulus (first %% second): ");
    scanf("%d %d", &num1, &num2);
    
    if (num2 != 0) {
        modulus = num1 % num2;
        printf("Thanks for your input! The modulus of %d and %d is: %d\n\n", num1, num2, modulus);
    } else {
        printf("We appreciate your effort, but modulus by zero is not defined! Please try again.\n\n");
    }
}

// Function to display the menu
void displayMenu() {
    printf("Please choose an arithmetic operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("6. Exit\n");
}

int main() {
    int choice;

    welcomeMessage();

    do {
        displayMenu();
        printf("Enter your choice (1-6): ");
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
                modulusNumbers();
                break;
            case 6:
                printf("Thank you for using the Grateful Arithmetic Program! Have a wonderful day!\n");
                break;
            default:
                printf("We appreciate your enthusiasm, but that's not a valid option! Try again.\n\n");
        }
    } while(choice != 6);

    return 0;
}