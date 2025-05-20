//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void print_board(int board[ROWS][COLS]) {
    int i, j;

    printf("B   I   N   G   O\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] == -1) {
                printf("X   ");
            } else {
                printf("%d   ", board[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int board[ROWS][COLS];
    int i, j, bool_check[75] = {0}, num, num_call = 0;
    srand(time(0));

    // initialize the board to -1
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = -1;
        }
    }

    // replace the center with a free space
    board[2][2] = 0;

    // loop until we hit "BINGO" (5 in a row)
    while (1) {
        // generate a random number between 1 and 75
        num = (rand() % 75) + 1;

        // check if the number has already been called
        if (bool_check[num] == 1) {
            continue;
        } else {
            bool_check[num] = 1;
        }

        num_call++;

        printf("Call: %d\n", num);

        // check if the number appears on the board and replace it with -1 if it does
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                if (board[i][j] == num) {
                    board[i][j] = -1;
                }
            }
        }

        // print the board
        print_board(board);

        // check for a "BINGO"
        if ((board[0][0] == -1 && board[0][1] == -1 && board[0][2] == -1 && board[0][3] == -1 && board[0][4] == -1) ||
            (board[1][0] == -1 && board[1][1] == -1 && board[1][2] == -1 && board[1][3] == -1 && board[1][4] == -1) ||
            (board[2][0] == -1 && board[2][1] == -1 && board[2][3] == -1 && board[2][3] == -1 && board[2][4] == -1) ||
            (board[3][0] == -1 && board[3][1] == -1 && board[3][2] == -1 && board[3][3] == -1 && board[3][4] == -1) ||
            (board[4][0] == -1 && board[4][1] == -1 && board[4][2] == -1 && board[4][3] == -1 && board[4][4] == -1) ||
            (board[0][0] == -1 && board[1][0] == -1 && board[2][0] == -1 && board[3][0] == -1 && board[4][0] == -1) ||
            (board[0][1] == -1 && board[1][1] == -1 && board[2][1] == -1 && board[3][1] == -1 && board[4][1] == -1) ||
            (board[0][2] == -1 && board[1][2] == -1 && board[2][2] == -1 && board[3][2] == -1 && board[4][2] == -1) ||
            (board[0][3] == -1 && board[1][3] == -1 && board[2][3] == -1 && board[3][3] == -1 && board[4][3] == -1) ||
            (board[0][4] == -1 && board[1][4] == -1 && board[2][4] == -1 && board[3][4] == -1 && board[4][4] == -1) ||
            (board[0][0] == -1 && board[1][1] == -1 && board[2][2] == -1 && board[3][3] == -1 && board[4][4] == -1) ||
            (board[0][4] == -1 && board[1][3] == -1 && board[2][2] == -1 && board[3][1] == -1 && board[4][0] == -1)) {
            printf("BINGO! Number of Calls: %d\n", num_call);
            break;
        }
    }

    return 0;
}