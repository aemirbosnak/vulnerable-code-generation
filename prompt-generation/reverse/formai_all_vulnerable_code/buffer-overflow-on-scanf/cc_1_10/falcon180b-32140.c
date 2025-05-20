//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define TOTAL_CARDS 8

void print_board(int board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] == 0)
                printf("_ ");
            else if (board[i][j] == 1)
                printf("X ");
            else if (board[i][j] == 2)
                printf("O ");
        }
        printf("\n");
    }
}

void init_board(int board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = 0;
        }
    }
}

int check_win(int board[ROWS][COLS]) {
    int i;

    // Check horizontal lines
    for (i = 0; i < ROWS; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[i][1] == board[i][2] && board[i][2] == board[i][0]) ||
            (board[i][0] == board[i][2] && board[i][2] == board[i][1])) {
            return 1;
        }
    }

    // Check vertical lines
    for (i = 0; i < COLS; i++) {
        if ((board[0][i] == board[1][i] && board[1][i] == board[2][i]) ||
            (board[1][i] == board[2][i] && board[2][i] == board[0][i]) ||
            (board[0][i] == board[2][i] && board[2][i] == board[1][i])) {
            return 1;
        }
    }

    // Check diagonal lines
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return 1;
    }

    return 0;
}

int main() {
    srand(time(NULL));
    int board[ROWS][COLS];
    int i, j, choice, flag = 0;

    init_board(board);

    while (1) {
        system("clear");
        print_board(board);

        printf("\nPlayer 1's turn. Enter your choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 4 && board[0][choice - 1] == 0) {
            board[0][choice - 1] = 1;
            flag = 1;
        } else {
            printf("Invalid choice. Try again.\n");
        }

        if (flag) {
            flag = 0;
            if (check_win(board)) {
                printf("\nPlayer 1 wins!\n");
                break;
            } else if (choice == 4) {
                printf("\nIt's a draw.\n");
                break;
            } else {
                system("sleep 1");
            }
        } else {
            system("sleep 1");
        }
    }

    return 0;
}