//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_SIZE 1024

// Define the log level enum
typedef enum {
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARN,
    LOG_LEVEL_ERROR,
    LOG_LEVEL_FATAL
} log_level;

// Define the log entry struct
typedef struct {
    time_t timestamp;
    log_level level;
    char message[MAX_LOG_SIZE];
} log_entry;

// Create a new log entry
log_entry *log_entry_new(log_level level, const char *message) {
    log_entry *entry = malloc(sizeof(log_entry));
    if (entry == NULL) {
        return NULL;
    }

    entry->timestamp = time(NULL);
    entry->level = level;
    strncpy(entry->message, message, MAX_LOG_SIZE - 1);
    entry->message[MAX_LOG_SIZE - 1] = '\0';

    return entry;
}

// Free a log entry
void log_entry_free(log_entry *entry) {
    free(entry);
}

// Write a log entry to a file
void log_entry_write(log_entry *entry, FILE *file) {
    fprintf(file, "%ld %d %s\n", entry->timestamp, entry->level, entry->message);
}

// Read a log entry from a file
log_entry *log_entry_read(FILE *file) {
    log_entry *entry = malloc(sizeof(log_entry));
    if (entry == NULL) {
        return NULL;
    }

    fscanf(file, "%ld %d %[^\n]", &entry->timestamp, &entry->level, entry->message);

    return entry;
}

// Get the log level string
const char *log_level_string(log_level level) {
    switch (level) {
        case LOG_LEVEL_DEBUG:
            return "DEBUG";
        case LOG_LEVEL_INFO:
            return "INFO";
        case LOG_LEVEL_WARN:
            return "WARN";
        case LOG_LEVEL_ERROR:
            return "ERROR";
        case LOG_LEVEL_FATAL:
            return "FATAL";
        default:
            return "UNKNOWN";
    }
}

// Print the log entry
void log_entry_print(log_entry *entry) {
    printf("%ld %s %s\n", entry->timestamp, log_level_string(entry->level), entry->message);
}

// Main function
int main(int argc, char **argv) {
    // Check if the user provided a log file name
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <log_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open the log file
    FILE *log_file = fopen(argv[1], "r");
    if (log_file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Read the log entries from the file
    log_entry *entry;
    while ((entry = log_entry_read(log_file)) != NULL) {
        // Print the log entry
        log_entry_print(entry);

        // Free the log entry
        log_entry_free(entry);
    }

    // Close the log file
    fclose(log_file);

    return EXIT_SUCCESS;
}