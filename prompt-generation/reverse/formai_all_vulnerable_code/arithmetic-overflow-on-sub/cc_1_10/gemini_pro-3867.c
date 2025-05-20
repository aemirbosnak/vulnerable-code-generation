//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: portable
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Define the maximum number of time travel events
#define MAX_EVENTS 10

// Define the possible time travel events
typedef enum {
    EVENT_BIRTH,
    EVENT_DEATH,
    EVENT_MARRIAGE,
    EVENT_DIVORCE,
    EVENT_JOB_START,
    EVENT_JOB_END,
    EVENT_MOVE,
    EVENT_TRAVEL,
    EVENT_OTHER
} event_type;

// Define the time travel event structure
typedef struct {
    event_type type;
    time_t timestamp;
    char description[256];
} event;

// Function to generate a random time travel event
event generate_event() {
    event e;
    
    // Generate a random event type
    e.type = (event_type)rand() % EVENT_OTHER;
    
    // Generate a random timestamp
    e.timestamp = time(NULL) - rand() % (365 * 24 * 60 * 60);
    
    // Generate a random description
    switch (e.type) {
        case EVENT_BIRTH:
            sprintf(e.description, "Birth");
            break;
        case EVENT_DEATH:
            sprintf(e.description, "Death");
            break;
        case EVENT_MARRIAGE:
            sprintf(e.description, "Marriage");
            break;
        case EVENT_DIVORCE:
            sprintf(e.description, "Divorce");
            break;
        case EVENT_JOB_START:
            sprintf(e.description, "Job start");
            break;
        case EVENT_JOB_END:
            sprintf(e.description, "Job end");
            break;
        case EVENT_MOVE:
            sprintf(e.description, "Move");
            break;
        case EVENT_TRAVEL:
            sprintf(e.description, "Travel");
            break;
        case EVENT_OTHER:
            sprintf(e.description, "Other");
            break;
    }
    
    return e;
}

// Function to print a time travel event
void print_event(event e) {
    printf("%s: %s\n", ctime(&e.timestamp), e.description);
}

// Function to main() function
int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Generate a random time travel event
    event e = generate_event();
    
    // Print the time travel event
    print_event(e);
    
    return 0;
}