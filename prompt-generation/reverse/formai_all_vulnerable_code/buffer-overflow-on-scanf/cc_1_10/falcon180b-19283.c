//Falcon-180B DATASET v1.0 Category: System event logger ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_EVENTS 100
#define EVENT_LOG_FILE "event_log.txt"

typedef struct {
    char event_type[20];
    time_t timestamp;
    char description[100];
} Event;

void log_event(char* event_type, char* description) {
    Event new_event;
    strcpy(new_event.event_type, event_type);
    strcpy(new_event.description, description);
    new_event.timestamp = time(NULL);

    FILE* event_log = fopen(EVENT_LOG_FILE, "a");
    if (event_log == NULL) {
        printf("Error: could not open event log file.\n");
        exit(1);
    }

    fprintf(event_log, "%s | %s | %s\n", ctime(&new_event.timestamp), new_event.event_type, new_event.description);
    fclose(event_log);
}

int main() {
    int choice;
    char event_type[20];
    char description[100];

    do {
        printf("Enter event type (up to 20 characters): ");
        scanf("%s", event_type);
        tolower(event_type);

        printf("Enter event description (up to 100 characters): ");
        scanf("%[^\n]", description);
        description[strcspn(description, "\n")] = '\0';

        log_event(event_type, description);

        printf("\nEvent logged successfully.\n");
        printf("Press 1 to log another event or any other key to exit.\n");
        scanf("%d", &choice);

    } while (choice == 1);

    return 0;
}