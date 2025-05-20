//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum TrafficLightState {
    GREEN,
    YELLOW,
    RED
};

void delay(int seconds) {
    clock_t start_time = clock();
    while (clock() < start_time + seconds * CLOCKS_PER_SEC);
}

enum TrafficLightState get_next_state(enum TrafficLightState state) {
    switch (state) {
        case GREEN:
            return YELLOW;
        case YELLOW:
            return RED;
        case RED:
            return GREEN;
    }
}

int main() {
    enum TrafficLightState current_state = GREEN;
    int countdown = 0;

    printf("Traffic Light Controller\n");

    while (1) {
        if (current_state == GREEN) {
            printf("Green Light\n");
            delay(10);
            current_state = YELLOW;
        } else if (current_state == YELLOW) {
            printf("Yellow Light\n");
            countdown = 3;
            while (countdown > 0) {
                delay(1);
                printf("%d\n", countdown);
                countdown--;
            }
            current_state = get_next_state(current_state);
        } else {
            printf("Red Light\n");
            delay(10);
            current_state = get_next_state(current_state);
        }
    }

    return 0;
}