//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

#define SIZE 100
#define MAX_TIME_TRAVEL 10

struct event {
    time_t time;
    char* message;
};

struct event events[MAX_TIME_TRAVEL];
int num_events = 0;

void add_event(time_t time, char* message) {
    if (num_events >= MAX_TIME_TRAVEL) {
        printf("ERROR: Maximum number of time travel events reached.\n");
        return;
    }
    events[num_events].time = time;
    events[num_events].message = strdup(message);
    num_events++;
}

void print_events() {
    for (int i = 0; i < num_events; i++) {
        printf("%s (%ld)\n", events[i].message, events[i].time);
    }
}

void time_travel(time_t target_time) {
    for (int i = 0; i < num_events; i++) {
        if (events[i].time == target_time) {
            printf("%s\n", events[i].message);
        }
    }
}

int main() {
    srand(time(NULL));
    add_event(time(NULL) + rand() % 86400, "Hello from the past!");
    add_event(time(NULL) + rand() % 86400 + 3600, "Greetings from the future!");
    add_event(time(NULL) + rand() % 86400 + 7200, "Time is relative.");

    while (1) {
        printf("Enter a Unix timestamp to travel to (0 to exit):\n");
        long input;
        scanf("%ld", &input);
        if (input == 0) {
            break;
        }
        time_t target_time = input;
        time_travel(target_time);
    }

    return 0;
}