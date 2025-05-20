//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int direction = 0;
    int speed = 0;
    int distance_traveled = 0;
    int battery_percentage = 100;

    printf("Welcome to the Remote Control Vehicle Simulation!\n");

    printf("Enter the current speed (in mph) >> ");
    scanf("%d", &speed);

    while (1) {
        if (battery_percentage <= 0) {
            printf("Battery run out. Game Over.");
            break;
        }

        printf("Current direction: %d degrees\n", direction);
        printf("Current speed: %d mph\n", speed);
        printf("Distance traveled: %d miles\n", distance_traveled);
        printf("Battery remaining: %d percent\n", battery_percentage);

        printf("Enter new direction (in degrees) or -1 to quit >> ");
        scanf("%d", &direction);

        if (direction == -1) {
            printf("Quitting the simulation...\n");
            break;
        }

        printf("Enter new speed (in mph) or -1 to quit >> ");
        scanf("%d", &speed);

        if (speed == -1) {
            printf("Quitting the simulation...\n");
            break;
        }

        int distance_to_travel = speed * 20;
        distance_traveled += distance_to_travel;

        int battery_drain = (distance_to_travel / 100) * 5;
        battery_percentage -= battery_drain;

        int random_event = rand() % 5;
        if (random_event == 0) {
            printf("Your vehicle just hit a tree! You had to reverse 50 miles.\n");
            distance_traveled -= 50;
        }
        else if (random_event == 1) {
            printf("Your vehicle just got stuck in mud! You had to reverse 30 miles.\n");
            distance_traveled -= 30;
        }
        else if (random_event == 2) {
            printf("Your vehicle just got a flat tire! You had to replace it before continuing.\n");
            battery_percentage -= 10;
        }
        else if (random_event == 3) {
            printf("You just found a shortcut! You traveled an extra 10 miles.\n");
            distance_traveled += 10;
            battery_percentage -= 3;
        }
        else if (random_event == 4) {
            printf("You just got lost! You had to drive an extra 20 miles to get back on track.\n");
            distance_traveled += 20;
            battery_percentage -= 8;
        }
    }

    return 0;
}