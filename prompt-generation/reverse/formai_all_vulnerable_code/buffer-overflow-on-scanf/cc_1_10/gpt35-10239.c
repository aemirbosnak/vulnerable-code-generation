//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SPEED 50
#define MAX_STEER 30

typedef struct {
    int speed;
    int steer;
} ControlPacket;

void getInputs(ControlPacket *cp) {
    printf("Enter the speed (0-%d): ", MAX_SPEED);
    scanf("%d", &(cp->speed));
    if (cp->speed > MAX_SPEED) {
        cp->speed = MAX_SPEED;
    } else if (cp->speed < 0) {
        cp->speed = 0;
    }

    printf("Enter the steering angle (-%d to %d): ", MAX_STEER, MAX_STEER);
    scanf("%d", &(cp->steer));
    if (cp->steer > MAX_STEER) {
        cp->steer = MAX_STEER;
    } else if (cp->steer < (-MAX_STEER)) {
        cp->steer = -MAX_STEER;
    }
}

void moveForward(int speed) {
    printf("Moving forward at speed %d\n", speed);
}

void moveBackward(int speed) {
    printf("Moving backward at speed %d\n", speed);
}

void steerLeft(int angle) {
    printf("Steering left at angle %d\n", angle);
}

void steerRight(int angle) {
    printf("Steering right at angle %d\n", angle);
}

int main() {
    ControlPacket cp;
    getInputs(&cp);

    if (cp.speed > 0) {
        moveForward(cp.speed);
    } else {
        moveBackward(abs(cp.speed));
    }

    if (cp.steer > 0) {
        steerRight(cp.steer);
    } else {
        steerLeft(abs(cp.steer));
    }

    return 0;
}