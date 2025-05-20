//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: portable
#include <stdio.h>
#include <stdlib.h>

char board[3][3]; // the Tic Tac Toe board
char player;      // the current player ('X' or 'O')

// function prototypes
void init_board();
void print_board();
void get_move();
int  get_winner();
int  is_full();

int main()
{
    int winner;

    init_board();

    printf("Welcome to Tic Tac Toe!\n");
    printf("=======================\n");

    // main game loop
    while (1) {
        // print the board
        print_board();
        
        // get the player's move
        get_move();
        
        // check for a winner
        winner = get_winner();
        if (winner != 0) {
            printf("Player %c wins!\n", winner);
            break;
        }
        
        // check for a draw
        if (is_full()) {
            printf("It's a draw!\n");
            break;
        }
        
        // switch players
        if (player == 'X')
            player = 'O';
        else
            player = 'X';
    }

    return 0;
}

// initialize the board
void init_board()
{
    int i, j;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            board[i][j] = ' ';
}

// print the board
void print_board()
{
    int i, j;

    printf("\n");
    printf("  1 2 3\n");
    printf(" -------\n");
    for (i = 0; i < 3; i++) {
        printf("%c ", 'a'+i);
        for (j = 0; j < 3; j++) {
            printf("|%c", board[i][j]);
        }
        printf("|\n");
        printf(" -------\n");
    }
    printf("\n");
}

// get the player's move
void get_move()
{
    int row, col;

    printf("Player %c's move: ", player);
    scanf(" %c%d", &row, &col);

    while (1) {
        // convert the row letter to a number
        row -= 'a';

        // check if the move is valid
        if (row < 0 || row > 2 || col < 1 || col > 3 || board[row][col-1] != ' ') {
            printf("Invalid move. Please try again: ");
            scanf(" %c%d", &row, &col);
        }
        else {
            break;
        }
    }

    // update the board
    board[row][col-1] = player;
}

// check for a winner
int get_winner()
{
    int i;

    // check rows
    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return board[i][0];
    }

    // check columns
    for (i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return board[0][i];
    }

    // check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0];

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2];

    // no winner yet
    return 0;
}

// check if the board is full
int is_full()
{
    int i, j;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (board[i][j] == ' ') return 0;

    return 1;
}