//Falcon-180B DATASET v1.0 Category: Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 20
#define WIDTH 30
#define PATH "maze.txt"

char maze[HEIGHT][WIDTH];
int playerX, playerY;

void loadMaze() {
    FILE *file;
    file = fopen(PATH, "r");
    if (file == NULL) {
        printf("Error loading maze\n");
        exit(1);
    }
    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            fscanf(file, "%c", &maze[y][x]);
            if (maze[y][x] == 'P') {
                playerX = x;
                playerY = y;
            }
        }
    }
    fclose(file);
}

void printMaze() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", maze[y][x]);
        }
        printf("\n");
    }
}

int move(int dx, int dy) {
    int newX = playerX + dx;
    int newY = playerY + dy;
    if (newX >= 0 && newX < WIDTH && newY >= 0 && newY < HEIGHT && maze[newY][newX]!= '#') {
        playerX = newX;
        playerY = newY;
        return 0;
    }
    return 1;
}

int main() {
    srand(time(NULL));
    loadMaze();
    printMaze();
    while (1) {
        char key;
        printf("Press a key to move:\n");
        scanf("%c", &key);
        int dx, dy;
        switch (key) {
            case 'w':
                dx = -1;
                dy = 0;
                break;
            case's':
                dx = 1;
                dy = 0;
                break;
            case 'a':
                dx = 0;
                dy = -1;
                break;
            case 'd':
                dx = 0;
                dy = 1;
                break;
            default:
                continue;
        }
        if (move(dx, dy)) {
            printf("You hit a wall!\n");
        } else {
            printf("You moved successfully!\n");
        }
        printMaze();
    }
    return 0;
}