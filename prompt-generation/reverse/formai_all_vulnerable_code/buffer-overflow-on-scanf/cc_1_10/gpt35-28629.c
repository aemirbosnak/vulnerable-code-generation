//FormAI DATASET v1.0 Category: Table Game ; Style: bold
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 9
#define PLAYER_1 'X'
#define PLAYER_2 'O'

bool validMove(char board[], int move)
{
    return (move >= 0 && move < BOARD_SIZE && board[move] == ' ');
}

bool checkWin(char board[], char symbol)
{
    if((board[0] == symbol && board[1] == symbol && board[2] == symbol) ||
       (board[3] == symbol && board[4] == symbol && board[5] == symbol) ||
       (board[6] == symbol && board[7] == symbol && board[8] == symbol) ||
       (board[0] == symbol && board[3] == symbol && board[6] == symbol) ||
       (board[1] == symbol && board[4] == symbol && board[7] == symbol) ||
       (board[2] == symbol && board[5] == symbol && board[8] == symbol) ||
       (board[0] == symbol && board[4] == symbol && board[8] == symbol) ||
       (board[2] == symbol && board[4] == symbol && board[6] == symbol))
    {
        return true;
    }
    return false;
}

bool checkTie(char board[])
{
    for(int i=0; i<BOARD_SIZE; i++)
    {
        if(board[i] == ' ')
        {
            return false;
        }
    }
    return true;
}

void printBoard(char board[])
{
    printf(" %c | %c | %c\n", board[0], board[1], board[2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", board[3], board[4], board[5]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", board[6], board[7], board[8]);
}

void game()
{
    char board[BOARD_SIZE] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int move;
    char currPlayer = PLAYER_1;
    bool gameOn = true;
    bool valid;
    
    printf("\nWelcome to my unique C Table Game!\n\n");
    printf("Player 1: X\n");
    printf("Player 2: O\n\n");
    
    printf("Game board layout:\n\n");
    printf(" 0 | 1 | 2 \n");
    printf("---+---+---\n");
    printf(" 3 | 4 | 5 \n");
    printf("---+---+---\n");
    printf(" 6 | 7 | 8 \n\n");
    
    while(gameOn)
    {
        printBoard(board);
        printf("\n%c's turn\n", currPlayer);
        
        do
        {
            printf("Enter move: ");
            scanf("%d", &move);
            valid = validMove(board, move);
            if(!valid)
            {
                printf("Invalid move. Try again.\n");
            }
        } while(!valid);
        
        board[move] = currPlayer;
        if(checkWin(board, currPlayer))
        {
            printBoard(board);
            printf("\n%c won the game!\n", currPlayer);
            gameOn = false;
        }
        else if(checkTie(board))
        {
            printBoard(board);
            printf("\nGame ended in a tie.\n");
            gameOn = false;
        }
        else
        {
            currPlayer = (currPlayer == PLAYER_1) ? PLAYER_2 : PLAYER_1;
        }
    }
}

int main()
{
    game();
    return 0;
}