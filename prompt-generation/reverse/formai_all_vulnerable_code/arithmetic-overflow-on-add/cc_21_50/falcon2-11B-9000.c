//Falcon2-11B DATASET v1.0 Category: Pac-Man Game Clone ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x, y;
} Point;

int main() {
    int width = 800, height = 600, dx, dy, x, y, i, j;
    int lives = 3, score = 0;
    Point pacman, food;
    char* foodLocs[] = {"top-left", "top-center", "top-right", "mid-left", "mid-center", "mid-right", "bottom-left", "bottom-center", "bottom-right"};
    srand(time(NULL));

    while (1) {
        for (i = 0; i < 9; i++) {
            food.x = rand() % width;
            food.y = rand() % height;
            if (food.x == 0 || food.x == width - 1 || food.y == 0 || food.y == height - 1) continue;
            else break;
        }

        pacman.x = rand() % width;
        pacman.y = rand() % height;

        while (pacman.x == food.x && pacman.y == food.y) {
            pacman.x = rand() % width;
            pacman.y = rand() % height;
        }

        printf("Score: %d\n", score);
        printf("Lives: %d\n", lives);
        printf("Food Location: %s\n", foodLocs[i]);
        printf("Pacman Location: (x, y) = (%d, %d)\n", pacman.x, pacman.y);

        printf("w - up\n");
        printf("s - down\n");
        printf("a - left\n");
        printf("d - right\n");
        printf("q - quit\n");

        scanf(" ");

        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                printf(" ");
            }
            printf("|");
            for (j = 0; j < 4; j++) {
                if (i == pacman.y && j == pacman.x) printf("*");
                else if (i == food.y && j == food.x) printf("*");
                else printf(" ");
            }
            printf("|\n");
            for (j = 0; j < 4; j++) {
                printf("-");
            }
            printf("|\n");
        }

        if (scanf(" ") == EOF) break;
        switch (getch()) {
            case 'w':
                dy = -1;
                dx = 0;
                break;
            case's':
                dy = 1;
                dx = 0;
                break;
            case 'a':
                dx = -1;
                dy = 0;
                break;
            case 'd':
                dx = 1;
                dy = 0;
                break;
            case 'q':
                return 0;
        }

        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                if (i == pacman.y && j == pacman.x) {
                    pacman.y += dy;
                    pacman.x += dx;
                    break;
                }
            }
            if (i == pacman.y && j == pacman.x) break;
        }

        if (pacman.x < 0 || pacman.x > width - 1 || pacman.y < 0 || pacman.y > height - 1) {
            printf("Game Over!\n");
            lives--;
            if (lives == 0) break;
            pacman.x = rand() % width;
            pacman.y = rand() % height;
        }

        score++;
    }

    return 0;
}