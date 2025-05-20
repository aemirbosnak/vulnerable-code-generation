//FormAI DATASET v1.0 Category: Checkers Game ; Style: satisfied
#include <stdio.h>

#define EMPTY '.'
#define PLAYER1 'O'
#define PLAYER2 'X'
#define MAX_MOVES 100

int rows, cols;
char board[20][20];
char player1_name[20], player2_name[20];

void print_board() {
    int i, j;

    printf("\n   ");
    for (i = 0; i < cols; i++)
        printf("%d ", i);
    printf("\n");

    for (i = 0; i < rows; i++) {
        printf("%d  ", i);

        for (j = 0; j < cols; j++)
            printf("%c ", board[i][j]);

        printf("\n");
    }
}

void init_board() {
    int i, j;

    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            board[i][j] = EMPTY;

    for (i = 0; i < cols; i++) {
        board[0][i] = PLAYER1;
        board[2][i] = PLAYER1;
        board[rows-1][i] = PLAYER2;
    }
}

void game() {
    int i, moves = 0, player = 1, winner = 0;
    int from_row, from_col, to_row, to_col;
    char player_char = PLAYER1;

    while (moves < MAX_MOVES && !winner) {
        printf("\n%s's turn", player_char == PLAYER1 ? player1_name : player2_name);
        print_board();

        printf("\nEnter the piece you want to move (row col): ");
        scanf("%d %d", &from_row, &from_col);

        if (board[from_row][from_col] != player_char) {
            printf("\nInvalid move, it's not your piece\n");
            continue;
        }

        printf("\nEnter the destination (row col): ");
        scanf("%d %d", &to_row, &to_col);

        if (board[to_row][to_col] != EMPTY) {
            printf("\nInvalid move, it's not an empty square\n");
            continue;
        }

        if (player_char == PLAYER1) {
            if (to_row > from_row && (to_row - from_row != 1 || abs(to_col - from_col) != 1)) {
                printf("\nInvalid move\n");
                continue;
            }
        }

        if (player_char == PLAYER2) {
            if (to_row < from_row && (from_row - to_row != 1 || abs(to_col - from_col) != 1)) {
                printf("\nInvalid move\n");
                continue;
            }
        }

        board[from_row][from_col] = EMPTY;
        board[to_row][to_col] = player_char;

        if (to_row == (player_char == PLAYER1 ? rows-1 : 0)) {
            winner = player;
        }

        player ^= 3;
        player_char = (player == 1 ? PLAYER1 : PLAYER2);
        moves++;
    }

    if (winner) {
        printf("\n%s wins!\n", winner == 1 ? player1_name : player2_name);
    } else {
        printf("\nDraw!\n");
    }
}

int main() {
    int i; 

    printf("Welcome to C Checkers Game!\n");
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    printf("Enter Player1's name: ");
    scanf("%s", player1_name);

    printf("Enter Player2's name: ");
    scanf("%s", player2_name);

    init_board();

    game();

    return 0;
}