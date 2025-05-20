//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846

/* Function Prototypes */
void move_forward(int distance, int speed);
void turn_left(int angle, int speed);
void turn_right(int angle, int speed);
void stop_robot(void);

int main() {
    int choice, distance, angle, speed;

    /* Initialize robot position */
    printf("Robot is at position (0, 0)\n");
    printf("Enter 1 to move forward, 2 to turn left, 3 to turn right, or 4 to stop: ");
    scanf("%d", &choice);

    while(choice!= 4) {
        switch(choice) {
            case 1:
                printf("Enter distance to move forward: ");
                scanf("%d", &distance);
                printf("Enter speed (1-10): ");
                scanf("%d", &speed);
                move_forward(distance, speed);
                break;
            case 2:
                printf("Enter angle to turn left (-180 to 180): ");
                scanf("%d", &angle);
                printf("Enter speed (1-10): ");
                scanf("%d", &speed);
                turn_left(angle, speed);
                break;
            case 3:
                printf("Enter angle to turn right (-180 to 180): ");
                scanf("%d", &angle);
                printf("Enter speed (1-10): ");
                scanf("%d", &speed);
                turn_right(angle, speed);
                break;
            default:
                printf("Invalid choice\n");
        }
        printf("Enter 1 to move forward, 2 to turn left, 3 to turn right, or 4 to stop: ");
        scanf("%d", &choice);
    }

    return 0;
}

/* Move forward function */
void move_forward(int distance, int speed) {
    int i;
    for(i=0; i<distance; i++) {
        printf("Robot is moving forward...\n");
        sleep(speed/10); /* Sleep for specified speed */
    }
}

/* Turn left function */
void turn_left(int angle, int speed) {
    int i;
    for(i=0; i<angle; i++) {
        printf("Robot is turning left...\n");
        sleep(speed/10); /* Sleep for specified speed */
    }
}

/* Turn right function */
void turn_right(int angle, int speed) {
    int i;
    for(i=0; i<angle; i++) {
        printf("Robot is turning right...\n");
        sleep(speed/10); /* Sleep for specified speed */
    }
}

/* Stop robot function */
void stop_robot(void) {
    printf("Robot has stopped\n");
}