//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define STOP 5

int main() {
    int choice;
    int speed = 0;

    printf("Welcome to the Remote Control Vehicle Simulation!\n");
    printf("Please enter your choice:\n");
    printf("1. Forward\n");
    printf("2. Backward\n");
    printf("3. Turn left\n");
    printf("4. Turn right\n");
    printf("5. Stop\n");
    scanf("%d", &choice);

    switch (choice) {
        case UP:
            speed = 10;
            break;
        case DOWN:
            speed = -10;
            break;
        case LEFT:
            speed = -5;
            break;
        case RIGHT:
            speed = 5;
            break;
        case STOP:
            speed = 0;
            break;
        default:
            printf("Invalid choice.\n");
            return 0;
    }

    while (1) {
        printf("Vehicle is moving with speed %d\n", speed);
        fflush(stdout);
        sleep(1);
    }

    return 0;
}