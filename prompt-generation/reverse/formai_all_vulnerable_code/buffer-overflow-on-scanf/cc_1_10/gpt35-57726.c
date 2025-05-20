//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate a random number
int generate_random_number(int lower, int upper)
{
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

int main()
{
    int guess, number_of_guesses = 0;
    int lower = 1, upper = 100;
    int random_number;

    // seed the random number generator with current time
    srand(time(0));

    printf("\n************** Welcome to the Number Guessing Game *****************\n\n");
    printf("RULES: You have to guess a number between 1 to 100\n");
    printf("HINTS: After each guess, the program will tell you whether the\n");
    printf("       actual number is higher or lower than your guess.\n\n");

    random_number = generate_random_number(lower, upper);

    while (1)
    {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        number_of_guesses++;

        if (guess == random_number)
        {
            printf("\nCongratulations! You have guessed the correct number in %d attempts.\n", number_of_guesses);
            break;
        }
        else if (guess < random_number)
        {
            printf("\nIncorrect! Actual number is higher than your guess.\n");
        }
        else
        {
            printf("\nIncorrect! Actual number is lower than your guess.\n");
        }
    }

    return 0;
}