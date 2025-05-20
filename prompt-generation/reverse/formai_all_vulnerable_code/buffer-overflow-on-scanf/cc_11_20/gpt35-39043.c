//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int player_choice, computer_choice;
    int player_score = 0, computer_score = 0;
    int round = 1;
    char play_again = 'y';

    printf("Welcome to Interstellar Combat!\n");

    while(play_again == 'y')
    {
        printf("Round %d:\n", round);
        printf("Choose your weapon:\n");
        printf("1. Laser Cannon\n");
        printf("2. Ion Blaster\n");
        printf("3. Photon Torpedo\n");
        printf("4. Quantum Disruptor\n");
        printf("Enter your choice: ");
        scanf("%d", &player_choice);

        srand(time(0));
        computer_choice = rand() % 4 + 1;

        printf("Computer chose weapon %d.\n", computer_choice);

        if(player_choice == computer_choice)
        {
            printf("It's a tie!\n");
        }
        else if(player_choice == 1 && computer_choice == 2 || 
                player_choice == 2 && computer_choice == 3 || 
                player_choice == 3 && computer_choice == 4 || 
                player_choice == 4 && computer_choice == 1)
        {
            printf("You win this round!\n");
            player_score++;
        }
        else
        {
            printf("You lost this round.\n");
            computer_score++;
        }

        printf("Player score: %d  Computer score: %d\n", player_score, computer_score);

        if(player_score >= 3 || computer_score >= 3)
        {
            if(player_score >= 3)
            {
                printf("You have won the game!\n");
            }
            else
            {
                printf("You have lost the game.\n");
            }

            printf("Do you want to play again? (y/n): ");
            scanf(" %c", &play_again);

            if(play_again == 'y')
            {
                player_score = 0;
                computer_score = 0;
                round = 1;
                printf("Starting a new game!\n");
            }
        }
        else
        {
            round++;
        }
    }

    printf("Thank you for playing!\n");

    return 0;
}