//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum { UP, DOWN, LEFT, RIGHT } Direction;

typedef struct {
    int x;
    int y;
} Position;

int main() {
    int size = 10; // size of the simulation area
    Position car = { rand() % size, rand() % size }; // starting position of the car
    Direction direction = UP; // starting direction of the car
    int distance = 0; // starting distance the car has traveled
    srand(time(NULL)); // seed the random generator with the current time

    // main loop of the simulation
    while (1) {
        // print out the current state of the simulation
        system("clear"); // clear the console screen
        printf("Distance: %d\n", distance);
        printf("+"); // top of the simulation area
        for (int i = 0; i < size; i++) {
            printf("-");
        }
        printf("+\n");
        for (int i = 0; i < size; i++) {
            printf("|"); // left border of the simulation area
            for (int j = 0; j < size; j++) {
                if (i == car.y && j == car.x) {
                    printf("O"); // the car
                }
                else {
                    printf(" ");
                }
            }
            printf("|\n"); // right border of the simulation area
        }
        printf("+");
        for (int i = 0; i < size; i++) {
            printf("-");
        }
        printf("+\n");

        // ask the user for input
        char input;
        printf("Enter input: ");
        scanf(" %c", &input);

        // move the car according to the input
        switch (input) {
        case 'w':
            direction = UP;
            break;
        case 'a':
            direction = LEFT;
            break;
        case 's':
            direction = DOWN;
            break;
        case 'd':
            direction = RIGHT;
            break;
        default:
            break;
        }
        switch (direction) {
        case UP:
            car.y--;
            break;
        case DOWN:
            car.y++;
            break;
        case LEFT:
            car.x--;
            break;
        case RIGHT:
            car.x++;
            break;
        }

        // make sure the car stays within the simulation area
        if (car.x < 0) car.x = 0;
        if (car.x >= size) car.x = size - 1;
        if (car.y < 0) car.y = 0;
        if (car.y >= size) car.y = size - 1;

        // increment the distance the car has traveled
        distance++;

        // check if the car has reached the edge of the simulation area
        if (car.x == 0 || car.x == size - 1 || car.y == 0 || car.y == size - 1) {
            printf("Congratulations! You have reached the edge of the simulation area in %d moves.\n", distance);
            break;
        }
    }

    return 0;
}