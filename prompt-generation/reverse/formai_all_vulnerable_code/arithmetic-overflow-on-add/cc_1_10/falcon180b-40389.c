//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME_TRAVEL_EVENTS 100
#define MAX_EVENT_DESCRIPTION_LENGTH 80

typedef struct {
    time_t timestamp;
    char event_description[MAX_EVENT_DESCRIPTION_LENGTH];
} TimeTravelEvent;

void print_event(TimeTravelEvent event) {
    printf("Event at %s: %s\n", ctime(&event.timestamp), event.event_description);
}

int main() {
    TimeTravelEvent events[MAX_TIME_TRAVEL_EVENTS];
    int num_events = 0;
    time_t current_time = time(NULL);
    char input[MAX_EVENT_DESCRIPTION_LENGTH];

    printf("Welcome to the Time Travel Simulator!\n");
    printf("You can travel through time and observe historical events.\n");
    printf("Press enter to begin...\n");
    scanf("%s", input);

    while (num_events < MAX_TIME_TRAVEL_EVENTS) {
        printf("Where would you like to travel? ");
        scanf("%s", input);
        if (strcmp(input, "quit") == 0) {
            break;
        }
        if (num_events >= MAX_TIME_TRAVEL_EVENTS) {
            printf("You have reached the maximum number of events.\n");
            break;
        }
        printf("Enter a description of the event: ");
        scanf("%s", events[num_events].event_description);
        events[num_events].timestamp = current_time;
        num_events++;
        current_time += 60 * 60 * 24; // travel 1 day into the future
    }

    printf("\nYour time travel itinerary:\n");
    for (int i = 0; i < num_events; i++) {
        print_event(events[i]);
    }

    return 0;
}