//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define MAX_PAIRS 20
#define BOARD_SIZE (MAX_ROWS * MAX_COLS)

void initBoard(char board[][MAX_COLS], int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            board[i][j] = '-';
        }
    }
}

void printBoard(char board[][MAX_COLS], int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void generatePairs(int pairs[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        pairs[i] = rand() % size;
    }
}

int main() {
    int rows, cols, pairs, matches = 0, attempts = 0;
    char board[MAX_ROWS][MAX_COLS];
    int *pairsArray;
    int choice;
    int player = 1;

    printf("Welcome to Memory Game!\n");

    do {
        printf("Enter board size (max %d): ", MAX_ROWS * MAX_COLS);
        scanf("%d", &rows);
        printf("Enter number of pairs (max %d): ", MAX_PAIRS);
        scanf("%d", &pairs);

        if (rows * cols < pairs * 2) {
            printf("Board size is too small for the number of pairs.\n");
        }
    } while (rows * cols < pairs * 2);

    pairsArray = malloc(pairs * sizeof(int));

    srand(time(NULL));
    generatePairs(pairsArray, pairs);

    initBoard(board, rows, cols);

    while (matches < pairs) {
        printf("Player %d's turn.\n", player);
        printBoard(board, rows, cols);

        do {
            printf("Enter row: ");
            scanf("%d", &choice);
            printf("Enter column: ");
            scanf("%d", &choice);
        } while (choice < 1 || choice > rows * cols);

        if (board[choice / cols][choice % cols] == '-') {
            attempts++;
        } else if (board[choice / cols][choice % cols] == pairsArray[matches]) {
            matches++;
            printf("Correct match!\n");
        } else {
            printf("Incorrect match.\n");
        }

        if (attempts == 2) {
            attempts = 0;
            player++;
            if (player > 2) {
                player = 1;
            }
        }

        if (matches == pairs) {
            printf("Congratulations! You win!\n");
            break;
        }
    }

    free(pairsArray);

    return 0;
}