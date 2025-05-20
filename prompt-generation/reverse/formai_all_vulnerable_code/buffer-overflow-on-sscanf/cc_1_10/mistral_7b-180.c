//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 5
#define COLS 5

int main() {
    FILE *file;
    int arr[ROWS][COLS];
    int sum_rows[ROWS] = {0};
    int sum_cols[COLS] = {0};
    int sum_diag1 = 0, sum_diag2 = 0;
    char line[100];
    int i = 0, j = 0, k = 0;

    file = fopen("filename.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        sscanf(line, "%d%d%d%d%d%d%d%d%d%d",
               &arr[i][0], &arr[i][1], &arr[i][2], &arr[i][3], &arr[i][4],
               &arr[i+1][0], &arr[i+1][1], &arr[i+1][2], &arr[i+1][3], &arr[i+1][4]);
        i++;
    }

    fclose(file);

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
        sum_rows[i] = 0;
        for (j = 0; j < COLS; j++) {
            sum_rows[i] += arr[i][j];
        }
        printf("Sum of row %d: %d\n", i+1, sum_rows[i]);
    }

    for (j = 0; j < COLS; j++) {
        sum_cols[j] = 0;
        for (i = 0; i < ROWS; i++) {
            sum_cols[j] += arr[i][j];
        }
        printf("Sum of column %d: %d\n", j+1, sum_cols[j]);
    }

    for (i = 0; i < ROWS; i++) {
        sum_diag1 += arr[i][i];
        sum_diag2 += arr[i][COLS-i];
    }

    printf("Sum of main diagonal: %d\n", sum_diag1);
    printf("Sum of secondary diagonal: %d\n", sum_diag2);

    return 0;
}