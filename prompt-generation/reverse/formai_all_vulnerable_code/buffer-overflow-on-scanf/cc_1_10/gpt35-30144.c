//FormAI DATASET v1.0 Category: Chess engine ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// custom function to print chess board
void printBoard(char board[8][8])
{
    printf("  +------------------------+\n");
    for(int i = 0; i < 8; i++)
    {
        printf("%d | ", 8-i);
        for(int j = 0; j < 8; j++)
            printf("%c ", board[i][j]);
        printf("|\n");
    }
    printf("  +------------------------+\n");
    printf("    a b c d e f g h\n");
}

// custom function to initialize the chess board
void initBoard(char board[8][8])
{
    char pieces[] = {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'};
    for(int i = 0; i < 8; i++)
    {
        board[0][i] = pieces[i];    // black pieces
        board[7][i] = pieces[i]-32; // white pieces
        board[1][i] = 'p';          // black pawns
        board[6][i] = 'P';          // white pawns
        for(int j = 2; j <= 5; j++)
            board[j][i] = ' ';      // empty squares
    }
}

// custom function to get user input and move the pieces
void move(char board[8][8])
{
    char from[3], to[3];
    printf("Enter the square to move from: ");
    scanf("%s", from);
    printf("Enter the square to move to: ");
    scanf("%s", to);
    int fromRow = 8 - (from[1] - '0');
    int fromCol = from[0] - 'a';
    int toRow = 8 - (to[1] - '0');
    int toCol = to[0] - 'a';
    if(board[fromRow][fromCol] == ' ')
        printf("Invalid move: Empty square selected.\n");
    else if(board[toRow][toCol] != ' ')
        printf("Invalid move: Destination square is not empty.\n");
    else
    {
        board[toRow][toCol] = board[fromRow][fromCol];
        board[fromRow][fromCol] = ' ';
    }
}

int main()
{
    char board[8][8];

    initBoard(board);
    printBoard(board);
    move(board);
    printBoard(board);

    return 0;
}