//GPT-4o-mini DATASET v1.0 Category: Chess AI ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 8

const char *pieces[2][6] = {
    {"R", "N", "B", "Q", "K", "P"},   // White pieces
    {"r", "n", "b", "q", "k", "p"}    // Black pieces
};

char board[SIZE][SIZE];

void initialize_board() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == 0) {
                board[i][j] = pieces[0][j][0]; // White pieces
            } else if (i == 1) {
                board[i][j] = pieces[0][5][0]; // White Pawns
            } else if (i == 6) {
                board[i][j] = pieces[1][5][0]; // Black Pawns
            } else if (i == 7) {
                board[i][j] = pieces[1][j][0]; // Black pieces
            } else {
                board[i][j] = '.'; // Empty squares
            }
        }
    }
}

void print_board() {
    printf("  a b c d e f g h\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", 8 - i);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int move_piece(char *move) {
    int from_file = move[0] - 'a'; // File
    int from_rank = 8 - (move[1] - '0'); // Rank
    int to_file = move[3] - 'a'; // File
    int to_rank = 8 - (move[4] - '0'); // Rank

    if (from_file < 0 || to_file < 0 || from_file >= SIZE || to_file >= SIZE ||
        from_rank < 0 || to_rank < 0 || from_rank >= SIZE || to_rank >= SIZE) {
        printf("Invalid move!\n");
        return 0;
    }

    // Check if the move is valid
    if (board[from_rank][from_file] == '.') {
        printf("No piece at the starting position!\n");
        return 0;
    }

    // Move the piece
    board[to_rank][to_file] = board[from_rank][from_file];
    board[from_rank][from_file] = '.';
    return 1;
}

void play_game() {
    char move[6];
    int turn = 0; // 0 for White's turn, 1 for Black's turn
    while (1) {
        print_board();
        if (turn == 0) {
            printf("Romeo's turn (White): Enter your move (e.g., e2 e4): ");
        } else {
            printf("Juliet's turn (Black): Enter your move (e.g., e7 e5): ");
        }
        fgets(move, sizeof(move), stdin);
        
        if (move_piece(move)) {
            turn = 1 - turn; // Switch turn
        } else {
            printf("Alas, the move was not completed, try again.\n");
        }
    }
}

int main() {
    printf("A tale of two players: Romeo and Juliet.\n");
    initialize_board();
    play_game();
    return 0;
}