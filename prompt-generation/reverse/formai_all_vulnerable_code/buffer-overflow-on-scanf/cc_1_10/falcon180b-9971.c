//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

char board[ROWS][COLS] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

void print_board() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_win() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }
    for (j = 0; j < COLS; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    return 0;
}

int main() {
    srand(time(NULL));
    int player = 1;
    int choice;
    while (1) {
        system("clear");
        print_board();
        printf("\nPlayer %d's turn.\n", player);
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice < 1 || choice > 9) {
            printf("Invalid choice.\n");
            continue;
        }
        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;
        if (board[row][col]!= 'X' && board[row][col]!= 'O') {
            board[row][col] = (player == 1)? 'X' : 'O';
            player = (player == 1)? 2 : 1;
        } else {
            printf("Invalid choice.\n");
        }
        if (check_win()) {
            printf("\nPlayer %d wins!\n", player);
            break;
        }
    }
    return 0;
}