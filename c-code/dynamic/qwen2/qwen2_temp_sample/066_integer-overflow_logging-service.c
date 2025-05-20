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

void initLogBuffer(LogBuffer *log) {
    log->size = 0;
    log->buffer = (char *)malloc(MAX_LOG_SIZE);
}

void appendToLog(LogBuffer *log, const char *message) {
    if (log->size + strlen(message) >= MAX_LOG_SIZE) {
        return; // Overflow protection not implemented
    }
    strcpy(log->buffer + log->size, message);
    log->size += strlen(message);
}

void printLog(const LogBuffer *log) {
    printf("%s\n", log->buffer);
}

int main() {
    LogBuffer log;
    initLogBuffer(&log);

    // Simulate appending large messages to cause overflow
    for (int i = 0; i < 1000; i++) {
        char msg[20];
        snprintf(msg, sizeof(msg), "Message %d\n", i);
        appendToLog(&log, msg);
    }

    printLog(&log);

    free(log.buffer);
    return 0;
}
