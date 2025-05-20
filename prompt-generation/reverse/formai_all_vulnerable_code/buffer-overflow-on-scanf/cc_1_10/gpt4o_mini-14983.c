//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_MOVES 100

// Function declarations
void initialize_game(int *board, int *scores, int players);
void print_board(int *board, int size);
void print_scores(int *scores, int players);
int player_move(int player_num);
bool check_winner(int *board, int size);
int random_position(int size);

// Entry point of the program
int main() {
    int players, board[9], scores[MAX_PLAYERS] = {0};
    bool game_over = false;

    // Seed the random number generator
    srand(time(NULL));

    // Prompt for number of players
    printf("Enter number of players (2 - %d): ", MAX_PLAYERS);
    scanf("%d", &players);
    if (players < 2 || players > MAX_PLAYERS) {
        printf("Invalid number of players. Setting to 2.\n");
        players = 2;
    }

    initialize_game(board, scores, players);

    // Game loop
    while (!game_over) {
        for (int i = 0; i < players; i++) {
            printf("\nPlayer %d's turn.\n", i + 1);
            print_board(board, 9);
            int move = player_move(i + 1);
            if (board[move] == 0) {
                board[move] = i + 1; // Set the board position to current player
                if (check_winner(board, 9)) {
                    print_board(board, 9);
                    printf("Player %d wins!\n", i + 1);
                    scores[i]++;
                    game_over = true;
                    break;
                }
            } else {
                printf("Position already taken. Try again.\n");
                i--; // Repeat the turn
            }
        }
        
        // Print scores
        print_scores(scores, players);
    }

    // Final score display
    printf("\nGame Over! Final Scores:\n");
    print_scores(scores, players);

    return 0;
}

// Initialize the game board and scores
void initialize_game(int *board, int *scores, int players) {
    for (int i = 0; i < 9; i++)
        board[i] = 0; // Initialize board with 0 (empty)
    for (int i = 0; i < players; i++)
        scores[i] = 0; // Initialize scores to 0
}

// Function to print the game board
void print_board(int *board, int size) {
    printf("\nCurrent Board:\n");
    for (int i = 0; i < size; i++) {
        if (board[i] == 0)
            printf("- ");
        else
            printf("%d ", board[i]);
        
        if ((i + 1) % 3 == 0)
            printf("\n");
    }
}

// Function to display the scores of players
void print_scores(int *scores, int players) {
    printf("\nScores:\n");
    for (int i = 0; i < players; i++) {
        printf("Player %d: %d\n", i + 1, scores[i]);
    }
}

// Function to handle player's move
int player_move(int player_num) {
    int move;
    printf("Player %d, enter your move (0-8): ", player_num);
    scanf("%d", &move);
    return move;
}

// Function to check for a winner
bool check_winner(int *board, int size) {
    // Winning combinations
    int win_conditions[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Columns
        {0, 4, 8}, {2, 4, 6}             // Diagonals
    };

    for (int i = 0; i < 8; i++) {
        if (board[win_conditions[i][0]] != 0 &&
            board[win_conditions[i][0]] == board[win_conditions[i][1]] &&
            board[win_conditions[i][1]] == board[win_conditions[i][2]]) {
            return true;
        }
    }
    return false;
}