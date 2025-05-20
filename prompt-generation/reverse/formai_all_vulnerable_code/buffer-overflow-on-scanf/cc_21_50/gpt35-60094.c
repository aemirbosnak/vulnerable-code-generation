//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int x, y, dx, dy;
    int energy = 100;
    int phase = 0;

    srand(time(NULL));
    x = rand() % 100;
    y = rand() % 100;

    printf("You wake up in a spaceship.\n");
    printf("Your coordinates: (%d, %d)\n", x, y);

    while (energy > 0) {
        printf("Phase %d\n", phase);

        if (phase == 0) {
            printf("You are in space.\n");
            printf("Choose a direction: (1) north, (2) south, (3) east, (4) west\n");
            scanf("%d", &dx);
            scanf("%d", &dy);
            x += dx;
            y += dy;
            if (x < 0 || x > 100 || y < 0 || y > 100) {
                printf("Out of bounds! Your spaceship crashes and you die.\n");
                return 0;
            }
        } else if (phase == 1) {
            printf("You land on a planet.\n");
            printf("You see a group of aliens approaching you.\n");
            energy -= 10;
            if (energy <= 0) {
                printf("You run out of energy and die.\n");
                return 0;
            } else {
                printf("Quick! (1) fight, (2) run away, (3) negotiate\n");
                int choice;
                scanf("%d", &choice);
                if (choice == 1) {
                    printf("You fight the aliens and win.\n");
                } else if (choice == 2) {
                    printf("You run away from the aliens.\n");
                    dx = rand() % 10;
                    dy = rand() % 10;
                    x += dx;
                    y += dy;
                    if (x < 0 || x > 100 || y < 0 || y > 100) {
                        printf("Out of bounds! Your spaceship crashes and you die.\n");
                        return 0;
                    }
                } else if (choice == 3) {
                    printf("You try to negotiate with the aliens.\n");
                    int luck = rand() % 10;
                    if (luck >= 5) {
                        printf("The aliens agree to leave you alone.\n");
                    } else {
                        printf("The aliens attack you.\n");
                        energy -= 10;
                        if (energy <= 0) {
                            printf("You run out of energy and die.\n");
                            return 0;
                        }
                    }
                }
            }
        } else if (phase == 2) {
            printf("You encounter a black hole.\n");
            printf("Choose a direction: (1) towards the black hole, (2) away from the black hole\n");
            int choice;
            scanf("%d", &choice);
            if (choice == 1) {
                printf("You get sucked into the black hole and die.\n");
                return 0;
            } else if (choice == 2) {
                printf("You manage to avoid the black hole.\n");
                dx = rand() % 10;
                dy = rand() % 10;
                x += dx;
                y += dy;
                if (x < 0 || x > 100 || y < 0 || y > 100) {
                    printf("Out of bounds! Your spaceship crashes and you die.\n");
                    return 0;
                }
            }
        }
        energy -= 10;
        if (energy <= 0) {
            printf("You run out of energy and die.\n");
            return 0;
        }
        printf("Your coordinates: (%d, %d)\n", x, y);
        printf("Your energy: %d\n", energy);
        phase++;
    }
    printf("You have explored the galaxy and run out of energy. Game over.\n");
    return 0;
}