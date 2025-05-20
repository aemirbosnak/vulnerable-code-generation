//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

void generate_primes(int n);

int main()
{
    int n, i, j, score = 0, primes_count = 0;
    char board[100];

    printf("Welcome to Prime Memory Game!\n");
    printf("Enter the number of rounds: ");
    scanf("%d", &n);

    generate_primes(n);

    for (i = 0; i < n; i++)
    {
        printf("Round %d:\n", i + 1);
        for (j = 0; j < primes_count; j++)
        {
            printf("%d ", board[j]);
        }
        printf("\n");
        printf("Enter the number of the prime you want to guess: ");
        scanf("%d", &i);

        if (board[i - 1] == 'X')
        {
            score++;
            printf("Congratulations! You guessed the prime.\n");
        }
        else
        {
            printf("Oops! The number you entered is not a prime.\n");
        }
    }

    printf("Your final score: %d\n", score);

    return 0;
}

void generate_primes(int n)
{
    int i, j, primes_count = 0;
    char board[100];

    for (i = 2; i <= n; i++)
    {
        for (j = 2; j * i <= n; j++)
        {
            if (i % j == 0)
            {
                board[primes_count++] = 'O';
            }
        }
        board[primes_count++] = 'X';
    }
}