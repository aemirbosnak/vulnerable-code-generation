//MISTRAL-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CAR_MAX_SPEED 10
#define CAR_MIN_SPEED 0
#define CAR_TURN_ANGLE 20

typedef struct {
    int x, y;
    int speed;
    int direction;
} Car;

void car_move(Car *car) {
    car->speed += 1;
    if (car->speed > CAR_MAX_SPEED) {
        car->speed = CAR_MAX_SPEED;
    }
    if (car->direction == 1) {
        car->y += car->speed;
    } else if (car->direction == 2) {
        car->x -= car->speed;
    }
}

void car_turn(Car *car, int angle) {
    car->direction += angle;
    if (car->direction > 3) {
        car->direction -= 3;
    } else if (car->direction < 0) {
        car->direction += 3;
    }
}

int main() {
    Car car = {0, 0, 1};
    int key;

    srand(time(NULL));

    while (1) {
        printf("Position: (%d, %d)\n", car.x, car.y);
        printf("Speed: %d\n", car.speed);
        printf("Direction: %d\n", car.direction);
        printf("Press a key to control the car:\n1) Forward\n2) Backward\n3) Left\n4) Right\n");
        scanf("%d", &key);

        switch (key) {
            case 1:
                car_move(&car);
                car_turn(&car, 0);
                break;
            case 2:
                car_turn(&car, 180);
                car_move(&car);
                break;
            case 3:
                car_turn(&car, -CAR_TURN_ANGLE);
                break;
            case 4:
                car_turn(&car, CAR_TURN_ANGLE);
                break;
            default:
                printf("Invalid key!\n");
                break;
        }

        // Add some randomness to the simulation
        if (rand() % 100 < 50) {
            int rand_speed = rand() % (CAR_MAX_SPEED + 1);
            car.speed = rand_speed;
        }
    }

    return 0;
}