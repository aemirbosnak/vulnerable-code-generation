//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_YEARS 10000
#define MAX_EVENTS 100

typedef struct {
    char description[256];
    int year;
} Event;

typedef struct {
    Event events[MAX_EVENTS];
    int event_count;
} Timeline;

void initialize_timeline(Timeline *timeline) {
    timeline->event_count = 0;
}

void add_event(Timeline *timeline, int year, const char *description) {
    if (timeline->event_count < MAX_EVENTS) {
        timeline->events[timeline->event_count].year = year;
        snprintf(timeline->events[timeline->event_count].description, sizeof(timeline->events[timeline->event_count].description), "%s", description);
        timeline->event_count++;
    } else {
        printf("Event limit reached. Cannot add more events.\n");
    }
}

void display_events(const Timeline *timeline) {
    printf("\nTimeline of Events:\n");
    for (int i = 0; i < timeline->event_count; i++) {
        printf("Year: %d - Event: %s\n", timeline->events[i].year, timeline->events[i].description);
    }
}

int get_current_year() {
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    return tm_info->tm_year + 1900; // tm_year is years since 1900
}

void time_travel(int target_year, Timeline *timeline) {
    // First check if the timeline has the target_year in its events
    for (int i = 0; i < timeline->event_count; i++) {
        if (timeline->events[i].year == target_year) {
            printf("Traveling to the year %d...\n", target_year);
            printf("In this year: %s\n", timeline->events[i].description);
            return;
        }
    }
    printf("No events found for the year %d. You have landed in an unmarked timeline.\n", target_year);
}

void display_menu() {
    printf("\n----- Time Travel Simulator -----\n");
    printf("1. Add Event\n");
    printf("2. Display Events\n");
    printf("3. Time Travel\n");
    printf("4. Exit\n");
    printf("-------------------------------\n");
}

int main() {
    Timeline timeline;
    initialize_timeline(&timeline);
    int choice;
    int year;
    char description[256];

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Year: ");
                scanf("%d", &year);
                printf("Enter Event Description: ");
                getchar(); // Consume newline
                fgets(description, sizeof(description), stdin);
                // Remove newline character from fgets
                description[strcspn(description, "\n")] = 0; 
                add_event(&timeline, year, description);
                break;
            case 2:
                display_events(&timeline);
                break;
            case 3:
                printf("Enter the year to travel to: ");
                scanf("%d", &year);
                time_travel(year, &timeline);
                break;
            case 4:
                printf("Exiting the Time Travel Simulator. Until next time!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}