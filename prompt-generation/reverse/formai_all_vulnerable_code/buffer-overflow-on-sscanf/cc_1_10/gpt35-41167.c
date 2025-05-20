//FormAI DATASET v1.0 Category: Log analysis ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Open the log file for reading
    FILE *log_file = fopen("example_log.txt", "r");

    // Make sure the file was opened successfully
    if (log_file == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    // Define our data structures for storing log data
    typedef struct {
        char date[11];
        char time[6];
        char level[10];
        char message[100];
    } LogEntry;

    // Create an array to store all of the log entries
    LogEntry log_entries[1000];
    int num_entries = 0;

    // Read each line of the log file and parse it into a LogEntry struct
    char line[200];
    while (fgets(line, sizeof(line), log_file)) {
        // Allocate memory for a new LogEntry struct
        LogEntry *new_entry = malloc(sizeof(LogEntry));
        if (new_entry == NULL) {
            printf("Error: unable to allocate memory for new log entry.\n");
            return 1;
        }

        // Parse the line and populate the new LogEntry struct
        sscanf(line, "%10s %5s %9s %[^\n]", new_entry->date, new_entry->time, new_entry->level, new_entry->message);

        // Add the new LogEntry struct to the array
        log_entries[num_entries++] = *new_entry;
    }

    // Close the log file now that we've read all of the data
    fclose(log_file);

    // Print out each log entry in a formatted manner
    for (int i = 0; i < num_entries; i++) {
        printf("%s %s [%s] %s\n", log_entries[i].date, log_entries[i].time, log_entries[i].level, log_entries[i].message);
    }

    // Free any allocated memory to avoid memory leaks
    for (int i = 0; i < num_entries; i++) {
        free(&log_entries[i]);
    }

    return 0;
}