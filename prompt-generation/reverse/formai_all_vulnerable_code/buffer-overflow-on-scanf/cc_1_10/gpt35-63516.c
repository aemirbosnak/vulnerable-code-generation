//FormAI DATASET v1.0 Category: Game ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

void *player1(void *arg);
void *player2(void *arg);

int main()
{
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, player1, NULL);
    pthread_create(&thread2, NULL, player2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}

void *player1(void *arg)
{
    int score = 0;
    char play;

    while (1)
    {
        printf("Player 1, enter your guess (A or B): ");
        scanf(" %c", &play);

        if (play == 'A')
        {
            printf("Correct!\n");
            score++;
        }
        else
        {
            printf("Incorrect.\n");
            break;
        }
    }

    printf("Player 1's final score: %d\n", score);
    pthread_exit(NULL);
}

void *player2(void *arg)
{
    int score = 0;
    char play;

    while (1)
    {
        printf("Player 2, enter your guess (A or B): ");
        scanf(" %c", &play);

        if (play == 'B')
        {
            printf("Correct!\n");
            score++;
        }
        else
        {
            printf("Incorrect.\n");
            break;
        }
    }

    printf("Player 2's final score: %d\n", score);
    pthread_exit(NULL);
}