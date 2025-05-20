//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 100
#define MIN_SPEED 0
#define MAX_TURN 100
#define MIN_TURN -100
#define MAX_ACCELERATION 10
#define MIN_ACCELERATION -10
#define MAX_BRAKE 10
#define MIN_BRAKE -10

typedef struct {
    int speed;
    int turn;
    int acceleration;
    int brake;
} RemoteControl;

RemoteControl readRemoteControl() {
    RemoteControl rc;
    printf("Enter speed (0-100): ");
    scanf("%d", &rc.speed);
    printf("Enter turn (0-100): ");
    scanf("%d", &rc.turn);
    printf("Enter acceleration (0-10): ");
    scanf("%d", &rc.acceleration);
    printf("Enter brake (0-10): ");
    scanf("%d", &rc.brake);
    return rc;
}

void applyRemoteControl(RemoteControl rc, int *speed, int *turn) {
    *speed += rc.speed;
    *turn += rc.turn;
}

void limitRemoteControl(RemoteControl *rc) {
    if (rc->speed > MAX_SPEED) {
        rc->speed = MAX_SPEED;
    } else if (rc->speed < MIN_SPEED) {
        rc->speed = MIN_SPEED;
    }

    if (rc->turn > MAX_TURN) {
        rc->turn = MAX_TURN;
    } else if (rc->turn < MIN_TURN) {
        rc->turn = MIN_TURN;
    }

    if (rc->acceleration > MAX_ACCELERATION) {
        rc->acceleration = MAX_ACCELERATION;
    } else if (rc->acceleration < MIN_ACCELERATION) {
        rc->acceleration = MIN_ACCELERATION;
    }

    if (rc->brake > MAX_BRAKE) {
        rc->brake = MAX_BRAKE;
    } else if (rc->brake < MIN_BRAKE) {
        rc->brake = MIN_BRAKE;
    }
}

int main() {
    srand(time(NULL));
    int speed = 0;
    int turn = 0;
    int acceleration = 0;
    int brake = 0;

    while (1) {
        RemoteControl rc = readRemoteControl();
        applyRemoteControl(rc, &speed, &turn);
        limitRemoteControl(&rc);
        printf("Speed: %d\n", speed);
        printf("Turn: %d\n", turn);
        printf("Acceleration: %d\n", acceleration);
        printf("Brake: %d\n", brake);
        printf("\n");
        usleep(100000);
    }

    return 0;
}