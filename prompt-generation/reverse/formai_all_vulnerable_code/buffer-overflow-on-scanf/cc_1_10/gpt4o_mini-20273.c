//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUF_SIZE 256
#define NUM_YEARS 10

typedef struct {
    int year;
    char event[BUF_SIZE];
} TimeEvent;

typedef struct {
    int current_year;
    TimeEvent time_events[NUM_YEARS];
    int event_count;
} TimeTraveler;

void init_time_traveler(TimeTraveler *traveler, int start_year) {
    traveler->current_year = start_year;
    traveler->event_count = 0;
    printf("Time Traveler initialized in the year %d.\n", start_year);
}

void add_time_event(TimeTraveler *traveler, int year, const char *event) {
    if (traveler->event_count < NUM_YEARS) {
        traveler->time_events[traveler->event_count].year = year;
        strncpy(traveler->time_events[traveler->event_count].event, event, BUF_SIZE);
        traveler->event_count++;
    } else {
        printf("Event catalog full! Cannot add more events.\n");
    }
}

void display_time_events(const TimeTraveler *traveler) {
    printf("\nTime Events:\n");
    for (int i = 0; i < traveler->event_count; i++) {
        printf("Year %d: %s\n", traveler->time_events[i].year, traveler->time_events[i].event);
    }
}

void travel_to_year(TimeTraveler *traveler, int target_year) {
    printf("Traveling from %d to %d...\n", traveler->current_year, target_year);
    traveler->current_year = target_year;
    printf("Arrived in the year %d.\n", traveler->current_year);
    display_time_events(traveler);
}

void simulate_time_travel(TimeTraveler *traveler) {
    int target_year;
    char event[BUF_SIZE];

    while (1) {
        printf("\nEnter a year to travel (or -1 to exit): ");
        scanf("%d", &target_year);
        
        if (target_year == -1) {
            break;
        }

        travel_to_year(traveler, target_year);

        printf("Enter an event happening in year %d: ", target_year);
        getchar();  // Consume newline
        fgets(event, BUF_SIZE, stdin);
        event[strcspn(event, "\n")] = 0; // Remove newline character

        add_time_event(traveler, target_year, event);
    }
    printf("Time travel session ended.\n");
}

int main() {
    int start_year;
    TimeTraveler traveler;

    printf("Enter starting year for the Time Traveler: ");
    scanf("%d", &start_year);
    init_time_traveler(&traveler, start_year);

    simulate_time_travel(&traveler);

    return 0;
}