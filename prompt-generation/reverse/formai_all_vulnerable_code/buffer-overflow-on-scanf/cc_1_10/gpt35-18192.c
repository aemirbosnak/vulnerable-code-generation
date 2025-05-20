//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: Alan Touring
#include <stdio.h>   
#include <stdlib.h>  
#include <time.h>   

// The tic tac toe board
char board[3][3];

// Randomly selects who plays first
int select_first_player()
{
    srand(time(NULL)); 
    int player = rand() % 2 + 1;
    return player;
}

// Prints the board on the console
void print_board()
{
    printf("\n    1   2   3\n\n");
    printf("1   %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("   ---+---+---\n");
    printf("2   %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("   ---+---+---\n");
    printf("3   %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}

// Checks if any player has won
char check_win()
{
    // Check the rows for a win
    for (int row = 0; row < 3; row++)
    {
        if (board[row][0] == board[row][1] && board[row][0] == board[row][2])
        {
            return board[row][0];
        }
    }
    
    // Check the columns for a win
    for (int col = 0; col < 3; col++)
    {
        if (board[0][col] == board[1][col] && board[0][col] == board[2][col])
        {
            return board[0][col];
        }
    }
    
    // Check the diagonals for a win
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return board[0][0];
    }
    else if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return board[0][2];
    }
    
    return ' ';
}

// AI to make a move
void make_ai_move()
{
    // Check if the AI can win in the next move
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (board[row][col] == ' ')
            {
                board[row][col] = 'O';
                if (check_win() == 'O')
                {
                    return;
                }
                else
                {
                    board[row][col] = ' ';
                }
            }
        }
    }
    
    // Check if the human can win in the next move and block
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (board[row][col] == ' ')
            {
                board[row][col] = 'X';
                if (check_win() == 'X')
                {
                    board[row][col] = 'O';
                    return;
                }
                else
                {
                    board[row][col] = ' ';
                }
            }
        }
    }
    
    // Make a random move
    int row;
    int col;
    do
    {
        row = rand() % 3;
        col = rand() % 3;
    }
    while (board[row][col] != ' ');
    
    board[row][col] = 'O';
}

// Main function that controls the game flow
int main()
{
    // Initialize the board with empty spaces
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            board[row][col] = ' ';
        }
    }
    
    // Randomly select who plays first
    int player = select_first_player();
    
    printf("Welcome to Tic Tac Toe!\n\n");
    
    // Game loop
    while (1)
    {
        // Print the board
        print_board();
        
        // Determine whose turn it is
        if (player == 1)
        {
            // Human's turn
            int row;
            int col;
            printf("\nYour turn (X)!\n");
            printf("Enter the row (1-3): ");
            scanf("%d", &row);
            printf("Enter the column (1-3): ");
            scanf("%d", &col);
            
            // Check for valid row and column input
            if ((row >= 1 && row <= 3) && (col >= 1 && col <= 3))
            {
                // Convert input to array index
                row -= 1;
                col -= 1;
                
                // Check if the space is already taken
                if (board[row][col] == ' ')
                {
                    board[row][col] = 'X';
                    
                    // Check for a win
                    if (check_win() == 'X')
                    {
                        print_board();
                        printf("\nCongratulations! You won!\n");
                        break;
                    }
                    
                    // Switch turns
                    player = 2;
                }
                else
                {
                    printf("\nThat space is already taken. Choose again.\n");
                }
            }
            else
            {
                printf("\nInvalid input. Choose again.\n");
            }
        }
        else
        {
            // AI's turn
            printf("\nAI's turn (O)!\n");
            make_ai_move();
            
            // Check for a win
            if (check_win() == 'O')
            {
                print_board();
                printf("\nSorry, you lost. Better luck next time!\n");
                break;
            }
            
            // Switch turns
            player = 1;
        }
        
        // Check for a tie (all spaces filled)
        int tie = 1;
        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                if (board[row][col] == ' ')
                {
                    tie = 0;
                }
            }
        }
        if (tie)
        {
            print_board();
            printf("\nIt's a tie!\n");
            break;
        }
    }
    
    return 0;
}