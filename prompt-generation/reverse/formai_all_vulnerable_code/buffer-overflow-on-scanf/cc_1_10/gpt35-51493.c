//FormAI DATASET v1.0 Category: System event logger ; Style: real-life
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EVENTS 1000

typedef struct {
    char timestamp[20];
    char event_type[20];
    char event_message[100];
} Event;

void log_event(Event events[], int *num_events, char event_type[], char event_message[]);
void display_events(Event events[], int num_events);
void write_events_to_file(Event events[], int num_events);

int main() {
    Event events[MAX_EVENTS];
    int num_events = 0;
    char event_type[20], event_message[100];
    int choice;

    printf("Welcome to the System event logger.\n");

    do {
        printf("\nMenu:\n");
        printf("1. Log a new event\n");
        printf("2. Display all events\n");
        printf("3. Write events to file\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter the event type: ");
                scanf("%s", event_type);

                printf("Enter the event message: ");
                getchar();
                fgets(event_message, sizeof(event_message), stdin);
                event_message[strlen(event_message) - 1] = '\0';

                log_event(events, &num_events, event_type, event_message);
                break;

            case 2:
                display_events(events, num_events);
                break;

            case 3:
                write_events_to_file(events, num_events);
                printf("\nEvents written to file successfully.\n");
                break;

            case 4:
                printf("\nExiting...\n");
                break;

            default:
                printf("\nPlease enter a valid choice.\n");
                break;
        }
    } while(choice != 4);

    return 0;
}

void log_event(Event events[], int *num_events, char event_type[], char event_message[]) {
    Event new_event;
    time_t current_time;
    struct tm * time_info;

    if (*num_events == MAX_EVENTS) {
        printf("\nEvent log is full. Cannot log new event.\n");
        return;
    }

    time(&current_time);
    time_info = localtime(&current_time);
    strftime(new_event.timestamp, sizeof(new_event.timestamp), "%Y-%m-%d %H:%M:%S", time_info);

    strcpy(new_event.event_type, event_type);
    strcpy(new_event.event_message, event_message);

    events[(*num_events)++] = new_event;

    printf("\nNew event logged successfully.\n");
}

void display_events(Event events[], int num_events) {
    if (num_events == 0) {
        printf("\nNo events to display.\n");
        return;
    }

    printf("\n%-20s %-20s %-100s\n", "Timestamp", "Event Type", "Event Message");

    for (int i = 0; i < num_events; i++) {
        printf("%-20s %-20s %-100s\n", events[i].timestamp, events[i].event_type, events[i].event_message);
    }
}

void write_events_to_file(Event events[], int num_events) {
    FILE *fp;

    fp = fopen("event_log.txt", "w");

    fprintf(fp, "%-20s %-20s %-100s\n", "Timestamp", "Event Type", "Event Message");

    for (int i = 0; i < num_events; i++) {
        fprintf(fp, "%-20s %-20s %-100s\n", events[i].timestamp, events[i].event_type, events[i].event_message);
    }

    fclose(fp);
}