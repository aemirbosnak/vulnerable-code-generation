//Gemma-7B DATASET v1.0 Category: Educational ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_Guess 5

int main()
{
    int player_one_guess, player_two_guess, secret_number, rounds = 0;
    char player_one_name[20], player_two_name[20];

    // Seed the random number generator
    srand(time(NULL));

    // Generate a secret number
    secret_number = rand() % MAX_Guess + 1;

    // Get the players' names
    printf("Enter player one's name: ");
    scanf("%s", player_one_name);

    printf("Enter player two's name: ");
    scanf("%s", player_two_name);

    // Start the game loop
    while (rounds < MAX_Guess)
    {
        // Get the player one's guess
        printf("%s, guess a number between 1 and %d: ", player_one_name, MAX_Guess);
        scanf("%d", &player_one_guess);

        // Get the player two's guess
        printf("%s, guess a number between 1 and %d: ", player_two_name, MAX_Guess);
        scanf("%d", &player_two_guess);

        // Check if the guesses are correct
        if (player_one_guess == secret_number && player_two_guess == secret_number)
        {
            // Both players guess correctly
            printf("Congratulations, %s and %s, you have guessed the secret number!", player_one_name, player_two_name);
            break;
        }
        else if (player_one_guess == secret_number)
        {
            // Player one guesses correctly
            printf("Congratulations, %s, you have guessed the secret number!", player_one_name);
            break;
        }
        else if (player_two_guess == secret_number)
        {
            // Player two guesses correctly
            printf("Congratulations, %s, you have guessed the secret number!", player_two_name);
            break;
        }
        else
        {
            // Neither player guesses correctly
            printf("Sorry, neither player has guessed the secret number. Try again.\n");
            rounds++;
        }
    }

    // End the game loop
    return 0;
}