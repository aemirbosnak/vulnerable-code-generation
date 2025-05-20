//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 10

int main()
{
    int num_guess, guess_history[MAX_NUM], score = 0, game_status = 0;
    char answer;

    // Initialize guess history
    for (int i = 0; i < MAX_NUM; i++)
    {
        guess_history[i] = 0;
    }

    // Generate a random number between 1 and MAX_NUM
    srand(time(NULL));
    int target_num = rand() % MAX_NUM + 1;

    // Game loop
    while (game_status == 0)
    {
        printf("Enter your guess: ");
        scanf("%d", &num_guess);

        // Check if guess is valid
        if (num_guess < 1 || num_guess > MAX_NUM)
        {
            printf("Invalid guess.\n");
            continue;
        }

        // Check if guess has already been made
        if (guess_history[num_guess] == 1)
        {
            printf("You already guessed that number.\n");
            continue;
        }

        // Record guess history
        guess_history[num_guess] = 1;

        // Check if guess is correct
        if (num_guess == target_num)
        {
            printf("Congratulations! You won!\n");
            game_status = 1;
            score++;
        }
        else if (num_guess < target_num)
        {
            printf("Too low. Try again.\n");
        }
        else
        {
            printf("Too high. Try again.\n");
        }

        // Ask player if they want to continue
        printf("Do you want to continue playing? (Y/N): ");
        scanf(" %c", &answer);

        // Check if player wants to continue
        if (answer == 'Y' || answer == 'y')
        {
            // Reset guess history
            for (int i = 0; i < MAX_NUM; i++)
            {
                guess_history[i] = 0;
            }
        }
        else
        {
            // End game
            game_status = 1;
        }
    }

    // Print final score
    printf("Your final score: %d\n", score);

    return 0;
}