//FormAI DATASET v1.0 Category: Table Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int players, cols, rows, turn, winner = 0, gameOver = 0, inputCol, inputRow;
    printf("Welcome to C Table Game!\n");
    printf("How many players will be playing? (2-4)\n");
    scanf("%d", &players);
    printf("How many columns and rows will the table have? (1-10)\n");
    scanf("%d %d", &cols, &rows);
    int table[cols][rows];
    for(int i = 0; i < cols; i++)
    {
        for(int j = 0; j < rows; j++)
        {
            table[i][j] = 0;
        }
    }
    while(!gameOver)
    {
        for(int i = 1; i <= players; i++)
        {
            turn = i;
            printf("Player %d's turn.\n", turn);
            printf("Enter column (1-%d) and row (1-%d) coordinates to place your token.\n", cols, rows);
            scanf("%d %d", &inputCol, &inputRow);
            if(inputCol < 1 || inputCol > cols || inputRow < 1 || inputRow > rows || table[inputCol-1][inputRow-1] != 0)
            {
                printf("Invalid input.\n");
                i--;
                continue;
            }
            table[inputCol-1][inputRow-1] = turn;
            for(int i = 0; i < cols; i++)
            {
                for(int j = 0; j < rows; j++)
                {
                    printf("%d ", table[i][j]);
                }
                printf("\n");
            }
            for(int i = 1; i <= players; i++)
            {
                for(int j = 0; j < cols; j++)
                {
                    for(int k = 0; k < rows; k++)
                    {
                        if(table[j][k] == i && table[j][k] == table[j][(k+1)%rows] && table[j][k] == table[(j+1)%cols][k] && table[j][k] == table[(j+1)%cols][(k+1)%rows])
                        {
                            winner = i;
                            gameOver = 1;
                            break;
                        }
                    }
                }
            }
            if(gameOver)
            {
                printf("Player %d wins!\n", winner);
                break;
            }
        }
    }
    return 0;
}