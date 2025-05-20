//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EVENTS 1000

typedef struct {
    char *ip;
    char *date;
    char *time;
    char *request;
    char *status;
} Event;

int main() {
    FILE *file;
    char line[1024];
    Event events[MAX_EVENTS];
    int num_events = 0;

    if ((file = fopen("access.log", "r")) == NULL) {
        printf("Error: could not open access.log\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        if (num_events >= MAX_EVENTS) {
            printf("Error: maximum number of events reached\n");
            break;
        }

        char *token = strtok(line, " ");
        events[num_events].ip = strdup(token);

        token = strtok(NULL, " ");
        events[num_events].date = strdup(token);

        token = strtok(NULL, " ");
        events[num_events].time = strdup(token);

        token = strtok(NULL, " ");
        events[num_events].request = strdup(token);

        token = strtok(NULL, " ");
        events[num_events].status = strdup(token);

        num_events++;
    }

    fclose(file);

    printf("Number of events: %d\n", num_events);

    for (int i = 0; i < num_events; i++) {
        printf("Event %d:\n", i);
        printf("IP: %s\n", events[i].ip);
        printf("Date: %s\n", events[i].date);
        printf("Time: %s\n", events[i].time);
        printf("Request: %s\n", events[i].request);
        printf("Status: %s\n", events[i].status);
        printf("\n");
    }

    for (int i = 0; i < num_events; i++) {
        free(events[i].ip);
        free(events[i].date);
        free(events[i].time);
        free(events[i].request);
        free(events[i].status);
    }

    return 0;
}