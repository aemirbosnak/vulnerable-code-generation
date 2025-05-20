//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100
#define MAX_TIMESTAMPS 1000

struct event {
    char *description;
    time_t timestamp;
};

struct event events[MAX_EVENTS];
time_t timestamps[MAX_TIMESTAMPS];
int num_events = 0;
int num_timestamps = 0;

void add_event(char *description) {
    if (num_events >= MAX_EVENTS) {
        printf("Error: Maximum number of events reached.\n");
        return;
    }
    events[num_events].description = description;
    events[num_events].timestamp = time(NULL);
    num_events++;
}

void travel_to_timestamp(int index) {
    if (index < 0 || index >= num_timestamps) {
        printf("Error: Invalid timestamp index.\n");
        return;
    }
    time_t target_timestamp = timestamps[index];
    struct tm *target_tm = localtime(&target_timestamp);
    printf("Traveling to %s", asctime(target_tm));
}

int main() {
    srand(time(NULL));

    add_event("Program started");

    int choice;
    do {
        printf("\nChoose an option:\n");
        printf("1. Add event\n");
        printf("2. Travel to timestamp\n");
        printf("3. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_event("Event added");
                break;
            case 2:
                printf("Enter timestamp index (0 to %d): ", num_timestamps - 1);
                scanf("%d", &choice);
                travel_to_timestamp(choice);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Error: Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}