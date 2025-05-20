//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3 // size of the board

void initialize_board(char board[SIZE][SIZE]);
void print_board(char board[SIZE][SIZE]);
int check_winner(char board[SIZE][SIZE]);
void player_move(char board[SIZE][SIZE], char player);
int is_full(char board[SIZE][SIZE]);
void play_game();

int main() {
    play_game();
    return 0;
}

void play_game() {
    char board[SIZE][SIZE];
    char player = 'X'; // Starting player
    int winner = 0;

    initialize_board(board);

    while (winner == 0 && !is_full(board)) {
        print_board(board);
        player_move(board, player);
        winner = check_winner(board);

        // Check for winner
        if (winner == 0)
            player = (player == 'X') ? 'O' : 'X'; // Switch player
    }

    print_board(board);
    if (winner == 1)
        printf("Player X wins!\n");
    else if (winner == 2)
        printf("Player O wins!\n");
    else
        printf("It's a draw!\n");
}

void initialize_board(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            board[i][j] = ' ';
}

void print_board(char board[SIZE][SIZE]) {
    printf("\nCurrent Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) {
            for (int j = 0; j < SIZE; j++)
                printf("---%s", "");
            printf("\n");
        }
    }
    printf("\n");
}

int check_winner(char board[SIZE][SIZE]) {
    // Check rows
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return (board[i][0] == 'X') ? 1 : (board[i][0] == 'O') ? 2 : 0;
        }
    }
    
    // Check columns
    for (int i = 0; i < SIZE; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return (board[0][i] == 'X') ? 1 : (board[0][i] == 'O') ? 2 : 0;
        }
    }
    
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return (board[0][0] == 'X') ? 1 : (board[0][0] == 'O') ? 2 : 0;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return (board[0][2] == 'X') ? 1 : (board[0][2] == 'O') ? 2 : 0;
    }

    return 0; // No winner yet
}

void player_move(char board[SIZE][SIZE], char player) {
    int row, col;
    while (1) {
        printf("Player %c, enter your move (row and column): ", player);
        scanf("%d %d", &row, &col);
        
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
            board[row][col] = player;
            break;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
}

int is_full(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == ' ')
                return 0; // Not full
    return 1; // Full
}