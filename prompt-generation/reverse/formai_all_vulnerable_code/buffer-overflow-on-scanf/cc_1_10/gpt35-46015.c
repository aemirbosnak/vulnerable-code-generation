//FormAI DATASET v1.0 Category: System event logger ; Style: medieval
#include <stdio.h>
#include <time.h>
#include <string.h>

#define MAX_EVENTS 100

typedef struct {
    char event_name[50];
    char event_description[500];
    char timestamp[50];
} Event;

Event events[MAX_EVENTS];
int num_of_events = 0;

void record_event(char *event_name, char *event_description) {
    // get timestamp
    time_t now;
    time(&now);
    char timestamp[50];
    strftime(timestamp, 50, "%Y-%m-%d %H:%M:%S", localtime(&now));
    
    // add event to events array
    strcpy(events[num_of_events].event_name, event_name);
    strcpy(events[num_of_events].event_description, event_description);
    strcpy(events[num_of_events].timestamp, timestamp);
    
    // increment number of events
    num_of_events++;
    
    // print success message
    printf("An event has been recorded successfully.\n");
}

void view_events() {
    if (num_of_events == 0) {
        printf("No events have been recorded yet.\n");
    } else {
        printf("List of recorded events:\n");
        for (int i = 0; i < num_of_events; i++) {
            printf("Event name: %s\n", events[i].event_name);
            printf("Event description: %s\n", events[i].event_description);
            printf("Timestamp: %s\n\n", events[i].timestamp);
        }
    }
}

int main() {
    // print welcome message
    printf("Welcome to the medieval event logger!\n");
    
    // loop until user chooses to exit
    int choice = 0;
    while (choice != 3) {
        printf("Please choose an option:\n");
        printf("1. Record an event\n");
        printf("2. View recorded events\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        
        // handle user choice
        switch (choice) {
            case 1: {
                // ask for event details
                char event_name[50];
                char event_description[500];
                printf("Please enter the name of the event: ");
                scanf("%s", event_name);
                printf("Please enter a description for the event: ");
                scanf("%s", event_description);
                
                // record the event
                record_event(event_name, event_description);
                break;
            }
            case 2: {
                // view recorded events
                view_events();
                break;
            }
            case 3: {
                // exit the program
                printf("Exiting the medieval event logger. Goodbye!\n");
                return 0;
            }
            default: {
                // handle invalid input
                printf("Invalid input. Please try again.\n");
                break;
            }
        }
    }
    return 0;
}