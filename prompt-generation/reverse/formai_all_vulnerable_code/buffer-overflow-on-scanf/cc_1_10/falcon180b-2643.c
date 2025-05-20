//Falcon-180B DATASET v1.0 Category: Procedurally Generated Maze ; Style: safe
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int maze[10][10];
int x, y, startx, starty, endx, endy;

//Function to generate maze
void generateMaze(int startX, int startY, int endX, int endY) {
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int i, j, k, l, count = 0;
    srand(time(NULL));

    //Initializing the maze with walls
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            maze[i][j] = 1;
        }
    }

    //Creating a path from start to end
    maze[startX][startY] = 0;
    maze[endX][endY] = 0;

    while (count < 100) {
        i = rand() % 10;
        j = rand() % 10;

        if (maze[i][j] == 1) {
            for (k = 0; k < 4; k++) {
                l = i + dir[k][0];
                int m = j + dir[k][1];

                if (l >= 0 && l < 10 && m >= 0 && m < 10 && maze[l][m] == 1) {
                    maze[i][j] = 0;
                    maze[l][m] = 0;
                    count++;
                    break;
                }
            }
        }
    }
}

//Function to print maze
void printMaze() {
    int i, j;

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (maze[i][j] == 1)
                printf("X ");
            else
                printf("_ ");
        }
        printf("\n");
    }
}

int main() {
    int i, j;

    printf("Enter the starting position (row and column): ");
    scanf("%d%d", &startx, &starty);

    printf("Enter the ending position (row and column): ");
    scanf("%d%d", &endx, &endy);

    generateMaze(startx, starty, endx, endy);
    printMaze();

    return 0;
}