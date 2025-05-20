//FormAI DATASET v1.0 Category: Error handling ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function prototypes
void player_turn(int* player_score, int* turn_score, int* dice);
void computer_turn(int* computer_score, int* turn_score, int* dice);
void error(char* message);

int main()
{
    //initialize variables
    int player_score = 0, computer_score = 0, turn_score = 0, dice = 0;
    int max_score = 100;

    //seed random number generator
    srand(time(NULL));

    //game loop
    while (player_score < max_score && computer_score < max_score)
    {
        //player turn
        player_turn(&player_score, &turn_score, &dice);

        //check for errors
        if (dice < 1 || dice > 6 || turn_score < 0 || turn_score > 30)
        {
            error("Error: Invalid dice roll or turn score reached maximum value!");
        }

        if (player_score >= max_score)
        {
            break;
        }

        //computer turn
        computer_turn(&computer_score, &turn_score, &dice);

        //check for errors
        if (dice < 1 || dice > 6 || turn_score < 0 || turn_score > 30)
        {
            error("Error: Invalid dice roll or turn score reached maximum value!");
        }

        if (computer_score >= max_score)
        {
            break;
        }
    }

    //determine winner
    if (player_score >= max_score)
    {
        printf("Congratulations, you win!\n");
    }
    else
    {
        printf("Sorry, you lost. Better luck next time!\n");
    }

    return 0;
}

void player_turn(int* player_score, int* turn_score, int* dice)
{
    char choice = 'r';

    //roll dice until player holds or busts
    do
    {
        *dice = rand() % 6 + 1;
        printf("You rolled a %d.\n", *dice);

        //check for bust
        if (*dice == 1)
        {
            printf("Busted! Your turn score is reset to 0.\n");
            *turn_score = 0;
            return;
        }
        else
        {
            *turn_score += *dice;
            printf("Your turn score is now %d.\n", *turn_score);
            printf("Would you like to roll again or hold? (r/h): ");
            scanf(" %c", &choice);
        }
    } while (choice == 'r');

    //add turn score to player score
    *player_score += *turn_score;
    *turn_score = 0;

    printf("You chose to hold.\n");
    printf("Your total score is now %d.\n", *player_score);
}

void computer_turn(int* computer_score, int* turn_score, int* dice)
{
    //roll dice until computer holds or busts
    do
    {
        *dice = rand() % 6 + 1;
        printf("The computer rolled a %d.\n", *dice);

        //check for bust
        if (*dice == 1)
        {
            printf("The computer busted! Its turn score is reset to 0.\n");
            *turn_score = 0;
            return;
        }
        else
        {
            *turn_score += *dice;
            printf("The computer's turn score is now %d.\n", *turn_score);
        }
    } while (*turn_score < 20);

    //add turn score to computer score
    *computer_score += *turn_score;
    *turn_score = 0;

    printf("The computer chose to hold.\n");
    printf("The computer's total score is now %d.\n", *computer_score);
}

void error(char* message)
{
    printf("%s\n", message);
    printf("Exiting program...\n");
    exit(1);
}