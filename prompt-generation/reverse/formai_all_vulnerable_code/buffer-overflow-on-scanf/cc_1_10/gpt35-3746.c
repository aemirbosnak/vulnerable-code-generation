//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3];
int player = 1;
int is_game_over = 0;

void print_board() {
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

void init_board() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

int is_valid_move(int row, int col) {
    if(row < 0 || row > 2 || col < 0 || col > 2) {
        return 0;
    }
    return board[row][col] == ' ';
}

void player_move() {
    int row, col;
    printf("Player %d's turn!\n", player);
    printf("Enter row and column (separated by space): ");
    scanf("%d %d", &row, &col);
    if(is_valid_move(row, col)) {
        board[row][col] = player == 1 ? 'X' : 'O';
        player = player == 1 ? 2 : 1;
    } else {
        printf("Invalid move! Try again.\n");
        player_move();
    }
}

void ai_move() {
    printf("AI's turn!\n");
    int row, col;
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while(!is_valid_move(row, col));
    board[row][col] = 'O';
    player = 1;
}

void check_game_over() {
    // Check rows
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            is_game_over = 1;
            return;
        }
    }
    // Check columns
    for(int i = 0; i < 3; i++) {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            is_game_over = 1;
            return;
        }
    }
    // Check diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        is_game_over = 1;
        return;
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        is_game_over = 1;
        return;
    }
    // Check for tie
    int num_empty = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == ' ') {
                num_empty++;
            }
        }
    }
    if(num_empty == 0) {
        is_game_over = 1;
        return;
    }
}

int main() {
    srand(time(NULL));
    init_board();
    printf("Welcome to Tic Tac Toe!\n");
    printf("You are player 1 (X) and the AI is player 2 (O).\n");
    while(!is_game_over) {
        print_board();
        if(player == 1) {
            player_move();
        } else {
            ai_move();
        }
        check_game_over();
    }
    print_board();
    printf("Game over!\n");
    if(player == 1) {
        printf("AI wins!\n");
    } else {
        printf("You win!\n");
    }
    return 0;
}