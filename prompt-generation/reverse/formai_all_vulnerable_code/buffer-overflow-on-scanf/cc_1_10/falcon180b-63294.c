//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 1000
#define MAX_EVENT_LENGTH 64
#define MAX_NAME_LENGTH 64

typedef struct {
    char name[MAX_NAME_LENGTH];
    char event[MAX_EVENT_LENGTH];
    time_t start_time;
    time_t end_time;
} Event;

int main() {
    Event events[MAX_EVENTS];
    int num_events = 0;
    char input[MAX_EVENT_LENGTH];

    printf("Welcome to the Futuristic Appointment Scheduler!\n");
    printf("Please enter your name: ");
    scanf("%s", input);
    strcpy(events[num_events].name, input);
    num_events++;

    while (num_events < MAX_EVENTS) {
        printf("Please enter an event (or type 'done' to finish): ");
        scanf("%s", input);

        if (strcmp(input, "done") == 0) {
            break;
        }

        strcpy(events[num_events].event, input);
        printf("Please enter the start time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", input);
        events[num_events].start_time = strptime(input, "%Y-%m-%d %H:%M:%S", NULL);
        printf("Please enter the end time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", input);
        events[num_events].end_time = strptime(input, "%Y-%m-%d %H:%M:%S", NULL);
        num_events++;
    }

    printf("\nYour schedule:\n");
    for (int i = 0; i < num_events; i++) {
        printf("%s - %s (%s - %s)\n", events[i].name, events[i].event, ctime(&events[i].start_time), ctime(&events[i].end_time));
    }

    return 0;
}