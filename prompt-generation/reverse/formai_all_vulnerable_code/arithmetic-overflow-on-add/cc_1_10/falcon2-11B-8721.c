//Falcon2-11B DATASET v1.0 Category: Pac-Man Game Clone ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
    int score;
    int direction;
} Pacman;

typedef struct {
    int x;
    int y;
} Ghost;

typedef struct {
    int x;
    int y;
} Power;

void move_pacman(Pacman* pacman, int dx, int dy) {
    pacman->x += dx;
    pacman->y += dy;
}

void move_ghost(Ghost* ghost, int dx, int dy) {
    ghost->x += dx;
    ghost->y += dy;
}

void move_power(Power* power, int dx, int dy) {
    power->x += dx;
    power->y += dy;
}

int main(int argc, char* argv[]) {
    srand(time(NULL));

    Pacman pacman;
    Ghost ghost;
    Power power;

    pacman.x = 50;
    pacman.y = 50;
    pacman.score = 0;
    pacman.direction = 0;

    ghost.x = 10;
    ghost.y = 10;

    power.x = 100;
    power.y = 100;

    int dx = 0, dy = 0;

    while (1) {
        printf("Score: %d\n", pacman.score);
        printf("x: %d, y: %d\n", pacman.x, pacman.y);

        switch (pacman.direction) {
            case 0:
                move_pacman(&pacman, 0, 1);
                break;
            case 1:
                move_pacman(&pacman, 1, 0);
                break;
            case 2:
                move_pacman(&pacman, 0, -1);
                break;
            case 3:
                move_pacman(&pacman, -1, 0);
                break;
        }

        move_ghost(&ghost, 1, 0);
        move_ghost(&ghost, -1, 0);

        move_power(&power, 1, 0);
        move_power(&power, -1, 0);

        if (pacman.x == power.x && pacman.y == power.y) {
            pacman.score++;
        }

        if (pacman.x == ghost.x && pacman.y == ghost.y) {
            printf("Game Over!\n");
            break;
        }

        if (pacman.x < 0 || pacman.x > 500 || pacman.y < 0 || pacman.y > 500) {
            printf("Game Over!\n");
            break;
        }

        if (power.x < 0 || power.x > 500 || power.y < 0 || power.y > 500) {
            power.x = 100 + rand() % 400;
            power.y = 100 + rand() % 400;
        }

        if (ghost.x < 0 || ghost.x > 500 || ghost.y < 0 || ghost.y > 500) {
            ghost.x = 10 + rand() % 400;
            ghost.y = 10 + rand() % 400;
        }

        printf("G: %d, %d\n", ghost.x, ghost.y);
        printf("P: %d, %d\n", power.x, power.y);

        printf("Enter direction (0-3): ");
        scanf("%d", &dx);

        if (dx == 0) {
            dy = 0;
        } else if (dx == 1) {
            dy = 1;
        } else if (dx == 2) {
            dy = -1;
        } else {
            dy = 0;
        }

        move_pacman(&pacman, dx, dy);

        if (pacman.score == 10) {
            printf("Congratulations! You won the game!\n");
            break;
        }

        printf("\n");
    }

    return 0;
}