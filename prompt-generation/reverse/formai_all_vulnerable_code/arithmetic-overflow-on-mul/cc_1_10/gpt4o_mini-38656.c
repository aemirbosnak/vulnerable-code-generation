//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to display a menu
void displayMenu() {
    printf("\n--- Welcome to the Grateful Math Playground! ---\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Random Math Quiz\n");
    printf("0. Exit\n");
    printf("Please enter your choice: ");
}

// Function to perform addition
void performAddition() {
    int num1, num2;
    printf("Enter two numbers to add: ");
    scanf("%d %d", &num1, &num2);
    printf("The sum of %d and %d is: %d\n", num1, num2, num1 + num2);
}

// Function to perform subtraction
void performSubtraction() {
    int num1, num2;
    printf("Enter two numbers to subtract (num1 - num2): ");
    scanf("%d %d", &num1, &num2);
    printf("The result of %d - %d is: %d\n", num1, num2, num1 - num2);
}

// Function to perform multiplication
void performMultiplication() {
    int num1, num2;
    printf("Enter two numbers to multiply: ");
    scanf("%d %d", &num1, &num2);
    printf("The product of %d and %d is: %d\n", num1, num2, num1 * num2);
}

// Function to perform division
void performDivision() {
    int num1, num2;
    printf("Enter two numbers for division (num1 / num2): ");
    scanf("%d %d", &num1, &num2);
    if (num2 != 0) {
        printf("The result of %d / %d is: %.2f\n", num1, num2, (float)num1 / num2);
    } else {
        printf("Oh no! Division by zero is undefined.\n");
    }
}

// Function to generate a random math quiz
void randomMathQuiz() {
    int num1, num2, userAnswer, correctAnswer;
    char operation;
    
    // Seed the random number generator
    srand(time(0));
    
    // Randomly choose two numbers and an operation
    num1 = rand() % 100 + 1; // Random number between 1 and 100
    num2 = rand() % 100 + 1; // Random number between 1 and 100
    operation = "+-*/"[rand() % 4]; // Randomly choose an operation

    // Calculate the correct answer based on the operation
    if (operation == '+') {
        correctAnswer = num1 + num2;
        printf("What is %d + %d? ", num1, num2);
    } else if (operation == '-') {
        correctAnswer = num1 - num2;
        printf("What is %d - %d? ", num1, num2);
    } else if (operation == '*') {
        correctAnswer = num1 * num2;
        printf("What is %d * %d? ", num1, num2);
    } else if (operation == '/') {
        // Ensure no division by zero
        while (num2 == 0) {
            num2 = rand() % 100 + 1; // Change num2 until it's not zero
        }
        correctAnswer = num1 / num2;
        printf("What is %d / %d? ", num1, num2);
    }

    // Get user's answer
    scanf("%d", &userAnswer);
    // Check the answer
    if (userAnswer == correctAnswer) {
        printf("Correct! Great job!\n");
    } else {
        printf("Oops! The correct answer was: %d. Keep it up!\n", correctAnswer);
    }
}

int main() {
    int choice;

    // Main loop to run the program
    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                performAddition();
                break;
            case 2:
                performSubtraction();
                break;
            case 3:
                performMultiplication();
                break;
            case 4:
                performDivision();
                break;
            case 5:
                randomMathQuiz();
                break;
            case 0:
                printf("Thank you for playing! Have a wonderful day!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}