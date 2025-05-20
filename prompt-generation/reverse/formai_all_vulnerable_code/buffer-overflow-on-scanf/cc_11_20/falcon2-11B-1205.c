//Falcon2-11B DATASET v1.0 Category: Pac-Man Game Clone ; Style: configurable
#include <stdio.h>

int main() {
    int width = 20;
    int height = 10;
    int x = 10;
    int y = 5;
    int food = 0;
    int score = 0;
    int dir = 0;
    int ghost_x = 0;
    int ghost_y = 0;
    int ghost_dir = 0;

    int pacman_x = x;
    int pacman_y = y;

    int ghost_x_min = -1;
    int ghost_x_max = width + 1;
    int ghost_y_min = -1;
    int ghost_y_max = height + 1;

    while (1) {
        printf("pacman: %d,%d\n", pacman_x, pacman_y);
        printf("food: %d\n", food);
        printf("score: %d\n", score);
        printf("ghosts: %d,%d\n", ghost_x, ghost_y);

        scanf("%d %d", &x, &y);
        scanf("%d %d", &food, &score);
        scanf("%d %d %d", &ghost_x, &ghost_y, &ghost_dir);

        if (food!= 0) {
            food = 0;
        } else if (score >= 100) {
            printf("You win!\n");
            break;
        } else if (score < 100 && x >= 0 && y >= 0 && x < width && y < height) {
            pacman_x = x;
            pacman_y = y;

            if (dir == 0) {
                pacman_x--;
            } else if (dir == 1) {
                pacman_x++;
            } else if (dir == 2) {
                pacman_y--;
            } else if (dir == 3) {
                pacman_y++;
            }
        } else {
            printf("Game Over!\n");
            break;
        }
    }

    return 0;
}