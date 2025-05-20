//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: innovative
#include <stdio.h>

#define MAX_LIVES 3

void play_again(int lives);

int main()
{
    int lives = MAX_LIVES;
    char guess_word[20] = "SECRET MESSAGE";
    char guess_letter;

    // Loop until the player guesses the word or runs out of lives
    while (lives > 0)
    {
        // Get the player's guess
        printf("Enter a letter: ");
        scanf("%c", &guess_letter);

        // Check if the guess letter is correct
        if (guess_letter == guess_word[0] || guess_letter == guess_word[1] || guess_letter == guess_word[2] || guess_letter == guess_word[3] || guess_letter == guess_word[4])
        {
            // The guess letter is correct
            printf("Correct guess!\n");

            // Check if the player has won
            if (guess_word[0] == guess_letter && guess_word[1] == guess_letter && guess_word[2] == guess_letter && guess_word[3] == guess_letter && guess_word[4] == guess_letter)
            {
                // The player has won
                printf("You have won! Congratulations!\n");
                break;
            }
        }
        else
        {
            // The guess letter is incorrect
            printf("Incorrect guess. Try again.\n");

            // Subtract a life
            lives--;
        }
    }

    // The player has run out of lives
    if (lives == 0)
    {
        printf("Game over. Sorry, you have run out of lives.\n");
    }

    // Play again
    play_again(lives);

    return 0;
}

void play_again(int lives)
{
    char answer;

    // Ask the player if they want to play again
    printf("Do you want to play again? (Y/N): ");
    scanf("%c", &answer);

    // If the player wants to play again, start the game over
    if (answer == 'Y' || answer == 'y')
    {
        main();
    }
}