//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 50
#define MAX_COLS 50
#define PATTERN_NUM 10

void generate_pattern(int arr[MAX_ROWS][MAX_COLS], int row, int col, int num) {
    int i, j;
    for (i = 0; i < num; i++) {
        for (j = 0; j < num; j++) {
            if ((i + j) % 2 == 0) {
                arr[row + i][col + j] = 1;
            } else {
                arr[row + i][col + j] = 0;
            }
        }
    }
}

void print_pattern(int arr[MAX_ROWS][MAX_COLS], int row, int col, int num) {
    int i, j;
    for (i = 0; i < num; i++) {
        for (j = 0; j < num; j++) {
            if (arr[row + i][col + j] == 1) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int arr[MAX_ROWS][MAX_COLS] = {0};
    int row, col;
    printf("Enter the number of rows: ");
    scanf("%d", &row);
    printf("Enter the number of columns: ");
    scanf("%d", &col);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int num = rand() % PATTERN_NUM + 1;
            generate_pattern(arr, i, j, num);
        }
    }

    printf("\nPattern:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            print_pattern(arr, i, j, PATTERN_NUM);
        }
    }

    return 0;
}