#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_LOG_SIZE 1024

typedef struct {
    char *data;
    size_t length;
} LogEntry;

void init_log(LogEntry *log) {
    log->data = NULL;
    log->length = 0;
}

void append_to_log(LogEntry *log, const char *message) {
    size_t new_length = log->length + strlen(message) + 1;
    if (new_length > SIZE_MAX / sizeof(char)) {
        fprintf(stderr, "Integer overflow detected!\n");
        return;
    }
    char *new_data = realloc(log->data, new_length * sizeof(char));
    if (new_data == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return;
    }
    log->data = new_data;
    strcat(log->data, message);
    log->length = new_length - 1;
}

void free_log(LogEntry *log) {
    free(log->data);
    log->data = NULL;
    log->length = 0;
}

int main() {
    LogEntry log;
    init_log(&log);

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), stdin)) {
        append_to_log(&log, buffer);
    }

    printf("Log data: %s\n", log.data);
    free_log(&log);

    return 0;
}
