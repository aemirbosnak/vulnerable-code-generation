//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 20
#define MAX_COLS 20
#define NUM_DROPS 1000
#define DROP_RATE 0.5
#define SITE_CAPACITY 0.75

int main() {
    int rows, cols, i, j, k, num_drops = 0;
    int **grid;
    double drop_rate, site_capacity;
    char choice;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    grid = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        grid[i] = (int *)malloc(cols * sizeof(int));
    }

    printf("Enter the drop rate (between 0 and 1): ");
    scanf("%lf", &drop_rate);

    printf("Enter the site capacity (between 0 and 1): ");
    scanf("%lf", &site_capacity);

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            grid[i][j] = 0;
        }
    }

    srand(time(NULL));

    while (num_drops < NUM_DROPS) {
        i = rand() % rows;
        j = rand() % cols;

        if (grid[i][j] == 0 && rand() % 100 < drop_rate * 100) {
            grid[i][j] = 1;
            num_drops++;
        }
    }

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (grid[i][j] == 1) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }

    printf("\n");
    printf("Do you want to simulate again? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        main();
    } else {
        exit(0);
    }

    return 0;
}