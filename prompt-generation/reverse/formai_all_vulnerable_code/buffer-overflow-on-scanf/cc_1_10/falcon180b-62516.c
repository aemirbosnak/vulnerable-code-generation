//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define TOTAL_CARDS (ROWS * COLS)
#define MATCH_VALUE 100

// Function prototypes
void initBoard(char board[ROWS][COLS]);
void printBoard(const char board[ROWS][COLS]);
void shuffleBoard(char board[ROWS][COLS]);
int checkMatch(const char board[ROWS][COLS]);

int main() {
    srand(time(NULL));
    char board[ROWS][COLS];
    initBoard(board);
    int matchesFound = 0;

    while (matchesFound < TOTAL_CARDS) {
        int row1, col1, row2, col2;
        printf("Enter the coordinates of the first card: ");
        scanf("%d %d", &row1, &col1);
        printf("Enter the coordinates of the second card: ");
        scanf("%d %d", &row2, &col2);

        if (checkMatch(board)) {
            matchesFound++;
        } else {
            printf("Not a match!\n");
            board[row1][col1] = '*';
            board[row2][col2] = '*';
        }

        printBoard(board);
    }

    printf("Congratulations! You found all the matches in %d turns.\n", matchesFound + 2);
    return 0;
}

void initBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '*';
        }
    }
}

void printBoard(const char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void shuffleBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int randRow = rand() % ROWS;
            int randCol = rand() % COLS;
            char temp = board[i][j];
            board[i][j] = board[randRow][randCol];
            board[randRow][randCol] = temp;
        }
    }
}

int checkMatch(const char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j]!= '*') {
                return 0;
            }
        }
    }
    return 1;
}