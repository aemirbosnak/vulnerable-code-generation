//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int choice, score = 0, lives = 3;
    char name[20];
    printf("Enter your name: ");
    scanf("%s", name);

    printf("Welcome, %s! Let's play a game of Guess the Number.\n", name);

    // Game loop
    while (lives > 0)
    {
        int number = rand() % 11 + 1;
        printf("Guess a number between 1 and 10: ");
        scanf("%d", &choice);

        if (choice == number)
        {
            printf("Congratulations, you guessed the number! You win!\n");
            score++;
        }
        else if (choice < number)
        {
            printf("Sorry, your guess is too low. Try again.\n");
        }
        else
        {
            printf("Sorry, your guess is too high. Try again.\n");
        }

        // Check if the player has won or lost
        if (score == 5)
        {
            printf("Congratulations, %s! You have won the game!\n", name);
            break;
        }
        else if (lives == 0)
        {
            printf("Sorry, %s. You have run out of lives. Game over.\n", name);
            break;
        }
    }

    // End of game
    printf("Thank you for playing, %s. See you next time.\n", name);

    return 0;
}