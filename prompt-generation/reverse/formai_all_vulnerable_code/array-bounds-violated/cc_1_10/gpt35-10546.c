//FormAI DATASET v1.0 Category: Memory Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void initialiseBoard(int board[][COLS]);
void displayGameBoard(int board[][COLS], int revealed[][COLS]);
int revealTile(int board[][COLS], int revealed[][COLS], int row, int col);
void hideCards(int board[][COLS], int revealed[][COLS], int row1, int col1, int row2, int col2);
int checkWin(int revealed[][COLS]);

int main()
{
    int board[ROWS][COLS];
    int revealed[ROWS][COLS] = {0};
    int row1, col1, row2, col2;
    int moveCount = 0;
    
    initialiseBoard(board);
    displayGameBoard(board, revealed);
    
    while (1) {
        printf("Enter row and column of first card: ");
        scanf("%d %d", &row1, &col1);
        while (revealTile(board, revealed, row1-1, col1-1) == 0) {
            printf("Tile already revealed. Enter row and column of first card: ");
            scanf("%d %d", &row1, &col1);
        }
        
        system("clear"); // clear screen
        
        displayGameBoard(board, revealed);
        
        printf("Enter row and column of second card: ");
        scanf("%d %d", &row2, &col2);
        while (revealTile(board, revealed, row2-1, col2-1) == 0) {
            printf("Tile already revealed. Enter row and column of second card: ");
            scanf("%d %d", &row2, &col2);
        }
        
        system("clear"); // clear screen
        
        displayGameBoard(board, revealed);
        
        if (board[row1-1][col1-1] != board[row2-1][col2-1]) {
            hideCards(board, revealed, row1-1, col1-1, row2-1, col2-1);
        }
        else {
            printf("Match!\n");
            if (checkWin(revealed)) {
                printf("Congratulations! You won in %d moves!\n", moveCount);
                return 0;
            }
        }
        moveCount++;
    }
    
    return 0;
}

void initialiseBoard(int board[][COLS])
{
    int cards[ROWS*COLS/2];
    int index = 0;
    
    /* Generate cards */
    for (int i = 1; i <= ROWS*COLS/2; i++) {
        cards[index++] = i;
        cards[index++] = i;
    }
    
    /* Randomly place cards on board */
    srand(time(NULL));
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            index = rand() % (ROWS*COLS - 2*c - 2*r);
            board[r][c] = cards[index];
            cards[index] = cards[ROWS*COLS - 2*c - 2*r - 1];
        }
    }
}

void displayGameBoard(int board[][COLS], int revealed[][COLS])
{
    printf("   ");
    for (int c = 0; c < COLS; c++) {
        printf("%d ", c+1);
    }
    printf("\n");
    
    for (int r = 0; r < ROWS; r++) {
        printf("%d  ", r+1);
        for (int c = 0; c < COLS; c++) {
            if (revealed[r][c]) {
                printf("%d ", board[r][c]);
            }
            else {
                printf("* ");
            }
        }
        printf("\n");
    }
}

int revealTile(int board[][COLS], int revealed[][COLS], int row, int col)
{
    if (revealed[row][col]) {
        return 0;
    }
    revealed[row][col] = 1;
    return 1;
}

void hideCards(int board[][COLS], int revealed[][COLS], int row1, int col1, int row2, int col2)
{
    revealed[row1][col1] = 0;
    revealed[row2][col2] = 0;
    printf("No match. Try again.\n");
}

int checkWin(int revealed[][COLS])
{
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            if (!revealed[r][c]) {
                return 0;
            }
        }
    }
    return 1;
}