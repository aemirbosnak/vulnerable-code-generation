//FormAI DATASET v1.0 Category: Table Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the board
void displayBoard(char board[][3])
{
    printf("\t %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("\t-----------\n");
    printf("\t %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("\t-----------\n");
    printf("\t %c | %c | %c \n\n", board[2][0], board[2][1], board[2][2]);
}

// Function to check if the game is won
int checkWin(char board[][3], char symbol)
{
    int i, j, win;
    
    /* Check for all rows */
    for(i=0; i<3; i++)
    {
        win = 1;
        for(j=0; j<3; j++)
            if (board[i][j] != symbol)
                win = 0;
            
        if (win == 1)
            return 1;
    }
    
    /* Check for all columns */
    for(i=0; i<3; i++)
    {
        win = 1;
        for(j=0; j<3; j++)
            if (board[j][i] != symbol)
                win = 0;
                
        if (win == 1)
            return 1;
    }
    
    /* Check diagonals */
    win = 1;
    for(i=0; i<3; i++)
        if (board[i][i] != symbol)
            win = 0;
            
    if (win == 1)
        return 1;
        
    win = 1;
    for(i=0; i<3; i++)
        if (board[i][2-i] != symbol)
            win = 0;
            
    if (win == 1)
        return 1;
    
    return 0;
}

// Function to get the user's move
void getUserMove(int *row, int *col)
{
    printf("Enter row number (1-3): ");
    scanf("%d", row);
    
    printf("Enter column number (1-3): ");
    scanf("%d", col);
    
    // Adjusting for 0-based indexing
    *row -= 1;
    *col -= 1;
}

// Function to get computer's move
void getComputerMove(char board[][3], int *row, int *col)
{
    int i, j, found = 0;
    
    // Look for a winning move
    // Check for all rows
    for(i=0; i<3 && !found; i++)
    {
        if (board[i][0] == ' ' && board[i][1] == 'O' && board[i][2] == 'O')
        {
            *row = i;
            *col = 0;
            found = 1;
        }
        else if (board[i][0] == 'O' && board[i][1] == ' ' && board[i][2] == 'O')
        {
            *row = i;
            *col = 1;
            found = 1;
        }
        else if (board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == ' ')
        {
            *row = i;
            *col = 2;
            found = 1;
        }
    }
    
    // Check for all columns
    for(i=0; i<3 && !found; i++)
    {
        if (board[0][i] == ' ' && board[1][i] == 'O' && board[2][i] == 'O')
        {
            *row = 0;
            *col = i;
            found = 1;
        }
        else if (board[0][i] == 'O' && board[1][i] == ' ' && board[2][i] == 'O')
        {
            *row = 1;
            *col = i;
            found = 1;
        }
        else if (board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == ' ')
        {
            *row = 2;
            *col = i;
            found = 1;
        }
    }
    
    // Check diagonals
    if (!found)
    {
        if (board[0][0] == ' ' && board[1][1] == 'O' && board[2][2] == 'O')
        {
            *row = 0;
            *col = 0;
            found = 1;
        }
        else if (board[0][0] == 'O' && board[1][1] == ' ' && board[2][2] == 'O')
        {
            *row = 1;
            *col = 1;
            found = 1;
        }
        else if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == ' ')
        {
            *row = 2;
            *col = 2;
            found = 1;
        }
        else if (board[0][2] == ' ' && board[1][1] == 'O' && board[2][0] == 'O')
        {
            *row = 0;
            *col = 2;
            found = 1;
        }
        else if (board[0][2] == 'O' && board[1][1] == ' ' && board[2][0] == 'O')
        {
            *row = 1;
            *col = 1;
            found = 1;
        }
        else if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == ' ')
        {
            *row = 2;
            *col = 0;
            found = 1;
        }
    }
    
    // If no winning move, then select a random cell
    if (!found)
    {
        do {
            *row = rand() % 3;
            *col = rand() % 3;
        }
        while (board[*row][*col] != ' ');
    }
}

// Main function
int main()
{
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    int winner = 0, row, col, turn, choice;
    char player, computer;

    // Seed the random number generator
    srand(time(NULL));
    
    printf("Welcome to the Tic Tac Toe game!\n\n");
    printf("Please select a symbol (X/O) for yourself: ");
    scanf(" %c", &player);

    // Assign symbol to the computer
    if (player == 'X')
        computer = 'O';
    else
        computer = 'X';
    
    printf("You chose %c. Computer will play with %c.\n", player, computer);
    printf("Would you like to take the first turn? (1/0): ");
    scanf("%d", &choice);
    
    // Assign turn based on user's choice
    if (choice == 1)
        turn = 1;
    else
        turn = 0;
    
    while (!winner)
    {
        if (turn)
        {
            printf("It's your turn.\n");
            getUserMove(&row, &col);
            board[row][col] = player;
        }
        else
        {
            printf("It's the computer's turn.\n");
            getComputerMove(board, &row, &col);
            board[row][col] = computer;
        }
        
        displayBoard(board);
        
        // Check for win
        if (checkWin(board, player))
        {
            printf("Congratulations! You won the game.\n");
            winner = 1;
        }
        else if (checkWin(board, computer))
        {
            printf("Sorry, computer won the game.\n");
            winner = 1;
        }
        else if (board[0][0] != ' ' && board[0][1] != ' ' && board[0][2] != ' ' &&
                 board[1][0] != ' ' && board[1][1] != ' ' && board[1][2] != ' ' &&
                 board[2][0] != ' ' && board[2][1] != ' ' && board[2][2] != ' ')
        {
            printf("Game over! It's a tie.\n");
            winner = 1;
        }
        
        turn = !turn;
    }
    
    return 0;
}