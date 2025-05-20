//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 8

typedef struct {
    int player1_wins;
    int player2_wins;
    int draws;
} GameStatistics;

char board[SIZE][SIZE];
GameStatistics stats;

void initialize_board() {
    memset(board, ' ', sizeof(board));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i % 2 != j % 2) {
                if (i < 3) {
                    board[i][j] = 'X'; // Player 1 pieces
                } else if (i > 4) {
                    board[i][j] = 'O'; // Player 2 pieces
                }
            }
        }
    }
}

void print_board() {
    printf("  A B C D E F G H\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int is_valid_move(int start_row, int start_col, int end_row, int end_col, char player) {
    // Basic validation checks for movement without capturing logic
    if (end_row < 0 || end_row >= SIZE || end_col < 0 || end_col >= SIZE) return 0;
    if (board[end_row][end_col] != ' ') return 0; // destination must be empty

    int dir = (player == 'X') ? 1 : -1; // Directions based on player
    if (end_row - start_row == dir && abs(end_col - start_col) == 1) {
        return 1; // Simple move
    }
    return 0; // Invalid move
}

void update_statistics(char winner) {
    if (winner == 'X') {
        stats.player1_wins++;
    } else if (winner == 'O') {
        stats.player2_wins++;
    } else {
        stats.draws++;
    }
}

void print_statistics() {
    printf("\nGame Statistics:\n");
    printf("Player 1 Wins: %d\n", stats.player1_wins);
    printf("Player 2 Wins: %d\n", stats.player2_wins);
    printf("Draws: %d\n", stats.draws);
}

int main() {
    stats.player1_wins = 0;
    stats.player2_wins = 0;
    stats.draws = 0;

    char current_player = 'X';
    initialize_board();
    while (1) {
        print_board();

        char start_col, end_col;
        int start_row, end_row;
        printf("Player %c's turn (Enter move in format: A1 B2): ", current_player);
        char move[6];
        if (!fgets(move, sizeof(move), stdin)) break;
        
        sscanf(move, "%c%d %c%d", &start_col, &start_row, &end_col, &end_row);

        int start_col_index = start_col - 'A';
        int end_col_index = end_col - 'A';
        start_row--; end_row--; // To adjust for 0-indexing

        if (is_valid_move(start_row, start_col_index, end_row, end_col_index, current_player)) {
            board[end_row][end_col_index] = board[start_row][start_col_index];
            board[start_row][start_col_index] = ' '; // Clear the starting piece

            // Check for winner (a very simplified example)
            if (end_row == SIZE - 1 && current_player == 'X') {
                print_board();
                printf("Player X Wins!\n");
                update_statistics('X');
                break;
            }
            else if (end_row == 0 && current_player == 'O') {
                print_board();
                printf("Player O Wins!\n");
                update_statistics('O');
                break;
            }

            current_player = (current_player == 'X') ? 'O' : 'X'; // Switch players
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
    print_statistics();
    return 0;
}