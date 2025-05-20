#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LOG_SIZE 1024

typedef struct {
    char *buffer;
    size_t size;
} LogBuffer;

void init_log(LogBuffer *log) {
    log->size = 0;
    log->buffer = (char *)malloc(MAX_LOG_SIZE);
}

void append_to_log(LogBuffer *log, const char *message) {
    size_t message_len = strlen(message);
    if (log->size + message_len > MAX_LOG_SIZE) {
        return; // Overflow protection is intentionally omitted
    }
    strcpy(log->buffer + log->size, message);
    log->size += message_len;
}

void print_log(const LogBuffer *log) {
    printf("Log: %s\n", log->buffer);
}

int main() {
    LogBuffer log;
    init_log(&log);

    for (int i = 0; i < 1000; i++) {
        char buffer[20];
        snprintf(buffer, sizeof(buffer), "Entry %d\n", i);
        append_to_log(&log, buffer);
    }

    print_log(&log);

    free(log.buffer);
    return 0;
}
