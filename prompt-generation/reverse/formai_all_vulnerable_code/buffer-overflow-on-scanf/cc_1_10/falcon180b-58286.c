//Falcon-180B DATASET v1.0 Category: System event logger ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define BUFFER_SIZE 1000
#define EVENT_MAX 100

typedef struct {
    char event_type[20];
    char event_message[80];
    time_t timestamp;
} Event;

int event_count = 0;
FILE *log_file = NULL;

void initialize_log_file(char *filename) {
    log_file = fopen(filename, "w");
    if (log_file == NULL) {
        printf("Error: Could not open log file.\n");
        exit(1);
    }
}

void write_event_to_log(Event event) {
    fprintf(log_file, "Event Type: %s\n", event.event_type);
    fprintf(log_file, "Event Message: %s\n", event.event_message);
    fprintf(log_file, "Timestamp: %s\n\n", ctime(&event.timestamp));
}

void close_log_file() {
    fclose(log_file);
}

void log_event(char *event_type, char *event_message) {
    time_t timestamp = time(NULL);
    Event event = {
       .event_type = event_type,
       .event_message = event_message,
       .timestamp = timestamp
    };
    write_event_to_log(event);
    event_count++;
}

int main() {
    char filename[20];
    printf("Enter log file name: ");
    scanf("%s", filename);
    initialize_log_file(filename);

    for (int i = 0; i < EVENT_MAX; i++) {
        log_event("Event Type", "Event Message");
    }

    close_log_file();
    printf("Total events logged: %d\n", event_count);
    return 0;
}