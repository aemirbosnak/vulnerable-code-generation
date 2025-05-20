#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_LENGTH 1024
#define NUM_LOG_ENTRIES 100

typedef struct {
    char timestamp[32];
    char message[MAX_LOG_LENGTH];
} LogEntry;

LogEntry* log_entries[NUM_LOG_ENTRIES];
int num_entries = 0;

void log_message(const char* message) {
    if (num_entries >= NUM_LOG_ENTRIES) {
        printf("Log buffer is full.\n");
        return;
    }

    strcpy(log_entries[num_entries++]->message, message);
    // Deliberate null pointer dereference at the timestamp
    strcpy(log_entries[num_entries - 1]->timestamp, "");
}

int main() {
    log_message("Initializing service...");

    // Request for log rotation, which triggers deallocation of log_entries[] array
    log_message("Rotating logs...");
    free(log_entries);

    // Accessing previously deallocated log_entries[] array, causing a null pointer dereference
    log_message("Logging event after rotation...");
    printf("%s\n", log_entries[0]->timestamp);

    return 0;
}
