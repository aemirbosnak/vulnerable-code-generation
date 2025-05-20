//MISTRAL-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x, y;
    int speed;
    char direction;
} Car;

void moveCar(Car *car, char direction, int speed) {
    switch (direction) {
        case 'N':
            car->y += speed;
            break;
        case 'S':
            car->y -= speed;
            break;
        case 'E':
            car->x += speed;
            break;
        case 'W':
            car->x -= speed;
            break;
        default:
            printf("Invalid direction!\n");
            break;
    }
}

void printCarPosition(Car car) {
    printf("Car position: (%d, %d)\n", car.x, car.y);
}

int main() {
    Car car = {0, 0, 0};

    char command;
    int speed;

    while (1) {
        printf("Enter command (N/S/E/W/Q): ");
        scanf("%c", &command);

        if (command == 'Q') {
            break;
        }

        printf("Enter speed: ");
        scanf("%d", &speed);

        moveCar(&car, command, speed);
        printCarPosition(car);
    }

    return 0;
}