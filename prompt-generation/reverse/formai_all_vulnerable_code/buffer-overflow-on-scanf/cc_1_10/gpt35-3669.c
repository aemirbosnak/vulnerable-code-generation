//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: interoperable
#include <stdio.h>

/* Enum for drone direction */
typedef enum {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT,
} Direction;

/* Function to control the drone's movement */
void controlDrone(Direction dir, int distance) {
    printf("Moving the drone ");
    switch (dir) {
        case FORWARD:
            printf("forward ");
            break;
        case BACKWARD:
            printf("backward ");
            break;
        case LEFT:
            printf("left ");
            break;
        case RIGHT:
            printf("right ");
            break;
    }
    printf("%d meters.\n", distance);
}

/* Function to change drone's altitude */
void changeAltitude(int altitude) {
    printf("Changing drone altitude to %d meters.\n", altitude);
}

int main() {
    Direction dir;
    int distance, altitude;

    printf("Type the direction (forward, backward, left, right): ");
    scanf("%d", &dir);
    printf("Type the distance to move in meters: ");
    scanf("%d", &distance);
    printf("Type the altitude to change in meters: ");
    scanf("%d", &altitude);

    controlDrone(dir, distance);
    changeAltitude(altitude);

    return 0;
}