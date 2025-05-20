//Code Llama-13B DATASET v1.0 Category: Bingo Simulator ; Style: statistical
// C Bingo Simulator

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the bingo board
#define BOARD_SIZE 5

// Define the number of bingo squares
#define NUM_SQUARES 25

// Define the number of players
#define NUM_PLAYERS 5

// Define the number of rounds
#define NUM_ROUNDS 5

// Define the number of bingo squares to mark
#define NUM_MARKS 5

// Define the winning squares
int winning_squares[NUM_MARKS];

// Define the players
typedef struct {
    char name[20];
    int marks[NUM_MARKS];
    int total_marks;
    int bingo;
} Player;

// Define the bingo board
typedef struct {
    int squares[NUM_SQUARES];
    int marked[NUM_SQUARES];
} Board;

// Generate a random number
int rand_int(int low, int high) {
    return (rand() % (high - low + 1)) + low;
}

// Generate a random number within the range of the board
int rand_square(int low, int high) {
    return rand_int(low, high);
}

// Check if a square is marked
int is_marked(int square, Board* board) {
    return board->marked[square];
}

// Mark a square on the board
void mark_square(int square, Board* board) {
    board->marked[square] = 1;
}

// Check if a player has bingo
int has_bingo(Player* player, Board* board) {
    for (int i = 0; i < NUM_MARKS; i++) {
        if (!is_marked(player->marks[i], board)) {
            return 0;
        }
    }
    return 1;
}

// Check if a player has won
int has_won(Player* player, Board* board) {
    return has_bingo(player, board);
}

// Print the bingo board
void print_board(Board* board) {
    for (int i = 0; i < NUM_SQUARES; i++) {
        if (i % BOARD_SIZE == 0) {
            printf("\n");
        }
        printf("%2d ", board->squares[i]);
    }
}

// Print the players
void print_players(Player* players) {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("%s ", players[i].name);
    }
}

// Print the results
void print_results(Player* players, Board* board) {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        if (has_won(&players[i], board)) {
            printf("%s has won!\n", players[i].name);
        }
    }
}

// Run the bingo simulation
void run_simulation(Player* players, Board* board) {
    // Generate the winning squares
    for (int i = 0; i < NUM_MARKS; i++) {
        winning_squares[i] = rand_square(0, NUM_SQUARES - 1);
    }

    // Print the bingo board
    print_board(board);

    // Print the players
    print_players(players);

    // Play the game
    for (int i = 0; i < NUM_ROUNDS; i++) {
        // Draw the winning number
        int winning_number = rand_square(0, NUM_SQUARES - 1);

        // Mark the winning square on the board
        mark_square(winning_number, board);

        // Check if any player has bingo
        for (int j = 0; j < NUM_PLAYERS; j++) {
            if (has_bingo(&players[j], board)) {
                players[j].bingo = 1;
            }
        }

        // Print the results
        print_results(players, board);
    }
}

int main() {
    // Initialize the players
    Player players[NUM_PLAYERS];
    for (int i = 0; i < NUM_PLAYERS; i++) {
        players[i].total_marks = 0;
        players[i].bingo = 0;
    }

    // Initialize the board
    Board board;
    for (int i = 0; i < NUM_SQUARES; i++) {
        board.squares[i] = i + 1;
        board.marked[i] = 0;
    }

    // Run the simulation
    run_simulation(players, &board);

    return 0;
}