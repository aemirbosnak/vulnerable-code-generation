//Falcon2-11B DATASET v1.0 Category: Procedurally Generated Maze ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct cell {
    int x;
    int y;
};

int maze[100][100];
int visited[100][100];

int main() {
    srand(time(NULL));
    int i, j, rows, cols, x, y, n;
    struct cell start, end;

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            maze[i][j] = rand() % 2;
            visited[i][j] = 0;
        }
    }

    start.x = rand() % cols;
    start.y = rand() % rows;

    end.x = rand() % cols;
    end.y = rand() % rows;

    printf("Start: (%d, %d)\n", start.x, start.y);
    printf("End:   (%d, %d)\n", end.x, end.y);

    printf("Path:  ");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (maze[i][j] == 1 && visited[i][j] == 0) {
                visited[i][j] = 1;
                printf("%d ", j);
            }
        }
        printf("\n");
    }

    printf("\n");

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (maze[i][j] == 1 && visited[i][j] == 0) {
                x = j;
                y = i;
            }
        }
    }

    printf("Path:  ");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (maze[i][j] == 1 && visited[i][j] == 0) {
                visited[i][j] = 1;
                printf("%d ", j);
            }
        }
        printf("\n");
    }

    printf("\n");

    printf("Path length: %d\n", i * j);
    return 0;
}