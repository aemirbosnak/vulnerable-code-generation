//FormAI DATASET v1.0 Category: Math exercise ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int a, b, c, d, score = 0, counter = 0;
    time_t t;

    srand((unsigned) time(&t));

    printf("*********************\n");
    printf("***** Math Quiz *****\n");
    printf("*********************\n\n");

    while (1) 
    {
        a = rand() % 100;
        b = rand() % 100;
        c = rand() % 100;
        d = rand() % 100;

        printf("What is %d + %d - %d * %d?\n", a, b, c, d);
        int answer;
        scanf("%d", &answer);

        int correct_answer = a + b - c * d;

        if (answer == correct_answer) 
        {
            printf("Correct!\n");
            score += 10;
            counter++;
            printf("Score: %d, Counter: %d\n", score, counter);
            if (score % 50 == 0) 
            {
                printf("Congratulations! You've earned a bonus score of 50.\n");
                score += 50;
                printf("Score: %d\n", score);
            }
            printf("*********************************\n");
        } 
        else 
        {
            printf("Incorrect. The correct answer is %d.\n", correct_answer);
            counter++;
            printf("Score: %d, Counter: %d\n", score, counter);
            printf("*********************************\n");
        }

        printf("\n");

        if (counter == 5) 
        {
            printf("Quiz complete! Final score: %d\n", score);
            break;
        }
    }

    return 0;
}