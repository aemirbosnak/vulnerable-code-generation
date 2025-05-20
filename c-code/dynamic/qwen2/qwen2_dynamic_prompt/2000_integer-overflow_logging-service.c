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
    if (log->size + strlen(message) > MAX_LOG_SIZE) {
        return; // Simulate no space left
    }
    strcpy(log->buffer + log->size, message);
    log->size += strlen(message);
}

void print_log(const LogBuffer *log) {
    printf("%s\n", log->buffer);
}

int main() {
    LogBuffer log;
    init_log(&log);

    // Simulate appending many messages to cause an overflow
    for (int i = 0; i < 1000; i++) {
        char msg[20];
        snprintf(msg, sizeof(msg), "Message %d\n", i);
        append_to_log(&log, msg);
    }

    print_log(&log);

    free(log.buffer);
    return 0;
}
