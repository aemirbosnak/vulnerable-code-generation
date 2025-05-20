//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum size of the log file
#define MAX_LOG_SIZE 1024000

// Define the maximum number of log lines
#define MAX_LOG_LINES 10000

// Define the maximum size of each log line
#define MAX_LOG_LINE_SIZE 1024

// Define the structure of a log entry
typedef struct log_entry {
    time_t timestamp;
    char *message;
} log_entry;

// Define the structure of the log file
typedef struct log_file {
    log_entry *entries;
    int num_entries;
    int max_entries;
} log_file;

// Create a new log file
log_file *log_file_new() {
    log_file *log = malloc(sizeof(log_file));
    if (log == NULL) {
        return NULL;
    }

    log->entries = malloc(sizeof(log_entry) * MAX_LOG_LINES);
    if (log->entries == NULL) {
        free(log);
        return NULL;
    }

    log->num_entries = 0;
    log->max_entries = MAX_LOG_LINES;

    return log;
}

// Free the memory associated with a log file
void log_file_free(log_file *log) {
    if (log == NULL) {
        return;
    }

    for (int i = 0; i < log->num_entries; i++) {
        free(log->entries[i].message);
    }

    free(log->entries);
    free(log);
}

// Add a log entry to a log file
int log_file_add_entry(log_file *log, time_t timestamp, char *message) {
    if (log == NULL || message == NULL) {
        return -1;
    }

    if (log->num_entries >= log->max_entries) {
        return -1;
    }

    log->entries[log->num_entries].timestamp = timestamp;
    log->entries[log->num_entries].message = strdup(message);
    log->num_entries++;

    return 0;
}

// Print the contents of a log file to the console
void log_file_print(log_file *log) {
    if (log == NULL) {
        return;
    }

    for (int i = 0; i < log->num_entries; i++) {
        printf("%s: %s\n", ctime(&log->entries[i].timestamp), log->entries[i].message);
    }
}

// Read a log file from a file
log_file *log_file_read_from_file(char *filename) {
    if (filename == NULL) {
        return NULL;
    }

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    log_file *log = log_file_new();
    if (log == NULL) {
        fclose(file);
        return NULL;
    }

    char line[MAX_LOG_LINE_SIZE];
    while (fgets(line, MAX_LOG_LINE_SIZE, file) != NULL) {
        // Parse the line
        time_t timestamp;
        char message[MAX_LOG_LINE_SIZE];
        if (sscanf(line, "%ld: %s", &timestamp, message) != 2) {
            continue;
        }

        // Add the entry to the log
        if (log_file_add_entry(log, timestamp, message) != 0) {
            log_file_free(log);
            fclose(file);
            return NULL;
        }
    }

    fclose(file);

    return log;
}

// Write a log file to a file
int log_file_write_to_file(log_file *log, char *filename) {
    if (log == NULL || filename == NULL) {
        return -1;
    }

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        return -1;
    }

    for (int i = 0; i < log->num_entries; i++) {
        fprintf(file, "%ld: %s\n", log->entries[i].timestamp, log->entries[i].message);
    }

    fclose(file);

    return 0;
}

// Search a log file for a keyword
int log_file_search(log_file *log, char *keyword) {
    if (log == NULL || keyword == NULL) {
        return -1;
    }

    int found = 0;

    for (int i = 0; i < log->num_entries; i++) {
        if (strstr(log->entries[i].message, keyword) != NULL) {
            printf("%s: %s\n", ctime(&log->entries[i].timestamp), log->entries[i].message);
            found = 1;
        }
    }

    return found;
}

// Main function
int main(int argc, char **argv) {
    // Check if a log file was specified
    if (argc < 2) {
        printf("Usage: %s <log file>\n", argv[0]);
        return 1;
    }

    // Read the log file
    log_file *log = log_file_read_from_file(argv[1]);
    if (log == NULL) {
        printf("Error reading log file\n");
        return 1;
    }

    // Print the contents of the log file
    log_file_print(log);

    // Search the log file for a keyword
    char keyword[] = "error";
    int found = log_file_search(log, keyword);
    if (found) {
        printf("The keyword \"%s\" was found in the log file\n", keyword);
    } else {
        printf("The keyword \"%s\" was not found in the log file\n", keyword);
    }

    // Free the memory associated with the log file
    log_file_free(log);

    return 0;
}