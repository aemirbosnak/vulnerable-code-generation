//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: Romeo and Juliet
#include <stdio.h>

#define EMPTY ' '
#define PLAYER 'X'
#define AI 'O'
#define SIZE 3

char board[SIZE][SIZE];

void initialize_board();
void display_board();
int check_winner();
void player_move();
void ai_move();
int check_full();

int main() {
    int winner = 0;
    initialize_board();

    while (winner == 0 && !check_full()) {
        display_board();
        player_move();
        winner = check_winner();
        if (winner != 0 || check_full()) {
            break;
        }
        ai_move();
        winner = check_winner();
    }

    display_board();
    
    if (winner == PLAYER) {
        printf("The valiant Player has triumphed, a glorious deed!\n");
    } else if (winner == AI) {
        printf("Alas! The cunning AI prevails, a tragic end.\n");
    } else {
        printf("A lamentable tie, both valiant souls shall rest.\n");
    }

    return 0;
}

void initialize_board() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
}

void display_board() {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("---|---|---\n");
    }
    printf("\n");
}

int check_winner() {
    // Check rows and columns for a winner
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != EMPTY) {
            return board[i][0];
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != EMPTY) {
            return board[0][i];
        }
    }
    // Check diagonals for a winner
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != EMPTY) {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != EMPTY) {
        return board[0][2];
    }
    return 0;
}

void player_move() {
    int row, col;
    printf("Enter the row and column (0, 1, or 2) where thou wish to place thy 'X': ");
    while (1) {
        scanf("%d %d", &row, &col);
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == EMPTY) {
            board[row][col] = PLAYER;
            break;
        }
        printf("Inappropriate move! Make haste, try again...\n");
    }
}

void ai_move() {
    int row, col;
    // Simple AI logic: find the first empty space
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (board[row][col] == EMPTY) {
                board[row][col] = AI;
                printf("The AI, with cunning art, hath placed 'O' in position (%d, %d).\n", row, col);
                return;
            }
        }
    }
}

int check_full() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == EMPTY) return 0;
    return 1;
}