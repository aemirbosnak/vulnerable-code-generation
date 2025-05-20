//FormAI DATASET v1.0 Category: Math exercise ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num1, num2, num3, num4, num5, answer;
    int correctAnswers = 0;
    int wrongAnswers = 0;
    int totalQuestions = 0;
    char selection;
    time_t t;

    // Intializes random number generator
    srand((unsigned) time(&t));

    printf("Welcome to the Math Exercise Program!\n");
    printf("You have 60 seconds to solve as many math problems as you can.\n");
    printf("Press 'y' to start or 'q' to quit.\n");

    // Asks user to start or quit
    scanf("%c", &selection);

    while (selection == 'y' || selection == 'Y')
    {
        // Generates random math problems
        num1 = rand() % 100;
        num2 = rand() % 100;
        num3 = rand() % 1000;
        num4 = rand() % 1000;
        num5 = rand() % 10;
        
        // Randomly selects the math operation
        switch(rand() % 4)
        {
            // Addition
            case 0:
                printf("\n%d + %d = ", num1, num2);
                answer = num1 + num2;
                break;
            // Subtraction
            case 1:
                printf("\n%d - %d = ", num1, num2);
                answer = num1 - num2;
                break;
            // Multiplication
            case 2:
                printf("\n%d * %d = ", num1, num2);
                answer = num1 * num2;
                break;
            // Division
            case 3:
                printf("\n%d / %d = ", num3, num5);
                answer = num3 / num5;
                break;
        }

        // Asks the player to enter their answer
        int playerAnswer;
        scanf("%d", &playerAnswer);
        totalQuestions++;
        
        // Checks if the answer is correct
        if (playerAnswer == answer)
        {
            correctAnswers++;
            printf("Correct!\n");
        }
        else
        {
            wrongAnswers++;
            printf("Wrong!\n");
        }
        
        // Ends the game if 60 seconds have passed
        if (time(NULL) - t >= 60)
        {
            printf("\nTime's up!\n");
            printf("You got %d out of %d questions correct.\n", correctAnswers, totalQuestions);
            printf("Press 'y' to play again or 'q' to quit.\n");
            scanf(" %c", &selection);
            correctAnswers = 0;
            wrongAnswers = 0;
            totalQuestions = 0;
            t = time(NULL);
        }
    }
    
    printf("Thanks for playing!\n");

    return 0;
}