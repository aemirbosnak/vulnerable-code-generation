//FormAI DATASET v1.0 Category: Math exercise ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Initializes random seed based on time

    printf("Welcome to the Math Exercise Program!\n\n");

    int num1, num2, answer, user_answer, score = 0, total_questions = 0;
    char choice;

    do {
        // Generates two random numbers between 1 and 100
        num1 = rand() % 100 + 1;
        num2 = rand() % 100 + 1;

        // Randomly chooses addition or subtraction 
        int operation = rand() % 2;

        if (operation == 0) { // Addition
            answer = num1 + num2;
            printf("Question %d: What is %d + %d? ", total_questions+1, num1, num2);
        } else { // Subtraction
            answer = num1 - num2;
            printf("Question %d: What is %d - %d? ", total_questions+1, num1, num2);
        }

        scanf("%d", &user_answer); // Gets user answer

        // Checks if user answered correctly and updates score
        if (user_answer == answer) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %d.\n", answer);
        }

        total_questions++; // Updates total number of questions

        // Asks user if they want to continue playing
        printf("\nDo you want to play again? (y/n) ");
        scanf(" %c", &choice);

        printf("\n");

    } while (choice == 'y' || choice == 'Y');

    // Prints final score and total questions
    printf("You answered %d out of %d questions correctly.\n", score, total_questions);

    return 0;
}