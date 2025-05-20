//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_YEARS 10000
#define MAX_EVENTS 100

typedef struct {
    int year;
    char event[256];
} TimeEvent;

typedef struct {
    TimeEvent events[MAX_EVENTS];
    int eventCount;
} TimeMachine;

void initTimeMachine(TimeMachine *tm) {
    tm->eventCount = 0;
}

void addEvent(TimeMachine *tm, int year, const char *event) {
    if (tm->eventCount < MAX_EVENTS) {
        tm->events[tm->eventCount].year = year;
        strncpy(tm->events[tm->eventCount].event, event, sizeof(tm->events[tm->eventCount].event));
        tm->eventCount++;
    } else {
        printf("Event list full! Cannot add more events.\n");
    }
}

void displayEvents(TimeMachine *tm) {
    if (tm->eventCount == 0) {
        printf("No events recorded.\n");
        return;
    }

    for (int i = 0; i < tm->eventCount; i++) {
        printf("Year: %d -> Event: %s\n", tm->events[i].year, tm->events[i].event);
    }
}

int compareEvents(const void *a, const void *b) {
    return ((TimeEvent *)a)->year - ((TimeEvent *)b)->year;
}

void sortEvents(TimeMachine *tm) {
    qsort(tm->events, tm->eventCount, sizeof(TimeEvent), compareEvents);
}

void travelToYear(TimeMachine *tm, int year) {
    printf("Traveling to the year %d...\n", year);
    int found = 0;

    for (int i = 0; i < tm->eventCount; i++) {
        if (tm->events[i].year == year) {
            printf("You have arrived in %d. Event: %s.\n", year, tm->events[i].event);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No recorded events for the year %d.\n", year);
    }
}

void printMenu() {
    printf("\n=== Time Travel Simulator ===\n");
    printf("1. Add Event\n");
    printf("2. Display Events\n");
    printf("3. Sort Events\n");
    printf("4. Travel to Year\n");
    printf("5. Exit\n");
    printf("=============================\n");
}

int main() {
    TimeMachine tm;
    initTimeMachine(&tm);
    int choice, year;
    char event[256];

    while (1) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter year of the event: ");
                scanf("%d", &year);
                printf("Enter event description: ");
                getchar();  // To consume the newline left by scanf
                fgets(event, sizeof(event), stdin);
                event[strcspn(event, "\n")] = 0; // Remove newline character
                addEvent(&tm, year, event);
                printf("Event added successfully.\n");
                break;
            case 2:
                displayEvents(&tm);
                break;
            case 3:
                sortEvents(&tm);
                printf("Events sorted by year.\n");
                break;
            case 4:
                printf("Enter year to travel to: ");
                scanf("%d", &year);
                travelToYear(&tm, year);
                break;
            case 5:
                printf("Exiting the Time Travel Simulator. Safe Travels!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}