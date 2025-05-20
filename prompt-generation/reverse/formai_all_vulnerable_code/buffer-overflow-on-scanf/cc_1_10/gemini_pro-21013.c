//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// Remote control car structure
typedef struct car {
    int speed;
    int direction;
    int x;
    int y;
} car_t;

// Remote control car simulation thread
void *car_simulation(void *arg) {
    car_t *car = (car_t *)arg;

    while (1) {
        // Update the car's position based on its speed and direction
        car->x += car->speed * cos(car->direction);
        car->y += car->speed * sin(car->direction);

        // Wrap the car around the edge of the screen if it goes off the edge
        if (car->x < 0) car->x = 800;
        if (car->x > 800) car->x = 0;
        if (car->y < 0) car->y = 600;
        if (car->y > 600) car->y = 0;

        // Sleep for a short period of time to simulate the car's movement
        usleep(10000);
    }

    return NULL;
}

// Main function
int main(int argc, char *argv[]) {
    // Create a new remote control car
    car_t car;
    car.speed = 0;
    car.direction = 0;
    car.x = 400;
    car.y = 300;

    // Create a new thread to simulate the car's movement
    pthread_t thread;
    pthread_create(&thread, NULL, car_simulation, &car);

    // Main loop
    while (1) {
        // Get the user's input
        char input;
        scanf("%c", &input);

        // Update the car's speed and direction based on the user's input
        switch (input) {
            case 'w':
                car.speed += 1;
                break;
            case 's':
                car.speed -= 1;
                break;
            case 'a':
                car.direction -= 0.1;
                break;
            case 'd':
                car.direction += 0.1;
                break;
        }

        // Draw the car on the screen
        printf("\033[2J");
        printf("\033[0;0H");
        for (int i = 0; i < 600; i++) {
            for (int j = 0; j < 800; j++) {
                if (i == car.y && j == car.x) {
                    printf("X");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }

    // Join the simulation thread
    pthread_join(thread, NULL);

    return 0;
}