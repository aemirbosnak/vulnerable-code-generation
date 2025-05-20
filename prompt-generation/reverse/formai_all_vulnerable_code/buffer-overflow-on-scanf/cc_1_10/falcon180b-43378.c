//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME 1000
#define MAX_EVENTS 100

typedef struct {
    time_t time;
    char *description;
} Event;

Event events[MAX_EVENTS];
int num_events = 0;

void add_event(char *description) {
    if (num_events >= MAX_EVENTS) {
        printf("Error: Too many events.\n");
        exit(1);
    }
    time_t current_time = time(NULL);
    events[num_events].time = current_time;
    events[num_events].description = description;
    num_events++;
}

void travel_to_time(time_t target_time) {
    int i;
    for (i = 0; i < num_events; i++) {
        if (events[i].time == target_time) {
            printf("%s\n", events[i].description);
            return;
        }
    }
    printf("No event found at this time.\n");
}

int main() {
    srand(time(NULL));
    add_event("You wake up in the morning.");
    add_event("You have breakfast.");
    add_event("You go to work.");
    add_event("You have lunch.");
    add_event("You finish work.");
    add_event("You have dinner.");
    add_event("You go to bed.");

    int choice;
    do {
        printf("Enter your choice:\n");
        printf("1. Travel to a specific time\n");
        printf("2. Travel to a random time\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        time_t target_time;
        if (choice == 1) {
            printf("Enter the target time (seconds since 1970-01-01 00:00:00 UTC): ");
            scanf("%ld", &target_time);
        } else if (choice == 2) {
            target_time = rand() % MAX_TIME;
        }

        travel_to_time(target_time);
    } while (choice!= 3);

    return 0;
}