//Falcon2-11B DATASET v1.0 Category: Game of Life ; Style: protected
#include <stdio.h>

int main() {
    int width, height, iterations;
    int cells[10][10];

    printf("Enter the width of the grid: ");
    scanf("%d", &width);

    printf("Enter the height of the grid: ");
    scanf("%d", &height);

    printf("Enter the number of iterations: ");
    scanf("%d", &iterations);

    int cells_num = width * height;

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            cells[i][j] = 0;
        }
    }

    for (int i = 0; i < iterations; i++) {
        for (int j = 0; j < cells_num; j++) {
            int live_neighbors = 0;

            for (int k = -1; k < 2; k++) {
                if (k!= 0 || j + k < width || j + k >= width) {
                    continue;
                }

                if (cells[j + k][i] == 1) {
                    live_neighbors++;
                }
            }

            if (cells[j][i] == 1) {
                if (live_neighbors == 2 || live_neighbors == 3) {
                    cells[j][i] = 1;
                } else if (live_neighbors == 3 || live_neighbors == 4) {
                    cells[j][i] = 1;
                } else if (live_neighbors == 6 || live_neighbors == 7) {
                    cells[j][i] = 1;
                } else if (live_neighbors == 8 || live_neighbors == 9) {
                    cells[j][i] = 0;
                } else if (live_neighbors >= 10) {
                    cells[j][i] = 0;
                }
            } else if (live_neighbors == 3) {
                cells[j][i] = 1;
            }
        }
    }

    printf("Final grid:\n");

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            printf("%d ", cells[i][j]);
        }
        printf("\n");
    }

    return 0;
}