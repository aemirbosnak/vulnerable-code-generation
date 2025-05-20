//Falcon-180B DATASET v1.0 Category: System event logger ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_EVENTS 1000
#define EVENT_FILE "events.log"

// Event structure
typedef struct {
    char type[50];
    char message[200];
    time_t timestamp;
} Event;

int main() {
    FILE *eventFile;
    char buffer[1024];
    int bytesRead;
    Event event;

    // Open the event file for appending
    eventFile = fopen(EVENT_FILE, "a");
    if (eventFile == NULL) {
        printf("Error opening event file.\n");
        return 1;
    }

    // Read events from the file
    while (fgets(buffer, sizeof(buffer), eventFile)!= NULL) {
        if (sscanf(buffer, "%s %s %ld\n", event.type, event.message, &event.timestamp) == 3) {
            printf("%s - %s (%ld)\n", event.type, event.message, event.timestamp);
        }
    }

    // Close the event file
    fclose(eventFile);

    // Open the event file for writing
    eventFile = fopen(EVENT_FILE, "w");
    if (eventFile == NULL) {
        printf("Error opening event file for writing.\n");
        return 1;
    }

    // Write events to the file
    while (1) {
        printf("Enter event type (max 50 characters): ");
        scanf("%s", event.type);

        printf("Enter event message (max 200 characters): ");
        scanf("%s", event.message);

        event.timestamp = time(NULL);
        fprintf(eventFile, "%s %s %ld\n", event.type, event.message, event.timestamp);

        if (feof(eventFile)) {
            printf("Event file is full.\n");
            break;
        }
    }

    // Close the event file
    fclose(eventFile);

    return 0;
}