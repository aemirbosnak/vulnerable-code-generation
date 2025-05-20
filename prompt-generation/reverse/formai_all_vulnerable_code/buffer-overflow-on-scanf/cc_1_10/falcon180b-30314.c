//Falcon-180B DATASET v1.0 Category: System event logger ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100
#define MAX_EVENT_TEXT_LEN 100

struct event {
    char text[MAX_EVENT_TEXT_LEN];
    time_t timestamp;
};

int main() {
    struct event events[MAX_EVENTS];
    int num_events = 0;
    FILE *log_file = NULL;

    // Open the log file for writing
    log_file = fopen("event_log.txt", "w");
    if (log_file == NULL) {
        printf("Error: Could not open log file.\n");
        exit(1);
    }

    // Log a startup event
    struct event startup_event = { "Program started", time(NULL) };
    fprintf(log_file, "STARTUP %s\n", ctime(&startup_event.timestamp));

    // Main event loop
    while (1) {
        // Check for user input
        char input[MAX_EVENT_TEXT_LEN];
        printf("Enter an event (or type 'quit' to exit): ");
        scanf("%s", input);

        // Exit the program if the user types "quit"
        if (strcmp(input, "quit") == 0) {
            break;
        }

        // Log the event
        struct event new_event = { input, time(NULL) };
        fprintf(log_file, "EVENT %s\n", ctime(&new_event.timestamp));
        num_events++;

        // Check if we need to rotate the log file
        if (num_events >= MAX_EVENTS) {
            fclose(log_file);
            log_file = fopen("event_log.txt", "w");
            if (log_file == NULL) {
                printf("Error: Could not open log file.\n");
                exit(1);
            }
            num_events = 0;
        }
    }

    // Log a shutdown event
    struct event shutdown_event = { "Program exited", time(NULL) };
    fprintf(log_file, "SHUTDOWN %s\n", ctime(&shutdown_event.timestamp));

    // Close the log file
    fclose(log_file);

    return 0;
}