//FormAI DATASET v1.0 Category: Checkers Game ; Style: Claude Shannon
#include <stdio.h>

#define BOARD_SIZE 8

// Define the symbols for the different types of pieces
#define EMPTY  '.'
#define BLACK  'b'
#define WHITE  'w'
#define KING_B 'B'
#define KING_W 'W'

// Define the starting position of the pieces on the board
char board[BOARD_SIZE][BOARD_SIZE] = 
{
    {'.', 'b', '.', 'b', '.', 'b', '.', 'b'},
    {'b', '.', 'b', '.', 'b', '.', 'b', '.'},
    {'.', 'b', '.', 'b', '.', 'b', '.', 'b'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'w', '.', 'w', '.', 'w', '.', 'w', '.'},
    {'.', 'w', '.', 'w', '.', 'w', '.', 'w'},
    {'w', '.', 'w', '.', 'w', '.', 'w', '.'},
};

// Print the board to the console
void print_board(void)
{
    int i, j;

    printf("   ");

    for (i = 0; i < BOARD_SIZE; i++)
        printf("%d ", i);

    printf("\n");

    for (i = 0; i < BOARD_SIZE; i++)
    {
        printf("%d  ", i);

        for (j = 0; j < BOARD_SIZE; j++)
            printf("%c ", board[i][j]);

        printf("%d\n", i);
    }

    printf("   ");

    for (i = 0; i < BOARD_SIZE; i++)
        printf("%d ", i);

    printf("\n");
}

// Check if a given move is legal for the given piece
int is_move_legal(char piece, int from_row, int from_col, int to_row, int to_col)
{
    int row_diff = to_row - from_row;
    int col_diff = to_col - from_col;

    if (piece == BLACK && row_diff == 1 && (col_diff == -1 || col_diff == 1))
        return 1;

    if (piece == WHITE && row_diff == -1 && (col_diff == -1 || col_diff == 1))
        return 1;

    if (piece == KING_B && abs(row_diff) == 1 && abs(col_diff) == 1)
        return 1;

    if (piece == KING_W && abs(row_diff) == 1 && abs(col_diff) == 1)
        return 1;

    return 0;
}

// Move a given piece from one position to another on the board
void move_piece(int from_row, int from_col, int to_row, int to_col)
{
    char piece = board[from_row][from_col];

    board[from_row][from_col] = EMPTY;
    board[to_row][to_col] = piece;
}

int main(void)
{
    int from_row, from_col, to_row, to_col;

    printf("Welcome to Checkers!\n");

    while (1)
    {
        print_board();

        printf("Enter the row and column of the piece you want to move: ");
        scanf("%d %d", &from_row, &from_col);

        printf("Enter the row and column of the square you want to move to: ");
        scanf("%d %d", &to_row, &to_col);

        // Check if the move is legal, otherwise ask for input again
        if (is_move_legal(board[from_row][from_col], from_row, from_col, to_row, to_col))
            move_piece(from_row, from_col, to_row, to_col);
        else
            printf("Illegal move!\n");
    }

    return 0;
}