//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 1
#define GREEN 2
#define YELLOW 3
#define PEDESTRIAN_RED 4
#define PEDESTRIAN_GREEN 5

typedef struct {
    int state;
    int duration;
    time_t start_time;
} traffic_light_t;

void init_traffic_light(traffic_light_t* light) {
    light->state = RED;
    light->duration = 30;
    light->start_time = time(NULL);
}

void change_traffic_light(traffic_light_t* light) {
    time_t current_time = time(NULL);
    if (light->state == RED) {
        if (current_time - light->start_time >= light->duration) {
            light->state = GREEN;
            light->duration = 30;
            light->start_time = current_time;
        }
    } else if (light->state == GREEN) {
        if (current_time - light->start_time >= light->duration) {
            light->state = YELLOW;
            light->duration = 3;
            light->start_time = current_time;
        }
    } else if (light->state == YELLOW) {
        if (current_time - light->start_time >= light->duration) {
            light->state = RED;
            light->duration = 30;
            light->start_time = current_time;
        }
    } else if (light->state == PEDESTRIAN_RED) {
        if (current_time - light->start_time >= light->duration) {
            light->state = PEDESTRIAN_GREEN;
            light->duration = 30;
            light->start_time = current_time;
        }
    } else {
        if (current_time - light->start_time >= light->duration) {
            light->state = PEDESTRIAN_RED;
            light->duration = 30;
            light->start_time = current_time;
        }
    }
}

int main() {
    traffic_light_t light;
    init_traffic_light(&light);

    while (1) {
        change_traffic_light(&light);
        printf("Current state: ");
        if (light.state == RED) {
            printf("RED\n");
        } else if (light.state == GREEN) {
            printf("GREEN\n");
        } else if (light.state == YELLOW) {
            printf("YELLOW\n");
        } else if (light.state == PEDESTRIAN_RED) {
            printf("PEDESTRIAN RED\n");
        } else {
            printf("PEDESTRIAN GREEN\n");
        }
        sleep(1);
    }

    return 0;
}