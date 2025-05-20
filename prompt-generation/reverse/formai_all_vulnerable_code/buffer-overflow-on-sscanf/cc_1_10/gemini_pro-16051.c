//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum length of a log line
#define MAX_LOG_LINE_LENGTH 1024

// Define the structure of a log entry
typedef struct log_entry {
    time_t timestamp;
    char *message;
} log_entry;

// Define the structure of a log file
typedef struct log_file {
    FILE *file;
    char *filename;
} log_file;

// Open a log file
log_file *open_log_file(char *filename) {
    log_file *log = malloc(sizeof(log_file));
    log->filename = filename;
    log->file = fopen(filename, "a");
    return log;
}

// Close a log file
void close_log_file(log_file *log) {
    fclose(log->file);
    free(log);
}

// Write a log entry to a log file
void write_log_entry(log_file *log, log_entry *entry) {
    fprintf(log->file, "%ld %s\n", entry->timestamp, entry->message);
}

// Read a log file and print the entries to the console
void read_log_file(log_file *log) {
    char line[MAX_LOG_LINE_LENGTH];
    while (fgets(line, MAX_LOG_LINE_LENGTH, log->file)) {
        // Parse the log line
        time_t timestamp;
        char *message;
        sscanf(line, "%ld %s", &timestamp, &message);

        // Create a log entry
        log_entry entry = {
            .timestamp = timestamp,
            .message = message,
        };

        // Print the log entry
        printf("%ld %s\n", entry.timestamp, entry.message);
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Check if a filename was provided
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Open the log file
    log_file *log = open_log_file(argv[1]);

    // Write a few log entries
    time_t timestamp = time(NULL);
    log_entry entry = {
        .timestamp = timestamp,
        .message = "This is a log entry",
    };
    write_log_entry(log, &entry);

    entry.message = "This is another log entry";
    write_log_entry(log, &entry);

    // Close the log file
    close_log_file(log);

    // Read the log file and print the entries to the console
    read_log_file(log);

    return 0;
}