//FormAI DATASET v1.0 Category: Table Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

void init_board(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = '-';
        }
    }
}

void print_board(char board[ROWS][COLS]) {
    int i, j;
    printf("\n");

    for (i = 0; i < ROWS; i++) {
        printf("\t\t\t");
        for (j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int check_winner(char board[ROWS][COLS]) {
    int i;

    // row check
    for (i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if (board[i][0] == 'x') return 1;
            else if (board[i][0] == 'o') return 2;
        }
    }

    // column check
    for (i = 0; i < COLS; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            if (board[0][i] == 'x') return 1;
            else if (board[0][i] == 'o') return 2;
        }
    }

    // diagonal check
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == 'x') return 1;
        else if (board[0][0] == 'o') return 2;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == 'x') return 1;
        else if (board[0][2] == 'o') return 2;
    }

    // check for draw
    for (i = 0; i < ROWS; i++) {
        int j;
        for (j = 0; j < COLS; j++) {
            if (board[i][j] == '-') return 0;
        }
    }

    return 3; // no winner and no empty spaces found
}

void player_move(char board[ROWS][COLS]) {
    int row, col;

    do {
        printf("Enter row number (1-3): ");
        scanf("%d", &row);

        printf("Enter column number (1-3): ");
        scanf("%d", &col);

        row--;
        col--;

        if (board[row][col] != '-') {
            printf("This cell is already occupied, please choose another one.\n");
        }
    } while (board[row][col] != '-');

    board[row][col] = 'x';
}

void computer_move(char board[ROWS][COLS]) {
    int row, col;

    do {
        row = rand() % ROWS;
        col = rand() % COLS;
    } while (board[row][col] != '-');

    board[row][col] = 'o';
}

int main() {
    char board[ROWS][COLS];
    int winner = 0, turn_count = 0;

    srand(time(NULL));
    init_board(board);

    printf("\t\t\tWelcome to Tic-Tac-Toe\n");

    do {
        print_board(board);

        if (turn_count % 2 == 0) {
            player_move(board);
        } else {
            computer_move(board);
        }

        winner = check_winner(board);
        turn_count++;

    } while (winner == 0);

    print_board(board);

    switch (winner) {
        case 1:
            printf("\t\t\tYou won! Congratulations!\n");
            break;
        case 2:
            printf("\t\t\tComputer won! Better luck next time!\n");
            break;
        case 3:
            printf("\t\t\tIt is a draw!\n");
            break;
        default:
            break;
    }

    return 0;
}