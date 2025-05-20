//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: Dennis Ritchie
#include <stdio.h>

// Function to display the board
void display_board(char board[3][3])
{
    printf("   1   2   3\n");
    printf("1  %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("  -----------\n");
    printf("2  %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("  -----------\n");
    printf("3  %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

// Function to check if the given move is valid or not
int is_move_valid(char board[3][3], int row, int column)
{
    // Check if the given position is blank and within the valid range
    if (board[row][column] == ' ' && row >= 0 && row < 3 && column >= 0 && column < 3)
        return 1;
    else
        return 0;
}

// Function to check if the game has been won or not
int has_game_won(char board[3][3], char symbol)
{
    // Check for all possible win conditions
    if ((board[0][0] == symbol && board[0][1] == symbol && board[0][2] == symbol) ||
        (board[1][0] == symbol && board[1][1] == symbol && board[1][2] == symbol) ||
        (board[2][0] == symbol && board[2][1] == symbol && board[2][2] == symbol) ||
        (board[0][0] == symbol && board[1][0] == symbol && board[2][0] == symbol) ||
        (board[0][1] == symbol && board[1][1] == symbol && board[2][1] == symbol) ||
        (board[0][2] == symbol && board[1][2] == symbol && board[2][2] == symbol) ||
        (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) ||
        (board[2][0] == symbol && board[1][1] == symbol && board[0][2] == symbol))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Function to make an optimal move for the computer
void make_move(char board[3][3], char symbol)
{
    int best_score = -1000, row = -1, column = -1, score;
    
    // Check all possible moves and choose the best one using Minimax algorithm
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = symbol;
                
                // If this move leads to a win, return its score
                if (has_game_won(board, symbol))
                {
                    score = 10;
                }
                else
                {
                    // Make the opposite move and get its score
                    make_move(board, (symbol == 'X') ? 'O' : 'X');
                    score = -best_score;
                }
                
                // Undo the move
                board[i][j] = ' ';
                
                // Update the best move
                if (score > best_score)
                {
                    best_score = score;
                    row = i;
                    column = j;
                }
            }
        }
    }
    
    // Make the best move
    board[row][column] = symbol;
}

int main()
{
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int row, column, turn = 0;
    
    printf("Tic Tac Toe Game\n");
    display_board(board);
    
    // Main game loop
    while (1)
    {
        // Alternate turns between the player and computer
        if (turn % 2 == 0)
        {
            printf("Player's turn\n");
            printf("Enter row and column coordinates (e.g. 1 2): ");
            scanf("%d %d", &row, &column);
            
            // Check if move is valid
            if (!is_move_valid(board, row-1, column-1))
            {
                printf("Invalid move. Please try again.\n");
                continue;
            }
            
            board[row-1][column-1] = 'X';
        }
        else
        {
            printf("Computer's turn\n");
            make_move(board, 'O');
        }
        
        display_board(board);
        
        // Check if game has been won or tied
        if (has_game_won(board, 'X'))
        {
            printf("Congratulations! You have won the game.\n");
            break;
        }
        else if (has_game_won(board, 'O'))
        {
            printf("Sorry, the computer has won the game.\n");
            break;
        }
        else if (turn == 8)
        {
            printf("The game is a tie.\n");
            break;
        }
        
        turn++;
    }
    
    return 0;
}