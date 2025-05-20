//FormAI DATASET v1.0 Category: Table Game ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to display the game board
void display_board(char board[][3])
{
    printf("\n\t 1\t2\t3\n\n");
    printf("1\t %c\t %c\t %c\n", board[0][0], board[0][1], board[0][2]);
    printf("2\t %c\t %c\t %c\n", board[1][0], board[1][1], board[1][2]);
    printf("3\t %c\t %c\t %c\n\n", board[2][0], board[2][1], board[2][2]);
}

// Function to check if someone has won the game
int check_win(char board[][3], char symbol)
{
    int i, j;
    
    // Check rows
    for (i = 0; i < 3; i++)
    {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol)
            return 1;
    }
    
    // Check columns
    for (j = 0; j < 3; j++)
    {
        if (board[0][j] == symbol && board[1][j] == symbol && board[2][j] == symbol)
            return 1;
    }
    
    // Check diagonals
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol)
        return 1;
        
    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)
        return 1;
    
    return 0;
}

int main()
{
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int i, j, row, column, player = 1;
    char symbol;
    
    srand(time(NULL));
    int rand_num = rand() % 2;
    
    if (rand_num == 0)
    {
        printf("Romeo plays first! ");
        symbol = 'O';
    }
    else
    {
        printf("Juliet plays first! ");
        symbol = 'X';
    }
    
    while (1)
    {
        display_board(board);
        
        // Get input from current player
        printf("Player %d, enter row and column for your %c: ", player, symbol);
        scanf("%d %d", &row, &column);
        
        // Validate input
        if (row < 1 || row > 3 || column < 1 || column > 3 || board[row-1][column-1] != ' ')
        {
            printf("Invalid input, try again.\n");
            continue;
        }
        
        // Mark the board with the symbol
        board[row-1][column-1] = symbol;
        
        // Check if someone has won the game
        if (check_win(board, symbol))
        {
            printf("Congratulations, player %d wins!\n", player);
            display_board(board);
            break;
        }
        
        // Check if there is a tie
        if (board[0][0] != ' ' && board[0][1] != ' ' && board[0][2] != ' ' &&
            board[1][0] != ' ' && board[1][1] != ' ' && board[1][2] != ' ' &&
            board[2][0] != ' ' && board[2][1] != ' ' && board[2][2] != ' ')
        {
            printf("It's a tie!\n");
            display_board(board);
            break;
        }
        
        // Switch to the other player
        if (player == 1)
        {
            player = 2;
            symbol = 'X';
        }
        else
        {
            player = 1;
            symbol = 'O';
        }
    }
    
    return 0;
}