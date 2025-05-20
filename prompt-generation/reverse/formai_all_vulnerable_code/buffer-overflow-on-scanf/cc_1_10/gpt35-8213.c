//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3];   // Tic Tac Toe board
char player1 = 'X'; // Human player
char player2 = 'O'; // AI player
char current_player; // Current player turn
int moves = 0;      // Total number of moves

void initialize_board() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void print_board() {
    int i, j;
    printf("      1   2   3  \n");
    printf("    ------------\n");
    for (i = 0; i < 3; i++) {
        printf(" %d  |", i+1);
        for (j = 0; j < 3; j++) {
            printf(" %c |", board[i][j]);
        }
        printf("\n");
        printf("    ------------\n");
    }
}

int check_win(char player) {
    int i;
    // Check rows
    for (i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }
    // Check columns
    for (i = 0; i < 3; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }
    // Check diagonal
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return 1;
    }
    return 0;
}

void update_board(int row, int col, char player) {
    board[row][col] = player;
    moves++;
}

int ai_move() {
    int i, j, k;
    // Check for possible winning moves
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = player2;
                if (check_win(player2)) {
                    return 1;
                }
                board[i][j] = ' ';
            }
        }
    }
    // Check for possible blocking moves
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = player1;
                if (check_win(player1)) {
                    board[i][j] = player2;
                    return 0;
                }
                board[i][j] = ' ';
            }
        }
    }
    // Choose a random move
    srand(time(NULL));
    do {
        i = rand() % 3;
        j = rand() % 3;
    } while (board[i][j] != ' ');
    board[i][j] = player2;
    return 0;
}

int main() {
    printf("Welcome to Tic Tac Toe!\n");
    initialize_board();
    print_board();
    printf("You can start the game by choosing a cell (row, col) to place your 'X'.\n");
    current_player = player1;
    while (moves < 9) {
        if (current_player == player1) {
            int row, col;
            do {
                printf("Player 1's turn (X): ");
                scanf("%d %d", &row, &col);
                if (board[row-1][col-1] != ' ') {
                    printf("Invalid move, try again.\n");
                    continue;
                }
                break;
            } while (1);
            update_board(row-1, col-1, player1);
            current_player = player2;
        } else {
            printf("AI's turn (O):\n");
            ai_move();
            current_player = player1;
        }
        print_board();
        if (check_win(player1)) {
            printf("Congratulations! Player 1 (X) wins!\n");
            return 0;
        }
        if (check_win(player2)) {
            printf("Sorry, the AI (O) wins!\n");
            return 0;
        }
    }
    printf("The game is a tie!\n");
    return 0;
}