//FormAI DATASET v1.0 Category: Educational ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

    printf("Welcome to the Mind-Bender C program!\n");

    int num1, num2, operator, answer, userAnswer, count = 0;
    char operatorChar;

    srand(time(NULL));

    // Create an infinite loop that can be broken out of when the user wants to stop
    while (1) {

        // Generate two random numbers between 1 and 100
        num1 = rand() % 100 + 1;
        num2 = rand() % 100 + 1;

        // Generate a random operator (1: addition, 2: subtraction, 3: multiplication, 4: division)
        operator = rand() % 4 + 1;

        // Convert operator integer to a character
        switch (operator) {
            case 1:
                operatorChar = '+';
                answer = num1 + num2;
                break;
            case 2:
                operatorChar = '-';
                answer = num1 - num2;
                break;
            case 3:
                operatorChar = '*';
                answer = num1 * num2;
                break;
            case 4:
                operatorChar = '/';
                answer = num1 / num2;
                break;
        }

        // Prompt the user with the generated math problem
        printf("\nSolve this problem: %d %c %d = ", num1, operatorChar, num2);

        // Get the user's answer
        scanf("%d", &userAnswer);

        // Check if the user's answer is correct and give feedback
        if (userAnswer == answer) {
            printf("Correct!\n");
            count++;
        }
        else {
            printf("Incorrect. The correct answer is %d.\n", answer);
        }

        // Ask if the user wants to continue or quit
        printf("Do you want to continue (1) or quit (2)? ");
        int choice;
        scanf("%d", &choice);
        if (choice == 2) {
            break;
        }
    }

    // Print the user's score
    printf("\nYou got %d out of %d questions correct.", count, count + 1);

    return 0;
}