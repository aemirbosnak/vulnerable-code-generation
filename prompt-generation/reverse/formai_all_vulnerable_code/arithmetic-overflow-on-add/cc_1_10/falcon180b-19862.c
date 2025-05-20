//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of events that can occur during time travel
#define MAX_EVENTS 100

// Define the structure for each event
typedef struct {
    time_t time;
    char description[100];
} Event;

// Function to compare two events based on their time
int compareEvents(const void* a, const void* b) {
    const Event* eventA = (const Event*)a;
    const Event* eventB = (const Event*)b;
    
    if (eventA->time < eventB->time) {
        return -1;
    } else if (eventA->time > eventB->time) {
        return 1;
    } else {
        return 0;
    }
}

// Function to print the list of events in chronological order
void printEvents(Event* events, int numEvents) {
    qsort(events, numEvents, sizeof(Event), compareEvents);
    
    for (int i = 0; i < numEvents; i++) {
        printf("%s - %s\n", ctime(&events[i].time), events[i].description);
    }
}

// Function to simulate time travel and record events
void timeTravel(Event* events, int* numEvents) {
    // Set the initial time
    time_t startTime = time(NULL);
    
    // Loop until the user decides to stop time traveling
    while (1) {
        // Print the current time
        printf("Current time: %s\n", ctime(&startTime));
        
        // Ask the user if they want to record an event
        char choice;
        printf("Do you want to record an event? (y/n): ");
        scanf(" %c", &choice);
        
        if (choice == 'y' || choice == 'Y') {
            // Get the event description from the user
            char description[100];
            printf("Enter the event description: ");
            scanf("%s", description);
            
            // Add the event to the list
            if (*numEvents >= MAX_EVENTS) {
                printf("Maximum number of events reached.\n");
            } else {
                events[*numEvents].time = startTime;
                strcpy(events[*numEvents].description, description);
                (*numEvents)++;
            }
        } else if (choice == 'n' || choice == 'N') {
            // Continue time traveling
            startTime = time(NULL) + 60; // Travel one minute into the future
        } else {
            printf("Invalid choice.\n");
        }
    }
}

int main() {
    // Initialize the event list
    Event events[MAX_EVENTS];
    int numEvents = 0;
    
    // Simulate time travel
    timeTravel(events, &numEvents);
    
    // Print the list of events in chronological order
    printf("\nList of events:\n");
    printEvents(events, numEvents);
    
    return 0;
}