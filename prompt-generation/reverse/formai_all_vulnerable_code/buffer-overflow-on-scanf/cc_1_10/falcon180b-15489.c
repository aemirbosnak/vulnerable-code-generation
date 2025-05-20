//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define TIME_LIMIT 100
#define TIME_STEP 1
#define MAX_EVENTS 1000
#define MAX_EVENT_NAME 50

typedef struct {
    int id;
    char name[MAX_EVENT_NAME];
    int time;
} Event;

Event events[MAX_EVENTS];
int num_events;

void add_event(char* name, int time) {
    num_events++;
    events[num_events-1].id = num_events-1;
    strcpy(events[num_events-1].name, name);
    events[num_events-1].time = time;
}

void sort_events() {
    int i, j;
    Event temp;
    for (i=0; i<num_events-1; i++) {
        for (j=i+1; j<num_events; j++) {
            if (events[i].time > events[j].time) {
                temp = events[i];
                events[i] = events[j];
                events[j] = temp;
            }
        }
    }
}

int main() {
    int i, j, time;
    char input[100];
    printf("Enter the name of the event: ");
    scanf("%s", input);
    add_event(input, 0);
    printf("Enter the name of the event: ");
    scanf("%s", input);
    add_event(input, 0);
    printf("Enter the name of the event: ");
    scanf("%s", input);
    add_event(input, 0);
    sort_events();
    time = 0;
    while (time < TIME_LIMIT) {
        for (i=0; i<num_events; i++) {
            if (events[i].time == time) {
                printf("%s\n", events[i].name);
            }
        }
        time += TIME_STEP;
    }
    return 0;
}