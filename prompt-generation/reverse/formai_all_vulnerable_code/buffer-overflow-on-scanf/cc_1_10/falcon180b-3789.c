//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>

enum {
    FORWARD = 0,
    BACKWARD = 1,
    LEFT = 2,
    RIGHT = 3,
    STOP = 4
};

enum {
    SPEED_MIN = 1,
    SPEED_MAX = 10
};

struct {
    int speed;
    int direction;
} remote;

void move(int speed, int direction) {
    printf("Vehicle is moving at %d speed with %d direction\n", speed, direction);
}

int main() {
    int choice;

    do {
        printf("What would you like to do with the vehicle?\n");
        printf("1. Move Forward\n");
        printf("2. Move Backward\n");
        printf("3. Turn Left\n");
        printf("4. Turn Right\n");
        printf("5. Stop\n");
        printf("6. Change Speed\n");
        printf("7. Change Direction\n");
        printf("8. Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                remote.speed = SPEED_MIN;
                remote.direction = FORWARD;
                move(remote.speed, remote.direction);
                break;
            case 2:
                remote.speed = SPEED_MIN;
                remote.direction = BACKWARD;
                move(remote.speed, remote.direction);
                break;
            case 3:
                remote.speed = SPEED_MIN;
                remote.direction = LEFT;
                move(remote.speed, remote.direction);
                break;
            case 4:
                remote.speed = SPEED_MIN;
                remote.direction = RIGHT;
                move(remote.speed, remote.direction);
                break;
            case 5:
                remote.speed = 0;
                remote.direction = STOP;
                move(remote.speed, remote.direction);
                break;
            case 6:
                printf("Enter new speed (1-10): ");
                scanf("%d", &remote.speed);
                printf("New speed set to %d\n", remote.speed);
                break;
            case 7:
                printf("Enter new direction (0-3): ");
                scanf("%d", &remote.direction);
                printf("New direction set to %d\n", remote.direction);
                break;
            case 8:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= 8);

    return 0;
}