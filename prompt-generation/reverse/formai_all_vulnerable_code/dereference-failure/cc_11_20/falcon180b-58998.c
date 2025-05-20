//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

int main() {
    int i, j;
    int **grid;
    int count = 0;
    int x, y;
    int choice;
    int neighbours = 0;

    srand(time(NULL));

    grid = (int **) malloc(SIZE * sizeof(int *));
    for (i = 0; i < SIZE; i++) {
        grid[i] = (int *) malloc(SIZE * sizeof(int));
        for (j = 0; j < SIZE; j++) {
            grid[i][j] = 0;
        }
    }

    while (1) {
        system("clear");
        printf("Press 1 to percolate.\n");
        printf("Press 2 to view the grid.\n");
        printf("Press 3 to quit.\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            x = rand() % SIZE;
            y = rand() % SIZE;

            if (grid[x][y] == 0) {
                grid[x][y] = 1;
                count++;
            }

            if (count == 0) {
                printf("The percolation has ended.\n");
            }

            break;

        case 2:
            for (i = 0; i < SIZE; i++) {
                for (j = 0; j < SIZE; j++) {
                    if (grid[i][j] == 1) {
                        printf("\033[1;31mX\033[0m ");
                    } else if (grid[i][j] == 2) {
                        printf("\033[1;34mX\033[0m ");
                    } else {
                        printf("X ");
                    }
                }
                printf("\n");
            }
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}