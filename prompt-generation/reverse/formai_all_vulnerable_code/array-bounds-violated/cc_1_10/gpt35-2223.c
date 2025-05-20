//FormAI DATASET v1.0 Category: Memory Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void shuffle(int *array, size_t n) {
    if (n > 1) {
        size_t i;
        for (i = 0; i < n - 1; i++) {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}

void printBoard(int board[][COLS], int key[][COLS], int rows, int cols) {
    int i, j;
    printf("\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (key[i][j] == 0) {
                printf("%3d", board[i][j]);
            } else {
                printf("%3c", 'X');
            }
        }
        printf("\n");
    }
    printf("\n");
}

int checkMatch(int *a, int *b, size_t n) {
    size_t i;
    for (i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int board[ROWS][COLS];
    int key[ROWS][COLS];
    int nums[ROWS*COLS/2];
    int picked[ROWS*COLS];
    int i, j, k, l;
    int numPairs = ROWS*COLS/2;
    int currPair = 0;

    srand(time(NULL));

    for (i = 0; i < numPairs; i++) {
      nums[2*i] = i + 1;
      nums[2*i+1] = i + 1;
    }

    shuffle(nums, ROWS*COLS);

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = nums[i*COLS+j];
            key[i][j] = 0;
        }
    }

    printBoard(board, key, ROWS, COLS);

    while (currPair < numPairs) {
        printf("Enter the coordinates of the first card (row,col): ");
        scanf("%d,%d", &i, &j);
        i--;
        j--;
        printf("\n");
        key[i][j] = 1;
        printBoard(board, key, ROWS, COLS);

        printf("Enter the coordinates of the second card (row,col): ");
        scanf("%d,%d", &k, &l);
        k--;
        l--;
        printf("\n");
        key[k][l] = 1;
        printBoard(board, key, ROWS, COLS);

        picked[currPair*2] = board[i][j];
        picked[currPair*2+1] = board[k][l];

        if (checkMatch(picked+currPair*2, nums+currPair*2, 2)) {
            printf("MATCH!\n");
            currPair++;
        } else {
            key[i][j] = 0;
            key[k][l] = 0;
            printf("NO MATCH.\n");
        }
        printBoard(board, key, ROWS, COLS);
    }
    printf("Congratulations! You have matched all of the pairs!\n");
}