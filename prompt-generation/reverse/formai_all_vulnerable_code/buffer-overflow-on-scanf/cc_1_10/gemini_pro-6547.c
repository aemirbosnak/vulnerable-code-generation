//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

#define COMMAND_STOP 0
#define COMMAND_FORWARD 1
#define COMMAND_BACKWARD 2
#define COMMAND_LEFT 3
#define COMMAND_RIGHT 4

struct rc_car {
    int speed;
    int direction;
    bool running;
    pthread_t thread;
};

struct rc_car *create_car(int speed, int direction)
{
    struct rc_car *car = malloc(sizeof(struct rc_car));
    car->speed = speed;
    car->direction = direction;
    car->running = false;
    return car;
}

void destroy_car(struct rc_car *car)
{
    free(car);
}

void *car_run(void *arg)
{
    struct rc_car *car = arg;

    while (car->running) {
        // Simulate driving the car based on the speed and direction
        usleep(1000000 / car->speed);
    }

    return NULL;
}

int main()
{
    int speed = 5;
    int direction = 0;

    struct rc_car *car = create_car(speed, direction);

    // Start the car
    car->running = true;
    pthread_create(&car->thread, NULL, car_run, car);

    // Simulate remote control inputs
    while (true) {
        int command;
        scanf("%d", &command);

        switch (command) {
            case COMMAND_STOP:
                car->running = false;
                pthread_join(car->thread, NULL);
                destroy_car(car);
                return 0;
            case COMMAND_FORWARD:
                car->direction = 0;
                break;
            case COMMAND_BACKWARD:
                car->direction = 180;
                break;
            case COMMAND_LEFT:
                car->direction -= 90;
                if (car->direction < 0)
                    car->direction += 360;
                break;
            case COMMAND_RIGHT:
                car->direction += 90;
                if (car->direction >= 360)
                    car->direction -= 360;
                break;
        }
    }

    return 0;
}