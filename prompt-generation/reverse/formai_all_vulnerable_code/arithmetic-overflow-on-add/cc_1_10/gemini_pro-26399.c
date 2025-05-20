//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 100
#define MAX_HEIGHT 100
#define MAX_ROTATION 180

struct drone {
    int speed;
    int height;
    int rotation;
};

void takeoff(struct drone *drone) {
    drone->speed = 0;
    drone->height = 0;
    drone->rotation = 0;
}

void land(struct drone *drone) {
    drone->speed = 0;
    drone->height = 0;
    drone->rotation = 0;
}

void up(struct drone *drone) {
    if (drone->height < MAX_HEIGHT) {
        drone->height++;
    }
}

void down(struct drone *drone) {
    if (drone->height > 0) {
        drone->height--;
    }
}

void forward(struct drone *drone) {
    if (drone->speed < MAX_SPEED) {
        drone->speed++;
    }
}

void backward(struct drone *drone) {
    if (drone->speed > 0) {
        drone->speed--;
    }
}

void left(struct drone *drone) {
    if (drone->rotation < MAX_ROTATION) {
        drone->rotation++;
    }
}

void right(struct drone *drone) {
    if (drone->rotation > 0) {
        drone->rotation--;
    }
}

void print_drone_status(struct drone *drone) {
    printf("Speed: %d\n", drone->speed);
    printf("Height: %d\n", drone->height);
    printf("Rotation: %d\n", drone->rotation);
}

void delay(int milliseconds) {
    clock_t start_time = clock();

    while (clock() < start_time + milliseconds) {
        ;
    }
}

int main() {
    struct drone drone;

    takeoff(&drone);

    for (int i = 0; i < 10; i++) {
        up(&drone);
        delay(100);
    }

    for (int i = 0; i < 10; i++) {
        forward(&drone);
        delay(100);
    }

    for (int i = 0; i < 10; i++) {
        right(&drone);
        delay(100);
    }

    for (int i = 0; i < 10; i++) {
        down(&drone);
        delay(100);
    }

    for (int i = 0; i < 10; i++) {
        backward(&drone);
        delay(100);
    }

    for (int i = 0; i < 10; i++) {
        left(&drone);
        delay(100);
    }

    land(&drone);

    print_drone_status(&drone);

    return 0;
}