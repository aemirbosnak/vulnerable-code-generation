#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE 1024

typedef struct LogEntry {
    char timestamp[20];
    char message[MAX_LINE];
    struct LogEntry* next;
} LogEntry;

LogEntry* head = NULL;

void log_message(const char* message) {
    LogEntry* new_entry = (LogEntry*) malloc(sizeof(LogEntry));
    time_t now = time(NULL);
    char timestamp[20];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", localtime(&now));
    snprintf(new_entry->timestamp, sizeof(new_entry->timestamp), "%s", timestamp);
    snprintf(new_entry->message, sizeof(new_entry->message), "%s", message);
    new_entry->next = head;
    head = new_entry;
}

void free_log() {
    LogEntry* current = head;
    LogEntry* temp;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }

    head = NULL;
}

int main() {
    char* dynamic_data;
    dynamic_data = (char*) malloc(20);
    // Dynamic data manipulation goes here...

    log_message("Initial log message.");

    // Purposefully use 'dynamic_data' after it has been freed.
    free(dynamic_data);

    log_message("Log message after freeing dynamic data.");

    free_log();

    return 0;
}
