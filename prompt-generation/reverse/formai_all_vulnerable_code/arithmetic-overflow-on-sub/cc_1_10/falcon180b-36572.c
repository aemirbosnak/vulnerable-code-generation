//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_TIME 1000
#define MIN_TIME 0

typedef struct {
    int current_time;
    bool time_travel_enabled;
} TimeMachine;

void init_time_machine(TimeMachine* tm) {
    tm->current_time = MIN_TIME;
    tm->time_travel_enabled = false;
}

void print_current_time(TimeMachine* tm) {
    printf("Current Time: %d\n", tm->current_time);
}

void toggle_time_travel(TimeMachine* tm) {
    if (tm->time_travel_enabled) {
        tm->time_travel_enabled = false;
        printf("Time Travel Disabled\n");
    } else {
        tm->time_travel_enabled = true;
        printf("Time Travel Enabled\n");
    }
}

void travel_to_future(TimeMachine* tm, int seconds) {
    tm->current_time += seconds;
    if (tm->current_time > MAX_TIME) {
        tm->current_time = MAX_TIME;
        printf("Cannot travel beyond %d\n", MAX_TIME);
    }
}

void travel_to_past(TimeMachine* tm, int seconds) {
    tm->current_time -= seconds;
    if (tm->current_time < MIN_TIME) {
        tm->current_time = MIN_TIME;
        printf("Cannot travel beyond %d\n", MIN_TIME);
    }
}

int main() {
    TimeMachine tm;
    init_time_machine(&tm);

    while (1) {
        print_current_time(&tm);

        int choice;
        printf("Enter your choice:\n");
        printf("1. Travel to the future\n");
        printf("2. Travel to the past\n");
        printf("3. Toggle time travel\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int seconds;
                printf("Enter the number of seconds to travel to the future:\n");
                scanf("%d", &seconds);
                travel_to_future(&tm, seconds);
                break;
            }
            case 2: {
                int seconds;
                printf("Enter the number of seconds to travel to the past:\n");
                scanf("%d", &seconds);
                travel_to_past(&tm, seconds);
                break;
            }
            case 3: {
                toggle_time_travel(&tm);
                break;
            }
            case 4: {
                exit(0);
            }
            default: {
                printf("Invalid choice\n");
            }
        }
    }

    return 0;
}