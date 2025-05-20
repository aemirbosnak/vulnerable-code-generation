//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 10
#define MIN_SPEED 1
#define TURN_ANGLE 10
#define FORWARD_DISTANCE 100
#define BACKWARD_DISTANCE 200
#define LEFT_DISTANCE 300
#define RIGHT_DISTANCE 400

void moveForward(int speed) {
    printf("Moving forward at %d speed\n", speed);
}

void moveBackward(int speed) {
    printf("Moving backward at %d speed\n", speed);
}

void turnLeft(int angle) {
    printf("Turning left by %d degrees\n", angle);
}

void turnRight(int angle) {
    printf("Turning right by %d degrees\n", angle);
}

void remoteControl(int choice) {
    int speed, angle;
    printf("Enter speed (1-10): ");
    scanf("%d", &speed);
    printf("Enter turn angle (1-90): ");
    scanf("%d", &angle);

    switch(choice) {
        case 1:
            moveForward(speed);
            break;
        case 2:
            moveBackward(speed);
            break;
        case 3:
            turnLeft(angle);
            break;
        case 4:
            turnRight(angle);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
}

int main() {
    int choice;

    srand(time(NULL));

    while(1) {
        printf("\n1. Move forward\n2. Move backward\n3. Turn left\n4. Turn right\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                remoteControl(1);
                break;
            case 2:
                remoteControl(2);
                break;
            case 3:
                remoteControl(3);
                break;
            case 4:
                remoteControl(4);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }

        printf("\nPress enter to continue...\n");
        getchar();
    }

    return 0;
}