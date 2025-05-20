//FormAI DATASET v1.0 Category: Math exercise ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int a, b, c, d, e, f, score = 0, life = 3;
    char answer;
    srand(time(NULL));
    printf("Welcome to the Medieval Math Quiz!\n");
    printf("You have %d lives. Be careful and good luck!\n", life);
    do
    {
        a = rand() % 20 + 1;
        b = rand() % 10 + 1;
        c = rand() % 5 + 1;
        d = rand() % 10 + 1;
        e = rand() % 20 + 1;
        f = rand() % 5 + 1;

        printf("\nQuestion 1: What is %d + %d?\n", a, b);
        scanf(" %c", &answer);
        if (answer == (a + b) + 48)
        {
            printf("Correct!\n");
            score++;
        }
        else
        {
            printf("Incorrect! The correct answer is %d.\n", a + b);
            life--;
        }

        printf("\nQuestion 2: What is %d - %d?\n", c, d);
        scanf(" %c", &answer);
        if (answer == (c - d) + 48)
        {
            printf("Correct!\n");
            score++;
        }
        else
        {
            printf("Incorrect! The correct answer is %d.\n", c - d);
            life--;
        }

        printf("\nQuestion 3: What is %d * %d?\n", e, f);
        scanf(" %c", &answer);
        if (answer == (e * f) + 48)
        {
            printf("Correct!\n");
            score++;
        }
        else
        {
            printf("Incorrect! The correct answer is %d.\n", e * f);
            life--;
        }

        printf("\nYour current score is %d and you have %d lives left.\n", score, life);

    } while (life > 0);

    if (life == 0)
    {
        printf("\nGame over! Your final score is %d.\n", score);
    }

    return 0;
}