//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_planets;
    int num_inhabited_planets;
    int num_inhabited_planets_destroyed;
    int num_inhabited_planets_survived;
    int num_inhabited_planets_peaceful;
    int num_inhabited_planets_hostile;
    int num_inhabited_planets_unknown;

    srand(time(0));
    num_planets = rand() % 1000 + 1; // Random number of planets between 1 and 1000

    printf("In a distant galaxy, there are %d planets.\n", num_planets);

    for (int i = 0; i < num_planets; i++) {
        int inhabited = rand() % 2; // Randomly determine if planet is inhabited or not

        if (inhabited) {
            num_inhabited_planets++;

            int destroyed = rand() % 2; // Randomly determine if planet is destroyed or not

            if (destroyed) {
                num_inhabited_planets_destroyed++;
            } else {
                int survived = rand() % 2; // Randomly determine if planet survived or not

                if (survived) {
                    num_inhabited_planets_survived++;
                } else {
                    int peaceful = rand() % 2; // Randomly determine if planet is peaceful or not

                    if (peaceful) {
                        num_inhabited_planets_peaceful++;
                    } else {
                        num_inhabited_planets_hostile++;
                    }
                }
            }
        } else {
            num_inhabited_planets_unknown++;
        }
    }

    printf("\nOut of %d planets, %d are inhabited.\n", num_planets, num_inhabited_planets);

    if (num_inhabited_planets_destroyed > 0) {
        printf("%d inhabited planets were destroyed.\n", num_inhabited_planets_destroyed);
    }

    if (num_inhabited_planets_survived > 0) {
        printf("%d inhabited planets survived.\n", num_inhabited_planets_survived);
    }

    if (num_inhabited_planets_peaceful > 0) {
        printf("%d inhabited planets are peaceful.\n", num_inhabited_planets_peaceful);
    }

    if (num_inhabited_planets_hostile > 0) {
        printf("%d inhabited planets are hostile.\n", num_inhabited_planets_hostile);
    }

    if (num_inhabited_planets_unknown > 0) {
        printf("%d inhabited planets are unknown.\n", num_inhabited_planets_unknown);
    }

    return 0;
}