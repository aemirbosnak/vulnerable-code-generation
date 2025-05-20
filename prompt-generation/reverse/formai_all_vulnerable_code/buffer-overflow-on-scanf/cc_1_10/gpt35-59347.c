//FormAI DATASET v1.0 Category: Memory Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 6

void printBoard(char board[][SIZE]);
void shuffleBoard(char board[][SIZE]);
void swap(char *a, char *b);
int getRow(char move[]);
int getColumn(char move[]);
int isValidMove(char board[][SIZE], char move[]);
void updateBoard(char board[][SIZE], char move[], int row, int col);
int isGameOver(char board[][SIZE]);

int main()
{
    char board[SIZE][SIZE] = {
        {'A', 'A', 'B', 'B', 'C', 'C'},
        {'D', 'D', 'E', 'E', 'F', 'F'},
        {'G', 'G', 'H', 'H', 'I', 'I'},
        {'J', 'J', 'K', 'K', 'L', 'L'},
        {'M', 'M', 'N', 'N', 'O', 'O'},
        {'P', 'P', 'Q', 'Q', 'R', 'R'}
    };
    char move[5], buffer;
    int row, col, count = 0;

    srand(time(NULL));
    shuffleBoard(board);

    printf("Welcome to the Memory Game!\n");
    printf("To make a move, enter a row and column (e.g. A1).\n");
    printf("Type 'exit' to quit the game.\n\n");
    printBoard(board);

    while (!isGameOver(board)) {
        printf("\nEnter your move: ");
        scanf("%s", move);

        if (isValidMove(board, move)) {
            row = getRow(move);
            col = getColumn(move);
            updateBoard(board, move, row, col);
            count++;
            printBoard(board);
        } else if (strncmp(move, "exit", 4) == 0) {
            break;
        } else {
            printf("Invalid move! Please try again.\n");
        }
    }

    printf("\nGame over! You made %d moves.\n", count);

    return 0;
}

void printBoard(char board[][SIZE])
{
    int i, j;

    printf("\n  1 2 3 4 5 6\n");

    for (i = 0; i < SIZE; i++) {
        printf("%c ", 'A' + i);

        for (j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void shuffleBoard(char board[][SIZE])
{
    int i, j;

    for (i = SIZE - 1; i >= 0; i--) {
        for (j = SIZE - 1; j >= 0; j--) {
            int r = rand() % (i + 1);
            int c = rand() % (j + 1);
            swap(&board[i][j], &board[r][c]);
        }
    }
}

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

int getRow(char move[])
{
    return move[0] - 'A';
}

int getColumn(char move[])
{
    return move[1] - '1';
}

int isValidMove(char board[][SIZE], char move[])
{
    int row = getRow(move);
    int col = getColumn(move);

    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
        return 0;
    }

    return board[row][col] != '-';
}

void updateBoard(char board[][SIZE], char move[], int row, int col)
{
    char buffer[2];

    sprintf(buffer, "%c%c", row + 'A', col + '1');
    board[row][col] = '-';
    board[row][col] = '-';
}

int isGameOver(char board[][SIZE])
{
    int i, j;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] != '-') {
                return 0;
            }
        }
    }

    return 1;
}