//Falcon2-11B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PI 3.14159265

typedef struct {
    int x;
    int y;
    int z;
    int w;
    int vx;
    int vy;
    int vz;
    int ax;
    int ay;
    int az;
} vehicle_t;

vehicle_t vehicle;

void update_vehicle_position(vehicle_t* v, int x, int y, int z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

void update_vehicle_velocity(vehicle_t* v, int vx, int vy, int vz) {
    v->vx = vx;
    v->vy = vy;
    v->vz = vz;
}

void update_vehicle_acceleration(vehicle_t* v, int ax, int ay, int az) {
    v->ax = ax;
    v->ay = ay;
    v->az = az;
}

void display_vehicle_info(vehicle_t* v) {
    printf("X: %d, Y: %d, Z: %d\n", v->x, v->y, v->z);
    printf("Vx: %d, Vy: %d, Vz: %d\n", v->vx, v->vy, v->vz);
    printf("Ax: %d, Ay: %d, Az: %d\n", v->ax, v->ay, v->az);
}

int main() {
    srand(time(NULL));

    vehicle = (vehicle_t){0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    while (1) {
        printf("Enter x, y, z (or 0, 0, 0 to stop): ");
        scanf("%d, %d, %d", &vehicle.x, &vehicle.y, &vehicle.z);

        if (vehicle.x == 0 && vehicle.y == 0 && vehicle.z == 0) {
            break;
        }

        vehicle.vx = rand() % 5 - 2;
        vehicle.vy = rand() % 5 - 2;
        vehicle.vz = rand() % 5 - 2;

        vehicle.ax = rand() % 5 - 2;
        vehicle.ay = rand() % 5 - 2;
        vehicle.az = rand() % 5 - 2;

        update_vehicle_position(&vehicle, vehicle.x, vehicle.y, vehicle.z);
        update_vehicle_velocity(&vehicle, vehicle.vx, vehicle.vy, vehicle.vz);
        update_vehicle_acceleration(&vehicle, vehicle.ax, vehicle.ay, vehicle.az);

        display_vehicle_info(&vehicle);
    }

    return 0;
}