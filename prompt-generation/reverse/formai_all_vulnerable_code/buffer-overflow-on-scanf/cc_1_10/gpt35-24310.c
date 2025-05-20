//FormAI DATASET v1.0 Category: Table Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Setting up the random seed with the current time for more randomness
    srand(time(NULL));
    
    // Setting up the initial values for the game
    int player_score = 0;
    int ai_score = 0;
    
    // Looping through the game until either the player or ai reaches 100 points
    while (player_score < 100 && ai_score < 100)
    {
        // Printing out the current scores
        printf("Player Score: %d\n", player_score);
        printf("AI Score: %d\n", ai_score);
        
        // Getting the player's input (1 for hold, 2 for roll)
        int input;
        printf("Enter 1 to hold, 2 to roll: ");
        scanf("%d", &input);
        
        // If the player chooses to roll, add a random number to their score
        if (input == 2)
        {
            int roll = rand() % 6 + 1;
            printf("You rolled a %d!\n", roll);
            player_score += roll;
            
            // Checking if the player's score is over 100 and win the game
            if (player_score >= 100)
            {
                printf("Congratulations! You won!");
                break;
            }
        }
        // If the player chooses to hold, it's the AI's turn
        else if (input == 1)
        {
            printf("You held.\n");
            
            // The AI chooses to roll until its score is higher than 20
            while (ai_score < 20)
            {
                int ai_roll = rand() % 6 + 1;
                printf("AI rolled a %d!\n", ai_roll);
                ai_score += ai_roll;
            }
            
            // Checking if the AI's score is over 100 and win the game
            if (ai_score >= 100)
            {
                printf("Sorry, the AI won.");
                break;
            }
        }
        // If the player's input is invalid, ask again
        else
        {
            printf("Invalid input. Try again.\n");
        }
    }
    
    return 0;
}