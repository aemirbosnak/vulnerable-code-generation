//FormAI DATASET v1.0 Category: Math exercise ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num1, num2, result, user_answer;
    int correct_answers = 0, wrong_answers = 0;

    srand(time(0)); // seed the random number generator

    printf("Welcome to the Math Exercise Program!\n");

    printf("\n\nWhat is the range of numbers you would like to work with?\n");
    printf("Enter the minimum value: ");
    scanf("%d", &num1);
    printf("Enter the maximum value: ");
    scanf("%d", &num2);

    printf("How many questions would you like to answer?\n");
    printf("Enter the number of questions: ");
    int num_questions;
    scanf("%d", &num_questions);

    for(int i = 1; i <= num_questions; i++)
    {
        // generate two random numbers
        int rand1 = rand() % (num2 - num1 + 1) + num1;
        int rand2 = rand() % (num2 - num1 + 1) + num1;

        printf("\nQuestion %d: What is %d + %d?\n", i, rand1, rand2);
        scanf("%d", &user_answer);

        // calculate actual result
        result = rand1 + rand2;

        // check if user's answer is correct
        if(user_answer == result)
        {
            printf("Correct! Good job!\n");
            correct_answers++;
        }
        else
        {
            printf("Sorry, incorrect. The correct answer is %d\n", result);
            wrong_answers++;
        }
    }

    float score = ((float)correct_answers / (float)num_questions) * 100.0; // calculate score

    printf("\n\nCongratulations! You have completed the Math Exercise Program!\n");
    printf("You answered %d questions correctly and %d questions incorrectly.\n", correct_answers, wrong_answers);
    printf("Your final score is %.2f%%.\n", score);

    return 0;
}