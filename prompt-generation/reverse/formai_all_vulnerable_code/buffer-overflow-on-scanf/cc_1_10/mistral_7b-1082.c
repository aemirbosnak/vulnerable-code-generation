//MISTRAL-7B DATASET v1.0 Category: System event logger ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENTS 50
#define EVENT_SIZE 256
#define LOG_FILE "enchanted_log.txt"

typedef struct _Event {
    char timestamp[32];
    char description[EVENT_SIZE];
} Event;

Event events[MAX_EVENTS];
int event_count = 0;

void log_event(char *description) {
    time_t now;
    struct tm *tm;
    char timestamp[32];

    time(&now);
    tm = localtime(&now);

    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", tm);

    strcpy(events[event_count].timestamp, timestamp);
    strcpy(events[event_count].description, description);
    event_count++;

    if (event_count >= MAX_EVENTS) {
        event_count--;
        printf("Log is full. Last event was: %s\n", events[event_count].description);
    } else {
        FILE *log_file = fopen(LOG_FILE, "a");
        fprintf(log_file, "%s - %s\n", events[event_count].timestamp, events[event_count].description);
        fclose(log_file);
        printf("Event logged: %s\n", description);
    }
}

int main() {
    int i;

    printf("\nWelcome to the Enchanted Event Logger!\n");

    for (i = 0; i < 10; i++) {
        char event_desc[EVENT_SIZE];
        printf("Enter event %d description: ", i + 1);
        scanf("%s", event_desc);

        log_event(event_desc);
    }

    printf("\nLogging complete. View log file: %s\n", LOG_FILE);

    return 0;
}