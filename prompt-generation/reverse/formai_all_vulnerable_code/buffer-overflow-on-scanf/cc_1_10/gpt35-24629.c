//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char board[3][3];

void display_board() {
    printf("-----------------\n");
    for(int i = 0; i < 3; i++) {
        printf("| %c | %c | %c |\n", board[i][0], board[i][1], board[i][2]);
        printf("-----------------\n");
    }
}

bool is_valid_move(int row, int col) {
    if(row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
        return false;
    }
    return true;
}

bool check_win(char c) {
    for(int i = 0; i < 3; i++) {
        //check rows
        if(board[i][0] == c && board[i][1] == c && board[i][2] == c) {
            return true;
        }
        //check columns
        if(board[0][i] == c && board[1][i] == c && board[2][i] == c) {
            return true;
        }
    }
    //check diagonals
    if(board[0][0] == c && board[1][1] == c && board[2][2] == c) {
        return true;
    }
    if(board[0][2] == c && board[1][1] == c && board[2][0] == c) {
        return true;
    }
    return false;
}

bool make_move(int row, int col, char c) {
    if(is_valid_move(row, col)) {
        board[row][col] = c;
        display_board();
        if(check_win(c)) {
            printf("Game over. %c wins.\n", c);
            return true;
        }
    }
    else {
        printf("Invalid move. Please try again.\n");
    }
    return false;
}

void computer_move() {
    /* 
     * This AI is designed to be extremely paranoid. It will try to block every
     * possible winning move of the player, and try to set up its own winning move,
     * whenever possible.
     */
    int best_row, best_col;
    int best_score = -1;
    int score;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(is_valid_move(i, j)) {
                //check if this move will result in a win for the computer
                board[i][j] = 'O';
                if(check_win('O')) {
                    make_move(i, j, 'O');
                    exit(0);
                }
                //check if this move will block a winning move of the player
                board[i][j] = 'X';
                if(check_win('X')) {
                    score = 0;
                    score += (i == 1) ? 2 : 1; //prefer center and edges over corners
                    score += (j == 1) ? 2 : 1;
                    if(score > best_score) {
                        best_row = i;
                        best_col = j;
                        best_score = score;
                    }
                }
                board[i][j] = ' ';
            }
        }
    }
    //no winning or blocking moves found, make a random move
    int row, col;
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (!is_valid_move(row, col));
    make_move(row, col, 'O');
}

int main() {
    //initialize the game board
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
    display_board();
    //main game loop
    while(true) {
        printf("Your turn. Enter row (0-2) and column (0-2): ");
        int row, col;
        scanf("%d %d", &row, &col);
        if(make_move(row, col, 'X')) {
            exit(0);
        }
        printf("Computer's turn.\n");
        computer_move();
    }
    return 0;
}