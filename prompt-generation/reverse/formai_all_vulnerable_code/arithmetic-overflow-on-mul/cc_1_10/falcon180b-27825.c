//Falcon-180B DATASET v1.0 Category: Table Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define MAX_NUMBERS 100

int main() {
    int rows, cols, i, j, num_cells, num, count = 0;
    int grid[MAX_ROWS][MAX_COLS] = {0};
    char choice;
    srand(time(0));

    printf("Welcome to the Number Grid Game!\n");
    printf("How many rows and columns do you want? (Max %d)\n", MAX_ROWS*MAX_COLS);
    scanf("%d %d", &rows, &cols);

    num_cells = rows * cols;
    printf("Enter %d numbers:\n", num_cells);

    for (i = 0; i < num_cells; i++) {
        scanf("%d", &num);
        grid[i/cols][i%cols] = num;
    }

    printf("\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%4d ", grid[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    do {
        printf("Enter your solution (row col): ");
        scanf("%d %d", &i, &j);
        if (grid[i][j] == 0) {
            printf("Invalid cell!\n");
        } else if (grid[i][j] == grid[0][0]) {
            printf("Correct! You win!\n");
        } else {
            printf("Incorrect! Try again.\n");
        }
        count++;
    } while (count < 3 && grid[i][j]!= grid[0][0]);

    return 0;
}