//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of events that can occur during time travel
#define MAX_EVENTS 100

// Define the structure for each event during time travel
typedef struct {
    time_t timestamp; // Unix timestamp for the event
    char* description; // Description of the event
} TimeTravelEvent;

// Function to compare two events based on their timestamp
int compareEvents(const void* a, const void* b) {
    const TimeTravelEvent* eventA = (const TimeTravelEvent*)a;
    const TimeTravelEvent* eventB = (const TimeTravelEvent*)b;
    
    if (eventA->timestamp < eventB->timestamp) {
        return -1;
    } else if (eventA->timestamp > eventB->timestamp) {
        return 1;
    } else {
        return 0;
    }
}

// Function to print all the events in chronological order
void printEvents(TimeTravelEvent events[], int numEvents) {
    qsort(events, numEvents, sizeof(TimeTravelEvent), compareEvents);
    
    for (int i = 0; i < numEvents; i++) {
        printf("%ld: %s\n", events[i].timestamp, events[i].description);
    }
}

int main() {
    // Initialize the random number generator
    srand(time(NULL));
    
    // Define the starting and ending times for the time travel
    time_t startTime = time(NULL) - 86400; // One day ago
    time_t endTime = time(NULL) + 86400; // One day from now
    
    // Initialize the array to store the events
    TimeTravelEvent events[MAX_EVENTS];
    
    // Initialize the number of events
    int numEvents = 0;
    
    // Loop through the time travel period and generate random events
    for (time_t currentTime = startTime; currentTime <= endTime; currentTime += 3600) { // One hour intervals
        if (numEvents >= MAX_EVENTS) {
            break;
        }
        
        // Generate a random event description
        char* eventDescription = (char*)malloc(100 * sizeof(char));
        sprintf(eventDescription, "Event %d occurred at %ld", numEvents + 1, currentTime);
        
        // Add the event to the array
        events[numEvents] = (TimeTravelEvent){currentTime, eventDescription};
        numEvents++;
    }
    
    // Print the events in chronological order
    printf("Time Travel Events:\n");
    printEvents(events, numEvents);
    
    return 0;
}