//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_YEARS 100
#define MAX_EVENTS 100

typedef struct {
    int year;
    char event[100];
} Event;

int main() {
    int num_events = 0;
    Event events[MAX_EVENTS];
    int current_year = 2022;
    char input[100];
    char choice;
    int year;
    int event_index;

    printf("Welcome to the Time Travel Simulator!\n\n");

    while (1) {
        printf("Enter your choice:\n");
        printf("1. Add event\n");
        printf("2. List events\n");
        printf("3. Travel to an event\n");
        printf("4. Quit\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter the year of the event (YYYY): ");
                scanf("%d", &year);
                printf("Enter the event name: ");
                scanf("%s", input);
                strcpy(events[num_events].event, input);
                events[num_events].year = year;
                num_events++;
                printf("Event added successfully!\n");
                break;
            case '2':
                printf("List of events:\n");
                for (int i = 0; i < num_events; i++) {
                    printf("%d: %s\n", events[i].year, events[i].event);
                }
                break;
            case '3':
                printf("Enter the year you want to travel to: ");
                scanf("%d", &year);
                for (int i = 0; i < num_events; i++) {
                    if (events[i].year == year) {
                        printf("You have traveled to the event '%s' in the year %d!\n", events[i].event, year);
                        break;
                    }
                }
                break;
            case '4':
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}