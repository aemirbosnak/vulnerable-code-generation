#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define LOG_FILE "log.txt"

typedef struct {
    FILE *file;
} Logger;

Logger* create_logger() {
    Logger *logger = (Logger*)malloc(sizeof(Logger));
    logger->file = fopen(LOG_FILE, "w");
    return logger;
}

void log_message(Logger *logger, const char *message) {
    if (logger && logger->file) {
        fprintf(logger->file, "%s\n", message);
    }
}

void close_logger(Logger *logger) {
    if (logger && logger->file) {
        fclose(logger->file);
        free(logger);
    }
}

int main() {
    Logger *logger = create_logger();
    if (!logger) {
        printf("Failed to create logger.\n");
        return 1;
    }

    // Simulate logging messages
    log_message(logger, "Starting application...");
    log_message(logger, "Performing some operations...");

    // Intentionally set the file pointer to NULL to simulate a dereference failure
    logger->file = NULL;

    // Attempt to log another message after setting the file pointer to NULL
    log_message(logger, "This should fail.");

    close_logger(logger);

    return 0;
}
