//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

char board[3][3];

void init_board() {
    int i, j;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            board[i][j] = '-';
        }
    }
}

// Prints the game board
void print_board() {
    int i, j;
    printf("\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Check if winning condition met (3 symbols in a row)
int check_winner(char symbol) {
    int i, j;
    // Check rows
    for(i = 0; i < 3; i++) {
        if(board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
            return 1;
        }
    }
    // Check columns
    for(i = 0; i < 3; i++) {
        if(board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) {
            return 1;
        }
    }
    // Check diagonals
    if(board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
        return 1;
    }
    if(board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) {
        return 1;
    }
    // No winning condition met
    return 0;
}

// Check if the board is full
int board_full() {
    int i, j;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            if(board[i][j] == '-') {
                return 0;
            }
        }
    }
    return 1;
}

// Get AI's move
void get_ai_move(char symbol) {
    int i, j;
    // Check for winning move
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            if(board[i][j] == '-') {
                board[i][j] = symbol;
                if(check_winner(symbol)) {
                    return;
                }
                board[i][j] = '-';
            }
        }
    }
    // Check for blocking move
    char opponent_symbol = (symbol == 'X' ? 'O' : 'X');
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            if(board[i][j] == '-') {
                board[i][j] = opponent_symbol;
                if(check_winner(opponent_symbol)) {
                    board[i][j] = symbol;
                    return;
                }
                board[i][j] = '-';
            }
        }
    }
    // Random move
    while(1) {
        i = rand() % 3;
        j = rand() % 3;
        if(board[i][j] == '-') {
            board[i][j] = symbol;
            return;
        }
    }
}

int main() {
    int row, col;
    char player1 = 'X', player2 = 'O';
    int current_player = 1;
    init_board();
    while(1) {
        printf("Current board:\n");
        print_board();
        if(current_player == 1) {
            printf("Player 1 (%c), enter row and column: ", player1);
        } else {
            printf("Player 2 (%c), enter row and column: ", player2);
        }
        scanf("%d %d", &row, &col);
        if(row < 1 || row > 3 || col < 1 || col > 3) {
            printf("Invalid input, please try again.\n");
            continue;
        }
        row--;
        col--;
        if(board[row][col] != '-') {
            printf("That position is already occupied, please try again.\n");
            continue;
        }
        if(current_player == 1) {
            board[row][col] = player1;
            if(check_winner(player1)) {
                printf("Player 1 wins!\n");
                print_board();
                return 0;
            }
        } else {
            board[row][col] = player2;
            if(check_winner(player2)) {
                printf("Player 2 wins!\n");
                print_board();
                return 0;
            }
        }
        if(board_full()) {
            printf("Game over, it's a tie!\n");
            print_board();
            return 0;
        }
        current_player = (current_player == 1 ? 2 : 1);
        if(current_player == 2) {
            printf("AI is making a move...\n");
            get_ai_move(player2);
            if(check_winner(player2)) {
                printf("AI wins!\n");
                print_board();
                return 0;
            }
        }
    }
    return 0;
}