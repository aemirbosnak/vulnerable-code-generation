//FormAI DATASET v1.0 Category: Table Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Board size constants
#define ROWS 4
#define COLS 4

// Player IDs as integers
#define PLAYER_ONE 1
#define PLAYER_TWO 2

// Board state constants
#define EMPTY_CELL ' '
#define PLAYER_ONE_CELL 'O'
#define PLAYER_TWO_CELL 'X'

// Function prototypes
void print_board(char board[][COLS]);
int get_next_move(char board[][COLS], int player_id);
int check_win_condition(char board[][COLS], int player_id);

int main()
{
    // Declare and initialize the board
    char board[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = EMPTY_CELL;
        }
    }

    // Seed the random number generator for coin toss
    srand(time(NULL));

    int current_player = rand() % 2 + 1; // randomly select which player goes first

    // Game loop
    int game_over = 0;
    while (!game_over) {
        print_board(board);

        int next_move = get_next_move(board, current_player);
        int row = next_move / COLS;
        int col = next_move % COLS;

        if (current_player == PLAYER_ONE) {
            board[row][col] = PLAYER_ONE_CELL;
        } else if (current_player == PLAYER_TWO) {
            board[row][col] = PLAYER_TWO_CELL;
        }

        int win = check_win_condition(board, current_player);
        if (win) {
            game_over = 1;
            printf("Player %d wins!\n", current_player);
            print_board(board);
            break;
        } else {
            // Switch to the other player
            current_player = (current_player == PLAYER_ONE) ? PLAYER_TWO : PLAYER_ONE;
        }
    }

    return 0;
}

void print_board(char board[][COLS])
{
    printf("\n   1   2   3   4\n");
    printf("  ---------------\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < COLS; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
        printf("  ---------------\n");
    }
}

int get_next_move(char board[][COLS], int player_id)
{
    int row, col, move;

    do {
        printf("Player %d, choose a row (1-4): ", player_id);
        scanf("%d", &row);
        printf("Player %d, choose a column (1-4): ", player_id);
        scanf("%d", &col);

        // Convert row and column choices to array indices (subtract 1)
        row--;
        col--;

        // Calculate the corresponding index in the 1D array representation of the board
        move = row * COLS + col;
    } while (board[row][col] != EMPTY_CELL);

    return move;
}

int check_win_condition(char board[][COLS], int player_id)
{
    // Check rows for a win
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] &&
            board[i][2] == board[i][3]) {
            if (board[i][0] == (player_id == PLAYER_ONE ? PLAYER_ONE_CELL : PLAYER_TWO_CELL)) {
                return 1;
            }
        }
    }

    // Check columns for a win
    for (int i = 0; i < COLS; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] &&
            board[2][i] == board[3][i]) {
            if (board[0][i] == (player_id == PLAYER_ONE ? PLAYER_ONE_CELL : PLAYER_TWO_CELL)) {
                return 1;
            }
        }
    }

    // Check diagonal from top-left to bottom-right for a win
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] &&
        board[2][2] == board[3][3]) {
        if (board[0][0] == (player_id == PLAYER_ONE ? PLAYER_ONE_CELL : PLAYER_TWO_CELL)) {
            return 1;
        }
    }

    // Check diagonal from top-right to bottom-left for a win
    if (board[0][3] == board[1][2] && board[1][2] == board[2][1] &&
        board[2][1] == board[3][0]) {
        if (board[0][3] == (player_id == PLAYER_ONE ? PLAYER_ONE_CELL : PLAYER_TWO_CELL)) {
            return 1;
        }
    }

    // No win condition
    return 0;
}