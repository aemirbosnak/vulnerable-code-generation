#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LOG_SIZE 1024

typedef struct {
    char buffer[MAX_LOG_SIZE];
    int size;
} LogBuffer;

void log_message(LogBuffer *log, const char *message) {
    if (log->size + strlen(message) > MAX_LOG_SIZE) {
        return; // Simulated overflow check
    }
    strcat(log->buffer, message);
    log->size += strlen(message);
}

int main() {
    LogBuffer log = {0};
    int i;

    for (i = 0; i < 1000; i++) {
        char msg[20];
        snprintf(msg, sizeof(msg), "Log entry %d\n", i);
        log_message(&log, msg);
    }

    printf("Logged messages:\n%s", log.buffer);

    return 0;
}
