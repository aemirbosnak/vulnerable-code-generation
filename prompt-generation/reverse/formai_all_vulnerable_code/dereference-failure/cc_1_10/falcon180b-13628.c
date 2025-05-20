//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define MAX_ROWS 50
#define MAX_COLS 100

int main() {
    int rows = 0, cols = 0;
    char *input = NULL;
    size_t len = 0;
    srand(time(NULL));

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%s", input);
    len = strlen(input);
    if (len == 0 || input[0]!= '0') {
        printf("Invalid input.\n");
        exit(1);
    }
    cols = atoi(input);

    if (rows > MAX_ROWS || cols > MAX_COLS) {
        printf("Input out of range.\n");
        exit(1);
    }

    int arr[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand() % 2;
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] == 1) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}