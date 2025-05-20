//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLIENTS 10
#define MAX_EVENTS 10

struct client {
    char name[20];
    char phone[20];
};

struct event {
    int start_time;
    int end_time;
    int duration;
    char description[100];
};

void print_schedule(struct event* events, int num_events) {
    printf("Schedule:\n");
    for (int i = 0; i < num_events; i++) {
        printf("Client: %s\n", events[i].description);
        printf("Start time: %d\n", events[i].start_time);
        printf("End time: %d\n", events[i].end_time);
        printf("Duration: %d\n\n", events[i].duration);
    }
}

int main() {
    struct client clients[MAX_CLIENTS];
    struct event events[MAX_EVENTS];
    int num_clients = 0, num_events = 0;
    int client_index, event_index;

    printf("Enter the number of clients:\n");
    scanf("%d", &num_clients);
    for (int i = 0; i < num_clients; i++) {
        printf("Enter client name and phone number:\n");
        fgets(clients[i].name, sizeof(clients[i].name), stdin);
        fgets(clients[i].phone, sizeof(clients[i].phone), stdin);
    }

    printf("Enter the number of events:\n");
    scanf("%d", &num_events);
    for (int i = 0; i < num_events; i++) {
        printf("Enter event details:\n");
        scanf("%d %d %d %s", &events[i].start_time, &events[i].end_time, &events[i].duration, events[i].description);
    }

    printf("Schedule:\n");
    for (int i = 0; i < num_events; i++) {
        printf("Client: %s\n", events[i].description);
        printf("Start time: %d\n", events[i].start_time);
        printf("End time: %d\n", events[i].end_time);
        printf("Duration: %d\n\n", events[i].duration);
    }

    return 0;
}