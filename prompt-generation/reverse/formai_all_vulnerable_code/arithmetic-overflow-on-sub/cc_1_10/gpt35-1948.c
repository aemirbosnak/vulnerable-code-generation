//FormAI DATASET v1.0 Category: Math exercise ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the immersive Math Exercise game!\n");
    printf("In this game, you will be given 10 random Math questions to answer within 15 seconds.\n");
    printf("Are you ready to play? Press any key to start.\n");
    getchar(); // wait for user input

    int correct_answers = 0;
    int i;
    for (i = 1; i <= 10; i++)
    {
        // generate two random numbers between 1 to 20
        srand(time(0)); // set seed for random number generation
        int num1 = rand() % 20 + 1;
        int num2 = rand() % 20 + 1;

        // randomly choose an operator between *, +, -
        srand(time(0) - i); // set seed for operator randomization
        int op = rand() % 3;
        char operator;
        int result;
        switch (op)
        {
            case 0: // multiply
                operator = '*';
                result = num1 * num2;
                break;
            case 1: // add
                operator = '+';
                result = num1 + num2;
                break;
            case 2: // subtract
                operator = '-';
                result = num1 - num2;
                break;
        }

        // ask the question and wait for user input
        printf("\nQuestion %d:\n", i);
        printf("%d %c %d =\n", num1, operator, num2);
        time_t start_time = time(0); // start time
        int user_answer;
        scanf("%d", &user_answer);
        time_t end_time = time(0); // end time
        double time_diff = difftime(end_time, start_time);

        // check user answer
        if (user_answer == result && time_diff <= 15)
        {
            printf("Correct! (time: %.2f seconds)\n", time_diff);
            correct_answers++;
        }
        else
        {
            printf("Wrong! The correct answer is %d. (time: %.2f seconds)\n", result, time_diff);
        }
    }

    // display final score and exit
    printf("\nCongratulations! You have answered %d out of 10 questions correctly.\n", correct_answers);
    printf("Thank you for playing the immersive Math Exercise game!\n");
    return 0;
}