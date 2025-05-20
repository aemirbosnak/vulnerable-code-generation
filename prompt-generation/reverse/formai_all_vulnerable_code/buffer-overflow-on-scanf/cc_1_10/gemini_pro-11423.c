//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define NUM_PLAYERS 2
#define MAX_TURNS 9

// Represents a square on the game board.
typedef struct {
    int player;  // The player who has claimed this square, or 0 if unclaimed.
    int value;  // The value of this square (1 or -1).
} Square;

// Represents the game board.
typedef struct {
    Square squares[BOARD_SIZE][BOARD_SIZE];
} Board;

// Represents a player.
typedef struct {
    int player_num;  // The player's number (1 or 2).
    int score;  // The player's score.
} Player;

// Initializes the game board.
void init_board(Board *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->squares[i][j].player = 0;
            board->squares[i][j].value = 0;
        }
    }
}

// Prints the game board to the console.
void print_board(Board *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board->squares[i][j].player == 0) {
                printf(" ");
            } else if (board->squares[i][j].player == 1) {
                printf("X");
            } else if (board->squares[i][j].player == 2) {
                printf("O");
            }
        }
        printf("\n");
    }
}

// Checks if the game has been won.
int check_win(Board *board) {
    // Check rows.
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->squares[i][0].player != 0 &&
            board->squares[i][1].player == board->squares[i][0].player &&
            board->squares[i][2].player == board->squares[i][0].player) {
            return board->squares[i][0].player;
        }
    }

    // Check columns.
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->squares[0][i].player != 0 &&
            board->squares[1][i].player == board->squares[0][i].player &&
            board->squares[2][i].player == board->squares[0][i].player) {
            return board->squares[0][i].player;
        }
    }

    // Check diagonals.
    if (board->squares[0][0].player != 0 &&
        board->squares[1][1].player == board->squares[0][0].player &&
        board->squares[2][2].player == board->squares[0][0].player) {
        return board->squares[0][0].player;
    }
    if (board->squares[0][2].player != 0 &&
        board->squares[1][1].player == board->squares[0][2].player &&
        board->squares[2][0].player == board->squares[0][2].player) {
        return board->squares[0][2].player;
    }

    // No winner yet.
    return 0;
}

// Gets the player's move.
int get_move(Player *player, Board *board) {
    int row, col;

    // Get the player's move.
    printf("Player %d, enter your move (row, column): ", player->player_num);
    scanf("%d %d", &row, &col);

    // Check if the move is valid.
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board->squares[row][col].player != 0) {
        printf("Invalid move. Please try again.\n");
        return get_move(player, board);
    }

    // Return the move.
    return row * BOARD_SIZE + col;
}

// Makes the player's move.
void make_move(Player *player, Board *board, int move) {
    int row = move / BOARD_SIZE;
    int col = move % BOARD_SIZE;

    // Claim the square.
    board->squares[row][col].player = player->player_num;

    // Update the player's score.
    player->score += board->squares[row][col].value;
}

// Plays the game.
void play_game() {
    // Initialize the game.
    Board board;
    init_board(&board);

    Player players[NUM_PLAYERS];
    for (int i = 0; i < NUM_PLAYERS; i++) {
        players[i].player_num = i + 1;
        players[i].score = 0;
    }

    // Play the game.
    int turn = 0;
    int winner = 0;
    while (turn < MAX_TURNS && winner == 0) {
        // Get the current player.
        Player *player = &players[turn % NUM_PLAYERS];

        // Get the player's move.
        int move = get_move(player, &board);

        // Make the player's move.
        make_move(player, &board, move);

        // Check if the game has been won.
        winner = check_win(&board);

        // Print the game board.
        print_board(&board);

        // Increment the turn.
        turn++;
    }

    // Declare the winner.
    if (winner == 0) {
        printf("The game ended in a draw.\n");
    } else {
        printf("Player %d wins!\n", winner);
    }
}

// Main function.
int main() {
    // Seed the random number generator.
    srand(time(NULL));

    // Play the game.
    play_game();

    return 0;
}