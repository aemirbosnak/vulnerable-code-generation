//FormAI DATASET v1.0 Category: Math exercise ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Function to generate a random number within a specified range
int generateRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    int num1, num2, choice;
    float result;

    printf("Welcome to the Math Excercise Program!\nChoose the type of operation you want to practice:\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Set the range for the two numbers based on the user's choice of operation
    int min, max;
    switch (choice) {
        case 1:
            printf("Addition selected\n");
            min = 0, max = 100;
            break;
        case 2:
            printf("Subtraction selected\n");
            min = -100, max = 100;
            break;
        case 3:
            printf("Multiplication selected\n");
            min = 0, max = 25;
            break;
        case 4:
            printf("Division selected\n");
            min = 1, max = 50;
            break;
        default:
            printf("Invalid choice, program terminating\n");
            exit(0);
    }

    // Generate two random numbers within the specified range
    srand(time(NULL));
    num1 = generateRandomNumber(min, max);
    num2 = generateRandomNumber(min, max);

    // Perform the selected operation on the two numbers
    switch (choice) {
        case 1:
            result = num1 + num2;
            break;
        case 2:
            result = num1 - num2;
            break;
        case 3:
            result = num1 * num2;
            break;
        case 4:
            if (num2 == 0) {
                printf("Error: division by zero, program terminating\n");
                exit(0);
            }
            result = (float) num1 / num2;
            break;
    }

    // Prompt the user to enter their answer and provide feedback
    float userAnswer;
    printf("What is the result of %d ", num1);
    switch (choice) {
        case 1:
            printf("+");
            break;
        case 2:
            printf("-");
            break;
        case 3:
            printf("*");
            break;
        case 4:
            printf("/");
            break;
    }
    printf(" %d ?\nEnter your answer: ", num2);
    scanf("%f", &userAnswer);

    if (fabs(userAnswer - result) <= 0.01) {
        printf("Congratulations! Your answer is correct\n");
    }
    else {
        printf("Sorry, the correct answer is %.2f\n", result);
    }

    printf("Thank you for using the Math Excercise Program, goodbye!\n");

    return 0;
}