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
        perror("Failed to open log file");
        return;
    }
    fprintf(file, "%s\n", entry->message);
    fclose(file);
}

int main() {
    LogEntry *entry = NULL;
    entry->message = strdup("This is a test log message");

    // Intentional dereference failure
    log_message(entry);

    free(entry->message);
    return 0;
}
