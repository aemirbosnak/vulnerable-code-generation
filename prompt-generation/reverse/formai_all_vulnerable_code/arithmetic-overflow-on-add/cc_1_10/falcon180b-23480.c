//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED_LIGHT_DURATION 30
#define YELLOW_LIGHT_DURATION 5
#define GREEN_LIGHT_DURATION 30
#define TOTAL_LIGHT_DURATION (RED_LIGHT_DURATION + YELLOW_LIGHT_DURATION + GREEN_LIGHT_DURATION)

enum light_state {
    RED_LIGHT,
    YELLOW_LIGHT,
    GREEN_LIGHT,
};

void print_light_state(enum light_state state) {
    switch (state) {
        case RED_LIGHT:
            printf("Red light\n");
            break;
        case YELLOW_LIGHT:
            printf("Yellow light\n");
            break;
        case GREEN_LIGHT:
            printf("Green light\n");
            break;
    }
}

int main() {
    enum light_state current_light = RED_LIGHT;
    enum light_state next_light = GREEN_LIGHT;
    time_t start_time, end_time;
    int i;

    srand(time(NULL));
    start_time = time(NULL);

    for (i = 0; i < 10; i++) {
        end_time = start_time + (i * TOTAL_LIGHT_DURATION);
        while (time(NULL) < end_time) {
            if (current_light == RED_LIGHT && next_light == GREEN_LIGHT) {
                printf("Yellow light flashing...\n");
            } else {
                print_light_state(current_light);
            }
            fflush(stdout);
            usleep(100000);
        }
        current_light = next_light;
        next_light = (current_light == GREEN_LIGHT)? RED_LIGHT : GREEN_LIGHT;
        printf("Light changed to %s\n", current_light == RED_LIGHT? "green" : "red");
        fflush(stdout);
        usleep(1000000);
    }

    return 0;
}