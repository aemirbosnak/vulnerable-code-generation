//FormAI DATASET v1.0 Category: System event logger ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Define event types
typedef enum Event{
    ERROR,
    WARNING,
    INFO
} Event;

// Define log metadata struct
typedef struct LogEntry{
    time_t timestamp;
    Event eventType;
    int eventCode;
    char message[128];
} LogEntry;

int main(){

    // Declare variable for log entry
    LogEntry entry;

    // Seed random number generator
    srand(time(NULL));

    // Loop 50 times to generate log events
    for(int i=1; i<=50; i++){

        // Assign random timestamp to log entry
        entry.timestamp = time(NULL) - (rand() % 10000);

        // Assign random event type to log entry
        int eventTypeRand = rand() % 3;
        if(eventTypeRand == 0){
            entry.eventType = ERROR;
        } else if(eventTypeRand == 1){
            entry.eventType = WARNING;
        } else {
            entry.eventType = INFO;
        }

        // Assign random event code to log entry
        entry.eventCode = rand() % 100;

        // Generate random message for log entry
        char message[128];
        sprintf(message, "Event generated at %ld with code %d", entry.timestamp, entry.eventCode);

        // Copy message to log entry
        for(int j=0; j<strlen(message); j++){
            entry.message[j] = message[j];
        }

        // Sleep for random amount of time to simulate event occurring at different times
        int sleepTime = rand() % 5;
        sleep(sleepTime);

        // Print log entry to console
        printf("Event %d: Timestamp=%ld, Type=%d, Code=%d, Message=%s\n", i, entry.timestamp, entry.eventType, entry.eventCode, entry.message);
    }

    return 0;
}