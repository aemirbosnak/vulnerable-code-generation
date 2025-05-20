//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 24
#define SPEED 5
#define DELAY 100000

// Define the remote control car
typedef struct {
    int x, y;
    int dir;
} Car;

// Initialize the car at the starting position
void init_car() {
    Car car = {0, HEIGHT / 2, 1};
    car.x = rand() % WIDTH;
    car.y = HEIGHT - 1;
    printf("Car initialized at (%d,%d)\n", car.x, car.y);
}

// Print the car on the screen
void draw_car(Car car) {
    int i = car.y - 1;
    while (i >= 0) {
        printf("  ");
        i--;
    }
    printf("O");
}

// Move the car forward
void move_forward(Car *car) {
    car->y--;
    if (car->y < 0) {
        car->y = HEIGHT - 1;
    }
}

// Turn the car left
void turn_left(Car *car) {
    car->dir = (car->dir + 3) % 4;
}

// Turn the car right
void turn_right(Car *car) {
    car->dir = (car->dir + 1) % 4;
}

// Handle user input
void handle_input(Car *car) {
    char input;
    printf("Enter command (w/a/s/d): ");
    scanf("%c", &input);
    switch (input) {
        case 'w':
        case 'W':
            move_forward(car);
            break;
        case 'a':
        case 'A':
            turn_left(car);
            break;
        case's':
        case 'S':
            turn_right(car);
            break;
        case 'd':
        case 'D':
            move_forward(car);
            turn_right(car);
            break;
        default:
            printf("Invalid command\n");
    }
}

// Main function
int main() {
    srand(time(NULL));
    init_car();
    Car car = {0, HEIGHT / 2, 1};
    while (1) {
        system("clear");
        draw_car(car);
        handle_input(&car);
        usleep(DELAY);
    }
    return 0;
}