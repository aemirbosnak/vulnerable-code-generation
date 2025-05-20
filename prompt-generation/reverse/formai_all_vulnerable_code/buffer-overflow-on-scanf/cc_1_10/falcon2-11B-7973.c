//Falcon2-11B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: real-life
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct car {
    int x;
    int y;
    int speed;
    bool is_turning;
};

void turn_left(struct car* car) {
    car->is_turning = true;
    car->speed = 0;
}

void turn_right(struct car* car) {
    car->is_turning = true;
    car->speed = 0;
}

void go_forward(struct car* car) {
    car->speed++;
    car->is_turning = false;
}

void go_backward(struct car* car) {
    car->speed--;
    car->is_turning = false;
}

void stop(struct car* car) {
    car->speed = 0;
    car->is_turning = false;
}

void move(struct car* car) {
    if (car->is_turning) {
        if (car->speed > 0) {
            turn_left(car);
        } else {
            turn_right(car);
        }
    } else if (car->speed > 0) {
        go_forward(car);
    } else if (car->speed < 0) {
        go_backward(car);
    } else {
        stop(car);
    }
}

int main() {
    struct car car;
    car.x = 0;
    car.y = 0;
    car.speed = 0;
    car.is_turning = false;

    printf("Remote control vehicle simulation\n");
    printf("-------------------------------\n");
    printf("X: %d, Y: %d, Speed: %d, Turning: %s\n", car.x, car.y, car.speed, car.is_turning? "True" : "False");

    while (true) {
        printf("Enter command: ");
        char command;
        scanf("%c", &command);

        switch (command) {
            case 'w':
                go_forward(&car);
                break;
            case's':
                go_backward(&car);
                break;
            case 'a':
                turn_left(&car);
                break;
            case 'd':
                turn_right(&car);
                break;
            case 'z':
                stop(&car);
                break;
            case 'q':
                printf("Quitting...\n");
                return 0;
            default:
                printf("Invalid command\n");
        }

        move(&car);
        printf("X: %d, Y: %d, Speed: %d, Turning: %s\n", car.x, car.y, car.speed, car.is_turning? "True" : "False");
    }

    return 0;
}