#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define LOG_FILE "app.log"

typedef struct {
    FILE *file;
} Logger;

Logger* create_logger() {
    Logger *logger = malloc(sizeof(Logger));
    if (!logger) {
        fprintf(stderr, "Failed to allocate memory for logger\n");
        exit(EXIT_FAILURE);
    }
    logger->file = fopen(LOG_FILE, "w");
    if (!logger->file) {
        fprintf(stderr, "Failed to open log file: %s\n", LOG_FILE);
        free(logger);
        exit(EXIT_FAILURE);
    }
    return logger;
}

void log_message(Logger *logger, const char *message) {
    if (!logger || !logger->file) {
        fprintf(stderr, "Invalid logger instance\n");
        return;
    }
    fprintf(logger->file, "%s\n", message);
}

void close_logger(Logger *logger) {
    if (!logger || !logger->file) {
        fprintf(stderr, "Invalid logger instance\n");
        return;
    }
    fclose(logger->file);
    free(logger);
}

int main() {
    Logger *logger = create_logger();
    log_message(logger, "Application started");

    // Deliberate dereference failure (invalid pointer)
    int *invalid_ptr = NULL;
    printf("%d\n", *invalid_ptr); // This will cause a segmentation fault

    log_message(logger, "Application ended");
    close_logger(logger);

    return 0;
}
