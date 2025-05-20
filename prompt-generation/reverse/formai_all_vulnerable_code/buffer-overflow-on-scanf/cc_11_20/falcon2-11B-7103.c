//Falcon2-11B DATASET v1.0 Category: Cryptography Implementation ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    // Randomly choose a number between 1 and 3 to represent the player's choice
    int player_choice = rand() % 3 + 1;

    int computer_choice = 0;
    int player_score = 0;
    int computer_score = 0;

    // Loop until both players have chosen an option
    while(player_score < 3 || computer_score < 3)
    {
        // Allow the player to choose an option
        printf("Player: Enter your choice (1 for Rock, 2 for Paper, 3 for Scissors): ");
        scanf("%d", &player_choice);

        // Choose a random number for the computer's choice
        computer_choice = rand() % 3 + 1;

        // Check the result of the game and update the scores
        if(player_choice == computer_choice)
            printf("It's a draw!\n");
        else if(player_choice == 1 && computer_choice == 2)
            printf("Computer wins!\n");
        else if(player_choice == 2 && computer_choice == 1)
            printf("Player wins!\n");
        else if(player_choice == 3 && computer_choice == 2)
            printf("Computer wins!\n");
        else if(player_choice == 2 && computer_choice == 3)
            printf("Player wins!\n");
        else if(player_choice == 1 && computer_choice == 3)
            printf("Computer wins!\n");

        // Update the scores
        player_score++;
        computer_score++;
    }

    // Check who won
    if(player_score > computer_score)
        printf("Player wins!\n");
    else if(player_score < computer_score)
        printf("Computer wins!\n");
    else if(player_score == computer_score)
        printf("It's a draw!\n");

    return 0;
}