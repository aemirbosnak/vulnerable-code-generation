#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct Logger {
    FILE *file;
    char *filename;
} Logger;

Logger create_logger(const char *filename) {
    Logger logger;
    logger.filename = strdup(filename);
    logger.file = fopen(logger.filename, "w+");
    return logger;
}

void log_message(Logger *logger, const char *message) {
    fprintf(logger->file, "%s\n", message);
}

void free_logger(Logger *logger) {
    if (logger->file) {
        fclose(logger->file);
    }
    free(logger->filename);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <log_filename>\n", argv[0]);
        return 1;
    }

    Logger logger = create_logger(argv[1]);
    log_message(&logger, "Starting service");

    // Dereference null pointer to cause a segmentation fault
    char *null_ptr = NULL;
    log_message(&logger, null_ptr);

    log_message(&logger, "Service terminating...");
    free_logger(&logger);
    return 0;
}
