//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265358979323846
#define RADIUS 6371e3
#define DEG_TO_RAD 0.01745329251994329576923690768489
#define RAD_TO_DEG 57.295779513082320876798154814105

typedef struct {
    double lat;
    double lon;
    double alt;
    double vel;
    double acc;
    double yaw;
} vehicle_t;

void init_vehicle(vehicle_t *v) {
    v->lat = 0;
    v->lon = 0;
    v->alt = 0;
    v->vel = 0;
    v->acc = 0;
    v->yaw = 0;
}

void update_vehicle(vehicle_t *v, double dt) {
    v->vel += v->acc * dt;
    v->alt += v->vel * dt;
    v->lon += v->vel * cos(v->yaw) * dt;
    v->lat += v->vel * sin(v->yaw) * dt;
}

void set_acceleration(vehicle_t *v, double acc) {
    v->acc = acc;
}

void set_yaw(vehicle_t *v, double yaw) {
    v->yaw = yaw;
}

void main() {
    vehicle_t v;
    init_vehicle(&v);

    double dt = 0.01;

    while (1) {
        printf("Enter acceleration (m/s^2): ");
        scanf("%lf", &v.acc);

        printf("Enter yaw rate (rad/s): ");
        scanf("%lf", &v.yaw);

        update_vehicle(&v, dt);

        double lat_rad = v.lat * DEG_TO_RAD;
        double lon_rad = v.lon * DEG_TO_RAD;
        double alt_km = v.alt / 1000;

        double lat_deg = lat_rad * RAD_TO_DEG;
        double lon_deg = lon_rad * RAD_TO_DEG;
        double alt_m = alt_km * 1000;

        printf("Latitude: %.6f degrees\n", lat_deg);
        printf("Longitude: %.6f degrees\n", lon_deg);
        printf("Altitude: %.0f meters\n", alt_m);

        printf("Press any key to continue...\n");
        getchar();
    }
}