//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED_LIGHT_DURATION 10
#define YELLOW_LIGHT_DURATION 3
#define GREEN_LIGHT_DURATION 20
#define PEDESTRIAN_LIGHT_DURATION 5

enum light_state {
    RED_LIGHT,
    YELLOW_LIGHT,
    GREEN_LIGHT,
    PEDESTRIAN_LIGHT
};

void change_light(enum light_state* light_state) {
    switch(*light_state) {
        case RED_LIGHT:
            *light_state = YELLOW_LIGHT;
            break;
        case YELLOW_LIGHT:
            *light_state = GREEN_LIGHT;
            break;
        case GREEN_LIGHT:
            *light_state = RED_LIGHT;
            break;
        case PEDESTRIAN_LIGHT:
            *light_state = RED_LIGHT;
            break;
    }
}

void traffic_light_controller() {
    enum light_state light_state = RED_LIGHT;
    time_t start_time = time(NULL);

    while (1) {
        time_t current_time = time(NULL);
        if (current_time - start_time >= GREEN_LIGHT_DURATION) {
            change_light(&light_state);
            start_time = current_time;
        }

        switch(light_state) {
            case RED_LIGHT:
                printf("Red light: %lds elapsed\n", current_time - start_time);
                break;
            case YELLOW_LIGHT:
                printf("Yellow light: %lds elapsed\n", current_time - start_time);
                break;
            case GREEN_LIGHT:
                printf("Green light: %lds elapsed\n", current_time - start_time);
                break;
            case PEDESTRIAN_LIGHT:
                printf("Pedestrian light: %lds elapsed\n", current_time - start_time);
                break;
        }

        sleep(1);
    }
}

int main() {
    traffic_light_controller();
    return 0;
}