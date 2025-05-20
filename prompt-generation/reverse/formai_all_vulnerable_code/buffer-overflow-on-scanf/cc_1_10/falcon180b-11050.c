//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENTS 100
#define MAX_EVENT_NAME_LEN 50
#define MAX_EVENT_DESC_LEN 100

typedef struct {
    char name[MAX_EVENT_NAME_LEN];
    char desc[MAX_EVENT_DESC_LEN];
    time_t start_time;
    time_t end_time;
} Event;

int num_events = 0;
Event events[MAX_EVENTS];

void add_event() {
    num_events++;
}

void remove_event(int index) {
    num_events--;
}

void display_events() {
    printf("Upcoming events:\n");
    for (int i = 0; i < num_events; i++) {
        printf("%s: %s\n", events[i].name, events[i].desc);
    }
}

int main() {
    srand(time(NULL));
    int choice;
    do {
        printf("1. Add event\n2. Remove event\n3. Display events\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            add_event();
            break;
        case 2:
            printf("Enter event index to remove: ");
            scanf("%d", &choice);
            remove_event(choice - 1);
            break;
        case 3:
            display_events();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    } while (1);
    return 0;
}