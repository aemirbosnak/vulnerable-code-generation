//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

int main()
{
    int board[ROWS][COLS];
    int i, j;
    int player = 1;
    int choice;
    int flag = 0;
    int count = 0;
    int computer_choice;
    int comp_flag = 0;
    int comp_count = 0;
    int game_over = 0;

    srand(time(NULL));

    // Initialize the board with hidden cards
    for(i=0; i<ROWS; i++)
    {
        for(j=0; j<COLS; j++)
        {
            board[i][j] = -1;
        }
    }

    // Print the initial board
    printf("Initial Board:\n");
    for(i=0; i<ROWS; i++)
    {
        for(j=0; j<COLS; j++)
        {
            printf(" %d ", board[i][j]);
        }
        printf("\n");
    }

    while(game_over == 0)
    {
        // Player's turn
        printf("\nPlayer %d's turn:\n", player);
        do
        {
            printf("Enter your choice (1-%d): ", ROWS*COLS-1);
            scanf("%d", &choice);
            if(choice < 1 || choice > ROWS*COLS-1)
            {
                printf("Invalid choice. Please try again.\n");
            }
        } while(choice < 1 || choice > ROWS*COLS-1);

        i = choice / COLS;
        j = choice % COLS;

        if(board[i][j] == -1)
        {
            printf("You chose an empty slot. Try again.\n");
        }
        else if(board[i][j]!= -1)
        {
            if(player == 1)
            {
                board[i][j] = 1;
            }
            else
            {
                board[i][j] = 2;
            }

            if(flag == 0)
            {
                flag = 1;
                count++;
            }

            if(count == ROWS*COLS/2)
            {
                game_over = 1;
                printf("\nPlayer %d wins!\n", player);
            }
        }
        else
        {
            printf("Invalid choice. Please try again.\n");
        }

        if(game_over == 0)
        {
            player = (player % 2)? 1 : 2;
        }
    }

    return 0;
}