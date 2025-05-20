//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(0)); // Seed random number generator

    printf("You are an astronaut on a mission to explore a distant planet in the Alpha Centauri system.\n");
    printf("As you land on the planet, you notice strange readings on your instruments.\n");
    printf("You step out of your spacecraft and begin to investigate.\n");

    int oxygen_level = 100;
    int alien_encounter = rand() % 2; // Randomly generate 0 or 1 for alien encounter
    int asteroid_encounter = rand() % 2; // Randomly generate 0 or 1 for asteroid encounter
    int distance_traveled = 0;
    int max_distance = 1000; // Maximum distance you can travel before running out of oxygen

    while (oxygen_level > 0 && distance_traveled < max_distance) { // Continue while you have oxygen and haven't reached max distance

        if (alien_encounter) {
            printf("You come face to face with a group of aliens!\n");
            printf("You can choose to fight or flee. Enter '1' to fight or '2' to flee: ");
            int choice;
            scanf("%d", &choice);
            if (choice == 1) {
                printf("You engage the aliens in battle!\n");
                printf("You manage to defeat them, but not without taking some damage.\n");
                oxygen_level -= 10;
            } else {
                printf("You turn tail and run!\n");
                distance_traveled -= 100;
            }
            alien_encounter = rand() % 2; // Generate new random number for future encounters
        }

        if (asteroid_encounter) {
            printf("You are hit by a shower of asteroids!\n");
            oxygen_level -= 20;
            asteroid_encounter = rand() % 2; // Generate new random number for future encounters
        }

        distance_traveled += 50;
        oxygen_level -= 5;

        if (distance_traveled >= max_distance) {
            printf("You have reached the maximum distance you can travel before running out of oxygen!\n");
        }

        if (oxygen_level <= 0) {
            printf("Your oxygen level has reached zero. You have died.\n");
        }

        if (distance_traveled < max_distance && oxygen_level > 0) {
            printf("You have traveled %d kilometers and have %d%% oxygen remaining.\n", distance_traveled, oxygen_level);
        }
    }

    return 0;
}