//FormAI DATASET v1.0 Category: Table Game ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int player_score = 0; //Intializing player score to zero
    int computer_score = 0; //Initializing computer score to zero
    int turn_score = 0; //Score for each turn
    int dice_roll; //Variable to store the value of the dice rolled
    int choice; //Variable to store player choice to roll or hold
    srand(time(NULL)); //Initializing random seed

    printf("*** Welcome to the Dice Game ***\n\n");

    while(player_score < 100 && computer_score < 100) //Loop runs until either player or computer reaches a score of 100
    {
        printf("Player's turn\n");
        printf("-------------\n\n");

        do
        {
            dice_roll = rand() % 6 + 1; //Rolling the dice
            printf("You rolled a %d\n", dice_roll);

            if(dice_roll == 1) //If 1 is rolled, turn score becomes 0 and player's turn ends
            {
                turn_score = 0;
                printf("Turn score: %d\n", turn_score);
                break;
            }

            turn_score += dice_roll;

            printf("Turn score so far: %d\n", turn_score);

            printf("Do you want to roll again or hold? (Enter 1 to roll and 2 to hold): ");
            scanf("%d", &choice);

        } while(choice == 1); //Loop runs until player chooses to hold

        player_score += turn_score; //Adding turn score to player's total score
        printf("======================\n");
        printf("Player's total score: %d\n", player_score);
        printf("======================\n\n");

        if(player_score >= 100) //If player's score becomes greater than or equal to 100, player wins
        {
            printf("Congratulations! You won!\n");
            break;
        }

        printf("Computer's turn\n");
        printf("----------------\n\n");

        do
        {
            dice_roll = rand() % 6 + 1;

            if(dice_roll == 1) //If 1 is rolled, turn score becomes 0 and computer's turn ends
            {
                turn_score = 0;
                break;
            }

            turn_score += dice_roll;

            if(turn_score >= 20) //If turn score becomes greater than or equal to 20, computer holds
            {
                printf("Computer holds\n");
                break;
            }

        } while(turn_score < 20); //Loop runs until turn score becomes greater than or equal to 20 or 1 is rolled

        computer_score += turn_score; //Adding turn score to computer's total score
        printf("========================\n");
        printf("Computer's total score: %d\n", computer_score);
        printf("========================\n\n");

        if(computer_score >= 100) //If computer's score becomes greater than or equal to 100, computer wins
        {
            printf("Sorry! Computer won!\n");
            break;
        }
    }

    return 0;
}