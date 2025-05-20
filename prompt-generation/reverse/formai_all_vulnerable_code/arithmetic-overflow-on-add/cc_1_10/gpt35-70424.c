//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>
#include <pthread.h>

#define ROWS 5
#define COLS 5

int numbers[ROWS * COLS] = {0};
bool called[ROWS * COLS] = {false};
pthread_mutex_t mutex;

void generateNumbers()
{
    srand(time(NULL));
    for (int i = 0; i < ROWS * COLS; i++)
    {
        int num = (rand() % (15 * i)) + ((15 * i) + 1);
        numbers[i] = num;
    }
}

void callNumber(int *num)
{
    pthread_mutex_lock(&mutex);

    for (int i = 0; i < ROWS * COLS; i++)
    {
        if (numbers[i] == *num)
        {
            called[i] = true;
            break;
        }
    }

    printf("Calling number: %d\n", *num);

    bool win = true;
    for (int r = 0; r < ROWS; r++)
    {
        win = true;
        for (int c = 0; c < COLS; c++)
        {
            if (!called[r * ROWS + c])
            {
                win = false;
                break;
            }
        }
        if (win)
        {
            printf("Bingo! Row %d wins!\n", r + 1);
            pthread_exit(NULL);
        }
    }

    for (int c = 0; c < COLS; c++)
    {
        win = true;
        for (int r = 0; r < ROWS; r++)
        {
            if (!called[r * ROWS + c])
            {
                win = false;
                break;
            }
        }
        if (win)
        {
            printf("Bingo! Column %d wins!\n", c + 1);
            pthread_exit(NULL);
        }
    }

    win = true;
    for (int i = 0; i < ROWS * COLS; i += ROWS + 1)
    {
        if (!called[i])
        {
            win = false;
            break;
        }
    }
    if (win)
    {
        printf("Bingo! Diagonal wins!\n");
        pthread_exit(NULL);
    }

    win = true;
    for (int i = ROWS - 1; i < ROWS * COLS - (ROWS - 2); i += ROWS - 1)
    {
        if (!called[i])
        {
            win = false;
            break;
        }
    }
    if (win)
    {
        printf("Bingo! Diagonal wins!\n");
        pthread_exit(NULL);
    }

    pthread_mutex_unlock(&mutex);
}

int main()
{
    generateNumbers();

    pthread_t tid;
    pthread_mutex_init(&mutex, NULL);
    char input[5];

    while (true)
    {
        printf("\nEnter a number between 1 and 75 (or 'q' to quit): ");
        fgets(input, 5, stdin);
        if (tolower(input[0]) == 'q')
        {
            printf("Quitting\n");
            break;
        }
        int num = atoi(input);
        if (num < 1 || num > 75)
        {
            printf("Invalid input. Please enter a number between 1 and 75\n");
            continue;
        }
        pthread_create(&tid, NULL, (void *)&callNumber, &num);
    }

    pthread_mutex_destroy(&mutex);
    return 0;
}