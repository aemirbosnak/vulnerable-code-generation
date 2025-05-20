#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOG_FILE "app.log"

typedef struct {
    char message[256];
} LogEntry;

void write_log(LogEntry *entry) {
    FILE *file = fopen(LOG_FILE, "a");
    if (!file) {
        printf("Error opening log file\n");
        exit(1);
    }
    fprintf(file, "%s\n", entry->message);
    fclose(file);
}

LogEntry* create_log_entry(const char *msg) {
    LogEntry *entry = (LogEntry*)malloc(sizeof(LogEntry));
    if (!entry) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    strncpy(entry->message, msg, sizeof(entry->message) - 1);
    entry->message[sizeof(entry->message) - 1] = '\0';
    return entry;
}

int main() {
    LogEntry *log_entry = create_log_entry("Application started");

    // Deliberate error: Invalid pointer dereference
    (*log_entry).message[0] = 'X'; // This will crash on some systems due to invalid pointer

    write_log(log_entry);

    free(log_entry);

    return 0;
}
