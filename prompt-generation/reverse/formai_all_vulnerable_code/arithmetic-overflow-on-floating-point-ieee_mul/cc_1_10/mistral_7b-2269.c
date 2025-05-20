//MISTRAL-7B DATASET v1.0 Category: GPS Navigation Simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#define PI M_PI

typedef struct { double lat, lon; } point;

void encrypt_coords(point* p, char* key) {
    int shift = 0;
    char* ptr = key;
    p->lat = fmod(p->lat + atof(ptr++) * PI / 180, PI * 2);
    shift = atoi(ptr++);
    p->lon = fmod(p->lon + atof(ptr++) * PI / 180, PI * 2);
    p->lat -= shift * PI / 180;
}

point decode_coords(point p, char* key) {
    int shift = 0;
    char* ptr = key;
    point q;
    q.lat = fmod(p.lat + shift * PI / 180, PI * 2);
    shift = atoi(ptr++);
    q.lon = fmod(p.lon + atof(ptr++) * PI / 180, PI * 2);
    q.lat -= shift * PI / 180;
    return q;
}

int main() {
    point start, goal, current;
    char key[20] = "27 01 N, 083 30 E, 12 28 N, 175 11 E";

    start.lat = 51.5074;
    start.lon = -0.0896;
    encrypt_coords(&start, key);

    goal.lat = 54.3562;
    goal.lon = -2.7963;
    encrypt_coords(&goal, key);

    current.lat = 51.5418;
    current.lon = -0.0123;
    encrypt_coords(&current, key);

    double dlat, dlon, dist;
    dlat = goal.lat - current.lat;
    dlon = fmod(goal.lon - current.lon, 2 * PI);

    dist = sqrt(pow(dlat, 2) + pow(dlon, 2) * cos(current.lat) * cos(goal.lat));

    printf("Current position: (%f, %f)\n", current.lat, current.lon);
    printf("Goal position: (%f, %f)\n", goal.lat, goal.lon);
    printf("Distance to goal: %.2f km\n", dist * 1.609344);

    while (dist > 0.01) {
        double newlat, newlon;
        current.lat += sin(PI / 24) * dist;
        current.lon += cos(current.lat) * asin(dist / sqrt(pow(sin(dlat), 2) + pow(sin(dlon), 2) * cos(current.lat) * cos(goal.lat))) * cos(current.lon - goal.lon);
        encrypt_coords(&current, key);
        dist -= 0.01;
    }

    printf("New position: (%f, %f)\n", current.lat, current.lon);

    return 0;
}