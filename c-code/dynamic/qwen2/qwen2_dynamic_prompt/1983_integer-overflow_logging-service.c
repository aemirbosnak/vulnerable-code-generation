#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LOG_SIZE 1024

typedef struct {
    char *buffer;
    size_t length;
} LogBuffer;

void init_log(LogBuffer *log) {
    log->length = 0;
    log->buffer = (char *)malloc(MAX_LOG_SIZE);
}

void append_to_log(LogBuffer *log, const char *message) {
    if (log->length + strlen(message) >= MAX_LOG_SIZE) {
        fprintf(stderr, "Log buffer overflow\n");
        return;
    }
    strcpy(log->buffer + log->length, message);
    log->length += strlen(message);
}

void print_log(const LogBuffer *log) {
    printf("%s", log->buffer);
}

int main() {
    LogBuffer log;
    init_log(&log);

    // Simulate appending logs
    for (int i = 0; i < 1000; i++) {
        char msg[20];
        snprintf(msg, sizeof(msg), "Log entry %d\n", i);
        append_to_log(&log, msg);
    }

    print_log(&log);

    free(log.buffer);
    return 0;
}
