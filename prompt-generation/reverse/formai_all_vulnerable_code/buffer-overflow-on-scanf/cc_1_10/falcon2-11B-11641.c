//Falcon2-11B DATASET v1.0 Category: Terminal Based Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void moveSpaceship(int direction) {
    switch (direction) {
        case -1:
            printf("Left\n");
            break;
        case 1:
            printf("Right\n");
            break;
        default:
            printf("Invalid direction\n");
            break;
    }
}

void shootAsteroid() {
    printf("Boom!\n");
}

int main() {
    int direction = 0;
    int asteroidCount = 10;
    int score = 0;

    srand(time(NULL));

    while (asteroidCount > 0) {
        printf("Score: %d\n", score);
        printf("Direction: ");
        scanf("%d", &direction);
        printf("Asteroids left: %d\n", asteroidCount);

        moveSpaceship(direction);

        if (direction == -1 || direction == 1) {
            asteroidCount--;
        }

        if (direction == -1) {
            shootAsteroid();
        }

        asteroidCount--;
    }

    printf("Game over!\n");

    return 0;
}