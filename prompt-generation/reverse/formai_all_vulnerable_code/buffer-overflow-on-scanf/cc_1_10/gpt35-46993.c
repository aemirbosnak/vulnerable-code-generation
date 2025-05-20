//FormAI DATASET v1.0 Category: Math exercise ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Initialize variables
    int num1, num2, answer, userAnswer, option;
    float score = 0;
    char userName[20];

    // Get user name
    printf("Enter your name: ");
    scanf("%s", userName);

    // Get user's option
    printf("\nHello, %s!\n", userName);
    printf("What type of math exercise would you like to practice today?\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n\n");
    printf("Please select an option (1, 2 or 3): ");
    scanf("%d", &option);

    // Ensure valid option is selected
    while (option < 1 || option > 3) {
        printf("\nInvalid option selected. Please select either 1, 2 or 3: ");
        scanf("%d", &option);
    }

    // Generate math exercises and get user answers
    while (score < 10) {
        srand(time(0));

        // Generate random numbers
        num1 = rand() % 101;
        num2 = rand() % 101;

        // Check option selected and generate corresponding exercise
        if (option == 1) {
            answer = num1 + num2;
            printf("\n%d + %d = ", num1, num2);
        } else if (option == 2) {
            answer = num1 - num2;
            printf("\n%d - %d = ", num1, num2);
        } else {
            answer = num1 * num2;
            printf("\n%d x %d = ", num1, num2);
        }

        // Get user's answer
        scanf("%d", &userAnswer);

        // Check if answer is correct and calculate score
        if (userAnswer == answer) {
            printf("Correct!\n");
            score += 1;
        } else {
            printf("Incorrect. The correct answer is: %d\n", answer);
        }
    }

    // Display final score
    printf("\nWell done, %s! You scored %.0f out of 10.\n", userName, score);

    return 0;
}