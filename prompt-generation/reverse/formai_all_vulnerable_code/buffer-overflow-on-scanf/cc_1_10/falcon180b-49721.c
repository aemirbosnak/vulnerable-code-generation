//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 100
#define MIN_SPEED 50
#define MAX_TURN_ANGLE 90
#define MIN_TURN_ANGLE -90
#define MAX_ACCELERATION 10
#define MIN_ACCELERATION -10

typedef struct {
    int speed;
    int turnAngle;
    int acceleration;
} RemoteControl;

void initRemoteControl(RemoteControl *remoteControl) {
    remoteControl->speed = MAX_SPEED;
    remoteControl->turnAngle = 0;
    remoteControl->acceleration = 0;
}

void updateRemoteControl(RemoteControl *remoteControl) {
    remoteControl->speed += remoteControl->acceleration;
    if (remoteControl->speed < MIN_SPEED) {
        remoteControl->speed = MIN_SPEED;
    } else if (remoteControl->speed > MAX_SPEED) {
        remoteControl->speed = MAX_SPEED;
    }

    remoteControl->turnAngle += remoteControl->acceleration;
    if (remoteControl->turnAngle < MIN_TURN_ANGLE) {
        remoteControl->turnAngle = MIN_TURN_ANGLE;
    } else if (remoteControl->turnAngle > MAX_TURN_ANGLE) {
        remoteControl->turnAngle = MAX_TURN_ANGLE;
    }
}

void printRemoteControlState(RemoteControl *remoteControl) {
    printf("Speed: %d\n", remoteControl->speed);
    printf("Turn Angle: %d\n", remoteControl->turnAngle);
    printf("Acceleration: %d\n", remoteControl->acceleration);
}

int main() {
    RemoteControl remoteControl;
    initRemoteControl(&remoteControl);

    while (1) {
        int choice;
        printf("Enter your choice:\n");
        printf("1. Increase Speed\n");
        printf("2. Decrease Speed\n");
        printf("3. Turn Right\n");
        printf("4. Turn Left\n");
        printf("5. Accelerate\n");
        printf("6. Decelerate\n");
        printf("7. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                remoteControl.speed += 10;
                break;
            case 2:
                remoteControl.speed -= 10;
                break;
            case 3:
                remoteControl.turnAngle += 10;
                break;
            case 4:
                remoteControl.turnAngle -= 10;
                break;
            case 5:
                remoteControl.acceleration += 5;
                break;
            case 6:
                remoteControl.acceleration -= 5;
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }

        updateRemoteControl(&remoteControl);
        printRemoteControlState(&remoteControl);
    }

    return 0;
}