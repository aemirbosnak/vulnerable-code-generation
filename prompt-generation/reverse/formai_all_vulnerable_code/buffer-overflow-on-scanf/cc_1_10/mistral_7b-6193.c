//MISTRAL-7B DATASET v1.0 Category: Time Travel Simulator ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_EVENTS 10
#define EVENT_LEN 50

typedef struct {
    char description[EVENT_LEN];
    int time;
} Event;

Event events[MAX_EVENTS];
int current_time = 0;

void print_menu() {
    printf("1. Travel to the past\n");
    printf("2. Travel to the future\n");
    printf("3. Add an event\n");
    printf("4. Display current event\n");
    printf("5. Display all events\n");
    printf("6. Quit\n");
}

void travel_past() {
    if (current_time > 0) {
        current_time--;
        printf("You have traveled to the past. Current time: %d\n", current_time);
    } else {
        printf("You cannot travel further back in time.\n");
    }
}

void travel_future() {
    int max_time = 0;
    for (int i = 0; i < MAX_EVENTS; i++) {
        if (events[i].time > max_time && events[i].time <= current_time + 1) {
            max_time = events[i].time;
        }
    }

    if (max_time > current_time + 1) {
        current_time++;
        printf("You have traveled to the future. Current time: %d\n", current_time);
    } else {
        printf("You cannot travel further into the future.\n");
    }
}

void add_event() {
    if (current_time >= MAX_EVENTS) {
        printf("Memory full.\n");
        return;
    }

    printf("Enter event description: ");
    scanf("%s", events[current_time].description);
    printf("Enter event time: ");
    scanf("%d", &events[current_time].time);
    printf("Event added.\n");
    current_time++;
}

void display_current() {
    if (current_time < MAX_EVENTS) {
        printf("Current event: %s\n", events[current_time].description);
    } else {
        printf("No current event.\n");
    }
}

void display_all() {
    for (int i = 0; i < current_time; i++) {
        printf("Event %d: %s (%.2d years ago)\n", i, events[i].description, current_time - i);
    }

    for (int i = current_time; i < MAX_EVENTS; i++) {
        printf("Event %d: %s (%.2d years in the future)\n", i, events[i].description, i - current_time);
    }
}

int main() {
    int choice;

    while (1) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                travel_past();
                break;
            case 2:
                travel_future();
                break;
            case 3:
                add_event();
                break;
            case 4:
                display_current();
                break;
            case 5:
                display_all();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}