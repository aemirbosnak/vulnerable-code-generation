//FormAI DATASET v1.0 Category: Table Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    //Initialization of variables
    int player1 = 0, player2 = 0;
    int roll, turn_total;
    char choice;

    //Set the seed for the random number generator
    srand((unsigned)time(NULL));

    printf("\n\nWelcome to the C Table Game! Let's begin!\n\n");

    do 
    {
        turn_total = 0;
        printf("Player 1, it's your turn.\n");

        //Roll the dice
        do 
        {
            roll = rand() % 6 + 1;
            printf("You rolled a %d.\n", roll);

            //Check if the player rolled a 1
            if (roll == 1) 
            {
                printf("Turn over. No points added.\n\n");
                turn_total = 0;
                break;
            }
            else 
            {
                turn_total += roll;
                printf("You currently have %d points in this turn.\n", turn_total);

                //Prompt user for choice to continue the turn or end it
                printf("Enter R to Roll Again, or H to Hold: ");
                scanf(" %c", &choice);

                //Ensure the user enters a valid choice
                while(choice != 'r' && choice != 'R' && choice != 'h' && choice != 'H')
                {
                    printf("Invalid choice. Enter R to Roll Again, or H to Hold: ");
                    scanf(" %c", &choice);
                }

                //If the user chooses to hold, add the current turn total to their total score
                if (choice == 'h' || choice == 'H') 
                {
                    player1 += turn_total;
                    printf("Your total score is now %d.\n\n", player1);
                    turn_total = 0;
                    break;
                }
            }
        } while (1);

        //Check if player 1 has won
        if(player1 >= 100) 
        {
            printf("Player 1 wins!\n\n");
            break;
        }

        turn_total = 0;
        printf("Player 2, it's your turn.\n");

        //Roll the dice
        do
        {
            roll = rand() % 6 + 1;
            printf("You rolled a %d.\n", roll);

            //Check if player rolled a 1
            if (roll == 1) 
            {
                printf("Turn over. No points added.\n\n");
                turn_total = 0;
                break;
            }
            else
            {
                turn_total += roll;
                printf("You currently have %d points in this turn.\n", turn_total);

                //If the computer's turn total is 20 or more, automatically hold
                if (turn_total >= 20)
                {
                    printf("Computer holds.\n");
                    player2 += turn_total;
                    printf("Computer's total score is now %d.\n\n", player2);
                    turn_total = 0;
                    break;
                }
            }
        } while (1);

        //Check if player 2 has won
        if (player2 >= 100) 
        {
            printf("Player 2 wins!\n\n");
            break;
        }

    } while (1);

    return 0;
}