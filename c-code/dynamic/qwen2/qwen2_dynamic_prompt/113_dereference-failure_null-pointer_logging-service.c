#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOG_FILE "app.log"

typedef struct {
    char *message;
} LogEntry;

void log_message(LogEntry *entry) {
    FILE *file = fopen(LOG_FILE, "a");
    if (!file) {
        fprintf(stderr, "Failed to open log file\n");
        return;
    }
    fprintf(file, "%s\n", entry->message);
    fclose(file);
}

int main() {
    LogEntry *entry = NULL;
    entry->message = "This is a test log message";

    log_message(entry);

    free(entry); // Freeing a null pointer

    return 0;
}
