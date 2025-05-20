//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_HISTORY 10
#define TIMESTAMP_SIZE 26

typedef struct {
    char event_name[50];
    char timestamp[TIMESTAMP_SIZE];
} Event;

typedef struct {
    Event events[MAX_HISTORY];
    int event_count;
} Timeline;

void initialize_timeline(Timeline *timeline) {
    timeline->event_count = 0;
}

void add_event(Timeline *timeline, const char *event_name) {
    if (timeline->event_count < MAX_HISTORY) {
        strncpy(timeline->events[timeline->event_count].event_name, event_name, sizeof(timeline->events[timeline->event_count].event_name) - 1);
        time_t now = time(NULL);
        ctime_r(&now, timeline->events[timeline->event_count].timestamp);
        timeline->events[timeline->event_count].timestamp[strlen(timeline->events[timeline->event_count].timestamp) - 1] = '\0'; // Remove newline
        timeline->event_count++;
        printf("Event added: %s at %s\n", event_name, timeline->events[timeline->event_count - 1].timestamp);
    } else {
        printf("Timeline is full. Cannot add more events.\n");
    }
}

void display_events(const Timeline *timeline) {
    printf("\nTimeline of Events:\n");
    for (int i = 0; i < timeline->event_count; i++) {
        printf("%d. %s - %s\n", i + 1, timeline->events[i].event_name, timeline->events[i].timestamp);
    }
}

void time_travel(int year, int month, int day) {
    struct tm newtime;
    time_t posttime;

    newtime.tm_year = year - 1900; // Year since 1900
    newtime.tm_mon = month - 1;     // Month [0-11]
    newtime.tm_mday = day;           // Day of the month [1-31]
    newtime.tm_hour = 0;             // Default hour
    newtime.tm_min = 0;              // Default minute
    newtime.tm_sec = 0;              // Default second
    newtime.tm_isdst = -1;           // Not considering daylight saving time

    posttime = mktime(&newtime);
    if (posttime == -1) {
        printf("Invalid date provided.\n");
    } else {
        printf("Time travel initiated to: %s", ctime(&posttime));
        // Here we would execute more complex time travel functionalities
    }
}

void menu() {
    printf("=== Time Travel Simulator ===\n");
    printf("1. Add Event\n");
    printf("2. Display Events\n");
    printf("3. Time Travel\n");
    printf("4. Exit\n");
}

int main() {
    Timeline timeline;
    initialize_timeline(&timeline);
    int choice;

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline after entering choice

        switch (choice) {
            case 1: {
                char event_name[50];
                printf("Enter event name: ");
                fgets(event_name, sizeof(event_name), stdin);
                event_name[strcspn(event_name, "\n")] = '\0'; // Remove newline
                add_event(&timeline, event_name);
                break;
            }
            case 2:
                display_events(&timeline);
                break;
            case 3: {
                int year, month, day;
                printf("Enter year: ");
                scanf("%d", &year);
                printf("Enter month: ");
                scanf("%d", &month);
                printf("Enter day: ");
                scanf("%d", &day);
                time_travel(year, month, day);
                break;
            }
            case 4:
                printf("Exiting the Time Travel Simulator. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}