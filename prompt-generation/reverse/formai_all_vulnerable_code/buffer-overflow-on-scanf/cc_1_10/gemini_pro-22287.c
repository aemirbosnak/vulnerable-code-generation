//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: systematic
#include <stdlib.h>
#include <stdio.h>

// Define the game board
char board[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

// Define the player symbols
char player1_symbol = 'X';
char player2_symbol = 'O';

// Define the game state
int game_state = 0;  // 0 = ongoing, 1 = player 1 wins, 2 = player 2 wins, 3 = draw

// Display the game board
void display_board() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
    }
}

// Get the player's move
int get_move(char player_symbol) {
    int row, column;
    printf("Player %c's turn: ", player_symbol);
    scanf("%d %d", &row, &column);
    return row * 3 + column;
}

// Check if the move is valid
int is_valid_move(int move) {
    int row = move / 3;
    int column = move % 3;
    return board[row][column] == ' ';
}

// Place the player's symbol on the board
void place_symbol(int move, char player_symbol) {
    int row = move / 3;
    int column = move % 3;
    board[row][column] = player_symbol;
}

// Check if there is a winner
int check_winner() {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0] == player1_symbol ? 1 : 2;
        }
    }

    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return board[0][j] == player1_symbol ? 1 : 2;
        }
    }

    // Check diagonals
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0] == player1_symbol ? 1 : 2;
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2] == player1_symbol ? 1 : 2;
    }

    // Check for draw
    int count = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != ' ') {
                count++;
            }
        }
    }

    if (count == 9) {
        return 3;
    }

    return 0;
}

// Play the game
void play_game() {
    int player = 1;  // Player 1 starts first
    while (game_state == 0) {
        int move = get_move(player == 1 ? player1_symbol : player2_symbol);
        if (is_valid_move(move)) {
            place_symbol(move, player == 1 ? player1_symbol : player2_symbol);
            display_board();
            game_state = check_winner();
            player = player == 1 ? 2 : 1;  // Switch players
        } else {
            printf("Invalid move, try again.\n");
        }
    }

    if (game_state == 1) {
        printf("Player 1 wins!\n");
    } else if (game_state == 2) {
        printf("Player 2 wins!\n");
    } else {
        printf("Draw!\n");
    }
}

int main() {
    play_game();
    return 0;
}