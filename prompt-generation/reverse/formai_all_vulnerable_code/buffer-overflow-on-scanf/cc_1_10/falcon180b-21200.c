//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_EVENTS 100
#define MAX_EVENT_CHARACTERS 50

typedef struct {
    time_t time;
    char description[MAX_EVENT_CHARACTERS];
} Event;

Event events[MAX_EVENTS];
int eventCount = 0;

void addEvent(time_t time, char* description) {
    if (eventCount >= MAX_EVENTS) {
        printf("Maximum number of events reached.\n");
        exit(1);
    }
    events[eventCount].time = time;
    strncpy(events[eventCount].description, description, MAX_EVENT_CHARACTERS);
    eventCount++;
}

void printEvents() {
    printf("Events:\n");
    for (int i = 0; i < eventCount; i++) {
        printf("%s - %s\n", ctime(&events[i].time), events[i].description);
    }
}

int main() {
    srand(time(NULL));
    int choice;
    bool quit = false;

    while (!quit) {
        printf("1. Add event\n2. Print events\n3. Time travel\n4. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter time (YYYY-MM-DD HH:MM:SS): ");
                char timeString[20];
                scanf("%s", timeString);
                time_t time = strptime(timeString, "%Y-%m-%d %H:%M:%S", NULL);
                if (time == NULL) {
                    printf("Invalid time format.\n");
                } else {
                    printf("Enter event description: ");
                    char description[MAX_EVENT_CHARACTERS];
                    scanf("%s", description);
                    addEvent(time, description);
                }
                break;
            case 2:
                printEvents();
                break;
            case 3:
                printf("Enter destination time (YYYY-MM-DD HH:MM:SS): ");
                char destTimeString[20];
                scanf("%s", destTimeString);
                time_t destTime = strptime(destTimeString, "%Y-%m-%d %H:%M:%S", NULL);
                if (destTime == NULL) {
                    printf("Invalid time format.\n");
                } else {
                    printf("Time travel initiated...\n");
                    srand(destTime);
                }
                break;
            case 4:
                quit = true;
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}