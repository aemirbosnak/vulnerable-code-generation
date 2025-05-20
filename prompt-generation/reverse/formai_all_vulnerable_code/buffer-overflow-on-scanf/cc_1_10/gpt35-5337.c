//FormAI DATASET v1.0 Category: Table Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define MAX_MOVES BOARD_SIZE * BOARD_SIZE

char board[BOARD_SIZE][BOARD_SIZE];
int turn;
int winner;

void clear_board()
{
    int i, j;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void print_board()
{
    int i, j;

    printf("\n");

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf(" %c ", board[i][j]);

            if (j != BOARD_SIZE - 1) {
                printf("|");
            }
        }

        printf("\n");

        if (i != BOARD_SIZE - 1) {
            for (j = 0; j < BOARD_SIZE; j++) {
                printf("---");

                if (j != BOARD_SIZE - 1) {
                    printf("+");
                }
            }

            printf("\n");
        }
    }

    printf("\n");
}

int is_valid_move(int row, int col)
{
    if (board[row][col] == ' ') {
        return 1;
    } else {
        return 0;
    }
}

int check_for_winner()
{
    int i, j;

    for (i = 0; i < BOARD_SIZE; i++) {
        if ((board[i][0] != ' ') && (board[i][0] == board[i][1]) && (board[i][1] == board[i][2])) {
            return 1;
        }
    }

    for (j = 0; j < BOARD_SIZE; j++) {
        if ((board[0][j] != ' ') && (board[0][j] == board[1][j]) && (board[1][j] == board[2][j])) {
            return 1;
        }
    }

    if ((board[0][0] != ' ') && (board[0][0] == board[1][1]) && (board[1][1] == board[2][2])) {
        return 1;
    }

    if ((board[2][0] != ' ') && (board[2][0] == board[1][1]) && (board[1][1] == board[0][2])) {
        return 1;
    }

    return 0;
}

void player_move()
{
    int row, col;

    printf("\nPlayer %d's turn!\n", turn);
    printf("Enter the row and column you want to play: ");
    scanf("%d %d", &row, &col);

    row--;
    col--;

    if (is_valid_move(row, col)) {
        board[row][col] = (turn == 1) ? 'X' : 'O';
        print_board();

        if (check_for_winner()) {
            printf("Player %d wins!\n", turn);
            winner = turn;
        } else if (turn == 1) {
            turn = 2;
        } else {
            turn = 1;
        }
    } else {
        printf("That move is not valid! Try again...\n");
        player_move();
    }
}

void computer_move()
{
    srand(time(NULL));

    int row, col;

    printf("\nComputer's turn!\n");

    do {
        row = rand() % BOARD_SIZE;
        col = rand() % BOARD_SIZE;
    } while (!is_valid_move(row, col));

    board[row][col] = 'O';

    print_board();

    if (check_for_winner()) {
        printf("Computer wins!\n");
        winner = 2;
    } else {
        turn = 1;
    }
}

int main()
{
    turn = 1;
    winner = 0;

    printf("Welcome to tic-tac-toe!\n");

    clear_board();
    print_board();

    while (winner == 0 && turn <= MAX_MOVES) {
        if (turn == 1) {
            player_move();
        } else {
            computer_move();
        }
    }

    if (winner == 0) {
        printf("The game is a tie!\n");
    }

    return 0;
}