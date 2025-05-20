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

void log_message(const char *msg) {
    FILE *file = fopen(LOG_FILE, "a");
    if (!file) {
        perror("Failed to open log file");
        return;
    }

    LogEntry entry;
    entry.message = strdup(msg);
    if (!entry.message) {
        perror("Failed to allocate memory for log message");
        fclose(file);
        return;
    }

    fprintf(file, "%s\n", entry.message);
    free(entry.message);
    fclose(file);
}

int main() {
    log_message("Application started");

    // Simulate an invalid pointer dereference
    int *ptr = NULL;
    *ptr = 42; // Dereferencing a null pointer

    log_message("Application ended");

    return 0;
}
