//Falcon-180B DATASET v1.0 Category: System event logger ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EVENTS 100
#define MAX_EVENT_NAME_LENGTH 50
#define MAX_EVENT_DESCRIPTION_LENGTH 200

typedef struct {
    char eventName[MAX_EVENT_NAME_LENGTH];
    char eventDescription[MAX_EVENT_DESCRIPTION_LENGTH];
    int eventID;
} Event;

Event events[MAX_EVENTS];
int numEvents = 0;

void addEvent(Event event) {
    if (numEvents >= MAX_EVENTS) {
        printf("Error: Maximum number of events reached.\n");
        return;
    }
    events[numEvents] = event;
    numEvents++;
}

void printEvents() {
    printf("Event ID\tEvent Name\tEvent Description\n");
    for (int i = 0; i < numEvents; i++) {
        printf("%d\t%s\t%s\n", events[i].eventID, events[i].eventName, events[i].eventDescription);
    }
}

int main() {
    printf("Event Logger\n");
    int choice;
    while (1) {
        printf("1. Add event\n2. Print events\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter event name (max %d characters): ", MAX_EVENT_NAME_LENGTH - 1);
                scanf("%s", events[numEvents].eventName);
                printf("Enter event description (max %d characters): ", MAX_EVENT_DESCRIPTION_LENGTH - 1);
                scanf("%s", events[numEvents].eventDescription);
                events[numEvents].eventID = numEvents + 1;
                addEvent(events[numEvents]);
                break;
            case 2:
                printEvents();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}