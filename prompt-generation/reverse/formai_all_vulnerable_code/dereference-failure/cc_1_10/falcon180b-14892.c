//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define GREEN 1
#define YELLOW 2
#define RED 3

#define PI 3.14159265358979323846

typedef struct {
    int state;
    double time_left;
} traffic_light;

traffic_light* create_light(int state) {
    traffic_light* light = (traffic_light*) malloc(sizeof(traffic_light));
    light->state = state;
    light->time_left = 0;
    return light;
}

void destroy_light(traffic_light* light) {
    free(light);
}

void change_state(traffic_light* light, int state) {
    light->state = state;
    light->time_left = PI / (double) state;
}

int get_state(traffic_light* light) {
    return light->state;
}

double get_time_left(traffic_light* light) {
    return light->time_left;
}

void update_time(traffic_light* light) {
    light->time_left -= 0.1;
    if (light->time_left <= 0) {
        change_state(light, (light->state + 1) % 3);
        light->time_left = PI / (double) light->state;
    }
}

int main() {
    traffic_light* light = create_light(GREEN);
    int state = GREEN;
    double time_left = PI / (double) state;

    while (1) {
        printf("State: %d, Time left: %.2f\n", state, time_left);
        update_time(light);
        state = get_state(light);
        time_left = get_time_left(light);
        sleep(1);
    }

    destroy_light(light);
    return 0;
}