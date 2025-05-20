//FormAI DATASET v1.0 Category: Memory Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

void initializeBoard(int board[MAX_SIZE][MAX_SIZE], int size);
void shuffle(int arr[MAX_SIZE], int size);
void printBoard(int board[MAX_SIZE][MAX_SIZE], int size);
int getPair(int board[MAX_SIZE][MAX_SIZE], int size, int r, int c);
int getRow();
int getColumn();

int main()
{
    int size, row, col, firstRow, firstCol, secondRow, secondCol, pairs = 0;
    int board[MAX_SIZE][MAX_SIZE];
    
    printf("Enter board size (even number between 4 and 100): ");
    scanf("%d", &size);
    
    // Validate input
    while (size < 4 || size > MAX_SIZE || size % 2 != 0) {
        printf("Invalid size! Please enter an even number between 4 and 100: ");
        scanf("%d", &size);
    }
    
    initializeBoard(board, size);
    shuffle(board[0], size * size);
    
    printf("Let's play the Memory game!\n\n");
    printBoard(board, size);
    
    while (pairs < (size * size) / 2) {
        printf("Enter first card location (row, column): ");
        firstRow = getRow();
        firstCol = getColumn();
        
        while (board[firstRow][firstCol] == -1) {
            printf("This card is already matched! Enter a different location.\n");
            printf("Enter first card location (row, column): ");
            firstRow = getRow();
            firstCol = getColumn();
        }
        
        board[firstRow][firstCol] = -1;
        printBoard(board, size);
        
        printf("Enter second card location (row, column): ");
        secondRow = getRow();
        secondCol = getColumn();
        
        while (board[secondRow][secondCol] == -1 || (firstRow == secondRow && firstCol == secondCol)) {
            if (board[secondRow][secondCol] == -1) {
                printf("This card is already matched! Enter a different location.\n");
            } else {
                printf("Can't choose the same location! Enter a different location.\n");
            }
            
            printf("Enter second card location (row, column): ");
            secondRow = getRow();
            secondCol = getColumn();
        }
        
        if (getPair(board, size, firstRow, firstCol) == getPair(board, size, secondRow, secondCol)) {
            printf("Congratulations! You found a pair.\n");
            board[secondRow][secondCol] = -1;
            pairs++;
        } else {
            printf("Sorry! Cards do not match.\n");
            board[firstRow][firstCol] = getPair(board, size, firstRow, firstCol);
        }
        
        printBoard(board, size);
    }
    
    printf("Great job! You won the game in %d moves.", pairs * 2);
    
    return 0;
}

void initializeBoard(int board[MAX_SIZE][MAX_SIZE], int size)
{
    int i, j, k = 0;
    
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            board[i][j] = k / 2;
            k++;
        }
    }
}

void shuffle(int arr[MAX_SIZE], int size)
{
    int i, j, temp;
    srand(time(NULL));
    
    for (i = size - 1; i > 0; i--) {
        j = rand() % (i + 1);
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void printBoard(int board[MAX_SIZE][MAX_SIZE], int size)
{
    int i, j;
    
    printf("\n    ");
    for (i = 0; i < size; i++) {
        printf("%-3d", i);
    }
    printf("\n   ");
    for (i = 0; i < size; i++) {
        printf("---");
    }
    printf("\n");
    
    for (i = 0; i < size; i++) {
        printf("%-2d |", i);
        for (j = 0; j < size; j++) {
            if (board[i][j] == -1) {
                printf(" X ");
            } else {
                printf(" - ");
            }
        }
        printf("| %d\n", i);
    }
    
    printf("   ");
    for (i = 0; i < size; i++) {
        printf("---");
    }
    printf("\n    ");
    for (i = 0; i < size; i++) {
        printf("%-3d", i);
    }
    printf("\n");
}

int getPair(int board[MAX_SIZE][MAX_SIZE], int size, int r, int c)
{
    int i, j;
    
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (i != r || j != c) {
                if (board[i][j] == board[r][c]) {
                    return board[i][j];
                }
            }
        }
    }
    
    return -1;
}

int getRow()
{
    int row;
    
    printf("Enter row (0-99): ");
    scanf("%d", &row);
    
    // Validate input
    while (row < 0 || row > 99) {
        printf("Invalid row! Please enter a number between 0 and 99: ");
        scanf("%d", &row);
    }
    
    return row;
}

int getColumn()
{
    int col;
    
    printf("Enter column (0-99): ");
    scanf("%d", &col);
    
    // Validate input
    while (col < 0 || col > 99) {
        printf("Invalid column! Please enter a number between 0 and 99: ");
        scanf("%d", &col);
    }
    
    return col;
}