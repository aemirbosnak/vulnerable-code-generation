//FormAI DATASET v1.0 Category: Table Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// function prototypes
void print_board(char board[3][3]);
int is_winner(char board[3][3], char c);
int player_move(char board[3][3], char c);
int computer_move(char board[3][3], char c);

int main()
{
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    srand(time(NULL)); // seed the random number generator

    // randomly choose starting player
    int player = rand() % 2; 

    printf("Welcome to BraveTicTacToe!\n");
    printf("Player 1: X\nPlayer 2: O\n");

    print_board(board);

    while (1) {
        if (player == 0) { // player 1's turn
            if (player_move(board, 'X') == -1) {
                printf("Invalid move, try again.\n");
                continue;
            }
            if (is_winner(board, 'X')) {
                printf("Player 1 wins!\n");
                break;
            }
            player = 1;
        } else { // player 2's turn
            if (computer_move(board, 'O') == -1) {
                printf("Invalid move, try again.\n");
                continue;
            }
            if (is_winner(board, 'O')) {
                printf("Computer wins!\n");
                break;
            }
            player = 0;
        }
        print_board(board);
        if (is_winner(board, 'X')) {
            printf("Player 1 wins!\n");
            break;
        } else if (is_winner(board, 'O')) {
            printf("Computer wins!\n");
            break;
        } else if (!strchr(board[0], ' ') && !strchr(board[1], ' ') && !strchr(board[2], ' ')) {
            printf("Tie game!\n");
            break;
        }
    }

    return 0;
}

// function to print the game board
void print_board(char board[3][3])
{
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

// function to check if a player has won
int is_winner(char board[3][3], char c)
{
    if ((board[0][0] == c && board[0][1] == c && board[0][2] == c) || // top row
        (board[1][0] == c && board[1][1] == c && board[1][2] == c) || // middle row
        (board[2][0] == c && board[2][1] == c && board[2][2] == c) || // bottom row
        (board[0][0] == c && board[1][0] == c && board[2][0] == c) || // left column
        (board[0][1] == c && board[1][1] == c && board[2][1] == c) || // middle column
        (board[0][2] == c && board[1][2] == c && board[2][2] == c) || // right column
        (board[0][0] == c && board[1][1] == c && board[2][2] == c) || // diagonal 1
        (board[0][2] == c && board[1][1] == c && board[2][0] == c)) { // diagonal 2
        return 1;
    } else {
        return 0;
    }
}

// function for player move
int player_move(char board[3][3], char c)
{
    int row, col;

    printf("Player 1 enter row and column (e.g. 1 2): ");
    scanf("%d %d", &row, &col);

    if (row < 1 || row > 3 || col < 1 || col > 3 || board[row-1][col-1] != ' ') {
        return -1;
    } else {
        board[row-1][col-1] = c;
        return 0;
    }
}

// function for computer move
int computer_move(char board[3][3], char c)
{
    int row, col;

    printf("Computer's move:\n");

    // random move for now
    row = rand() % 3;
    col = rand() % 3;

    if (board[row][col] == ' ') {
        board[row][col] = c;
        return 0;
    } else {
        return -1;
    }
}