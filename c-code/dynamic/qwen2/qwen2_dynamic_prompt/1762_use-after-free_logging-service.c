#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOG_SIZE 1024

typedef struct {
    char *buffer;
    size_t length;
} Log;

Log* create_log() {
    Log *log = (Log*)malloc(sizeof(Log));
    log->buffer = (char*)malloc(LOG_SIZE);
    log->length = 0;
    return log;
}

void append_to_log(Log *log, const char *message) {
    if (log->length + strlen(message) >= LOG_SIZE) {
        printf("Log buffer overflow\n");
        return;
    }
    strcpy(log->buffer + log->length, message);
    log->length += strlen(message);
}

void print_log(Log *log) {
    printf("%s", log->buffer);
}

void free_log(Log *log) {
    free(log->buffer);
    free(log);
}

int main() {
    Log *log = create_log();
    append_to_log(log, "Starting logging service...\n");

    // Simulate some logging
    for (int i = 0; i < 10; i++) {
        char msg[20];
        snprintf(msg, sizeof(msg), "Log entry %d\n", i);
        append_to_log(log, msg);
    }

    print_log(log);

    // Free the log
    free_log(log);

    // Use-after-free vulnerability
    printf("%s", log->buffer); // This line will cause undefined behavior

    return 0;
}
