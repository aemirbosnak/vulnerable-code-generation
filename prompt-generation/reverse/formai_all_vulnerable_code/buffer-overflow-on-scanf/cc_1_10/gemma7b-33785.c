//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 10

void play_game(int num_players, int max_num)
{
    int i, j, guess_num, score = 0, target_num;

    // Generate a random target number between 1 and max_num
    target_num = rand() % max_num + 1;

    // Each player takes a turn to guess the target number
    for (i = 0; i < num_players; i++)
    {
        printf("Enter your guess: ");
        scanf("%d", &guess_num);

        // Check if the guess is correct
        if (guess_num == target_num)
        {
            score++;
            printf("Congratulations! You guessed the target number.\n");
        }
        else
        {
            printf("Sorry, your guess is incorrect.\n");
        }
    }

    // Print the final score
    printf("Your final score is: %d\n", score);
}

int main()
{
    int num_players, max_num;

    // Get the number of players and the maximum number
    printf("Enter the number of players: ");
    scanf("%d", &num_players);

    printf("Enter the maximum number: ");
    scanf("%d", &max_num);

    // Play the game
    play_game(num_players, max_num);

    return 0;
}