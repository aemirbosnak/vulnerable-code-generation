//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of events that can be stored
#define MAX_EVENTS 100

// Define the structure for each event
typedef struct {
    time_t timestamp; // The time when the event occurred
    char description[100]; // The description of the event
} Event;

// Function to compare two events based on their timestamps
int compareEvents(const void *a, const void *b) {
    const Event *eventA = (const Event *)a;
    const Event *eventB = (const Event *)b;
    
    if(eventA->timestamp < eventB->timestamp) {
        return -1;
    } else if(eventA->timestamp > eventB->timestamp) {
        return 1;
    } else {
        return 0;
    }
}

// Function to print the list of events in chronological order
void printEvents(Event events[], int numEvents) {
    qsort(events, numEvents, sizeof(Event), compareEvents);
    
    for(int i = 0; i < numEvents; i++) {
        printf("%s - %s\n", ctime(&events[i].timestamp), events[i].description);
    }
}

int main() {
    // Initialize the list of events
    Event events[MAX_EVENTS];
    int numEvents = 0;
    
    // Simulate time travel
    time_t currentTime = time(NULL);
    
    while(numEvents < MAX_EVENTS) {
        char input[100];
        printf("Enter an event that occurred at %s or type 'travel' to go back in time: ", ctime(&currentTime));
        scanf("%s", input);
        
        if(strcmp(input, "travel") == 0) {
            currentTime -= 3600; // Go back one hour
        } else {
            strcpy(events[numEvents].description, input);
            events[numEvents].timestamp = currentTime;
            numEvents++;
        }
    }
    
    // Print the list of events in chronological order
    printEvents(events, numEvents);
    
    return 0;
}