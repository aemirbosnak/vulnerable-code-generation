//Falcon-180B DATASET v1.0 Category: System event logger ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define MAX_EVENT_NUMBER 100
#define MAX_EVENT_LENGTH 100

typedef struct {
    char event_name[MAX_EVENT_LENGTH];
    int event_number;
    time_t event_time;
} Event;

void add_event(Event* event_array, int num_events, char* event_name) {
    int i;
    for(i = 0; i < num_events; i++) {
        if(strcmp(event_array[i].event_name, event_name) == 0) {
            event_array[i].event_number++;
            return;
        }
    }
    strcpy(event_array[num_events].event_name, event_name);
    event_array[num_events].event_number = 1;
    event_array[num_events].event_time = time(NULL);
    num_events++;
}

void print_event(Event event) {
    printf("Event Name: %s\n", event.event_name);
    printf("Event Number: %d\n", event.event_number);
    printf("Event Time: %s", ctime(&event.event_time));
}

void sort_events(Event* event_array, int num_events) {
    int i, j;
    Event temp;
    for(i = 0; i < num_events - 1; i++) {
        for(j = i + 1; j < num_events; j++) {
            if(event_array[i].event_number < event_array[j].event_number) {
                temp = event_array[i];
                event_array[i] = event_array[j];
                event_array[j] = temp;
            }
        }
    }
}

int main() {
    Event event_array[MAX_EVENT_NUMBER];
    int num_events = 0;
    char event_name[MAX_EVENT_LENGTH];

    printf("Welcome to the Event Logger!\n");
    while(1) {
        printf("\nEnter an event name (or type 'quit' to exit): ");
        scanf("%s", event_name);
        if(strcmp(event_name, "quit") == 0) {
            break;
        }
        add_event(event_array, num_events, event_name);
        num_events++;
    }

    printf("\nEvent Log:\n");
    sort_events(event_array, num_events);
    for(int i = 0; i < num_events; i++) {
        print_event(event_array[i]);
    }

    return 0;
}