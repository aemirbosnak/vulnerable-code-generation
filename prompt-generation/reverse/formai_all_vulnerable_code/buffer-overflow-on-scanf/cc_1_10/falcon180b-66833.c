//Falcon-180B DATASET v1.0 Category: System event logger ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENT_SIZE 1024

// Event structure
typedef struct {
    char event_name[MAX_EVENT_SIZE];
    time_t event_time;
} Event;

// Function prototypes
int add_event(Event* event_log, int event_count, char* event_name);
void print_event_log(Event* event_log, int event_count);

int main() {
    Event event_log[100]; // Maximum of 100 events
    int event_count = 0; // Number of events recorded

    while (1) {
        printf("Enter event name (or type 'exit' to quit): ");
        scanf("%s", event_log[event_count].event_name);

        if (strcmp(event_log[event_count].event_name, "exit") == 0) {
            break;
        }

        event_log[event_count].event_time = time(NULL);
        event_count++;
    }

    print_event_log(event_log, event_count);

    return 0;
}

int add_event(Event* event_log, int event_count, char* event_name) {
    if (event_count >= 100) {
        printf("Event log is full.\n");
        return -1;
    }

    strcpy(event_log[event_count].event_name, event_name);
    event_log[event_count].event_time = time(NULL);
    event_count++;

    return 0;
}

void print_event_log(Event* event_log, int event_count) {
    printf("Event log:\n");
    printf("-----------------------------\n");

    for (int i = 0; i < event_count; i++) {
        printf("%s (%ld)\n", event_log[i].event_name, event_log[i].event_time);
    }

    printf("-----------------------------\n");
}