//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED_LIGHT 0
#define YELLOW_LIGHT 1
#define GREEN_LIGHT 2
#define PEDESTRIAN_LIGHT 3

void init_traffic_lights(int* lights, int num_lights, int state) {
    for (int i = 0; i < num_lights; i++) {
        lights[i] = state;
    }
}

void change_traffic_lights(int* lights, int num_lights, int from_state, int to_state) {
    for (int i = 0; i < num_lights; i++) {
        if (lights[i] == from_state) {
            lights[i] = to_state;
        }
    }
}

void print_traffic_lights(int* lights, int num_lights) {
    for (int i = 0; i < num_lights; i++) {
        printf("%d ", lights[i]);
    }
    printf("\n");
}

int main() {
    int num_lights = 4;
    int* lights = malloc(num_lights * sizeof(int));

    init_traffic_lights(lights, num_lights, RED_LIGHT);
    print_traffic_lights(lights, num_lights);

    for (int i = 0; i < 10; i++) {
        change_traffic_lights(lights, num_lights, RED_LIGHT, GREEN_LIGHT);
        print_traffic_lights(lights, num_lights);
        sleep(1);
    }

    for (int i = 0; i < 10; i++) {
        change_traffic_lights(lights, num_lights, GREEN_LIGHT, YELLOW_LIGHT);
        print_traffic_lights(lights, num_lights);
        sleep(1);
    }

    for (int i = 0; i < 10; i++) {
        change_traffic_lights(lights, num_lights, YELLOW_LIGHT, RED_LIGHT);
        print_traffic_lights(lights, num_lights);
        sleep(1);
    }

    free(lights);
    return 0;
}