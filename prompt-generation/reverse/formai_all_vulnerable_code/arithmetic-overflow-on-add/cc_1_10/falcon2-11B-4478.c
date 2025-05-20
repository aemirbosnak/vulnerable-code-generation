//Falcon2-11B DATASET v1.0 Category: Pac-Man Game Clone ; Style: retro
#include <stdio.h>

void print_pacman(int x, int y) {
    printf("M ");
    printf("%d ", y);
    printf("%d ", x);
}

void print_dot(int x, int y) {
    printf("* ");
    printf("%d ", y);
    printf("%d ", x);
}

void move_pacman(int x, int y, int dx, int dy) {
    x += dx;
    y += dy;
    if (x < 0 || y < 0 || x >= 10 || y >= 10) {
        printf("Game over!\n");
    } else {
        print_pacman(x, y);
    }
}

void move_dot(int x, int y, int dx, int dy) {
    x += dx;
    y += dy;
    if (x < 0 || y < 0 || x >= 10 || y >= 10) {
        printf("Game over!\n");
    } else {
        print_dot(x, y);
    }
}

int main() {
    int x, y;
    int dx, dy;

    printf("Movement: Up, Down, Left, Right\n");
    printf("Press enter to start.\n");
    getchar();

    while (1) {
        printf("Press enter to move Pacman:\n");
        getchar();

        move_pacman(x, y, dx, dy);
        printf("\n");

        printf("Press enter to move Dot:\n");
        getchar();

        move_dot(x, y, dx, dy);
        printf("\n");
    }

    return 0;
}