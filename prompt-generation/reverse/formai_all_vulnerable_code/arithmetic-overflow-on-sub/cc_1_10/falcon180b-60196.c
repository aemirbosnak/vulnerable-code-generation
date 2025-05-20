//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>

#define RED_LIGHT_DURATION 10
#define YELLOW_LIGHT_DURATION 3
#define GREEN_LIGHT_DURATION 15
#define TOTAL_CYCLE_DURATION (RED_LIGHT_DURATION + YELLOW_LIGHT_DURATION + GREEN_LIGHT_DURATION)

enum light_state {
    RED,
    YELLOW,
    GREEN
};

void signal_handler(int signal) {
    switch(signal) {
        case SIGINT:
            printf("Interrupted by user.\n");
            break;
        default:
            printf("Received unknown signal %d.\n", signal);
    }
}

void setup_signals() {
    signal(SIGINT, signal_handler);
}

void change_light(enum light_state new_light_state) {
    static enum light_state current_light_state = RED;
    static time_t last_change_time = 0;

    time_t current_time = time(NULL);

    if(current_time - last_change_time >= TOTAL_CYCLE_DURATION) {
        last_change_time = current_time;
        current_light_state = new_light_state;
        printf("Light changed to %s.\n", current_light_state == RED? "red" : current_light_state == YELLOW? "yellow" : "green");
    }
}

int main() {
    setup_signals();

    while(1) {
        change_light(RED);
        sleep(RED_LIGHT_DURATION);
        change_light(YELLOW);
        sleep(YELLOW_LIGHT_DURATION);
        change_light(GREEN);
        sleep(GREEN_LIGHT_DURATION);
    }

    return 0;
}