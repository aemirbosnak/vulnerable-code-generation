//FormAI DATASET v1.0 Category: Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to play the game
void play_game(int level)
{
    printf("\nYou are playing Level %d\n", level);

    // Generate a random number
    int random_number = rand() % level + 1;

    int guess_count = 0;
    int guess_limit = 3;

    while (guess_count < guess_limit)
    {
        printf("\nEnter your guess between 1 and %d: ", level);
        int guess;
        scanf("%d", &guess);

        if (guess == random_number)
        {
            printf("\nCongratulations! You have guessed the number correctly!\n");
            return;
        }
        else
        {
            printf("\nIncorrect guess. Please try again.\n");
            guess_count++;
        }
    }

    printf("\nGame Over. You have run out of guesses.\n");
}

int main()
{
    int selection = 0;

    do
    {
        printf("\n--- Welcome to the Number Guessing Game! ---\n\n");
        printf("Select a level to play:\n");
        printf("1. Easy (1-5)\n");
        printf("2. Intermediate (1-10)\n");
        printf("3. Hard (1-20)\n");
        printf("4. Quit\n");

        scanf("%d", &selection);

        switch (selection)
        {
            case 1:
                play_game(5);
                break;
            case 2:
                play_game(10);
                break;
            case 3:
                play_game(20);
                break;
            case 4:
                printf("\nThank you for playing the Number Guessing Game!\n");
                break;
            default:
                printf("\nInvalid selection. Please try again.\n");
        }
    } while (selection != 4);

    return 0;
}