#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 10
#define FORWARD 1
#define REVERSE -1
#define QUIT 0

typedef struct {
    int speed;
    int direction;
    int distance;
    clock_t start_time;
} Car;

void update_distance(Car *car) {
    clock_t current_time = clock();
    double elapsed_time = (current_time - car->start_time) / CLOCKS_PER_SEC;
    car->distance += elapsed_time * car->speed * abs(car->direction);
}

void print_car_state(const Car *car) {
    printf("Speed: %d\n", car->speed);
    printf("Direction: %s\n", car->direction > 0 ? "Forward" : "Reverse");
    printf("Distance: %d\n", car->distance);
    printf("Elapsed Time: %.2fs\n", (clock() - car->start_time) / CLOCKS_PER_SEC);
}

int main() {
    Car car = { .speed = 0, .direction = 0, .distance = 0, .start_time = clock() };

    int command;
    while ((command = getchar()) != QUIT) {
        switch (command) {
            case '+':
                car.speed = (car.speed + 1) % MAX_SPEED;
                break;
            case '-':
                car.speed = (car.speed - 1 + MAX_SPEED) % MAX_SPEED;
                break;
            case 'f':
                car.direction = FORWARD;
                break;
            case 'r':
                car.direction = REVERSE;
                break;
        }
        update_distance(&car);
        print_car_state(&car);
    }

    return 0;
}
