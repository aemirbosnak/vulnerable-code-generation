//Falcon2-11B DATASET v1.0 Category: Terminal Based Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initialize variables
    int user_choice;
    int computer_choice;
    int game_result = 0;
    srand(time(NULL)); // Seed the random number generator

    printf("Welcome to the Rock Paper Scissors Game!\n");

    // Game loop
    while(game_result == 0)
    {
        // Get user choice
        printf("Choose your weapon: 1 - Rock, 2 - Paper, 3 - Scissors\n");
        scanf("%d", &user_choice);

        // Randomize computer choice
        computer_choice = rand() % 3 + 1;

        // Check user choice and computer choice
        if (user_choice == computer_choice)
        {
            printf("It's a tie!\n");
        }
        else if ((user_choice == 1 && computer_choice == 2) ||
               (user_choice == 2 && computer_choice == 3) ||
               (user_choice == 3 && computer_choice == 1))
        {
            game_result = 1;
            printf("You win!\n");
        }
        else
        {
            game_result = 2;
            printf("You lose...\n");
        }

        // Ask to play again
        printf("Do you want to play again? (y/n)\n");
        char play_again;
        scanf(" %c", &play_again);
        if (play_again == 'n')
        {
            break;
        }
    }

    printf("Thank you for playing!\n");

    return 0;
}