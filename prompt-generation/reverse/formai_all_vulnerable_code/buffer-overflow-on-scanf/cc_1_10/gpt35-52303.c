//FormAI DATASET v1.0 Category: Game ; Style: high level of detail
#include <stdio.h>

// Function to print the game board
void printBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            printf("| %c ", board[i][j]);
        printf("|\n");
    }
    printf("\n");
}

// Function to check for a winner
int checkWinner(char board[3][3]) {
    // Check for horizontal wins
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
    }
    // Check for vertical wins
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;
    }
    // Check for diagonal wins
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;
    return 0;
}

// Main function to run the game
int main() {
    // Initialize game board
    char board[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };
    // Initialize player and game variables
    char player = 'X';
    int numMoves = 0, row, col, winner = 0;
    printf("\tTic Tac Toe Game\n\n");
    do {
        // Print game board
        printBoard(board);
        // Get player's move
        printf("Player %c, enter the row and column of your move: ", player);
        scanf("%d %d", &row, &col);
        // Check if move is valid
        if (row > 0 && row < 4 && col > 0 && col < 4 && board[row-1][col-1] != 'X' && board[row-1][col-1] != 'O') {
            board[row-1][col-1] = player;
            numMoves++;
            // Check for winner
            if (numMoves >= 5) {
                winner = checkWinner(board);
                if (winner == 1) {
                    printf("\n\nCongratulations! Player %c has won the game!\n\n", player);
                    printBoard(board);
                    break;
                }
            }
            // Switch player
            if (player == 'X')
                player = 'O';
            else
                player = 'X';
            // Check for tie game
            if (numMoves == 9) {
                printf("\n\nThe game is a tie.\n\n");
                printBoard(board);
                break;
            }
        }
        else {
            printf("\n\nInvalid move. Please try again.\n\n");
        }
    } while (1);
    return 0;
}