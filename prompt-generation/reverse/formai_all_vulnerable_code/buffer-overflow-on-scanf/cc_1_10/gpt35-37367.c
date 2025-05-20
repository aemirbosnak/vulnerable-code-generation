//FormAI DATASET v1.0 Category: Chess engine ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main()
{
    printf("Welcome to Happy Chess Engine!\n");

    // Initialize the chess board
    char board[8][8] = {
        {'R','N','B','Q','K','B','N','R'},
        {'P','P','P','P','P','P','P','P'},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {'p','p','p','p','p','p','p','p'},
        {'r','n','b','q','k','b','n','r'}
    };

    // Print the chess board
    printf("     a  b  c  d  e  f  g  h\n");
    for(int i=0; i<8; i++)
    {
        printf("%d  ", 8-i);
        for(int j=0; j<8; j++)
        {
            printf("|%c ", board[i][j]);
        }
        printf("|\n");
        printf("   -----------------------\n");
    }

    // Ask the user for their move
    char move[6];
    printf("Enter your move (e.g. e2-e4): ");
    scanf("%s", move);

    // Parse the user input
    int start_row = 8 - (move[1] - '0');
    int start_col = move[0] - 'a';
    int end_row = 8 - (move[4] - '0');
    int end_col = move[3] - 'a';

    // Move the piece on the board
    char piece = board[start_row][start_col];
    board[end_row][end_col] = piece;
    board[start_row][start_col] = ' ';

    // Print the updated chess board
    printf("     a  b  c  d  e  f  g  h\n");
    for(int i=0; i<8; i++)
    {
        printf("%d  ", 8-i);
        for(int j=0; j<8; j++)
        {
            printf("|%c ", board[i][j]);
        }
        printf("|\n");
        printf("   -----------------------\n");
    }

    printf("Great move! Keep playing Happy Chess Engine!\n");

    return 0;
}