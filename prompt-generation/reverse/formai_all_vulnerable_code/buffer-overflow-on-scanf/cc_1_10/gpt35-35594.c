//FormAI DATASET v1.0 Category: Memory Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 4

/* Function prototypes */
void shuffle(int arr[]);
void swap(int *x, int *y);
void playGame(int arr[]);

int main()
{
    int arr[MAX] = {1, 2, 3, 4};

    /* Randomizing the array */
    srand(time(NULL));
    shuffle(arr);

    /* Display the shuffled array */
    printf("The memory game starts:\n");
    for (int i = 0; i < MAX; i++)
        printf("? ");

    printf("\n");

    /* Wait for user input to reveal the numbers */
    getchar();
    for (int i = 0; i < MAX; i++)
        printf("%d ", arr[i]);

    /* Wait for user input to continue */
    getchar();

    /* Clear the screen */
    system("cls");

    /* Start the game */
    playGame(arr);

    return 0;
}

/* Shuffle array using Fisher-Yates algorithm */
void shuffle(int arr[])
{
    for (int i = MAX - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        swap(&arr[i], &arr[j]);
    }
}

/* Swap two variables */
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

/* Play game with the shuffled array */
void playGame(int arr[])
{
    int guesses[MAX] = {0}; /* Keep track of user guesses */
    int correct = 0;        /* Keep track of correct guesses */

    while (correct < MAX)
    {
        /* Display the shuffled array */
        for (int i = 0; i < MAX; i++)
        {
            if (guesses[i] == 1)
                printf("%d ", arr[i]);
            else
                printf("? ");
        }

        /* Ask for user input */
        printf("\nGuess a number 1-4: ");
        int guess;
        scanf("%d", &guess);

        /* Check if user input is valid */
        if (guess < 1 || guess > 4)
        {
            printf("Invalid input. Try again.\n");
            continue;
        }

        /* Check if user has already made the same guess */
        for (int i = 0; i < MAX; i++)
        {
            if (guesses[i] == 1 && arr[i] == guess)
            {
                printf("You've already guessed that number. Try again.\n");
                continue;
            }
        }

        /* Check if user guess is correct */
        for (int i = 0; i < MAX; i++)
        {
            if (arr[i] == guess)
            {
                guesses[i] = 1;
                correct++;
            }
        }

        /* Clear the screen */
        system("cls");
    }

    /* Display the final array and winning message */
    for (int i = 0; i < MAX; i++)
        printf("%d ", arr[i]);
    printf("\nCongratulations! You won!\n");
}