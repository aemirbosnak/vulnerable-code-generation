//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_YEARS 100
#define MAX_EVENTS 100

typedef struct {
    int year;
    char event[50];
} Event;

void addEvent(Event events[], int numEvents, int year, char* event) {
    if (numEvents >= MAX_EVENTS) {
        printf("Error: Too many events!\n");
        exit(1);
    }
    events[numEvents].year = year;
    strcpy(events[numEvents].event, event);
    numEvents++;
}

int main() {
    srand(time(NULL));
    int numEvents = 0;
    Event events[MAX_EVENTS];
    addEvent(events, numEvents, 0, "You are born.");

    int choice;
    while (1) {
        printf("What year is it? ");
        scanf("%d", &choice);
        if (choice < 0 || choice > MAX_YEARS) {
            printf("Invalid year.\n");
            continue;
        }
        for (int i = 0; i < numEvents; i++) {
            if (events[i].year == choice) {
                printf("%s\n", events[i].event);
            }
        }
        printf("What do you want to do?\n");
        printf("1. Add an event.\n");
        printf("2. Go back in time.\n");
        printf("3. Go forward in time.\n");
        printf("4. Quit.\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the year of the event: ");
                int year;
                scanf("%d", &year);
                printf("Enter the event: ");
                char event[50];
                scanf("%s", event);
                addEvent(events, numEvents, year, event);
                break;
            case 2:
                if (numEvents > 0 && events[numEvents - 1].year > 0) {
                    events[numEvents - 1].year--;
                } else {
                    printf("Cannot go back any further.\n");
                }
                break;
            case 3:
                if (numEvents > 0 && events[numEvents - 1].year < MAX_YEARS - 1) {
                    events[numEvents - 1].year++;
                } else {
                    printf("Cannot go forward any further.\n");
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}