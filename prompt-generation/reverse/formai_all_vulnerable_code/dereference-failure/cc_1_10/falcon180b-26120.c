//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_EVENTS 1000
#define EVENT_SIZE 64

typedef struct {
    char *data;
    int size;
    time_t timestamp;
} Event;

int main() {
    Event events[MAX_EVENTS];
    int num_events = 0;
    char input[EVENT_SIZE];
    char *token;
    time_t current_time;
    int i;

    srand(time(NULL));
    current_time = time(NULL);

    printf("Intrusion Detection System\n");
    while (1) {
        printf("Enter an event: ");
        fgets(input, EVENT_SIZE, stdin);
        token = strtok(input, " ");
        if (token == NULL) {
            continue;
        }
        if (num_events >= MAX_EVENTS) {
            printf("Event buffer is full.\n");
            continue;
        }
        events[num_events].data = malloc(strlen(input) + 1);
        strcpy(events[num_events].data, input);
        events[num_events].size = strlen(input);
        events[num_events].timestamp = current_time;
        num_events++;
    }

    while (1) {
        current_time = time(NULL);
        for (i = 0; i < num_events; i++) {
            if (current_time - events[i].timestamp > 60) {
                free(events[i].data);
                events[i] = events[num_events - 1];
                num_events--;
                i--;
            }
        }
        printf("Current events:\n");
        for (i = 0; i < num_events; i++) {
            printf("%s\n", events[i].data);
        }
        sleep(1);
    }

    return 0;
}