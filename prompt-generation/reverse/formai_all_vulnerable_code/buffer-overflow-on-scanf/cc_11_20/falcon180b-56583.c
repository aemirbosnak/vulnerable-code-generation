//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define DRONE_SPEED 100
#define DRONE_TURN_SPEED 50
#define DRONE_MAX_SPEED 200
#define DRONE_MIN_SPEED 50

int main() {
    int speed = DRONE_SPEED;
    int turn_speed = DRONE_TURN_SPEED;
    int max_speed = DRONE_MAX_SPEED;
    int min_speed = DRONE_MIN_SPEED;

    printf("Welcome to the drone remote control!\n");
    printf("You can control the drone's speed and turn speed.\n");

    while (1) {
        printf("Current speed: %d\n", speed);
        printf("Current turn speed: %d\n", turn_speed);

        printf("Enter a command:\n");
        printf("1. Increase speed\n");
        printf("2. Decrease speed\n");
        printf("3. Increase turn speed\n");
        printf("4. Decrease turn speed\n");
        printf("5. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            speed += 10;
            if (speed > max_speed) {
                speed = max_speed;
            }
            break;

        case 2:
            speed -= 10;
            if (speed < min_speed) {
                speed = min_speed;
            }
            break;

        case 3:
            turn_speed += 10;
            if (turn_speed > max_speed) {
                turn_speed = max_speed;
            }
            break;

        case 4:
            turn_speed -= 10;
            if (turn_speed < min_speed) {
                turn_speed = min_speed;
            }
            break;

        case 5:
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}