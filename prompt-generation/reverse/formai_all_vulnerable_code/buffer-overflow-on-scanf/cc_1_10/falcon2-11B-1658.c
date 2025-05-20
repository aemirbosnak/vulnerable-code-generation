//Falcon2-11B DATASET v1.0 Category: Drone Remote Control ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

struct Drone {
    int x;
    int y;
    int z;
};

struct RemoteControl {
    struct Drone* drone;
    int motorPower;
    int direction;
};

struct Drone* createDrone(int x, int y, int z) {
    struct Drone* drone = (struct Drone*) malloc(sizeof(struct Drone));
    drone->x = x;
    drone->y = y;
    drone->z = z;
    return drone;
}

struct RemoteControl* createRemoteControl(struct Drone* drone, int motorPower, int direction) {
    struct RemoteControl* remoteControl = (struct RemoteControl*) malloc(sizeof(struct RemoteControl));
    remoteControl->drone = drone;
    remoteControl->motorPower = motorPower;
    remoteControl->direction = direction;
    return remoteControl;
}

void moveDrone(struct RemoteControl* remoteControl) {
    int x = remoteControl->drone->x + (remoteControl->direction * remoteControl->motorPower);
    int y = remoteControl->drone->y + (remoteControl->direction * remoteControl->motorPower);
    int z = remoteControl->drone->z + (remoteControl->direction * remoteControl->motorPower);
    remoteControl->drone->x = x;
    remoteControl->drone->y = y;
    remoteControl->drone->z = z;
}

int main() {
    struct Drone* drone = createDrone(0, 0, 0);
    struct RemoteControl* remoteControl = createRemoteControl(drone, 50, 1);

    while (1) {
        printf("Enter direction (1/2/3/4 for up/down/left/right): ");
        int direction;
        scanf("%d", &direction);

        moveDrone(remoteControl);
        printf("Drone position: (%d, %d, %d)\n", remoteControl->drone->x, remoteControl->drone->y, remoteControl->drone->z);

        printf("Enter motor power (1-100): ");
        int motorPower;
        scanf("%d", &motorPower);

        moveDrone(remoteControl);
        printf("Drone position: (%d, %d, %d)\n", remoteControl->drone->x, remoteControl->drone->y, remoteControl->drone->z);
    }

    return 0;
}