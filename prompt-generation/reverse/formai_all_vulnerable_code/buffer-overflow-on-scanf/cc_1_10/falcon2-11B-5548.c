//Falcon2-11B DATASET v1.0 Category: Tic Tac Toe AI ; Style: excited
#include <stdio.h>
#include <stdbool.h>

void print_board(char board[][3], int num_rows, int num_cols);
void check_win(char board[][3], int num_rows, int num_cols);
int get_user_input(char board[][3], int num_rows, int num_cols);
void print_help(void);

int main(void)
{
    char board[3][3];
    int num_rows = 3;
    int num_cols = 3;
    int num_moves = 0;

    print_help();
    while (num_moves < 9) {
        print_board(board, num_rows, num_cols);
        printf("\nYour move %d. Enter your move (1-9): ", num_moves + 1);
        int move = get_user_input(board, num_rows, num_cols);
        if (move == -1) {
            break;
        }
        board[move - 1][move - 1] = 'X';
        num_moves++;
        check_win(board, num_rows, num_cols);
    }
    print_board(board, num_rows, num_cols);
    printf("\n\nGame Over!\n");

    return 0;
}

void print_board(char board[][3], int num_rows, int num_cols)
{
    for (int row = 0; row < num_rows; row++) {
        for (int col = 0; col < num_cols; col++) {
            printf("%c ", board[row][col]);
        }
        printf("\n");
    }
}

void check_win(char board[][3], int num_rows, int num_cols)
{
    bool win = false;
    // Check rows
    for (int row = 0; row < num_rows; row++) {
        if (board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
            win = true;
            printf("Player 1 wins!\n");
            break;
        }
    }
    // Check columns
    for (int col = 0; col < num_cols; col++) {
        if (board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
            win = true;
            printf("Player 1 wins!\n");
            break;
        }
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        win = true;
        printf("Player 1 wins!\n");
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        win = true;
        printf("Player 1 wins!\n");
    }
    if (!win) {
        printf("It's a tie!\n");
    }
}

int get_user_input(char board[][3], int num_rows, int num_cols)
{
    char input;
    int move;
    while (1) {
        printf("Enter your move (1-9): ");
        if (scanf("%c", &input)!= 1) {
            break;
        }
        move = input - '1';
        if (move < 0 || move >= num_rows * num_cols) {
            printf("Invalid move. Try again.\n");
        } else if (board[move / num_cols][move % num_cols]!= '.') {
            printf("Move already taken. Try again.\n");
        } else {
            return move;
        }
    }
    return -1;
}

void print_help(void)
{
    printf("Welcome to Tic Tac Toe!\n");
    printf("Rules:\n");
    printf("1. Players take turns placing X and O on a 3x3 grid.\n");
    printf("2. The first player to get 3 of their marks in a row, column, or diagonal wins.\n");
    printf("3. If all spaces are filled and no player has 3 in a row, it's a tie.\n");
    printf("Enter any key to start the game.\n");
    getchar();
}