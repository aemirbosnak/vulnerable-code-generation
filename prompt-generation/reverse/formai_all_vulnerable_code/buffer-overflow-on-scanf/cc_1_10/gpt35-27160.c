//FormAI DATASET v1.0 Category: Table Game ; Style: safe
#include <stdio.h>

char board[3][3];   // tic tac toe board

void init_board() {
    int i, j;
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            board[i][j] = ' ';
        }
    }
}

void print_board() {
    int i, j;
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            printf("|%c", board[i][j]);
        }
        printf("|\n");
    }
}

int check_winner(char symbol) {
    int i, j;
    // horizontal
    for(i=0; i<3; i++) {
        if(board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
            return 1;
        }
    }
    // vertical
    for(i=0; i<3; i++) {
        if(board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) {
            return 1;
        }
    }
    // diagonal
    if(board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
        return 1;
    }
    if(board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) {
        return 1;
    }
    return 0;
}

int main() {
    int row, col;
    char player = 'X';
    init_board();
    printf("Tic Tac Toe\n");
    printf("==========\n");
    print_board();
    while(1) {
        printf("Player %c's turn\n", player);
        printf("Enter row (1-3): ");
        scanf("%d", &row);
        printf("Enter column (1-3): ");
        scanf("%d", &col);
        if(row<1 || row>3 || col<1 || col>3) {
            printf("Invalid input\n");
            continue;
        }
        row--;
        col--;
        if(board[row][col] != ' ') {
            printf("That cell is already taken\n");
            continue;
        }
        board[row][col] = player;
        print_board();
        if(check_winner(player)) {
            printf("Player %c wins!\n", player);
            break;
        }
        if(player == 'X') {
            player = 'O';
        } else {
            player = 'X';
        }
    }
    return 0;
}