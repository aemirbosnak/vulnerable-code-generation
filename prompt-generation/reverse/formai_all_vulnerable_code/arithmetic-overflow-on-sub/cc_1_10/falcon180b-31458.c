//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define NUM_LIGHTS 4
#define RED_LIGHT 1
#define YELLOW_LIGHT 2
#define GREEN_LIGHT 3
#define PEDESTRIAN_LIGHT 4
#define LIGHT_DURATION 10 // seconds
#define PEDESTRIAN_DURATION 20 // seconds

typedef struct {
    int id;
    int duration;
    int current_state;
    time_t last_change_time;
} Light;

Light lights[NUM_LIGHTS];

void initialize_lights() {
    for (int i = 0; i < NUM_LIGHTS; i++) {
        lights[i].id = i;
        lights[i].duration = LIGHT_DURATION;
        lights[i].current_state = RED_LIGHT;
        lights[i].last_change_time = 0;
    }
}

void change_light(int light_id, int new_state) {
    lights[light_id].current_state = new_state;
    lights[light_id].last_change_time = time(NULL);
}

int main() {
    initialize_lights();

    while (true) {
        time_t current_time = time(NULL);

        for (int i = 0; i < NUM_LIGHTS; i++) {
            if (current_time - lights[i].last_change_time >= lights[i].duration) {
                switch (lights[i].current_state) {
                    case RED_LIGHT:
                        change_light(i, YELLOW_LIGHT);
                        break;
                    case YELLOW_LIGHT:
                        change_light(i, GREEN_LIGHT);
                        break;
                    case GREEN_LIGHT:
                        change_light(i, RED_LIGHT);
                        break;
                    case PEDESTRIAN_LIGHT:
                        change_light(i, RED_LIGHT);
                        break;
                }
            }
        }

        sleep(1);
    }

    return 0;
}