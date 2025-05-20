//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

char grid[MAX_ROWS][MAX_COLS];
int rows, cols;

void generate_grid(int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            grid[i][j] = rand() % 2? 'X' : 'O';
        }
    }
}

void print_grid(int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int r, c;
    printf("Enter the number of rows: ");
    scanf("%d", &r);
    printf("Enter the number of columns: ");
    scanf("%d", &c);

    if (r > MAX_ROWS || c > MAX_COLS) {
        printf("Error: Grid dimensions are too large.\n");
        return 1;
    }

    rows = r;
    cols = c;
    generate_grid(r, c);
    print_grid(r, c);

    return 0;
}