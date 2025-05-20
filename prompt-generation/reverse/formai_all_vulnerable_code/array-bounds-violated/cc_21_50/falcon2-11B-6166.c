//Falcon2-11B DATASET v1.0 Category: Drone Remote Control ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_HEIGHT 100
#define MAX_SPEED 10
#define MIN_SPEED 1

#define LEFT_POT 0
#define RIGHT_POT 1
#define UP_POT 2
#define DOWN_POT 3

#define RIGHT_TRIGGER 4
#define LEFT_TRIGGER 5
#define TOP_TRIGGER 6
#define BOTTOM_TRIGGER 7

int main(void) {
    int pot[4] = {0, 0, 0, 0};
    int trigger[4] = {0, 0, 0, 0};
    int speed = 0;
    int height = 0;
    int direction = 0;
    int max_height = MAX_HEIGHT;
    int max_speed = MAX_SPEED;
    int min_speed = MIN_SPEED;

    srand(time(NULL));

    printf("Press 1 to move left, 2 to move right, 3 to move up, 4 to move down\n");
    printf("Press 5 to increase speed, 6 to decrease speed\n");
    printf("Press 7 to go up, 8 to go down, 9 to go left, 0 to go right\n");
    printf("Press * to toggle the direction of movement\n");
    printf("Press # to toggle the height limit\n");
    printf("Press $ to toggle the speed limit\n");
    printf("Press 0 to exit\n");

    while (1) {
        int key = getchar();
        if (key == '1') {
            pot[LEFT_POT] = 1;
            pot[RIGHT_POT] = 0;
            pot[UP_POT] = 0;
            pot[DOWN_POT] = 0;
            speed = 0;
        } else if (key == '2') {
            pot[LEFT_POT] = 0;
            pot[RIGHT_POT] = 1;
            pot[UP_POT] = 0;
            pot[DOWN_POT] = 0;
            speed = 0;
        } else if (key == '3') {
            pot[LEFT_POT] = 0;
            pot[RIGHT_POT] = 0;
            pot[UP_POT] = 1;
            pot[DOWN_POT] = 0;
            speed = 0;
        } else if (key == '4') {
            pot[LEFT_POT] = 0;
            pot[RIGHT_POT] = 0;
            pot[UP_POT] = 0;
            pot[DOWN_POT] = 1;
            speed = 0;
        } else if (key == '5') {
            speed++;
            if (speed > max_speed) {
                speed = max_speed;
            }
        } else if (key == '6') {
            speed--;
            if (speed < min_speed) {
                speed = min_speed;
            }
        } else if (key == '7') {
            height++;
            if (height > max_height) {
                height = max_height;
            }
        } else if (key == '8') {
            height--;
            if (height < 0) {
                height = 0;
            }
        } else if (key == '9') {
            direction = 1;
            direction ^= 1;
        } else if (key == '0') {
            direction = 0;
            direction ^= 1;
        } else if (key == '*') {
            direction =!direction;
        } else if (key == '#') {
            max_height =!max_height;
        } else if (key == '$') {
            max_speed =!max_speed;
        } else if (key == '0') {
            break;
        }

        printf("Pot %d: %d\n", LEFT_POT, pot[LEFT_POT]);
        printf("Pot %d: %d\n", RIGHT_POT, pot[RIGHT_POT]);
        printf("Pot %d: %d\n", UP_POT, pot[UP_POT]);
        printf("Pot %d: %d\n", DOWN_POT, pot[DOWN_POT]);
        printf("Trigger %d: %d\n", RIGHT_TRIGGER, trigger[RIGHT_TRIGGER]);
        printf("Trigger %d: %d\n", LEFT_TRIGGER, trigger[LEFT_TRIGGER]);
        printf("Trigger %d: %d\n", TOP_TRIGGER, trigger[TOP_TRIGGER]);
        printf("Trigger %d: %d\n", BOTTOM_TRIGGER, trigger[BOTTOM_TRIGGER]);
        printf("Speed: %d\n", speed);
        printf("Height: %d\n", height);
        printf("Direction: %d\n", direction);

        int x_change = speed;
        int y_change = 0;
        if (direction) {
            y_change = -speed;
            x_change = 0;
        }

        int new_height = height + y_change;
        if (new_height > max_height) {
            new_height = max_height;
        }

        int new_speed = speed + x_change;
        if (new_speed > max_speed) {
            new_speed = max_speed;
        } else if (new_speed < min_speed) {
            new_speed = min_speed;
        }

        height = new_height;
        speed = new_speed;

        usleep(1000);
    }

    return 0;
}