//MISTRAL-7B DATASET v1.0 Category: Recursive ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 7
#define MIN_NUMBER 1
#define MAX_NUMBER 100

int generate_number();
int recursive_guess(int number, int guess, int tries_left, int *winner);

int main(int argc, char *argv[])
{
    int number = generate_number();
    int guess;
    int tries_left = MAX_TRIES;
    int my_score = 0;
    int opponent_score = 0;
    int winner = 0;

    printf("Welcome to the Number Guessing Game! I'm thinking of a number between %d and %d.\n", MIN_NUMBER, MAX_NUMBER);
    printf("You have %d tries to guess it. Your opponent also has %d tries.\n", MAX_TRIES, MAX_TRIES);

    while (tries_left > 0 && winner == 0)
    {
        recursive_guess(number, guess, tries_left, &winner);

        if (winner == 1)
            printf("Congratulations, you guessed the number correctly! Your score is %d, opponent's score is %d.\n", my_score + 1, opponent_score);
        else if (winner == -1)
            printf("Sorry, your guess is too high. Opponent's turn.\n");
        else if (winner == -2)
            printf("Sorry, your guess is too low. Opponent's turn.\n");

        if (tries_left > 1)
        {
            printf("Your turn again. Your score is %d.\n", my_score);
            scanf("%d", &guess);
        }
        else
        {
            printf("Last chance! Your turn.\n");
            guess = generate_number();
        }

        if (guess == number)
            my_score++;
        else
            opponent_score++;

        tries_left--;
    }

    if (winner == 0)
        printf("Game over! The number was %d.\n", number);

    return 0;
}

int generate_number()
{
    int number;
    srand(time(NULL));
    number = rand() % (MAX_NUMBER - MIN_NUMBER + 1) + MIN_NUMBER;
    return number;
}

int recursive_guess(int number, int guess, int tries_left, int *winner)
{
    if (guess < number)
    {
        if (tries_left > 1)
        {
            (*winner) = recursive_guess(number, guess + 1, tries_left - 1, winner);
            if (*winner != 0)
                return *winner;
        }
        else
            (*winner) = -2;
    }
    else if (guess > number)
    {
        if (tries_left > 1)
        {
            (*winner) = recursive_guess(number, guess - 1, tries_left - 1, winner);
            if (*winner != 0)
                return *winner;
        }
        else
            (*winner) = -1;
    }
    else
    {
        (*winner) = 1;
    }

    return *winner;
}