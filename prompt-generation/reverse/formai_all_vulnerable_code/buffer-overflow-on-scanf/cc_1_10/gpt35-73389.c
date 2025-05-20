//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: happy
#include <stdio.h>

char board[3][3]; // 3x3 board for tic tac toe

// Function to print the board
void print_board()
{
    printf("\n");
    printf("\t %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("\t---+---+---\n");
    printf("\t %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("\t---+---+---\n");
    printf("\t %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

// Function to check if there is a winner
int check_winner(char player)
{
    // Check rows
    for(int i = 0; i < 3; i++)
    {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return 1;
    }

    // Check columns
    for(int i = 0; i < 3; i++)
    {
        if(board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return 1;
    }

    // Check diagonals
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return 1;

    if(board[2][0] == player && board[1][1] == player && board[0][2] == player)
        return 1;

    // No winner found
    return 0;
}

// Function to check if the game is a tie
int check_tie()
{
    // Check if there are any empty cells left on the board
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] == ' ')
                return 0;
        }
    }

    // Game is a tie
    return 1;
}

// Function for the computer's turn
void computer_turn(char player)
{
    int row, col;

    // Generate random row and column until an empty cell is found
    do
    {
        row = rand() % 3;
        col = rand() % 3;
    }
    while(board[row][col] != ' ');

    // Make the move and print the board
    board[row][col] = player;
    printf("Computer played: (%d,%d)\n", row, col);
    print_board();
}

// Function for the player's turn
void player_turn(char player)
{
    int row, col;

    // Get the row and column from the user and validate it
    do
    {
        printf("Enter the row and column: ");
        scanf("%d %d", &row, &col);
        if(row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ')
            printf("Invalid move, try again\n");
    }
    while(row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ');

    // Make the move and print the board
    board[row][col] = player;
    print_board();
}

int main()
{
    char player = 'X';
    int winner = 0;

    // Initialize the board with empty cells
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }

    printf("Welcome to the happy Tic Tac Toe game!\n");
    printf("You are playing against the computer.\n");
    print_board();

    // Game loop
    while(1)
    {
        if(player == 'X')
            player_turn(player);
        else
            computer_turn(player);

        // Check if there is a winner or a tie
        if(check_winner(player) == 1)
        {
            printf("%c is the winner!\n", player);
            winner = 1;
            break;
        }

        if(check_tie() == 1)
        {
            printf("It's a tie!\n");
            break;
        }

        // Switch players
        if(player == 'X')
            player = 'O';
        else
            player = 'X';
    }

    // Print the final board
    print_board();

    printf("Thank you for playing the happy Tic Tac Toe game!\n");

    return 0;
}