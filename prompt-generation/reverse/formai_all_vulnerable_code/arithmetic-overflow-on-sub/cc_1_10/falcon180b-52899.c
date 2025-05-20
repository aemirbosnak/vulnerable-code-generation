//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EVENTS 1000

// Struct to hold event data
typedef struct {
    time_t timestamp;
    char *description;
} Event;

// Function to compare two events based on their timestamps
int compare_events(const void *a, const void *b) {
    const Event *event_a = (const Event *)a;
    const Event *event_b = (const Event *)b;

    if (event_a->timestamp < event_b->timestamp) {
        return -1;
    } else if (event_a->timestamp > event_b->timestamp) {
        return 1;
    } else {
        return 0;
    }
}

// Function to print the list of events in chronological order
void print_events(Event events[], int num_events) {
    qsort(events, num_events, sizeof(Event), compare_events);

    for (int i = 0; i < num_events; i++) {
        printf("%s - %s\n", ctime(&events[i].timestamp), events[i].description);
    }
}

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Initialize event list
    Event events[MAX_EVENTS];
    int num_events = 0;

    // Main loop
    while (1) {
        // Print current date and time
        time_t now = time(NULL);
        printf("Current time: %s\n", ctime(&now));

        // Prompt user for input
        char input[100];
        printf("Enter an event (or type 'quit' to exit): ");
        scanf("%s", input);

        // Check if user wants to quit
        if (strcmp(input, "quit") == 0) {
            break;
        }

        // Generate random timestamp between now and 1 hour ago
        time_t timestamp = now - rand() % 3600;

        // Convert timestamp to string representation
        char timestamp_str[100];
        strftime(timestamp_str, sizeof(timestamp_str), "%Y-%m-%d %H:%M:%S", localtime(&timestamp));

        // Add event to list
        events[num_events].timestamp = timestamp;
        events[num_events].description = strdup(input);
        num_events++;

        // Print confirmation message
        printf("Event added: %s - %s\n", timestamp_str, input);

        // Check if event list is full
        if (num_events >= MAX_EVENTS) {
            printf("Event list is full. Exiting...\n");
            break;
        }
    }

    // Print list of events in chronological order
    printf("\nChronological list of events:\n");
    print_events(events, num_events);

    return 0;
}