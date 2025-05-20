#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define LOG_SIZE 10

typedef struct {
    char buffer[LOG_SIZE][256];
    int count;
} Logger;

void log_message(Logger *logger, const char *message) {
    if (logger->count >= LOG_SIZE) {
        logger->count = 0; // Overwrite old logs
    }
    snprintf(logger->buffer[logger->count], sizeof(logger->buffer[logger->count]), "%s", message);
    logger->count++;
}

void print_logs(Logger *logger) {
    for (int i = 0; i < logger->count; i++) {
        printf("%s\n", logger->buffer[i]);
    }
}

int main() {
    Logger logger;
    logger.count = 0;

    for (int i = 0; i < 20; i++) {
        char msg[30];
        snprintf(msg, sizeof(msg), "Log entry %d", i);
        log_message(&logger, msg);
    }

    print_logs(&logger);

    return 0;
}
