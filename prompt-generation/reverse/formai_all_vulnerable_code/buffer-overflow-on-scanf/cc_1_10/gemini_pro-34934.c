//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// Define the players
typedef enum {
    ROMEO,
    JULIET
} player_t;

// Define the game state
typedef struct {
    player_t current_player;
    int romeo_score;
    int juliet_score;
} game_state_t;

// Define the game board
char board[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

// Define the game functions
void print_board(game_state_t* game_state);
void make_move(game_state_t* game_state, int row, int col);
int check_for_winner(game_state_t* game_state);
void play_game();

// Print the game board
void print_board(game_state_t* game_state) {
    printf("Romeo: %d Juliet: %d\n", game_state->romeo_score, game_state->juliet_score);
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Make a move
void make_move(game_state_t* game_state, int row, int col) {
    if (board[row][col] == ' ') {
        if (game_state->current_player == ROMEO) {
            board[row][col] = 'X';
            game_state->current_player = JULIET;
        } else {
            board[row][col] = 'O';
            game_state->current_player = ROMEO;
        }
    }
}

// Check for a winner
int check_for_winner(game_state_t* game_state) {
    // Check for horizontal wins
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            if (board[i][0] == 'X') {
                game_state->romeo_score++;
            } else {
                game_state->juliet_score++;
            }
            return 1;
        }
    }

    // Check for vertical wins
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
            if (board[0][j] == 'X') {
                game_state->romeo_score++;
            } else {
                game_state->juliet_score++;
            }
            return 1;
        }
    }

    // Check for diagonal wins
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        if (board[0][0] == 'X') {
            game_state->romeo_score++;
        } else {
            game_state->juliet_score++;
        }
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        if (board[0][2] == 'X') {
            game_state->romeo_score++;
        } else {
            game_state->juliet_score++;
        }
        return 1;
    }

    // Check for a tie
    int tie = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                tie = 0;
            }
        }
    }
    if (tie) {
        return 2;
    }

    // No winner yet
    return 0;
}

// Play the game
void play_game() {
    // Initialize the game state
    game_state_t game_state;
    game_state.current_player = ROMEO;
    game_state.romeo_score = 0;
    game_state.juliet_score = 0;

    // Play the game loop
    while (1) {
        // Print the board
        print_board(&game_state);

        // Get the player's move
        int row, col;
        printf("Enter the row and column of your move (e.g. 1 2): ");
        scanf("%d %d", &row, &col);

        // Make the move
        make_move(&game_state, row - 1, col - 1);

        // Check for a winner
        int winner = check_for_winner(&game_state);
        if (winner == 1) {
            printf("Game over! %s wins!\n", game_state.current_player == ROMEO ? "Romeo" : "Juliet");
            break;
        } else if (winner == 2) {
            printf("Tie game!\n");
            break;
        }
    }
}

// Main function
int main() {
    play_game();
    return 0;
}