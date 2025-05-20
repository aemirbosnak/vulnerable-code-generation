//Code Llama-13B DATASET v1.0 Category: Intrusion detection system ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define constants
#define MAX_LENGTH 100
#define THRESHOLD 5

// Define structs
typedef struct {
    char name[MAX_LENGTH];
    int count;
} LogEntry;

typedef struct {
    LogEntry* entries;
    int size;
    int capacity;
} Log;

// Function prototypes
void add_entry(Log* log, const char* name);
void print_log(Log* log);
int is_intrusion(Log* log);

int main() {
    // Create a new log
    Log log;
    log.entries = malloc(sizeof(LogEntry) * 10);
    log.size = 0;
    log.capacity = 10;

    // Add some entries to the log
    add_entry(&log, "john");
    add_entry(&log, "jane");
    add_entry(&log, "john");
    add_entry(&log, "jane");
    add_entry(&log, "john");

    // Check if there is an intrusion
    if (is_intrusion(&log)) {
        printf("Intrusion detected!\n");
    } else {
        printf("No intrusion detected.\n");
    }

    // Print the log
    print_log(&log);

    // Free the log
    free(log.entries);

    return 0;
}

void add_entry(Log* log, const char* name) {
    // Check if the log is full
    if (log->size == log->capacity) {
        log->capacity *= 2;
        log->entries = realloc(log->entries, log->capacity * sizeof(LogEntry));
    }

    // Add the entry to the log
    strcpy(log->entries[log->size].name, name);
    log->entries[log->size].count = 1;
    log->size++;
}

void print_log(Log* log) {
    for (int i = 0; i < log->size; i++) {
        printf("%s: %d\n", log->entries[i].name, log->entries[i].count);
    }
}

int is_intrusion(Log* log) {
    // Check if any name appears more than THRESHOLD times
    for (int i = 0; i < log->size; i++) {
        if (log->entries[i].count > THRESHOLD) {
            return 1;
        }
    }

    return 0;
}