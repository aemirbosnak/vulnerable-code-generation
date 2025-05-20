//Falcon2-11B DATASET v1.0 Category: Procedurally Generated Maze ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int width, height, numWalls, numStart, numEnd;
    srand(time(NULL));

    printf("Enter the width of the maze: ");
    scanf("%d", &width);

    printf("Enter the height of the maze: ");
    scanf("%d", &height);

    printf("Enter the number of walls: ");
    scanf("%d", &numWalls);

    printf("Enter the starting position (row, column): ");
    scanf("%d%d", &numStart, &numEnd);

    int** maze = (int**)malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++) {
        maze[i] = (int*)malloc(width * sizeof(int));
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            maze[i][j] = 0;
        }
    }

    for (int i = 0; i < numWalls; i++) {
        int r1, c1, r2, c2;
        printf("Enter the coordinates of wall %d: ", i + 1);
        scanf("%d%d%d%d", &r1, &c1, &r2, &c2);

        if (r1 > r2 || c1 > c2) {
            printf("Invalid coordinates for wall %d\n", i + 1);
            continue;
        }

        for (int k = r1; k <= r2; k++) {
            for (int l = c1; l <= c2; l++) {
                maze[k][l] = 1;
            }
        }
    }

    for (int i = 0; i < numStart; i++) {
        int r, c;
        printf("Enter the coordinates of start position %d: ", i + 1);
        scanf("%d%d", &r, &c);

        if (r > height - 1 || c > width - 1) {
            printf("Invalid coordinates for start position %d\n", i + 1);
            continue;
        }

        maze[r][c] = 2;
    }

    for (int i = 0; i < numEnd; i++) {
        int r, c;
        printf("Enter the coordinates of end position %d: ", i + 1);
        scanf("%d%d", &r, &c);

        if (r > height - 1 || c > width - 1) {
            printf("Invalid coordinates for end position %d\n", i + 1);
            continue;
        }

        maze[r][c] = 3;
    }

    printf("Maze created successfully!\n");

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }

    free(maze);

    return 0;
}