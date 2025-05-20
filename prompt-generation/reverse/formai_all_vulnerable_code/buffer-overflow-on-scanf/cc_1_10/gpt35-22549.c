//FormAI DATASET v1.0 Category: System event logger ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct event {
    time_t timestamp;
    char* description;
} Event;

typedef struct eventLog {
    int size;
    Event* events;
} EventLog;

int main() {
    printf("Welcome to the unique C System event logger program!\n");
    printf("Your mission, should you choose to accept it, is to log system events and their timestamps.\n");
    printf("Are you ready? Press 'Y' to start logging or any other key to exit.\n");

    char input;
    scanf("%c", &input);

    if (input != 'Y') {
        printf("Goodbye! Better luck next time.\n");
        return 0;
    }

    EventLog log;
    log.size = 0;
    log.events = NULL;

    printf("Logging started. Press 'X' to stop logging at any time.\n");

    time_t now;
    char* description = malloc(sizeof(char) * 256);

    while (1) {
        printf("Enter a description of the event: ");
        scanf("%s", description);

        if (description[0] == 'X') {
            printf("Logging stopped.\n");
            break;
        }

        now = time(NULL);

        log.size++;
        log.events = realloc(log.events, sizeof(Event) * log.size);

        Event newEvent;
        newEvent.timestamp = now;
        newEvent.description = description;

        log.events[log.size - 1] = newEvent;

        printf("Event logged! Enter another event or press 'X' to stop logging.\n");
    }

    printf("Thank you for using the system event logger program!\n");

    printf("Here are all the events that were logged:\n");

    for (int i = 0; i < log.size; i++) {
        printf("%s at %s", log.events[i].description, ctime(&log.events[i].timestamp));
    }

    return 0;
}