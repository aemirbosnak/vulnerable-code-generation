//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int velocity = 0;
    int direction = 0;

    printf("Welcome to the RC Vehicle Simulation Program\n");

    printf("Please enter your desired velocity (between 1 and 10): ");
    scanf("%d", &velocity);

    while (velocity < 1 || velocity > 10) {
        printf("Invalid input. Please enter your desired velocity (between 1 and 10): ");
        scanf("%d", &velocity);
    }

    printf("Please enter your desired direction (between -180 and 180 degrees): ");
    scanf("%d", &direction);

    while (direction < -180 || direction > 180) {
        printf("Invalid input. Please enter your desired direction (between -180 and 180 degrees): ");
        scanf("%d", &direction);
    }

    int battery_level = 100;
    int distance_travelled = 0;

    while (battery_level > 0) {
        printf("\n");

        if (velocity > 5) {
            printf("Warning: High velocity! Please drive responsibly.\n");
        }

        if (battery_level < 20) {
            printf("Warning: Low battery! Please recharge.\n");
        }

        int turn = rand() % 4;

        if (turn == 0) {
            printf("Turning left.\n");
            direction -= 45;
        } else if (turn == 1) {
            printf("Turning right.\n");
            direction += 45;
        }

        printf("Velocity: %d\n", velocity);
        printf("Direction: %d\n", direction);
        
        int distance_this_round = velocity;
        distance_travelled += distance_this_round;
        battery_level -= velocity + turn;

        printf("Distance travelled this round: %d\n", distance_this_round);
        printf("Distance travelled so far: %d\n", distance_travelled);
        printf("Battery level: %d\n", battery_level);
    }

    printf("\n");
    printf("Battery depleted! Please recharge your RC vehicle.\n");

    return 0;
}