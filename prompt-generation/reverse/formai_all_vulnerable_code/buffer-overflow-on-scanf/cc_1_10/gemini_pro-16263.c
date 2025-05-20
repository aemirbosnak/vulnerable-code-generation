//GEMINI-pro DATASET v1.0 Category: Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declare the game board
char board[3][3];

// Declare the player symbols
char player1 = 'X';
char player2 = 'O';

// Declare the game state
int game_state = 0; // 0 = ongoing, 1 = player 1 wins, 2 = player 2 wins, 3 = tie

// Function to print the game board
void print_board() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if the game is over
int check_game_over() {
    // Check if there is a winner
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return board[i][0] == player1 ? 1 : 2;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return board[0][i] == player1 ? 1 : 2;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return board[0][0] == player1 ? 1 : 2;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return board[0][2] == player1 ? 1 : 2;
    }

    // Check if there is a tie
    int tie = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                tie = 0;
            }
        }
    }
    if (tie) {
        return 3;
    }

    // The game is still ongoing
    return 0;
}

// Function to get the player's move
void get_player_move(char player) {
    int row, col;

    printf("Player %c, enter your move (row, col): ", player);
    scanf("%d %d", &row, &col);

    // Check if the move is valid
    while (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
        printf("Invalid move. Please enter a valid move: ");
        scanf("%d %d", &row, &col);
    }

    // Update the game board
    board[row - 1][col - 1] = player;
}

// Function to start the game
void start_game() {
    // Initialize the game board
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }

    // Print the game board
    print_board();

    // Get the players' names
    char player1_name[20], player2_name[20];
    printf("Player 1, enter your name: ");
    scanf("%s", player1_name);
    printf("Player 2, enter your name: ");
    scanf("%s", player2_name);

    // Start the game loop
    while (game_state == 0) {
        // Get player 1's move
        get_player_move(player1);

        // Print the game board
        print_board();

        // Check if the game is over
        game_state = check_game_over();

        // If the game is over, break out of the loop
        if (game_state != 0) {
            break;
        }

        // Get player 2's move
        get_player_move(player2);

        // Print the game board
        print_board();

        // Check if the game is over
        game_state = check_game_over();
    }

    // Print the game over message
    if (game_state == 1) {
        printf("%s wins!\n", player1_name);
    } else if (game_state == 2) {
        printf("%s wins!\n", player2_name);
    } else {
        printf("Tie!\n");
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Start the game
    start_game();

    return 0;
}