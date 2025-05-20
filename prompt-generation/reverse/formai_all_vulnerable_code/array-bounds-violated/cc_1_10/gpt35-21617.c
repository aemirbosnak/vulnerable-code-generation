//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3];
int user_choice = -1;

void init_board() {
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            board[i][j] = '-';
        }
    }
}

void print_board() {
    printf("\n\t\t  Tic Tac Toe\n\n\n");
    for (int i=0; i<3; i++) {
        printf("\t\t");
        for (int j=0; j<3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n\n");
    }
    printf("\n");
}

int is_valid_move(int row, int col) {
    if (row>=0 && row<=2 && col>=0 && col<=2 && board[row][col]== '-') {
        return 1;
    }
    return 0;
}

int get_user_move() {
    int user_row, user_col;
    printf("Enter your move(row col): ");
    scanf("%d %d", &user_row, &user_col);
    if (is_valid_move(user_row, user_col)) {
        return user_row*3 + user_col;
    }
    printf("Invalid move, try again!\n");
    return -1;
}

void make_user_move() {
    user_choice = get_user_move();
    int user_row = user_choice / 3;
    int user_col = user_choice % 3;
    board[user_row][user_col] = 'X';
}

int get_random_move() {
    int rand_choice;
    do {
        rand_choice = rand()%9;
    } while (board[rand_choice/3][rand_choice%3] != '-');
    return rand_choice;
}

int evaluate_board(char sym) {
    if (board[0][0] == sym && board[0][1] == sym && board[0][2] == sym) return 1;
    if (board[1][0] == sym && board[1][1] == sym && board[1][2] == sym) return 1;
    if (board[2][0] == sym && board[2][1] == sym && board[2][2] == sym) return 1;
    if (board[0][0] == sym && board[1][0] == sym && board[2][0] == sym) return 1;
    if (board[0][1] == sym && board[1][1] == sym && board[2][1] == sym) return 1;
    if (board[0][2] == sym && board[1][2] == sym && board[2][2] == sym) return 1;
    if (board[0][0] == sym && board[1][1] == sym && board[2][2] == sym) return 1;
    if (board[0][2] == sym && board[1][1] == sym && board[2][0] == sym) return 1;
    return 0;
}

int is_board_full() {
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (board[i][j] == '-') {
                return 0;
            }
        }
    }
    return 1;
}

void make_ai_move() {
    int ai_choice;
    if (user_choice == -1) {
        ai_choice = get_random_move();
    } else {
        int row = user_choice / 3;
        int col = user_choice % 3;
        if (board[row][col] == 'X') {
            ai_choice = get_random_move();
        } else {
            ai_choice = user_choice;
        }
    }
    int ai_row = ai_choice / 3;
    int ai_col = ai_choice % 3;
    board[ai_row][ai_col] = 'O';
}

int main() {
    srand(time(0));
    init_board();
    printf("         Welcome to Tic Tac Toe!\n\n");
    printf("Instructions:\n\n");
    printf("1. You are 'X' and the computer is 'O'\n");
    printf("2. Enter your move as a row column pair, where\n");
    printf("   the row and column numbers are between 0 and 2.\n");
    printf("3. The first player to get 3 in a row wins!\n\n");
    while(1) {
        print_board();
        make_user_move();
        if (evaluate_board('X')) {
            printf("Congratulations! You win!\n");
            break;
        }
        if (is_board_full()) {
            printf("It's a tie!\n");
            break;
        }
        make_ai_move();
        if (evaluate_board('O')) {
            printf("Sorry, you lose!\n");
            break;
        }
        if (is_board_full()) {
            printf("It's a tie!\n");
            break;
        }
    }
    return 0;
}