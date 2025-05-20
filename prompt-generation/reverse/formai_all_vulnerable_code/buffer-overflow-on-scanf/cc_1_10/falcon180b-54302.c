//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME_TRAVEL_EVENTS 100
#define MAX_EVENT_NAME_LENGTH 50
#define MAX_EVENT_DESCRIPTION_LENGTH 200

typedef struct {
    char name[MAX_EVENT_NAME_LENGTH];
    char description[MAX_EVENT_DESCRIPTION_LENGTH];
    time_t timestamp;
} TimeTravelEvent;

int main() {
    int numEvents = 0;
    TimeTravelEvent events[MAX_TIME_TRAVEL_EVENTS];

    srand(time(NULL));
    for (int i = 0; i < MAX_TIME_TRAVEL_EVENTS; i++) {
        events[i].timestamp = rand() % 1000000000;
        events[i].name[0] = '\0';
        events[i].description[0] = '\0';
    }

    printf("Welcome to the Time Travel Simulator!\n\n");
    printf("Please enter your name:\n");
    scanf("%s", events[numEvents].name);

    printf("You have been granted the ability to travel through time!\n\n");

    while (1) {
        printf("Current time: %s\n", ctime(&events[numEvents].timestamp));
        printf("Enter an event name to travel to:\n");
        scanf("%s", events[numEvents].name);

        int foundEvent = 0;
        for (int i = 0; i < numEvents; i++) {
            if (strcmp(events[i].name, events[numEvents].name) == 0) {
                foundEvent = 1;
                break;
            }
        }

        if (foundEvent) {
            printf("You have traveled to the event '%s'!\n\n", events[numEvents].name);
            printf("Description:\n%s\n", events[numEvents].description);
        } else {
            printf("Event not found.\n");
        }

        printf("Press enter to continue...\n");
        getchar();
    }

    return 0;
}