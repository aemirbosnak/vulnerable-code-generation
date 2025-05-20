//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point position;
    int speed;
    bool direction;
} Car;

int main() {
    Car remoteControlCar = {{0, 0}, 0, true};

    while (true) {
        printf("Enter direction and speed (eg: A12): ");
        char direction;
        int speed;
        scanf("%c%d", &direction, &speed);

        printf("\n");

        if (direction == 'A') {
            if (remoteControlCar.direction == true) {
                remoteControlCar.position.x += speed;
            }
            else {
                remoteControlCar.position.x -= speed;
            }
        }
        else if (direction == 'B') {
            if (remoteControlCar.direction == true) {
                remoteControlCar.position.y += speed;
            }
            else {
                remoteControlCar.position.y -= speed;
            }
        }
        else if (direction == 'C') {
            remoteControlCar.speed = speed;
        }
        else if (direction == 'D') {
            remoteControlCar.direction = !remoteControlCar.direction;
        }

        printf("Position: (%d, %d)\n", remoteControlCar.position.x, remoteControlCar.position.y);
        printf("Speed: %d\n", remoteControlCar.speed);
        printf("Direction: %s\n", remoteControlCar.direction ? "Forward" : "Backward");

        printf("---------------------------------------\n");
    }

    return 0;
}