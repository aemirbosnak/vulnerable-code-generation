//Falcon-180B DATASET v1.0 Category: Table Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int board[3][3];
    int player = 1;
    int computer = 2;
    int choice;
    int flag = 0;
    int count = 0;
    char again;

    srand(time(NULL));

    do
    {
        system("clear");
        printf("\n\n\n");
        printf("      TIC-TAC-TOE\n");
        printf("=================\n");
        printf("Player 1: X and Player 2: O\n");
        printf("Enter your choice: \n1. NEW GAME\n2. QUIT\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                for(int i=0; i<3; i++)
                {
                    for(int j=0; j<3; j++)
                    {
                        board[i][j] = 0;
                    }
                }
                count = 0;
                flag = 0;
                while(flag == 0)
                {
                    int row, col;
                    row = rand() % 3;
                    col = rand() % 3;

                    if(board[row][col]!= 1 && board[row][col]!= 2)
                    {
                        if(player % 2 == 1)
                        {
                            board[row][col] = 1;
                            printf("Player 1's Turn\n");
                            printf("Enter your choice: \n");
                            scanf("%d %d", &row, &col);
                            if(row == rand() % 3 && col == rand() % 3)
                            {
                                board[row][col] = 1;
                                printf("\nPlayer 1 Wins!");
                                flag = 1;
                            }
                            else
                            {
                                board[row][col] = 2;
                                printf("\nPlayer 2 Wins!");
                                flag = 1;
                            }
                        }
                        else
                        {
                            board[row][col] = 2;
                            printf("Player 2's Turn\n");
                            printf("Enter your choice: \n");
                            scanf("%d %d", &row, &col);
                            if(row == rand() % 3 && col == rand() % 3)
                            {
                                board[row][col] = 2;
                                printf("\nPlayer 2 Wins!");
                                flag = 1;
                            }
                            else
                            {
                                board[row][col] = 1;
                                printf("\nPlayer 1 Wins!");
                                flag = 1;
                            }
                        }
                    }
                }
                break;

            case 2:
                printf("\nExiting...\n");
                exit(0);

            default:
                printf("\nInvalid Choice!");
        }

    }while(1);

    return 0;
}