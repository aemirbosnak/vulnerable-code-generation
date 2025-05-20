//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_ROWS 100
#define MAX_COLS 100

char **pattern;
int rows, cols;

void generate_pattern(int n) {
    int i, j, k, count = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j) {
                pattern[i][j] = 'X';
            } else if ((i + j) % 2 == 0) {
                pattern[i][j] = 'O';
            } else {
                pattern[i][j] = '.';
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of rows and columns (max 100): ");
    scanf("%d", &n);
    if (n > MAX_ROWS || n > MAX_COLS) {
        printf("Error: Input is too large.\n");
        exit(1);
    }
    rows = cols = n;
    pattern = (char **)malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        pattern[i] = (char *)malloc(cols * sizeof(char));
    }
    generate_pattern(n);
    printf("\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c", pattern[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < rows; i++) {
        free(pattern[i]);
    }
    free(pattern);
    return 0;
}