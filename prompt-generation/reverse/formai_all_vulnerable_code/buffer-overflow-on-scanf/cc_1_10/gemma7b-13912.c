//Gemma-7B DATASET v1.0 Category: Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 100

void play_game()
{
    int number_of_guesses = 0;
    int guess_number;
    int target_number;

    target_number = rand() % MAX_NUM + 1;

    printf("Welcome to the guessing game!\n");
    printf("I'm thinking of a number between 1 and %d. Can you guess what it is?\n", MAX_NUM);

    while (number_of_guesses < 5)
    {
        printf("Enter your guess: ");
        scanf("%d", &guess_number);

        if (guess_number == target_number)
        {
            printf("Congratulations! You guessed the number!\n");
            break;
        }
        else if (guess_number < target_number)
        {
            printf("Your guess is too low. Try again.\n");
        }
        else if (guess_number > target_number)
        {
            printf("Your guess is too high. Try again.\n");
        }

        number_of_guesses++;
    }

    if (number_of_guesses == 5)
    {
        printf("Sorry, you ran out of guesses. The target number was %d.\n", target_number);
    }
}

int main()
{
    play_game();

    return 0;
}