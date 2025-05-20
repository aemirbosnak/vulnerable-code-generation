//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int get_random_number(int min, int max) {
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min;
}

int main() {
    printf("Welcome to the Remote Control Vehicle Simulation!\n");

    int battery_level = 100;
    int distance_traveled = 0;
    int speed = 0;

    while (battery_level > 0) {
        printf("\n");
        printf("Battery Level: %d%%\n", battery_level);
        printf("Distance Traveled: %d meters\n", distance_traveled);
        printf("Speed: %d km/h\n", speed);

        printf("\n");

        printf("Enter direction (forward or backward): ");
        char direction[10];
        scanf("%s", direction);

        printf("Enter distance to travel (meters): ");
        int distance;
        scanf("%d", &distance);

        if (strcmp(direction, "forward") == 0) {
            speed = get_random_number(10, 30);

            printf("Traveling forward at %d km/h...\n", speed);

            for (int i = 0; i < distance; i++) {
                printf("%d meters traveled...\n", i + 1);
                distance_traveled++;
                battery_level--;
            }

            printf("Arrived at destination!\n");
            speed = 0;
        } else if (strcmp(direction, "backward") == 0) {
            printf("Reversing...\n");

            for (int i = 0; i < distance; i++) {
                printf("%d meters traveled...\n", i + 1);
                distance_traveled--;
                battery_level--;
            }

            printf("Arrived at starting point!\n");
            speed = 0;
        } else {
            printf("Invalid direction entered!\n");
        }

        printf("\n");
    }

    printf("Out of battery! Simulation ended.\n");

    return 0;
}