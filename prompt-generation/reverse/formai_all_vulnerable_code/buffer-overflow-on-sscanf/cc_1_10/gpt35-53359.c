//FormAI DATASET v1.0 Category: Log analysis ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a log entry
typedef struct log_entry {
    int timestamp;
    char* message;
} LogEntry;

int main() {
    // Open the log file for reading
    FILE* log_file = fopen("example.log", "r");
    if (log_file == NULL) {
        printf("Error: could not open log file");
        exit(EXIT_FAILURE);
    }
    
    // Create an array to store the log entries
    LogEntry log_entries[1000];
    int num_entries = 0;
    
    // Read the log file line by line
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, log_file)) != -1) {
        // Parse the timestamp and message from the log entry
        int timestamp = 0;
        char* message = malloc(256);
        sscanf(line, "%d %s", &timestamp, message);
        
        // Create a new log entry object and add it to the array
        LogEntry new_entry;
        new_entry.timestamp = timestamp;
        new_entry.message = message;
        log_entries[num_entries] = new_entry;
        num_entries++;
        
        // Resize the array if necessary
        if (num_entries >= 1000) {
            printf("Error: too many log entries");
            exit(EXIT_FAILURE);
        }
    }
    
    // Close the log file and free the memory used by the line buffer
    fclose(log_file);
    free(line);
    
    // Print out the log entries in chronological order
    for (int i = 0; i < num_entries; i++) {
        for (int j = i + 1; j < num_entries; j++) {
            if (log_entries[i].timestamp > log_entries[j].timestamp) {
                LogEntry temp_entry = log_entries[i];
                log_entries[i] = log_entries[j];
                log_entries[j] = temp_entry;
            }
        }
    }
    
    for (int i = 0; i < num_entries; i++) {
        printf("%d %s", log_entries[i].timestamp, log_entries[i].message);
    }
    
    return 0;
}