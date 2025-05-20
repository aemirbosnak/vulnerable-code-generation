//Falcon-180B DATASET v1.0 Category: System event logger ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EVENTS 100
#define MAX_EVENT_SIZE 256

typedef struct {
    char event[MAX_EVENT_SIZE];
    time_t timestamp;
} Event;

int main() {
    FILE *fp;
    char filename[MAX_EVENT_SIZE];
    Event events[MAX_EVENTS];
    int num_events = 0;
    int i;

    printf("Enter the name of the event log file: ");
    scanf("%s", filename);

    fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (1) {
        printf("Enter an event (or type 'quit' to exit): ");
        scanf("%s", events[num_events].event);

        if (strcmp(events[num_events].event, "quit") == 0) {
            break;
        }

        events[num_events].timestamp = time(NULL);
        num_events++;

        if (num_events >= MAX_EVENTS) {
            printf("Event log is full.\n");
            break;
        }
    }

    for (i = 0; i < num_events; i++) {
        fprintf(fp, "%s - %ld\n", events[i].event, events[i].timestamp);
    }

    fclose(fp);

    printf("Event log saved to file '%s'.\n", filename);

    return 0;
}