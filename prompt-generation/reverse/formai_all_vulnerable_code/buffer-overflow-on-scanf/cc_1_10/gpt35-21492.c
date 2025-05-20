//FormAI DATASET v1.0 Category: Math exercise ; Style: real-life
/*
This program will randomly generate a set of addition and subtraction problems and will prompt the user to solve them. 
At the end of the quiz, it will display the user's score. 

Instructions: 
- User will be prompted to enter the number of questions they want to attempt. 
- Questions will be randomly generated between 1 and 100 for both operands. 
- For each question, user will be prompted to enter their answer. 
- If the answer is correct, 1 point will be awarded, otherwise no points will be awarded. 
- The final score will be displayed at the end of the quiz.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Variables
    int num_questions, score = 0;

    // Prompt the user for the number of questions they want to attempt
    printf("How many questions do you want to attempt? ");
    scanf("%d", &num_questions);

    // Generate random addition and subtraction problems and prompt user for answers
    for (int i = 1; i <= num_questions; i++) {
        // Generate two random numbers between 1 and 100
        int num1 = rand() % 100 + 1;
        int num2 = rand() % 100 + 1;

        // Generate an operator (1 for addition, 2 for subtraction)
        int operator = rand() % 2 + 1;

        // Display the problem and prompt the user for an answer
        int user_answer;
        if (operator == 1) {
            printf("%d + %d = ", num1, num2);
            scanf("%d", &user_answer);
            if (user_answer == num1 + num2) {
                score++;
            }
        } else {
            printf("%d - %d = ", num1, num2);
            scanf("%d", &user_answer);
            if (user_answer == num1 - num2) {
                score++;
            }
        }
    }

    // Display the final score
    printf("\nYou scored %d out of %d.\n", score, num_questions);

    return 0;
}