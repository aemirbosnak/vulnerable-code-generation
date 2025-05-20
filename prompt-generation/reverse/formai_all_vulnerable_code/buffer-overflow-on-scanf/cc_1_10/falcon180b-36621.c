//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 5

void print_board(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void generate_board(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2? 'X' : 'O';
        }
    }
}

int check_win(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == board[i][3] && board[i][3] == board[i][4])
            return 1;
    }

    for (int j = 0; j < COLS; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[2][j] == board[3][j])
            return 1;
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3])
        return 1;

    if (board[0][4] == board[1][3] && board[1][3] == board[2][2] && board[2][2] == board[3][1])
        return 1;

    return 0;
}

int main() {
    srand(time(NULL));
    char board[ROWS][COLS];
    generate_board(board);
    int player = 1;
    int choice;

    while (1) {
        system("clear");
        print_board(board);
        printf("\nPlayer %d's turn\n", player);
        printf("Enter your move (1-%d): ", COLS - 1);
        scanf("%d", &choice);

        if (choice < 1 || choice > COLS - 1) {
            printf("Invalid move\n");
            continue;
        }

        if (board[0][choice - 1]!= 'X' && board[0][choice - 1]!= 'O') {
            board[0][choice - 1] = (player % 2 == 0)? 'X' : 'O';
            player++;
        } else {
            printf("Invalid move\n");
        }

        if (check_win(board)) {
            printf("\nPlayer %d wins!\n", player % 2 + 1);
            break;
        }

        if (player % 2 == 0)
            player++;
        else
            player--;
    }

    return 0;
}