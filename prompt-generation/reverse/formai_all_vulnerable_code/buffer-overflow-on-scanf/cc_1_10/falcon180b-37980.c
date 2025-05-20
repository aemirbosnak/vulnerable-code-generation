//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define MATCH_PAIR 8

void shuffle(int arr[][COLS], int n) {
    int i, j, temp;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i!= j) {
                temp = arr[i][j];
                arr[i][j] = arr[j][i];
                arr[j][i] = temp;
            }
        }
    }
}

int check_win(int arr[][COLS], int n) {
    int i, j, count = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (arr[i][j] == MATCH_PAIR) {
                count++;
            }
        }
    }
    if (count == MATCH_PAIR * n) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int arr[ROWS][COLS];
    int i, j, n, match_count = 0;
    srand(time(NULL));
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            arr[i][j] = rand() % 10;
        }
    }
    printf("Shuffled array:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    while (1) {
        printf("Enter row and column numbers: ");
        scanf("%d%d", &i, &j);
        if (arr[i][j] == MATCH_PAIR) {
            match_count++;
            printf("Match found!\n");
        } else {
            printf("No match found.\n");
        }
        printf("Number of matches so far: %d\n", match_count);
        if (match_count == MATCH_PAIR * ROWS * COLS) {
            printf("\nCongratulations! You won!\n");
            break;
        } else if (match_count == 0) {
            printf("\nSorry, you lose.\n");
            break;
        }
        if (check_win(arr, ROWS)) {
            printf("\nYou won!\n");
            break;
        }
    }
    return 0;
}