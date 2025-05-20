//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: calm
#include <stdlib.h>
#include <stdio.h>

#define MAX 100

int main() {
    int **arr = (int **)malloc(MAX * MAX * sizeof(int));
    for (int i = 0; i < MAX; i++) {
        arr[i] = (int *)malloc(MAX * sizeof(int));
    }

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            arr[i][j] = 0;
        }
    }

    int x = MAX / 2;
    int y = MAX / 2;

    arr[x][y] = 1;

    int percolate = 0;
    while (percolate < MAX) {
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                if (arr[i][j] == 1) {
                    if (i - 1 >= 0 && arr[i - 1][j] == 0) {
                        arr[i - 1][j] = 1;
                    }
                    if (i + 1 < MAX && arr[i + 1][j] == 0) {
                        arr[i + 1][j] = 1;
                    }
                    if (j - 1 >= 0 && arr[i][j - 1] == 0) {
                        arr[i][j - 1] = 1;
                    }
                    if (j + 1 < MAX && arr[i][j + 1] == 0) {
                        arr[i][j + 1] = 1;
                    }
                }
            }
        }

        percolate++;
    }

    for (int i = 0; i < MAX; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}