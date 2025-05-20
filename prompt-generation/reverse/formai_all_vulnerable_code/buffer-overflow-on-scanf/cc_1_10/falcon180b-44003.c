//Falcon-180B DATASET v1.0 Category: System event logger ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EVENTS 100
#define MAX_EVENT_LENGTH 100

typedef struct {
    time_t timestamp;
    char message[MAX_EVENT_LENGTH];
} Event;

int main() {
    FILE *log_file;
    char log_path[MAX_EVENT_LENGTH];
    Event events[MAX_EVENTS];
    int num_events = 0;

    // Get user input for log file path
    printf("Enter log file path: ");
    scanf("%s", log_path);

    // Append ".log" to the log file path
    strcat(log_path, ".log");

    // Open the log file for writing
    log_file = fopen(log_path, "w");
    if (log_file == NULL) {
        printf("Error: could not open log file.\n");
        exit(1);
    }

    // Loop until user enters "quit"
    char command[MAX_EVENT_LENGTH];
    while (1) {
        printf("Enter command (log or quit): ");
        scanf("%s", command);

        if (strcmp(command, "log") == 0) {
            // Get user input for event message
            printf("Enter event message: ");
            scanf("%s", events[num_events].message);

            // Get current timestamp
            time_t now = time(NULL);
            strftime(events[num_events].message, MAX_EVENT_LENGTH, "%Y-%m-%d %H:%M:%S", localtime(&now));

            // Write event to log file
            fprintf(log_file, "%s\n", events[num_events].message);

            // Increment number of events
            num_events++;
        } else if (strcmp(command, "quit") == 0) {
            // Close the log file
            fclose(log_file);
            printf("Program exited.\n");
            exit(0);
        } else {
            // Invalid command
            printf("Invalid command.\n");
        }
    }

    return 0;
}