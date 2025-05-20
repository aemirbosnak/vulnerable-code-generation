//FormAI DATASET v1.0 Category: System event logger ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of events
#define MAX_EVENTS 100

// Define the maximum length of event descriptions
#define MAX_DESCRIPTION_LENGTH 100

// Define the maximum length of the location string
#define MAX_LOCATION_LENGTH 50

// Define a struct to hold the event information
typedef struct {
    char description[MAX_DESCRIPTION_LENGTH];
    char location[MAX_LOCATION_LENGTH];
    time_t timestamp;
} Event;

// Define an array to hold the events
Event events[MAX_EVENTS];

// Define a variable to keep track of the number of events logged
int numEvents = 0;

// Function to add a new event to the log
void logEvent(char *description, char *location) {
    if (numEvents >= MAX_EVENTS) {
        printf("Event log is full!\n");
        return;
    }
    
    // Add the event to the log
    Event newEvent;
    newEvent.timestamp = time(NULL);
    strncpy(newEvent.description, description, MAX_DESCRIPTION_LENGTH);
    strncpy(newEvent.location, location, MAX_LOCATION_LENGTH);
    events[numEvents] = newEvent;
    numEvents++;
    
    // Print a confirmation message
    printf("Event logged successfully!\n");
}

// Function to display all events in the log
void displayEvents() {
    if (numEvents == 0) {
        printf("Event log is empty!\n");
        return;
    }
    
    printf("=============== EVENT LOG ===============\n");
    for (int i = 0; i < numEvents; i++) {
        printf("EVENT #%d\n", i+1);
        printf("Timestamp: %s", ctime(&events[i].timestamp));
        printf("Description: %s\n", events[i].description);
        printf("Location: %s\n", events[i].location);
        printf("----------------------------------------\n");
    }
}

int main() {
    printf("Welcome to the post-apocalyptic event logger.\n");
    
    // Run the event logger until the user chooses to quit
    while (1) {
        printf("Choose an option:\n");
        printf("1. Log a new event\n");
        printf("2. Display all events\n");
        printf("3. Quit\n");
        
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter a description for the event: ");
                char description[MAX_DESCRIPTION_LENGTH];
                scanf("%s", description);
                printf("Enter a location for the event: ");
                char location[MAX_LOCATION_LENGTH];
                scanf("%s", location);
                logEvent(description, location);
                break;
            case 2:
                displayEvents();
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
}