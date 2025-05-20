//FormAI DATASET v1.0 Category: Memory Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void initializeBoard(int board[ROWS][COLS]);
void printBoard(int board[ROWS][COLS]);
void shuffleBoard(int board[ROWS][COLS]);
int getChoice(int board[ROWS][COLS]);
int checkWin(int board[ROWS][COLS]);

int main()
{
    int board[ROWS][COLS];
    int choice1, choice2;
    int counter = 0;

    srand(time(NULL));

    initializeBoard(board);
    shuffleBoard(board);
    printBoard(board);

    while (checkWin(board) != 1) {
        printf("Choice %d: ", counter + 1);
        choice1 = getChoice(board);
        printf("\n");
        printf("Choice %d: ", counter + 2);
        choice2 = getChoice(board);
        printf("\n");

        if (board[choice1 / ROWS][choice1 % COLS] != board[choice2 / ROWS][choice2 % COLS]) {
            printf("No match.\n");
        }

        counter += 2;
        printBoard(board);
    }

    printf("Congratulations! You won in %d moves!\n", counter);

    return 0;
}

void initializeBoard(int board[ROWS][COLS])
{
    int i, j, count = 1;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = count++;
        }
    }
}

void printBoard(int board[ROWS][COLS])
{
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%3d ", board[i][j]);
        }

        printf("\n");
    }

    printf("\n");
}

void shuffleBoard(int board[ROWS][COLS])
{
    int i, j, tmp, randRow, randCol;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            randRow = rand() % ROWS;
            randCol = rand() % COLS;

            tmp = board[i][j];
            board[i][j] = board[randRow][randCol];
            board[randRow][randCol] = tmp;
        }
    }
}

int getChoice(int board[ROWS][COLS])
{
    int choice, valid = 0;

    while (valid == 0) {
        scanf("%d", &choice);

        if (choice >= 1 && choice <= ROWS * COLS) {
            if (board[(choice - 1) / ROWS][(choice - 1) % COLS] != 0) {
                valid = 1;
            } else {
                printf("Invalid choice. That space is already revealed.\n");
                printf("Please choose again: ");
            }
        } else {
            printf("Invalid choice. Please enter a number between 1 and %d: ", ROWS * COLS);
        }
    }

    board[(choice - 1) / ROWS][(choice - 1) % COLS] = 0;
    return choice - 1;
}

int checkWin(int board[ROWS][COLS])
{
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] != 0) {
                return 0;
            }
        }
    }

    return 1;
}