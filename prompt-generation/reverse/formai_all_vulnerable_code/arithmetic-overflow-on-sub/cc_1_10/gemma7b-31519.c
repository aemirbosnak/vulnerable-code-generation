//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_Cars 10
#define MAX_Lights 5

typedef struct Car {
    int x, y, direction, speed;
    struct Car* next;
} Car;

typedef struct Light {
    int state, next_state;
    struct Light* next;
} Light;

Light* create_light(int state, int next_state) {
    Light* light = malloc(sizeof(Light));
    light->state = state;
    light->next_state = next_state;
    light->next = NULL;
    return light;
}

Car* create_car(int x, int y, int direction, int speed) {
    Car* car = malloc(sizeof(Car));
    car->x = x;
    car->y = y;
    car->direction = direction;
    car->speed = speed;
    car->next = NULL;
    return car;
}

void simulate_traffic(Car* head, Light* head_light) {
    time_t t = time(NULL);
    while (time(NULL) - t < 10) {
        for (Car* car = head; car; car = car->next) {
            switch (car->direction) {
                case 0:
                    car->x++;
                    break;
                case 1:
                    car->y++;
                    break;
                case 2:
                    car->x--;
                    break;
                case 3:
                    car->y--;
                    break;
            }

            if (car->speed > 0) {
                car->speed--;
            } else {
                car->speed = 0;
            }

            switch (head_light->state) {
                case 0:
                    if (car->x % 2 == 0) {
                        car->speed = 2;
                        head_light->next_state = 1;
                    }
                    break;
                case 1:
                    if (car->x % 2 == 1) {
                        car->speed = 2;
                        head_light->next_state = 0;
                    }
                    break;
            }
        }

        head_light->state = head_light->next_state;
        sleep(1);
    }
}

int main() {
    Car* head = create_car(0, 0, 0, 2);
    Light* head_light = create_light(0, 1);

    simulate_traffic(head, head_light);

    return 0;
}