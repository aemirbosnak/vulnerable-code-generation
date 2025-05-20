//Falcon-180B DATASET v1.0 Category: System event logger ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of events that can be stored
#define MAX_EVENTS 100

// Define the structure for each event
typedef struct {
    time_t timestamp;
    char *description;
} Event;

// Declare the global array of events
Event events[MAX_EVENTS];

// Declare the current index into the array
int currentIndex = 0;

// Function prototypes
void logEvent(char *description);
void printEvents();

// Main function
int main() {
    int choice;

    // Loop until the user chooses to quit
    do {
        // Print the menu
        printf("=== Event Logger ===\n");
        printf("1. Log an event\n");
        printf("2. Print events\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Call the appropriate function based on the user's choice
        switch(choice) {
            case 1:
                logEvent("Hello, world!");
                break;
            case 2:
                printEvents();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while(choice!= 3);

    return 0;
}

// Function to log an event
void logEvent(char *description) {
    // Check if the array is full
    if(currentIndex == MAX_EVENTS) {
        printf("Error: Event array is full.\n");
        return;
    }

    // Get the current time
    time_t now = time(NULL);

    // Store the event in the array
    events[currentIndex].timestamp = now;
    events[currentIndex].description = description;

    // Increment the index
    currentIndex++;
}

// Function to print the events
void printEvents() {
    // Check if there are any events
    if(currentIndex == 0) {
        printf("No events have been logged.\n");
        return;
    }

    // Print the events in reverse chronological order
    for(int i = currentIndex - 1; i >= 0; i--) {
        printf("%s (%ld seconds ago)\n", events[i].description, difftime(time(NULL), events[i].timestamp));
    }
}