//FormAI DATASET v1.0 Category: Table Game ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int r, c, score, choice;
    char player1[20], player2[20], p[3] = {'X', 'O'};
    time_t t;

    //Get player names
    printf("Enter Player 1 name: ");
    scanf("%s", &player1);
    printf("\nEnter Player 2 name: ");
    scanf("%s", &player2);

    //Randomly select the starting player
    srand((unsigned) time(&t));
    int randIndex = rand() % 2;
    printf("\n%s will start the game.\n\n", randIndex == 0 ? player1 : player2);

    //Initialize the table
    int table[3][3];
    for(r = 0; r < 3; r++)
    {
        for(c = 0; c < 3; c++)
        {
            table[r][c] = 0;
        }
    }

    //Display the table
    printf("\t\t\t    1    2    3\n");
    printf("\t\t\t  +----+----+----+\n");
    for(r = 0; r < 3; r++)
    {
        printf("\t\t\t%d |", (r+1));
        for(c = 0; c < 3; c++)
        {
            printf(" %c  |", table[r][c] == 0 ? ' ' : p[table[r][c] - 1]);
        }
        if(r < 2)
            printf("\n\t\t\t  +----+----+----+\n");
    }
    printf("\n");

    //Start game loop
    for(score = 0; score < 9; score++)
    {
        //Get current player's input
        printf("%s's turn.(Enter Row number followed by column number): ", randIndex == 0 ? player1 : player2);
        scanf("%d%d", &r, &c);

        //Check if input is valid
        if(r < 1 || r > 3 || c < 1 || c > 3 || table[r-1][c-1] != 0)
        {
            printf("\nInvalid input. Try again.\n\n");
            score--;
            continue;
        }
        
        //Update the table
        table[r-1][c-1] = randIndex+1;
        randIndex = (randIndex+1) % 2;

        //Display the updated table
        printf("\n\n");
        printf("\t\t\t    1    2    3\n");
        printf("\t\t\t  +----+----+----+\n");
        for(r = 0; r < 3; r++)
        {
            printf("\t\t\t%d |", (r+1));
            for(c = 0; c < 3; c++)
            {
                printf(" %c  |", table[r][c] == 0 ? ' ' : p[table[r][c] - 1]);
            }
            if(r < 2)
                printf("\n\t\t\t  +----+----+----+\n");
        }
        printf("\n");

        //Check if current player won
        if((table[0][0] == table[0][1] && table[0][1] == table[0][2] && table[0][0] == randIndex+1) || 
           (table[1][0] == table[1][1] && table[1][1] == table[1][2] && table[1][0] == randIndex+1) ||
           (table[2][0] == table[2][1] && table[2][1] == table[2][2] && table[2][0] == randIndex+1) ||
           (table[0][0] == table[1][0] && table[1][0] == table[2][0] && table[0][0] == randIndex+1) ||
           (table[0][1] == table[1][1] && table[1][1] == table[2][1] && table[0][1] == randIndex+1) ||
           (table[0][2] == table[1][2] && table[1][2] == table[2][2] && table[0][2] == randIndex+1) ||
           (table[0][0] == table[1][1] && table[1][1] == table[2][2] && table[0][0] == randIndex+1) ||
           (table[0][2] == table[1][1] && table[1][1] == table[2][0] && table[0][2] == randIndex+1))
        {
            printf("\n%s won the game!\n", randIndex == 0 ? player1 : player2);
            return 0;
        }
    }

    //All cells filled and no player won so it's a tie
    printf("\nIt's a tie!\n");

    return 0;
}