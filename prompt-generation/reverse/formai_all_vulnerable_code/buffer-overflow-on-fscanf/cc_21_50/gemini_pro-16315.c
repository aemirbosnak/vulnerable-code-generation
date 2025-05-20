//GEMINI-pro DATASET v1.0 Category: Pac-Man Game Clone ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <maze file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    char maze[100][100];
    int mazeWidth, mazeHeight;
    fscanf(fp, "%d %d", &mazeWidth, &mazeHeight);
    for (i = 0; i < mazeHeight; i++) {
        for (j = 0; j < mazeWidth; j++) {
            fscanf(fp, " %c", &maze[i][j]);
        }
    }

    fclose(fp);

    int pacX, pacY;
    for (i = 0; i < mazeHeight; i++) {
        for (j = 0; j < mazeWidth; j++) {
            if (maze[i][j] == 'P') {
                pacX = j;
                pacY = i;
            }
        }
    }

    int numDots = 0;
    for (i = 0; i < mazeHeight; i++) {
        for (j = 0; j < mazeWidth; j++) {
            if (maze[i][j] == '.') {
                numDots++;
            }
        }
    }

    while (numDots > 0) {
        int dir = rand() % 4;
        int newPacX = pacX;
        int newPacY = pacY;
        switch (dir) {
            case 0:  // up
                newPacY--;
                break;
            case 1:  // down
                newPacY++;
                break;
            case 2:  // left
                newPacX--;
                break;
            case 3:  // right
                newPacX++;
                break;
        }

        if (maze[newPacY][newPacX] == '.' || maze[newPacY][newPacX] == ' ') {
            maze[pacY][pacX] = ' ';
            maze[newPacY][newPacX] = 'P';
            pacX = newPacX;
            pacY = newPacY;
            if (maze[newPacY][newPacX] == '.') {
                numDots--;
            }
        }

        // draw the maze
        printf("\x1b[2J");
        for (i = 0; i < mazeHeight; i++) {
            for (j = 0; j < mazeWidth; j++) {
                printf("%c", maze[i][j]);
            }
            printf("\n");
        }
    }

    printf("You win!\n");

    return 0;
}