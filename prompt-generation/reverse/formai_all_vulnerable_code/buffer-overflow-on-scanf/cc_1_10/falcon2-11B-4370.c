//Falcon2-11B DATASET v1.0 Category: Space Invaders Game Clone ; Style: introspective
#include <stdio.h>

int main() {
    int x, y, score, aliens, i;
    char input;

    printf("Space Invaders Game\n");
    printf("Welcome to the Space Invaders Game!\n");
    printf("Press 'x' to start the game, 'y' to quit\n");

    scanf(" %c", &input);

    while (input!= 'x') {
        scanf(" %c", &input);
        printf("Invalid input. Please try again.\n");
    }

    score = 0;
    aliens = 10;

    while (aliens > 0) {
        printf("Alien Count: %d\n", aliens);

        for (i = 0; i < aliens; i++) {
            printf("Alien %d:\n", i + 1);
            printf("X: %d\n", rand() % 100);
            printf("Y: %d\n", rand() % 100);
            printf("Moving: %s\n", (rand() % 2)? "left" : "right");
            printf("Attacking: %s\n", (rand() % 2)? "up" : "down");
            printf("Shooting: %s\n", (rand() % 2)? "yes" : "no");
            printf("Ready to shoot: %s\n", (rand() % 2)? "yes" : "no");
            printf("\n");
        }

        printf("Press 'x' to shoot, 'y' to quit\n");
        scanf(" %c", &input);

        if (input == 'x') {
            printf("You shot!\n");
            score++;
            aliens--;
        } else {
            break;
        }
    }

    printf("Score: %d\n", score);

    return 0;
}