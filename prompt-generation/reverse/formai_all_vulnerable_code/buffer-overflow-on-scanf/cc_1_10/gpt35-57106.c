//FormAI DATASET v1.0 Category: Math exercise ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    srand(time(NULL));

    printf("Welcome to Math Exercise Program!\n");
    printf("Here are 10 questions to test your math skills:\n\n");

    int score = 0;
    int i;
    for(i = 1; i <= 10; i++)
    {
        int num1 = rand() % 100 + 1;
        int num2 = rand() % 100 + 1;
        int correct_answer;

        switch(rand() % 4)
        {
            case 0:
                correct_answer = num1 + num2;
                printf("%d. What is %d + %d?\n", i, num1, num2);
                break;
            case 1:
                correct_answer = num1 - num2;
                printf("%d. What is %d - %d?\n", i, num1, num2);
                break;
            case 2:
                correct_answer = num1 * num2;
                printf("%d. What is %d * %d?\n", i, num1, num2);
                break;
            case 3:
                correct_answer = num1 / num2;
                printf("%d. What is %d / %d (rounded to nearest whole number)?\n", i, num1, num2);
                break;
            default:
                break;
        }

        int user_answer;
        scanf("%d", &user_answer);

        if(user_answer == correct_answer)
        {
            printf("Correct!\n\n");
            score++;
        }
        else
        {
            printf("Incorrect! The correct answer is %d.\n\n", correct_answer);
        }
    }

    printf("You got %d out of 10 questions correct!\n", score);

    if(score > 7)
    {
        printf("Great job! You have exceptional math skills!\n");
    }
    else if(score > 4)
    {
        printf("Not bad! You have good math skills!\n");
    }
    else
    {
        printf("Better luck next time! Keep practicing your math skills!\n");
    }

    return 0;
}