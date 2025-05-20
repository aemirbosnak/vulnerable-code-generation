//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: intelligent
#include <stdlib.h>
#include <stdio.h>

char board[3][3]; // Tic-Tac-Toe game board

// Initialize the Tic-Tac-Toe game board with whitespace characters
void init_board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Print the current Tic-Tac-Toe game board
void print_board() {
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("___|___|___\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("___|___|___\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("   |   |   \n");
}

// Check if there is a winner on the current Tic-Tac-Toe game board
char check_win() {
    // Check for horizontal wins
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return board[i][0];
        }
    }

    // Check for vertical wins
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return board[0][i];
        }
    }

    // Check for diagonal wins
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return board[0][0];
    }

    if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] != ' ') {
        return board[2][0];
    }

    // If there is no winner yet, check for a tie
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return ' ';
            }
        }
    }

    // If there are no more empty squares, it is a tie
    return 'T';
}

// Get the next move from the human player
void human_move(char player) {
    int row, col;

    printf("Player %c, enter your move (row [1-3] column [1-3]): ", player);
    scanf("%d %d", &row, &col);

    // Make sure the move is in a valid location
    while (board[row - 1][col - 1] != ' ') {
        printf("That square is already taken. Please choose a different square.\n");
        printf("Player %c, enter your move (row [1-3] column [1-3]): ", player);
        scanf("%d %d", &row, &col);
    }

    // Set the game board with the human player's move
    board[row - 1][col - 1] = player;
}

// Get the next move from the computer player using a simple AI strategy
void computer_move(char player) {
    printf("Player %c is thinking...\n", player);

    // Make a random move for now (very simple AI strategy)
    int row = rand() % 3;
    int col = rand() % 3;

    while (board[row][col] != ' ') {
        row = rand() % 3;
        col = rand() % 3;
    }

    // Set the game board with the computer player's move
    board[row][col] = player;
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    printf("Welcome to Tic-Tac-Toe!\n");

    init_board(); // Initialize the game board
    print_board(); // Print the starting game board

    char winner = ' ';
    char current_player = 'X';

    // Play the game until there is a winner or a tie
    while (winner == ' ') {
        if (current_player == 'X') {
            human_move(current_player);
        } else {
            computer_move(current_player);
        }

        // Print the updated game board
        print_board();

        // Check if the current player won or if there is a tie
        winner = check_win();

        // Switch to the other player
        current_player = (current_player == 'X' ? 'O' : 'X');
    }

    // Print the game over message
    if (winner == 'T') {
        printf("Tie game!\n");
    } else {
        printf("Player %c wins!\n", winner);
    }

    return 0;
}