//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EVENTS 1000
#define MAX_EVENT_NAME_LENGTH 50
#define MAX_EVENT_DESCRIPTION_LENGTH 200

typedef struct {
    char name[MAX_EVENT_NAME_LENGTH];
    char description[MAX_EVENT_DESCRIPTION_LENGTH];
    time_t timestamp;
} Event;

int main() {
    int numEvents = 0;
    Event events[MAX_EVENTS];
    char input[100];
    time_t currentTime = time(NULL);

    printf("Welcome to the Time Travel Simulator!\n");
    printf("You can travel back in time to witness historical events.\n");
    printf("Type 'list' to see the available events.\n");
    printf("Type 'travel <event name>' to travel back in time.\n");
    printf("Type 'quit' to exit.\n");

    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);

        if (strcmp(input, "list") == 0) {
            printf("Available events:\n");
            for (int i = 0; i < numEvents; i++) {
                printf("%s - %s\n", events[i].name, events[i].description);
            }
        } else if (strcmp(input, "travel") == 0) {
            char eventName[MAX_EVENT_NAME_LENGTH];
            strcpy(eventName, strtok(input, " "));

            for (int i = 0; i < numEvents; i++) {
                if (strcmp(eventName, events[i].name) == 0) {
                    printf("Traveling back in time to witness %s...\n", events[i].name);
                    currentTime = events[i].timestamp;
                    break;
                }
            }
        } else if (strcmp(input, "quit") == 0) {
            break;
        } else {
            char eventName[MAX_EVENT_NAME_LENGTH];
            strcpy(eventName, strtok(input, " "));

            time_t eventTimestamp = strtol(strtok(NULL, " "), NULL, 10);

            if (numEvents >= MAX_EVENTS) {
                printf("Maximum number of events reached.\n");
            } else {
                strcpy(events[numEvents].name, eventName);
                strcpy(events[numEvents].description, "");
                events[numEvents].timestamp = eventTimestamp;
                numEvents++;
            }
        }
    }

    return 0;
}