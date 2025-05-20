//FormAI DATASET v1.0 Category: Chess engine ; Style: happy
#include <stdlib.h>
#include <stdio.h>

//Declare 'chessBoard' as a 2D array of characters
char chessBoard[8][8] = 
{{'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
 {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
 {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
 {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
 {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
 {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
 {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
 {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}};

int main() {

    int row, col;
    char move[5];
    printf("Welcome to Happy Chess!\n\n");

    //Display the empty chess board
    printf("     a b c d e f g h\n");
    printf("   +-----------------+\n");
    for (row = 0; row < 8; row++) {
        printf(" %d |", (8-row));
        for (col = 0; col < 8; col++) {
            printf("%c|", chessBoard[row][col]);
        }
        printf(" %d", (8-row));
        printf("\n");
    }
    printf("   +-----------------+\n");
    printf("     a b c d e f g h\n");

    //Ask for and get a move
    printf("\nYour move (ex: 'e2e4'): ");
    scanf("%s", move);

    //Make the move on the board
    int startRow = 8 - (move[1] - '0');
    int startCol = move[0] - 'a';
    int endRow = 8 - (move[3] - '0');
    int endCol = move[2] - 'a';
    char piece = chessBoard[startRow][startCol];
    chessBoard[startRow][startCol] = ' ';
    chessBoard[endRow][endCol] = piece;

    //Display the updated chess board
    printf("\n     a b c d e f g h\n");
    printf("   +-----------------+\n");
    for (row = 0; row < 8; row++) {
        printf(" %d |", (8-row));
        for (col = 0; col < 8; col++) {
            printf("%c|", chessBoard[row][col]);
        }
        printf(" %d", (8-row));
        printf("\n");
    }
    printf("   +-----------------+\n");
    printf("     a b c d e f g h\n");

    printf("\nGreat move! Keep up the good work!\n");
    return 0;
}