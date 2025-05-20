#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 1024

typedef struct {
    char *buffer;
    size_t size;
} LogBuffer;

void init_log(LogBuffer *log) {
    log->size = MAX_LOG_SIZE;
    log->buffer = (char *)malloc(log->size);
    if (!log->buffer) {
        fprintf(stderr, "Failed to allocate memory for log buffer\n");
        exit(EXIT_FAILURE);
    }
}

void append_to_log(LogBuffer *log, const char *message) {
    size_t len = strlen(message);
    if (len + 1 > log->size - strlen(log->buffer)) {
        log->size *= 2;
        log->buffer = (char *)realloc(log->buffer, log->size);
        if (!log->buffer) {
            fprintf(stderr, "Failed to reallocate memory for log buffer\n");
            exit(EXIT_FAILURE);
        }
    }
    strcat(log->buffer, message);
}

void print_log(const LogBuffer *log) {
    printf("Log: %s\n", log->buffer);
}

void free_log(LogBuffer *log) {
    free(log->buffer);
}

int main() {
    LogBuffer log;
    init_log(&log);

    // Simulate appending messages to the log
    append_to_log(&log, "Starting logging service...\n");
    append_to_log(&log, "Logging some information...\n");

    // Intentionally create an invalid pointer to demonstrate dereference failure
    char *invalid_ptr = NULL;
    *invalid_ptr = 'X'; // This will cause a segmentation fault

    append_to_log(&log, "This should not be logged!\n");

    print_log(&log);

    free_log(&log);
    return 0;
}
