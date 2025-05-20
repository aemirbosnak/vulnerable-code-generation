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
    if (!logger->file) {
        perror("Failed to open log file");
        free(logger);
        return NULL;
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

void destroy_logger(Logger *logger) {
    if (logger) {
        fclose(logger->file);
        free(logger);
    }
}

int main() {
    Logger *logger = create_logger();
    if (!logger) {
        fprintf(stderr, "Failed to create logger\n");
        return EXIT_FAILURE;
    }

    log_message(logger, "Application started");

    // Intentionally accessing an invalid memory location to simulate a dereference failure
    int *invalid_ptr = NULL;
    printf("%d\n", *invalid_ptr); // Dereferencing null pointer

    log_message(logger, "Application ended");

    destroy_logger(logger);
    return EXIT_SUCCESS;
}
