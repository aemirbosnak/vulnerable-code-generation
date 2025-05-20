//FormAI DATASET v1.0 Category: Table Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int player1_score = 0, player2_score = 0, row, col, turn = 1, dice_roll, temp_score;
    char player1_name[50], player2_name[50];
    srand(time(0));
    
    printf("\nWelcome to The Ultimate C Table Game!");
    printf("\nEnter name of player 1: ");
    scanf("%s", player1_name);
    printf("\nEnter name of player 2: ");
    scanf("%s", player2_name);
    
    printf("\n%s, your token is 'X' and %s, your token is 'O'\n", player1_name, player2_name);
    
    while(player1_score < 100 && player2_score < 100)
    {
        printf("\n------- ROUND %d -------", turn);
        printf("\n%s score: %d", player1_name, player1_score);
        printf("\n%s score: %d", player2_name, player2_score);
        printf("\nCurrent player: %s", turn == 1 ? player1_name : player2_name);
      
        printf("\nRolling the dice...");
        dice_roll = rand() % 6 + 1;
        printf("\nYou rolled a %d!", dice_roll);
      
        if(dice_roll == 1)
        {
            printf("\nOh no! You rolled a 1 and lost your turn");
            turn = turn == 1 ? 2 : 1;
            continue;
        }
      
        printf("\nEnter row: ");
        scanf("%d", &row);
        printf("Enter column: ");
        scanf("%d", &col);
      
        if(turn == 1)
        {
            temp_score = player1_score + dice_roll;
          
            if(temp_score >= 100)
            {
                printf("\nCongratulations %s!!! You won!", player1_name);
                return 0;
            }
            else if(col == temp_score || row == temp_score)
              player1_score = temp_score;
            else
            {
                printf("\nOh no! You missed your shot and lost your turn. Better luck next time!");
                turn = 2;
                continue;
            }
        }
        else
        {
            temp_score = player2_score + dice_roll;
          
            if(temp_score >= 100)
            {
                printf("\nCongratulations %s!!! You won!", player2_name);
                return 0;
            }
            else if(col == temp_score || row == temp_score)
              player2_score = temp_score;
            else
            {
                printf("\nOh no! You missed your shot and lost your turn. Better luck next time!");
                turn = 1;
                continue;
            }
        }
        
        turn = turn == 1 ? 2 : 1;
    }
    
    return 0;
}