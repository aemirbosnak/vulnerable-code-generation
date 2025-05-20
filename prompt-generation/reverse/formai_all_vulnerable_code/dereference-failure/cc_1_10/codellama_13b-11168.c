//Code Llama-13B DATASET v1.0 Category: System event logger ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to store log entries
typedef struct {
    time_t timestamp;
    char message[256];
} LogEntry;

// Global variables
LogEntry* log_entries = NULL;
int num_log_entries = 0;

// Function to add a new log entry
void add_log_entry(const char* message) {
    LogEntry entry;
    entry.timestamp = time(NULL);
    strcpy(entry.message, message);

    // Reallocate memory for the log entries array
    log_entries = realloc(log_entries, (num_log_entries + 1) * sizeof(LogEntry));
    if (log_entries == NULL) {
        printf("Error: Unable to allocate memory for log entries\n");
        exit(1);
    }

    // Add the new log entry to the array
    log_entries[num_log_entries] = entry;
    num_log_entries++;
}

// Function to print the log entries
void print_log_entries() {
    for (int i = 0; i < num_log_entries; i++) {
        LogEntry entry = log_entries[i];
        printf("[%s] %s\n", ctime(&entry.timestamp), entry.message);
    }
}

int main() {
    // Add some log entries
    add_log_entry("This is a test message");
    add_log_entry("Another test message");
    add_log_entry("This is the third test message");

    // Print the log entries
    print_log_entries();

    // Free the log entries array
    free(log_entries);

    return 0;
}