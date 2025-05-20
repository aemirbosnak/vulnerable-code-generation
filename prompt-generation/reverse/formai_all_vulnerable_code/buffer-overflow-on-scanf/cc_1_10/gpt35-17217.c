//FormAI DATASET v1.0 Category: Math exercise ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random integer between range min and max
int generateRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to display the menu
void displayMenu() {
    printf("Welcome to the Math Exercise Program!\n");
    printf("1. Addition Exercise\n");
    printf("2. Subtraction Exercise\n");
    printf("3. Multiplication Exercise\n");
    printf("4. Exit Program\n");
    printf("\nPlease choose an option: ");
}

// Function to add two numbers and return the result
int add(int num1, int num2) {
    return num1 + num2;
}

// Function to subtract two numbers and return the result
int subtract(int num1, int num2) {
    return num1 - num2;
}

// Function to multiply two numbers and return the result
int multiply(int num1, int num2) {
    return num1 * num2;
}

// Function to display the results of the exercise
void displayResults(int answer, int userAnswer) {
    if (answer == userAnswer) {
        printf("Congratulations! Your answer is correct.\n");
    } else {
        printf("Sorry. Your answer is incorrect. The correct answer is %d.\n", answer);
    }
}

int main() {
    int option, num1, num2, answer, userAnswer;

    srand(time(NULL)); // Initialize random number generator

    do {
        displayMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                // Addition Exercise
                num1 = generateRandomNumber(1, 100);
                num2 = generateRandomNumber(1, 100);
                answer = add(num1, num2);

                printf("Please solve the following problem:\n");
                printf("%d + %d = ", num1, num2);
                scanf("%d", &userAnswer);

                displayResults(answer, userAnswer);
                break;

            case 2:
                // Subtraction Exercise
                num1 = generateRandomNumber(1, 100);
                num2 = generateRandomNumber(1, num1);
                answer = subtract(num1, num2);

                printf("Please solve the following problem:\n");
                printf("%d - %d = ", num1, num2);
                scanf("%d", &userAnswer);

                displayResults(answer, userAnswer);
                break;

            case 3:
                // Multiplication Exercise
                num1 = generateRandomNumber(1, 20);
                num2 = generateRandomNumber(1, 20);
                answer = multiply(num1, num2);

                printf("Please solve the following problem:\n");
                printf("%d * %d = ", num1, num2);
                scanf("%d", &userAnswer);

                displayResults(answer, userAnswer);
                break;

            case 4:
                // Exit Program
                printf("Thank you for using the Math Exercise Program.\n");
                break;

            default:
                printf("Invalid option. Please try again.\n");
                break;
        }

        printf("\n");
    } while (option != 4);

    return 0;
}