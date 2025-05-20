//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

void print_instructions(void);
int generate_random_number(int min, int max);
int validate_guess(int guess, int target);
void print_game_over(int target);

int main(void)
{
    int min = 1, max = 20;
    int target = generate_random_number(min, max);
    int guess, valid, attempts = 0;

    print_instructions();

    while (attempts < 5)
    {
        printf("\nAttempt %d: Enter your guess (%d-%d): ", attempts + 1, min, max);
        scanf("%d", &guess);

        valid = validate_guess(guess, target);

        if (valid == 1)
        {
            printf("\nCongratulations, you guessed it right! The answer was %d.\n", target);
            return 0;
        }
        else if (valid == -1) 
        {
            printf("Your guess was below the accepted range. Try again.\n");
        }
        else if (valid == -2) 
        {
            printf("Your guess was above the accepted range. Try again.\n");
        }
        else 
        {
            printf("Your guess was incorrect. Try again.\n");
        }

        attempts++;
    }

    print_game_over(target);
    return 0;
}

void print_instructions(void)
{
    printf("\n\nWelcome to the Number Guessing Game!\n");
    printf("You have 5 attempts to guess a number between 1 and 20.\n");
}

int generate_random_number(int min, int max)
{
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min;
}

int validate_guess(int guess, int target)
{
    if (guess < 1) return -1;
    if (guess > 20) return -2;
    if (guess == target) return 1;
    return 0;
}

void print_game_over(int target)
{
    printf("\n\nGame Over! You have reached 5 attempts.\n");
    printf("The number you were trying to guess was %d.\n", target);
    printf("Better luck next time!\n\n");
}