//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 50
#define MIN_SPEED 0
#define NUM_DIRECTIONS 4
#define NUM_SENSORS 3
#define SENSOR_RANGE 10

typedef struct {
    int speed;
    int direction;
    int sensor_values[NUM_SENSORS];
} vehicle_t;

void initialize_vehicle(vehicle_t* v) {
    v->speed = MIN_SPEED;
    v->direction = 0;
    for (int i = 0; i < NUM_SENSORS; i++) {
        v->sensor_values[i] = 0;
    }
}

void print_sensor_values(vehicle_t* v) {
    for (int i = 0; i < NUM_SENSORS; i++) {
        printf("Sensor %d: %d\n", i+1, v->sensor_values[i]);
    }
}

void update_sensor_values(vehicle_t* v) {
    for (int i = 0; i < NUM_SENSORS; i++) {
        v->sensor_values[i] = rand() % SENSOR_RANGE;
    }
}

void move_vehicle(vehicle_t* v, int speed, int direction) {
    v->speed = speed;
    v->direction = direction;
}

int main() {
    srand(time(NULL));

    vehicle_t vehicle;
    initialize_vehicle(&vehicle);

    while (1) {
        system("clear");

        printf("Current speed: %d\n", vehicle.speed);
        printf("Current direction: %d\n", vehicle.direction);
        print_sensor_values(&vehicle);

        int choice;
        printf("Choose an action:\n");
        printf("1. Move forward\n");
        printf("2. Turn left\n");
        printf("3. Turn right\n");
        printf("4. Stop\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                move_vehicle(&vehicle, vehicle.speed+1, vehicle.direction);
                break;
            case 2:
                move_vehicle(&vehicle, vehicle.speed, (vehicle.direction-1)%NUM_DIRECTIONS);
                break;
            case 3:
                move_vehicle(&vehicle, vehicle.speed, (vehicle.direction+1)%NUM_DIRECTIONS);
                break;
            case 4:
                move_vehicle(&vehicle, MIN_SPEED, vehicle.direction);
                break;
            default:
                printf("Invalid choice.\n");
        }

        update_sensor_values(&vehicle);
    }

    return 0;
}