//FormAI DATASET v1.0 Category: Table Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to check if a given cell is valid for move
int is_valid_move(int row, int col, int size)
{
    return (row >= 0) && (row < size) &&
           (col >= 0) && (col < size);
}

// Function to check if a given cell is empty
int is_empty(int row, int col, char board[][100], int size)
{
    return board[row][col] == '_';
}

// Function to print the board
void print_board(char board[][100], int size)
{
    printf("\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            printf("%c ", board[i][j]);
        printf("\n");
    }
    printf("\n");
}

// Function to play the game
void play_game(int size)
{
    char board[100][100];
    int row, col, player = 1, winner = 0;
    srand(time(0));

    // Initialize board with empty cells
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            board[i][j] = '_';

    // Game loop
    while (1) {
        // Clear the screen
        system("cls");

        // Print player's turn
        printf("Player %d's turn\n", player);

        // Print the board
        print_board(board, size);

        // Prompt player for move
        printf("Enter row and column to move: ");
        scanf("%d %d", &row, &col);

        // Check if move is valid and empty
        if (is_valid_move(row, col, size) && is_empty(row, col, board, size)) {
            // Update board with player's symbol
            board[row][col] = player == 1 ? 'X' : 'O';

            // Check for winner
            // Horizontal check
            for (int i = 0; i < size; i++)
                if (board[row][i] != board[row][col])
                    break;
                else if (i == size - 1) {
                    winner = player;
                    break;
                }

            // Vertical check
            for (int i = 0; i < size; i++)
                if (board[i][col] != board[row][col])
                    break;
                else if (i == size - 1) {
                    winner = player;
                    break;
                }

            // Diagonal check
            if (row == col) {
                for (int i = 0; i < size; i++)
                    if (board[i][i] != board[row][col])
                        break;
                    else if (i == size - 1) {
                        winner = player;
                        break;
                    }
            }

            // Reverse diagonal check
            if (row + col == size - 1) {
                for (int i = 0; i < size; i++)
                    if (board[i][size - 1 - i] != board[row][col])
                        break;
                    else if (i == size - 1) {
                        winner = player;
                        break;
                    }
            }

            // Break the loop if winner is found
            if (winner)
                break;

            // Switch to next player
            player = player == 1 ? 2 : 1;
        } else {
            printf("Invalid move!\n");
            printf("Press enter to continue...");
            getchar();
            getchar();
        }
    }

    // Clear the screen
    system("cls");

    // Print player's turn
    printf("Player %d's turn\n", player);

    // Print the final board
    print_board(board, size);

    // Print winner
    printf("Player %d won the game!\n", winner);

    // Wait for user input
    printf("Press enter to continue...");
    getchar();
}

// Main function
int main()
{
    int size;

    // Prompt user for board size
    printf("Enter board size (minimum 3): ");
    scanf("%d", &size);

    // Check if board size is valid
    if (size < 3) {
        printf("Invalid board size!\n");
        return 1;
    }

    // Play the game
    play_game(size);

    // Exit program
    return 0;
}