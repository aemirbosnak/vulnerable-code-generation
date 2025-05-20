//FormAI DATASET v1.0 Category: Memory Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

void initBoard(int board[][BOARD_SIZE], int size);
void shuffle(int array[], int size);
void printBoard(int board[][BOARD_SIZE], int size);
int checkMatch(int board[][BOARD_SIZE], int size, int row1, int col1, int row2, int col2);

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE];
    int row1, col1, row2, col2;
    int matchedPairs = 0;
    srand(time(0)); // seed random number generator

    initBoard(board, BOARD_SIZE);
    printBoard(board, BOARD_SIZE);

    while (matchedPairs < BOARD_SIZE * BOARD_SIZE / 2) {
        printf("Enter first card row and column: ");
        scanf("%d %d", &row1, &col1);
        printf("Enter second card row and column: ");
        scanf("%d %d", &row2, &col2);

        if (checkMatch(board, BOARD_SIZE, row1, col1, row2, col2)) {
            printf("Matched!\n");
            matchedPairs++;
        } else {
            printf("Not a match.\n");
        }

        printBoard(board, BOARD_SIZE);
    }

    printf("Congratulations, you have matched all pairs!\n");
    return 0;
}

void initBoard(int board[][BOARD_SIZE], int size)
{
    int values[size*size/2];
    int index = 0;

    // create an array of unique random values
    for (int i = 0; i < size*size/2; i++) {
        values[i] = i+1;
    }
    shuffle(values, size*size/2);

    // fill board with pairs of random values
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            board[row][col] = values[index/2];
            index++;
        }
    }
}

void shuffle(int array[], int size)
{
    // Fisher-Yates shuffle algorithm
    for (int i = size-1; i > 0; i--) {
        int j = rand() % (i+1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

void printBoard(int board[][BOARD_SIZE], int size)
{
    printf("-----------------\n");
    for (int row = 0; row < size; row++) {
        printf("|");
        for (int col = 0; col < size; col++) {
            if (board[row][col] == 0) {
                printf("   ");
            } else {
                printf(" %d ", board[row][col]);
            }
            printf("|");
        }
        printf("\n-----------------\n");
    }
}

int checkMatch(int board[][BOARD_SIZE], int size, int row1, int col1, int row2, int col2)
{
    if (board[row1][col1] == board[row2][col2]) {
        board[row1][col1] = 0;
        board[row2][col2] = 0;
        return 1;
    } else {
        return 0;
    }
}