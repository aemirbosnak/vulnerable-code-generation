//Falcon-180B DATASET v1.0 Category: Maze Route Finder ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int maze[SIZE][SIZE];
int solution[SIZE][SIZE];

void generateMaze() {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            maze[i][j] = rand() % 2;
        }
    }
}

void printMaze() {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (maze[i][j] == 1) {
                printf("X");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void solveMaze(int x, int y) {
    int i, j, k;
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int count = 0;

    while (count < 4) {
        i = x + directions[count][0];
        j = y + directions[count][1];

        if (i >= 0 && i < SIZE && j >= 0 && j < SIZE && maze[i][j] == 0 && solution[i][j] == 0) {
            solution[i][j] = 1;
            solution[x][y] = count + 1;
            x = i;
            y = j;
            count++;
        } else {
            count = 0;
        }
    }
}

int main() {
    srand(time(NULL));
    generateMaze();
    printMaze();

    int startX, startY, endX, endY;
    printf("Enter starting position (x y): ");
    scanf("%d %d", &startX, &startY);
    printf("Enter ending position (x y): ");
    scanf("%d %d", &endX, &endY);

    solveMaze(startX, startY);

    printf("\nSolution:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (solution[i][j]!= 0) {
                printf("%d ", solution[i][j]);
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }

    return 0;
}