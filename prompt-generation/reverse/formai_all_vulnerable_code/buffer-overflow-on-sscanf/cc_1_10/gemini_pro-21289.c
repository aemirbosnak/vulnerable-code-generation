//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of a log entry
#define MAX_LOG_ENTRY_SIZE 1024

// Define the maximum number of log entries
#define MAX_LOG_ENTRIES 100

// Define the log file name
#define LOG_FILE_NAME "log.txt"

// Define the log entry structure
typedef struct log_entry {
    char timestamp[20];
    char level[10];
    char message[MAX_LOG_ENTRY_SIZE];
} log_entry;

// Read the log file and store the log entries in an array
log_entry log_entries[MAX_LOG_ENTRIES];
int num_log_entries = 0;

void read_log_file() {
    // Open the log file
    FILE *log_file = fopen(LOG_FILE_NAME, "r");
    if (log_file == NULL) {
        perror("Error opening log file");
        exit(1);
    }

    // Read the log entries from the file
    char line[MAX_LOG_ENTRY_SIZE];
    while (fgets(line, MAX_LOG_ENTRY_SIZE, log_file)) {
        // Parse the log entry
        sscanf(line, "%s %s %[^\n]", log_entries[num_log_entries].timestamp, log_entries[num_log_entries].level, log_entries[num_log_entries].message);

        // Increment the number of log entries
        num_log_entries++;
    }

    // Close the log file
    fclose(log_file);
}

// Print the log entries to the console
void print_log_entries() {
    for (int i = 0; i < num_log_entries; i++) {
        printf("%s %s %s\n", log_entries[i].timestamp, log_entries[i].level, log_entries[i].message);
    }
}

// Search the log entries for a specific message
int search_log_entries(char *message) {
    for (int i = 0; i < num_log_entries; i++) {
        if (strstr(log_entries[i].message, message) != NULL) {
            return i;
        }
    }

    return -1;
}

// Main function
int main() {
    // Read the log file
    read_log_file();

    // Print the log entries to the console
    print_log_entries();

    // Search the log entries for a specific message
    int index = search_log_entries("Error");
    if (index == -1) {
        printf("No error messages found in the log file\n");
    } else {
        printf("Error message found at index %d: %s\n", index, log_entries[index].message);
    }

    return 0;
}